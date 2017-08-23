#!/usr/bin/env python
#
# Mulator - An extensible {ARM} {e,si}mulator
# Copyright 2011-2012  Pat Pannuto <pat.pannuto@gmail.com>
# Copyright 2017  Andrew Lukefahr <lukefahr@indiana.edu>
#
# This file is part of Mulator.
#
# Mulator is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Mulator is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Mulator.  If not, see <http://www.gnu.org/licenses/>.

from inspect import getframeinfo, stack
import os
import sys

import PyMulatorC

class PyMulator(object):
    
    class PyMulatorError(Exception): pass

    class RegFile:
        def __getitem__(this,key):
            print ('RegRd ' + str(key))
            if key == 'pc': return 0+4 # ARM PC is wierd
            return 0
        def __setitem__(this,key,val):            
            print ('RegWr ' + str(key))
    
    class Memory:
        def __getitem__(this,key):
            addr = key[0]
            size = key[1]
            print ('MemRd uint' + str(size) + '_t ' + hex(addr))
            return 0x4011
        def __setitem__(this,key,val):            
            print ('MemWr ' + str(key))
 

    def dprintf(this, out):
        if (this.debug == True):
            caller = getframeinfo(stack()[1][0])
            print "DEBUG\t%s:%d : %s" %  \
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
        this.dprintf('Input: ' + gdb_str)

        try:

            cmds = gdb_str.split()

            # register read
            if 'info' == cmds[0]:
                assert( len(cmds) > 1) 

                if 'register' in cmds[1]:
                    assert(len(cmds) > 2)

                    this.dprintf('Reading Register: ' + cmds[2])

                    reg = cmds[2]

                    reg_val = this.registers[reg]

                    result = reg + ' ' + hex(reg_val)

            # register write
            elif cmds[0].startswith('p'):
                assert( len(cmds) > 3)
                this.dprintf('Writing Register: ' + cmds[1])

                reg = cmds[1].strip('$')
                # 2 is equal sign
                val = int(cmds[3],16)
                
                this.registers[reg] = val 

                result = '$0 = ' + hex(val)

            # memory read
            elif cmds[0].startswith('x/'):
                assert( len(cmds) > 1)
                this.dprintf('Reading Memory: ' + cmds[1])

                addr = int(cmds[1],16)

                if '/1xw' in cmds[0]: # word
                    val = this.memory[(addr,32)]
                elif '/1xh' in cmds[0]: # halfword
                    val = this.memory[(addr,16)]
                elif '/1xb' in cmds[0]: # word
                    val = this.memory[(addr,8)]
                else: 
                    raise Exception("Bad Memory Read")

                result = hex(addr) + ': ' + hex(val)
           
            elif 'set' == cmds[0]:
                assert(len(cmds) > 4 )
                this.dprintf('Writing Memory: ' + cmds[2])

                addr = int(cmds[2],16)

                if cmds[1] == '{uint32_t}':
                    size = 32
                elif cmds[1] == '{uint16_t}':
                    size = 16
                elif cmds[1] == '{uint8_t}':
                    size = 8
                else: raise Exception("Bad Memory Write")

                val = int(cmds[4],16)

                this.memory[(addr,size)] = val 

                result = hex(addr) + ': ' + hex(val)
                
            this.dprintf('Output: ' + str(result))
            return result

        except Exception as e:
            print("Callback Exception Occured")
            exc_type, exc_obj, exc_tb = sys.exc_info()
            fname = os.path.split(exc_tb.tb_frame.f_code.co_filename)[1]
            print(exc_type, fname, exc_tb.tb_lineno)
            return None



