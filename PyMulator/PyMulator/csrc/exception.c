/** 
 * Library to wrap M-ulator into the 
 * M3 soft-DBG project
 *
 * Andrew Lukefahr
 * lukefahr@umich.edu
 */

#include <assert.h>

#include "cpu/exception.h"

void 
exception_return( uint32_t exception_return_pc){
	assert(false);
}

void UsageFault_divide_by_0(void)
{
	assert(false);
}

