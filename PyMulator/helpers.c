/** 
 * Library to wrap M-ulator into the 
 * M3 soft-DBG project
 *
 * Andrew Lukefahr
 * lukefahr@indiana.edu
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interface.h"


uint32_t _read32 ( const char * gdb_cmd)
{
    uint32_t ret;
    char * cmd; 
    char * resp;
    
    //copy the const cmd into another buffer
    asprintf( &cmd, "%s", gdb_cmd);
    //callback to get data
    call_from_mulator(cmd, &resp);
    
    //parse the response data
    assert(resp!= NULL);
    char * arg1 = strtok(resp, " \t");
    char * arg2 = strtok(NULL, " \t");
    assert( arg1 != NULL);
    assert( arg2 != NULL);

    //pull out the value
    ret = strtol( arg2, NULL, 16); 

    //cleanup memory
    free(cmd);
    free(resp);
   
    //and we're done
    return ret;
}

uint32_t _write32 ( const char * gdb_cmd)
{
    uint32_t ret;
    char * cmd; 
    char * resp;
    
    //copy the const cmd into another buffer
    asprintf( &cmd, "%s", gdb_cmd);
    //callback to get data
    call_from_mulator(cmd, &resp);
    
    //parse the response data
    assert(resp!= NULL);
    char * arg1 = strtok(resp, " \t");
    //writes come with an equal sign
    char * eq = strtok(NULL, " \t"); 
    char * arg2 = strtok(NULL, " \t");
    assert( arg1 != NULL);
    assert( arg2 != NULL);

    //pull out the value
    ret = strtol( arg2, NULL, 16); 

    //cleanup memory
    free(cmd);
    free(resp);
   
    //and we're done
    return ret;
}

