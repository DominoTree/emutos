/*
 * clock.h - BIOS time and date routines
 *
 * Copyright (C) 2001-2019 The EmuTOS development team
 *
 * Authors:
 *  LVL   Laurent Vogel
 *
 * This file is distributed under the GPL, version 2 or at your
 * option any later version.  See doc/license.txt for details.
 */

#ifndef CLOCK_H
#define CLOCK_H

void clockvec(char *buf);

/* interface for machine.c */

#if CONF_WITH_MEGARTC
void detect_megartc(void);
#endif /* CONF_WITH_MEGARTC */

#if CONF_WITH_ICDRTC
void detect_icdrtc(void);
#endif /* CONF_WITH_ICDRTC */

#if CONF_WITH_ULTRASATAN_CLOCK
void detect_ultrasatan(void);
long ultrasatan_endcmd(short mode);
long ultrasatan_hdone(void);
long ultrasatan_wait_dma_cmpl(unsigned long t_ticks);
long ultrasatan_qdone(void);
long ultrasatan_fdone(void);
ULONG ultrasatangetdt(void);
UBYTE ultrasatansetdt(ULONG dt);
UBYTE ultrasatan_readfw(UBYTE ACSI_id, UBYTE *buffer);
UBYTE ultrasatan_longrw(UBYTE ReadNotWrite, UBYTE *cmd, UBYTE *buffer);
#endif /* CONF_WITH_ULTRASATAN_CLOCK */

#if CONF_WITH_MONSTER
void detect_monster_rtc(void);
#endif /* CONF_WITH_MONSTER */

/* internal init */

void clock_init(void);

/* xbios functions */

void settime(LONG time);
LONG gettime(void);

#endif /* CLOCK_H */
