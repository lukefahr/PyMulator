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

// Stuff needed to make the existing code happy

/** no idea */
int raiseonerror = 1;

/**
 * terminates the "simulation" 
 * (which we aren't really running)
 */
void sim_terminate(bool should_exit)
{
    printf("SIM TERMINATE\n");
    exit(EXIT_SUCCESS);
}



/**
 * My main test-driver program
 */
int main(void)
{
    uint32_t inst = 0x4011;
    struct op* op = find_op( inst);
    
    assert(op);
    if (op->is16)
        op->op16.fn(inst);
    else
        op->op32.fn(inst);

    return 0;
}
