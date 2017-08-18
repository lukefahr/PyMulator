
import PyMulatorC

class PyMulator(object):
    
    class PyMulatorError(Exception):
        pass

    class PyMulatorCallbackError(PyMulatorError):
        pass

    def __init__(this):
        
        # register our callback function
        PyMulatorC.register_callback(this.callback)

        this._reg_read = this._default_reg_read
        this._reg_write = this._default_reg_write
        this._mem_read = this._default_mem_read
        this._mem_write = this._default_mem_write


    def stepi(this):
        PyMulatorC.call_to_mulator("stepi")

    def callback(this, gdb_str):
        cmds = gdb_str.split()

        # register read
        if 'info' == cmds[0]:
            if ( len(cmds) < 2): 
                raise PyMulatorCallbackError(gdb_str)

            if 'register' in cmds[1]:
                
                reg = cmds[2]
                reg_val = this._reg_read(reg)

                result = reg + ' ' + hex(reg_val)

            else:
                raise PyMulatorCallbackError(gdb_str)

        # register write
        elif 'p' == cmds[0]:

            if ( len(cmds) < 4): 
                raise PyMulatorCallbackError(gdb_str)

            reg = cmds[1].strip('$')
            # 2 is equal sign
            val = int(cmds[3],16)
            
            this._reg_write(reg,val)

            result = '$0 = ' + hex(val)

        # memory read
        elif 'x/1xh' in cmds[0]:

            if ( len(cmds) < 2): 
                raise PyMulatorCallbackError(gdb_str)
            
            addr = cmds[1]
            val = this._mem_read(addr)

            result = hex(addr) + ': ' + hex(val)
        
        else: raise PyMulatorCallbackError(gdb_str)

        print ('Input: ' + gdb_str)
        print ('Output: ' + result)
        return result


    def _default_reg_read(this, reg):
        print ("Using Default Register Read")
        return 0

    def _default_reg_write(this, reg, val):
        print ("Using Default Register Read")
        return 0

    def _default_mem_read(this, addr):
        print ("Using Default Memory Read")
        return 0x4011

    def _default_mem_write(this, addr, val):
        print ("Using Default Memory Read")
        return 0




