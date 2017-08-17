/** 
 * Library to wrap M-ulator into the 
 * M3 soft-DBG project
 *
 * Andrew Lukefahr
 * lukefahr@umich.edu
 */
#ifndef __INTERFACE_H__
#define __INTERFACE_H__

/** this will use gdb syntax */
void call_to_mulator( const char * cmd);

/** this will use gdb syntax */
extern void call_from_mulator( char * command, char ** result);

#endif


