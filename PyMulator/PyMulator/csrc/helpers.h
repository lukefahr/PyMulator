/* Mulator - An extensible {ARM} {e,si}mulator
 * Copyright 2011-2012  Pat Pannuto <pat.pannuto@gmail.com>
 * Copyright 2017  Andrew Lukefahr <lukefahr@indiana.edu>
 *
 * This file is part of Mulator.
 *
 * Mulator is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Mulator is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Mulator.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __HELPERS_H__
#define __HELPERS_H__

#include <stdlib.h>

int32_t _read32 ( const char * gdb_cmd, uint32_t * val );
int32_t _write32 ( const char * gdb_cmd, uint32_t * val );

#if __STDC_VERSION__ < 199901L
     # if __GNUC__ >= 2
         #  define __func__ __FUNCTION__
     # else
         #  define __func__ "<unknown>"
     # endif
 #endif

#define UNIMPLIMENTED()                                 \
    do {                                                \
        fprintf(stderr, "%s:%d:%s NOT IMPLIMENTED\n",   \
                __FILE__, __LINE__, __func__);          \
        exit(EXIT_FAILURE);                             \
    } while(0)              

#endif


