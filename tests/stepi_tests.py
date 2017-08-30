#!/usr/bin/env python

from PyMulator.PyMulator import PyMulator

import logging
logging.basicConfig(level=logging.DEBUG, \
    format="%(levelname)s %(name)s %(message)s")
logger = logging.getLogger(__name__)

class TestStepi(object):

    #class TestFailedException(Exception):
    #    logger.error( '='*80 + '\n\nTEST FAILED\n\n' + '='*80)

    @classmethod
    def setup_class(cls,):
        pass

    @classmethod
    def teardown_class(cls,):
        pass

    class CallbackContainer(object):
        def __init__(this, local):
            this.local = local
        def __getitem__(this,key):
            return this.local[key]
        def __setitem__(this,key,val):            
            this.local[key] = val

    class RegFile(CallbackContainer):
        def __str__(this):
            return ', '.join(
                    map(lambda x: str(x)+':'+hex(this.local[x]), 
                        this.local)
                       )
    class Memory(CallbackContainer):
        def __str__(this):
            return ', '.join(
                map(lambda x: 
                    hex(x[0])+'(' + str(x[1]) + '):' + hex(this.local[x]), 
                    this.local)
                    )


    def test_nop(this):
        
        logger.info("Nop test")

        regVals= { 'pc' : 0x04+4, # pc = pc+4
                    'r8' : 0x0 ,
                  }
        memVals= { (0x04,16): 0x46c0 } #nop

        rf = this.RegFile(regVals)
        mem = this.Memory(memVals)
        
        pm = PyMulator( rf, mem)

        logger.info('Stepping')
        pm.stepi()
        
        assert( regVals['pc'] == 0x6)
        assert( regVals['r8'] == 0x0)

    def test_str(this):
        
        logger.info("test store")

        regVals= { 'pc' : 0x06+4, # pc = pc+4
                    'r0' : 0xbaac ,
                    'r1' : 0xbeef ,
                  }
        memVals= { (0x06,16): 0x6001 } #str r1, [r0, #0]

        rf = this.RegFile(regVals)
        mem = this.Memory(memVals)
        
        pm = PyMulator( rf, mem)

        logger.info('Stepping')
        pm.stepi()
      
        #print ( str(rf) )
        #print ( str(mem))
        assert( regVals['pc'] == 0x8)
        assert( memVals[(0xbaac,8)] == 0xef)
        assert( memVals[(0xbaad,8)] == 0xbe)

    def test_movs(this):
        
        logger.info("move test")

        regVals= { 'pc' : 0x08+4, # pc = pc+4
                    'r0' : 0xbaadbeef,
                    'xpsr': 0x81000000,
                  }
        memVals= { (0x08,16): 0x2001 } #movs r0, #1

        rf = this.RegFile(regVals)
        mem = this.Memory(memVals)
        
        pm = PyMulator( rf, mem)

        logger.info('Stepping')
        pm.stepi()
      
        #print ( str(rf) )
        #print ( str(mem))
        assert( regVals['pc'] == 0xa)
        assert( regVals['r0'] == 0x1)

    def test_bx(this):
        
        logger.info("move branch exchange")

        regVals= { 'pc' : 0x0a+4, # pc = pc+4
                    'lr' : 0xabce,
                    'xpsr': 0x81000000,
                  }
        memVals= { (0x0a,16): 0x4770 } #bx lr

        rf = this.RegFile(regVals)
        mem = this.Memory(memVals)
        
        pm = PyMulator( rf, mem)

        logger.info('Stepping')
        pm.stepi()
      
        assert( regVals['pc'] == 0xabce)
        assert( regVals['lr'] == 0xabce)





if __name__ == '__main__':
    
    t = TestStepi()
    t.test_nop()

