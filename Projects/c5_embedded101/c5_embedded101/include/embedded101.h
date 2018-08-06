/*
 * embedded101.h
 *
 *  Created on: 6 Aug 2018
 *      Author: User
 */

#ifndef EMBEDDED101_H_
#define EMBEDDED101_H_

/***************************************** Standard Header Files *****************************************/
#include <stdint.h>


/***************************************** WDOG related *****************************************/

/** WDOG - Register Layout Typedef */
typedef struct {
  volatile uint32_t CS;                                /**< Watchdog Control and Status Register, offset: 0x0 */
  volatile uint32_t CNT;                               /**< Watchdog Counter Register, offset: 0x4 */
  volatile uint32_t TOVAL;                             /**< Watchdog Timeout Value Register, offset: 0x8 */
  volatile uint32_t WIN;                               /**< Watchdog Window Register, offset: 0xC */
} WDOG_Type, *WDOG_MemMapPtr;

/** Number of instances of the WDOG module. */
#define WDOG_INSTANCE_COUNT                      (1u)

/* WDOG - Peripheral instance base addresses */
/** Peripheral WDOG base address */
#define WDOG_BASE                                (0x40052000u)
/** Peripheral WDOG base pointer */
#define WDOG                                     ((WDOG_Type *)WDOG_BASE)
/** Array initializer of WDOG peripheral base addresses */
#define WDOG_BASE_ADDRS                          { WDOG_BASE }
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASE_PTRS                           { WDOG }



#endif /* EMBEDDED101_H_ */
