
from inspect import getframeinfo, stack
import os

import PyMulatorC

class PyMulator(object):
    
    class PyMulatorError(Exception): pass

    class RegFile:
        def __getitem__(this,key):
            print ('RegRd ' + str(key))
            return 0
        def __setitem__(this,key,val):            
            print ('RegWr ' + str(key))
    
    class Memory:
        def __getitem__(this,key):
            print ('MemRd ' + str(key))
            return 0x4011
        def __setitem__(this,key,val):            
            print ('MemWr ' + str(key))
 

    def dprintf(this, out):
        if (this.debug == True):
            caller = getframeinfo(stack()[1][0])
            print "%s:%d : %s" %  \
                (os.path.basename(caller.filename), caller.lineno, out)

    def __init__(this, registers, memory, debug=False):
        
        this.debug = debug

        this.registers = registers
        this.memory = memory 

        if (this.registers == None):
            print ("WARNING: dummy RegFile")
            this.registers = this.RegFile()
        if (this.memory == None):
            print ("WARNING: dummy Memory")
            this.memory = this.Memory()

        # register our callback function
        PyMulatorC.register_callback(this._callback)

    def stepi(this):
        PyMulatorC.call_to_mulator("stepi")

    def _callback(this, gdb_str):

        result = None

        this.dprintf('Input: ' + gdb_str)

        cmds = gdb_str.split()

        # register read
        if 'info' == cmds[0] and (len(cmds) > 1): 

            if 'register' in cmds[1] and (len(cmds) > 2):
                this.dprintf('Reading Register: ' + cmds[2])

                reg = cmds[2]

                reg_val = this.registers[reg]

                result = reg + ' ' + hex(reg_val)

        # register write
        elif 'p' == cmds[0] and ( len(cmds) > 3): 
            this.dprintf('Writing Register: ' + cmds[1])

            reg = cmds[1].strip('$')
            # 2 is equal sign
            val = int(cmds[3],16)
            
            this.registers[reg] = val 

            result = '$0 = ' + hex(val)

        # memory read
        elif 'x/1xh' == cmds[0] and ( len(cmds) > 1): 
            this.dprintf('Reading Memory: ' + cmds[1])

            addr = int(cmds[1],16)
            val = this.memory[addr]

            result = hex(addr) + ': ' + hex(val)
       
        elif 'set' == cmds[0] and (len(cmds) > 4 ):
            
            if cmds[1] == '{uint16_t}':
                this.dprintf('Writing Memory: ' + cmds[2])

                addr = int(cmds[2],16)
                val = int(cmds[4],16)

                this.memory[addr] = val 

                result = hex(addr) + ': ' + hex(val)
            
        this.dprintf('Output: ' + str(result))
        return result


