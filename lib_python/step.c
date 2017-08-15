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

#include "core/opcodes.h"

int32_t step(uint32_t inst)
{
    //uint32_t inst = 0x4011;

    struct op* op = find_op( inst);
    
    assert(op);
    if (op->is16)
        op->op16.fn(inst);
    else
        op->op32.fn(inst);

    return 0;
}


