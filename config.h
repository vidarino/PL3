/*
 * config.h -- PS3 Jailbreak payload : configuration file
 *
 * Copyright (C) Youness Alaoui (KaKaRoTo)
 *
 * This software is distributed under the terms of the GNU General Public
 * License ("GPL") version 3, as published by the Free Software Foundation.
 *
 */

#ifndef PL3_CONFIG_H
#define PL3_CONFIG_H


/* Define this macro if want to use the jig method */
#define USE_JIG

/* The firmware version supported gets defined in the Makefile */
//#define FIRMWARE_3_41
//#define FIRMWARE_3_15
//#define FIRMWARE_3_01

/* Enable model version patching */
/* Only works for firmwares 3.41 and 3.15 */
#define MODELSET

/* Enable firmware 3.50 spoofing */
/* Only works for firmware 3.41 */
#define VERSIONTEST

#endif /* PL3_CONFIG_H */

