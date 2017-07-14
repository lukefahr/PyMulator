/** 
 * Library to wrap M-ulator into the 
 * M3 soft-DBG project
 *
 * Andrew Lukefahr
 * lukefahr@umich.edu
 */

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

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "cpu/registers.h"

enum Mode CurrentMode;
uint32_t physical_reg[SP_REG];	// SP,LR,PC not held here, so 13 registers
uint32_t sp_process; // "private" export
uint32_t sp_main; // "private" export
uint32_t *physical_sp_p = &sp_main;
uint32_t physical_lr;

#ifdef M_PROFILE

union apsr_t physical_apsr;
union ipsr_t physical_ipsr;
union epsr_t physical_epsr;

union ufsr_t ufsr;

uint32_t physical_primask;
//     0: priority	The exception mask register, a 1-bit register.
//			Setting PRIMASK to 1 raises the execution priority to 0.
uint32_t physical_basepri;
/* The base priority mask, an 8-bit register. BASEPRI changes the priority
 * level required for exception preemption. It has an effect only when BASEPRI
 * has a lower value than the unmasked priority level of the currently
 * executing software.  The number of implemented bits in BASEPRI is the same
 * as the number of implemented bits in each field of the priority registers,
 * and BASEPRI has the same format as those fields.  For more information see
 * Maximum supported priority value on page B1-636.  A value of zero disables
 * masking by BASEPRI.
 */
uint32_t physical_faultmask;
/* The fault mask, a 1-bit register. Setting FAULTMASK to 1 raises the
 * execution priority to -1, the priority of HardFault. Only privileged
 * software executing at a priority below -1 can set FAULTMASK to 1. This means
 * HardFault and NMI handlers cannot set FAULTMASK to 1. Returning from any
 * exception except NMI clears FAULTMASK to 0.
 */

union control_t physical_control;
//     0: nPRIV, thread mode only (0 == privileged, 1 == unprivileged)
//     1: SPSEL, thread mode only (0 == use SP_main, 1 == use SP_process)
//     2: FPCA, (1 if FP extension active)

#endif // M


////////////////////////////////////////////////////////////////////////////////

uint32_t CORE_reg_read(int r)
{
    assert(false);
    return 0;
	//extern uint32_t physical_reg[SP_REG];
	//extern uint32_t *physical_sp_p;
	//extern uint32_t physical_lr;
	//extern uint32_t id_ex_PC;

	//assert(r >= 0 && r < 16 && "CORE_reg_read");
	//if (r == SP_REG) {
	//	return SR(physical_sp_p) & 0xfffffffc;
	//} else if (r == LR_REG) {
	//	return SR(&physical_lr);
	//} else if (r == PC_REG) {
	//	return SR(&id_ex_PC) & 0xfffffffe;
	//} else {
	//	return SR(&physical_reg[r]);
	//}
}

void CORE_reg_write(int r, uint32_t val) {
    assert(false);
	//assert(r >= 0 && r < 16 && "CORE_reg_write");
	//if (r == SP_REG) {
	//	SW(physical_sp_p, val & 0xfffffffc);
	//} else if (r == LR_REG) {
	//	SW(&physical_lr, val);
	//} else if (r == PC_REG) {
	//	DBG2("Writing %08x to PC\n", val & 0xfffffffe);
	//	pipeline_flush_exception_handler(val & 0xfffffffe);
	//}
	//else {
	//	SW(&(physical_reg[r]), val);
	//}
}

#ifdef M_PROFILE
// <8:0> from IPSR
// <26:24,15:10> from ESPR
// <31:27>,[if DSP: <19:16>] from APSR
static const uint32_t xPSR_ipsr_mask = 0x000001ff;
static const uint32_t xPSR_epsr_mask = 0x0700fc00;
static const uint32_t xPSR_apsr_dsp_mask = 0xf80f0000;
static const uint32_t xPSR_apsr_nodsp_mask = 0xf8000000;

uint32_t CORE_xPSR_read(void) {
    assert(false);
	uint32_t xPSR = 0;
	xPSR |= CORE_ipsr_read().storage & xPSR_ipsr_mask;
	xPSR |= CORE_epsr_read().storage & xPSR_epsr_mask;
    // M0's don't have DSP cores
    //if (HaveDSPExt())
    //    xPSR |= CORE_apsr_read().storage & xPSR_apsr_dsp_mask;
    //else
		xPSR |= CORE_apsr_read().storage & xPSR_apsr_nodsp_mask;
	return xPSR;
}

void CORE_xPSR_write(uint32_t xPSR) {
    assert(false);
	union ipsr_t i = CORE_ipsr_read();
	union epsr_t e = CORE_epsr_read();
	union apsr_t a = CORE_apsr_read();

	i.storage &= ~xPSR_ipsr_mask;
	i.storage |= xPSR & xPSR_ipsr_mask;
	CORE_ipsr_write(i);

	e.storage &= ~xPSR_epsr_mask;
	e.storage |= xPSR & xPSR_epsr_mask;
	CORE_epsr_write(e);

	uint32_t apsr_mask;
    // M0's don't have DSP cores
	//if (HaveDSPExt())
	//	apsr_mask = xPSR_apsr_dsp_mask;
	//else
		apsr_mask = xPSR_apsr_nodsp_mask;
	a.storage &= ~apsr_mask;
	a.storage |= xPSR & apsr_mask;
	CORE_apsr_write(a);
}

enum Mode CORE_CurrentMode_read(void) {
    assert(false);
	extern enum Mode CurrentMode;
	return SR(&CurrentMode);
}

void CORE_CurrentMode_write(enum Mode mode) {
    assert(false);
	extern enum Mode CurrentMode;
	return SW(&CurrentMode, mode);
}

union apsr_t CORE_apsr_read(void) {
    assert(false);
	extern union apsr_t physical_apsr;
	union apsr_t a;
	a.storage = SR(&physical_apsr.storage);
	return a;
}

void CORE_apsr_write(union apsr_t val) {
    assert(false);
	extern union apsr_t physical_apsr;
	uint8_t in_ITblock(void);

	if (in_ITblock()) {
		DBG1("WARN update of apsr in IT block\n");
	}
#ifdef M_PROFILE
	if (val.storage & 0x07f0ffff) {
		DBG1("WARN update of reserved APSR bits\n");
	}
#endif
	SW(&physical_apsr.storage, val.storage);
}

union ipsr_t CORE_ipsr_read(void) {
    assert(false);
	extern union ipsr_t physical_ipsr;
	union ipsr_t i;
	i.storage = SR(&physical_ipsr.storage);
	return i;
}

void CORE_ipsr_write(union ipsr_t val) {
    assert(false);
	extern union ipsr_t physical_ipsr;
	SW(&physical_ipsr.storage, val.storage);
}

union epsr_t CORE_epsr_read(void) {
    assert(false);
	extern union epsr_t physical_epsr;
	union epsr_t e;
	e.storage = SR(&physical_epsr.storage);
	return e;
}

void CORE_epsr_write(union epsr_t val) {
    assert(false);
	extern union epsr_t physical_epsr;
	SW(&physical_epsr.storage, val.storage);
}

bool CORE_control_nPRIV_read(void) {
    assert(false);
	extern union control_t physical_control;
	union control_t c;
	c.storage = SR(&physical_control.storage);
	return c.nPRIV;
}

void CORE_control_nPRIV_write(bool npriv) {
    assert(false);
	extern union control_t physical_control;
	union control_t c;
	c.storage = SR(&physical_control.storage);
	c.nPRIV = npriv;
	SW(&physical_control.storage, c.storage);
}

bool CORE_control_SPSEL_read(void) {
    assert(false);
	extern union control_t physical_control;
	union control_t c;
	c.storage = SR(&physical_control.storage);
	return c.SPSEL;
}


static void control_SPSEL_write(bool spsel, bool force, enum Mode forced_mode) {
    assert(false);
	union control_t c;
	c.storage = SR(&physical_control.storage);
	c.SPSEL = spsel;
	SW(&physical_control.storage, c.storage);

	enum Mode mode = (force) ? forced_mode : CORE_CurrentMode_read();
	(void) mode;

	// XXX: I'm confused on exactly the semantics here, esp w.r.t. exceptions
	//if (mode == Mode_Thread) {
		SWP(&physical_sp_p, (spsel) ? &sp_process : &sp_main);
	//} else {
	//	CORE_ERR_unpredictable("SPSEL write in Handler mode\n");
	//}
}

void CORE_control_SPSEL_write(bool spsel) {
    assert(false);
	control_SPSEL_write(spsel, false, 0);
}

void CORE_update_mode_and_SPSEL(enum Mode mode, bool spsel) {
    assert(false);
	CORE_CurrentMode_write(mode);
	control_SPSEL_write(spsel, true, mode);
}

bool CORE_primask_read(void) {
    assert(false);
	extern uint32_t physical_primask;
	return SR(&physical_primask);
}

void CORE_primask_write(bool val) {
    assert(false);
	extern uint32_t physical_primask;
	SW(&physical_primask, val);
}

uint8_t CORE_basepri_read(void) {
    assert(false);
	extern uint32_t physical_basepri;
	return SR(&physical_basepri);
}

void CORE_basepri_write(uint8_t val) {
    assert(false);
	extern uint32_t physical_basepri;
	SW(&physical_basepri, val);
}

bool CORE_faultmask_read(void) {
    assert(false);
	extern uint32_t physical_faultmask;
	return SR(&physical_faultmask);
}

void CORE_faultmask_write(bool val) {
    assert(false);
	extern uint32_t physical_faultmask;
	SW(&physical_faultmask, val);
}

union ufsr_t CORE_ufsr_read(void) {
    assert(false);
	extern union ufsr_t ufsr;
	union ufsr_t u;
	u.storage = SR(&ufsr.storage);
	return u;
}

void CORE_ufsr_write(union ufsr_t u) {
    assert(false);
	extern union ufsr_t ufsr;
	SW(&ufsr.storage, u.storage);
}
#endif


