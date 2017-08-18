/** 
 * Library to wrap M-ulator into the 
 * M3 soft-DBG project
 *
 * Andrew Lukefahr
 * lukefahr@indiana.edu
 */

#ifndef __HELPERS_H__
#define __HELPERS_H__

int32_t _read32 ( const char * gdb_cmd, uint32_t * val );
int32_t _write32 ( const char * gdb_cmd, uint32_t * val );

#endif


