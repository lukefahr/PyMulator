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



/**
 * called for an illegal instruction
 */
void 
CORE_ERR_illegal_instr_real( const char * f, int l, uint32_t inst)
{
    printf("CORE_ERR_illegal_instr, inst: %08x\n", inst);
    printf("Dumping core...\n");
    printf( "%s:%d\tUnknown inst\n", f, l);
    exit(EXIT_FAILURE);
}

/**
 * called for an un-implimented instruction
 */
void 
CORE_ERR_not_implemented_real(const char *f, int l, const char *opt_msg) {
    printf("%s:%d\tCORE_ERR_not_implemented -- %s\n", f, l, opt_msg);
    exit(EXIT_FAILURE);
}

/** 
 * called for ARM's "UNPREDICTABLE" instructions
 */
void 
CORE_ERR_unpredictable_real(const char *f, int l, const char *opt_msg) {
    printf( "%s:%d\tCORE_ERR_unpredictable -- %s\n", f, l, opt_msg);
    exit(EXIT_FAILURE);
}


