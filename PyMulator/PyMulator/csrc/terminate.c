/** 
 * Library to wrap M-ulator into the 
 * M3 soft-DBG project
 *
 * Andrew Lukefahr
 * lukefahr@indiana.edu
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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


