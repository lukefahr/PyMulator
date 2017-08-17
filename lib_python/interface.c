/** 
 * Library to wrap M-ulator into the 
 * M3 soft-DBG project
 *
 * Andrew Lukefahr
 * lukefahr@umich.edu
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "cpu/core.h"
#include "core/opcodes.h"
#include "cpu/registers.h"

void _stepi();

/** this will use gdb syntax */
void call_to_mulator( const char * cmd)
{
    if( !strncmp(cmd, "stepi", sizeof("stepi")) )
        _stepi();
}




void _stepi()
{
    uint32_t pc = CORE_reg_read( PC_REG );     
    uint32_t inst = read_halfword(pc);
    
    // If inst[15:11] are any of
    // 11101, 11110, or 11111 then this is
    // a 32-bit thumb inst
    switch (inst & 0xf800) {
        case 0xe800:
        case 0xf000:
        case 0xf800:
        {
            inst <<= 16;
            pc = pc + 2;
            inst |= read_halfword(pc);

            break;
        }
        default:
            break;
    }
    
    struct op* op = find_op( inst);
    
    assert(op);
    if (op->is16)
        op->op16.fn(inst);
    else
        op->op32.fn(inst);

}

