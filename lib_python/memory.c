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

uint32_t 
read_word_quiet(uint32_t addr)
{
	assert(false);
	return 0;
}

uint32_t 
read_word(uint32_t addr)
{
	assert(false);
	return 0;
}

void 
write_word(uint32_t addr, uint32_t val)
{
	assert(false);
}

void 
write_word_aligned(uint32_t addr, uint32_t val)
{	
	assert(false);
}

void 
write_word_unaligned(uint32_t addr, uint32_t val)
{
	assert(false);
}

uint16_t 
read_halfword(uint32_t addr)
{
	assert(false);
	return 0;
}

void 
write_halfword(uint32_t addr, uint16_t val)
{
	assert(false);
}

void 
write_halfword_unaligned(uint32_t addr, uint16_t val)
{
	assert(false);
}

uint8_t 
read_byte(uint32_t addr)
{
	assert(false);
	return 0;
}

void 
write_byte(uint32_t addr, uint8_t val)
{
	assert(false);
}


