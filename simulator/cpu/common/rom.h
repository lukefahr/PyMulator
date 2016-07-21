/* Mulator - An extensible {ARM} {e,si}mulator
 * Copyright 2011-2012  Pat Pannuto <pat.pannuto@gmail.com>
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

#ifndef ROM_H
#define ROM_H

#include "core/common.h"

////////////////////////////////////////////////////////////////////////
// Only include this peripheral if requested in the platform memmap.h //
#ifdef ROMBOT
#define HAVE_ROM

#define ROMSIZE (ROMTOP - ROMBOT) // In bytes

#ifndef PP_STRING
#define PP_STRING "ROM"
#include "core/pretty_print.h"
#endif

void flash_ROM(const uint8_t *image, int offset, uint32_t nbytes);
#ifdef PRINT_ROM_ENABLE
size_t dump_ROM(FILE *fp);
#endif

#endif // ROMBOT
// Only include this peripheral if requested in the platform memmap.h //
////////////////////////////////////////////////////////////////////////

#endif // ROM_H
