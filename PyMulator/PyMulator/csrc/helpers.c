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


int32_t _read32 ( const char * gdb_cmd, uint32_t * val)
{
    char * cmd; 
    char * resp;
    
    //copy the const cmd into another buffer
    asprintf( &cmd, "%s", gdb_cmd);
    //callback to get data
    call_from_mulator(cmd, &resp);
    
    //parse the response data
    if (resp == NULL) goto _read32err; 

    char * arg1 = strtok(resp, " \t");
    char * arg2 = strtok(NULL, " \t");

    if (arg1 == NULL) goto _read32err;
    if (arg2 == NULL) goto _read32err; 

    //pull out the value
    *val = (uint32_t) strtol( arg2, NULL, 16); 

    //cleanup memory
    free(cmd);
    free(resp);
   
    //and we're done
    return 0;

    _read32err:
    free(cmd);
    free(resp);
    return -1;
}

int32_t _write32 ( const char * gdb_cmd, uint32_t * val)
{
    char * cmd; 
    char * resp;
    
    //copy the const cmd into another buffer
    asprintf( &cmd, "%s", gdb_cmd);
    //callback to get data
    call_from_mulator(cmd, &resp);
    
    //parse the response data
    if (resp== NULL) goto _write32err;

    char * arg1 = strtok(resp, " \t");
    //writes come with an equal sign
    strtok(NULL, " \t"); 
    char * arg2 = strtok(NULL, " \t");
    if ( arg1 == NULL) goto _write32err;
    if ( arg2 == NULL) goto _write32err;

    //pull out the value
    *val = (uint32_t) strtol( arg2, NULL, 16); 

    //cleanup memory
    free(cmd);
    free(resp);
   
    //and we're done
    return 0;

    _write32err:
    
    free(cmd);
    free(resp);
    return -1;
}

