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

/***************************************** GPIO related *****************************************/

#define GPIO_BASE 	(0x400FF000)   		/* GPIO base address */

#define PORT_A		((uint32_t *)(GPIO_BASE + 0x00))	/* PORT A address */
#define PORT_B		((uint32_t *)(GPIO_BASE + 0x40))	/* PORT B address */
#define PORT_C		((uint32_t *)(GPIO_BASE + 0x80))	/* PORT C address */
#define PORT_D		((uint32_t *)(GPIO_BASE + 0xC0))	/* PORT D address */
#define PORT_E		((uint32_t *)(GPIO_BASE + 0x100))	/* PORT E address */



#define PTC12		(12U)								/* Button 1 position */
#define PTC13		(13U)								/* Button 2 position */
#define PTD15		(15U)								/* Red LED position */
#define PTD0		(0U)								/* Blue LED position */
#define PTD16		(16U)								/* Green LED position */

#define BTN_1		((uint32_t)(1<<PTC12))				/* Button 1 bitmask */
#define BTN_0		((uint32_t)(1<<PTC13))				/* Button 0 bitmask */
#define LED_RED		((uint32_t)(1<<PTD15))				/* Red LED bitmask */
#define LED_BLUE	((uint32_t)(1<<PTD0))				/* Blue LED bitmask */
#define LED_GREEN	((uint32_t)(1<<PTD16))				/* Red LED bitmask */


typedef struct {
	volatile uint32_t PDOR;
	volatile uint32_t PSOR;
	volatile uint32_t PCOR;
	volatile uint32_t PTOR;
	volatile uint32_t PDIR;
	volatile uint32_t PDDR;
	volatile uint32_t PIDR;
	volatile uint32_t * PCC;
} GPIO_map_t, *GPIO_map_tp;



/*********** PCC *******************/
#define PCC_BASE 		(0x40065000u)   		/* PCC base address */

#define PCC_PORT_A		((uint32_t *)(PCC_BASE + 0x124u))	/* PCC PORT A address */
#define PCC_PORT_B		((uint32_t *)(PCC_BASE + 0x128u))	/* PCC PORT B address */
#define PCC_PORT_C		((uint32_t *)(PCC_BASE + 0x12Cu))	/* PCC PORT C address */
#define PCC_PORT_D		((uint32_t *)(PCC_BASE + 0x130u))	/* PCC PORT D address */
#define PCC_PORT_E		((uint32_t *)(PCC_BASE + 0x134u))	/* PCC PORT E address */

#define PCC_ENABLE_PORT_MASK		(1u << 30)

/*********** PCR - Port Control Register *******************/
#define PCR_PORT_C		((uint32_t *)(0x4004B000))	/* PCC PORT C address */
#define PCR_PORT_D		((uint32_t *)(0x4004C000))	/* PCC PORT D address */



#define PCR_GPIO_MODE_MASK		(1 << 8)

/*********** PCC *******************/



















#endif /* EMBEDDED101_H_ */
