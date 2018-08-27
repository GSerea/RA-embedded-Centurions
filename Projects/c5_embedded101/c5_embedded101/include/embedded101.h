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

#define GPIO_BASE 	(0x400FF000u)   		/* GPIO base address */

#define PORT_A		((uint32_t *)(GPIO_BASE + 0x00u))	/* PORT A address */
#define PORT_B		((uint32_t *)(GPIO_BASE + 0x40u))	/* PORT B address */
#define PORT_C		((uint32_t *)(GPIO_BASE + 0x80u))	/* PORT C address */
#define PORT_D		((uint32_t *)(GPIO_BASE + 0xC0u))	/* PORT D address */
#define PORT_E		((uint32_t *)(GPIO_BASE + 0x100u))	/* PORT E address */



#define PTC12		(12U)								/* Button 1 position */
#define PTC13		(13U)								/* Button 2 position */
#define PTD15		(15U)								/* Red LED position */
#define PTD16		(16U)								/* GREEN LED position */
#define PTD0		(0U)								/* BLUE LED position */

#define BTN_1		((uint32_t)(1<<PTC12))				/* Button 1 bitmask */
#define BTN_2		((uint32_t)(1<<PTC13))				/* Button 2 bitmask */

#define LED_RED			(1<<PTD15)						/* Red LED bitmask */
#define LED_BLUE 		(1<<PTD0)						/* BLUE LED bitmask */
#define LED_GREEN		(1<<PTD16)						/* GREEN LED bitmask */
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



/***************************************** PCC *****************************************/
#define PCC_BASE 		(0x40065000u)   		/* PCC base address */

#define PCC_PORT_A		((uint32_t *)(PCC_BASE + 0x124u))	/* PCC PORT A address */
#define PCC_PORT_B		((uint32_t *)(PCC_BASE + 0x128u))	/* PCC PORT B address */
#define PCC_PORT_C		((uint32_t *)(PCC_BASE + 0x12Cu))	/* PCC PORT C address */
#define PCC_PORT_D		((uint32_t *)(PCC_BASE + 0x130u))	/* PCC PORT D address */
#define PCC_PORT_E		((uint32_t *)(PCC_BASE + 0x134u))	/* PCC PORT E address */

#define PCC_ENABLE_PORT_MASK		(1u << 30)

#define PCC_PCCn_CGC_MASK                        0x40000000u

#define PCC_PCCn_PCS_MASK                        0x7000000u
#define PCC_PCCn_PCS_SHIFT                       24u
#define PCC_PCCn_PCS(x)                          (((uint32_t)(((uint32_t)(x))<<PCC_PCCn_PCS_SHIFT))&PCC_PCCn_PCS_MASK)

#define PCC_LPIT	((uint32_t *)(PCC_BASE + 0xDCu))



/**************************PCR - Port Control Register *******************/
#define PCR_PORT_D		((uint32_t *)(0x4004C000))	/* PCC PORT D address */
#define PCR_PORT_C		((uint32_t *)(0x4004B000))	/* PCC PORT C address */

#define PCR_GPIO_MODE_MASK		(1 << 8)




/*******************************_____NVIC______*******************/
#define S32_NVIC_ISER_COUNT                      4u
#define S32_NVIC_ICER_COUNT                      4u
#define S32_NVIC_ISPR_COUNT                      4u
#define S32_NVIC_ICPR_COUNT                      4u
#define S32_NVIC_IABR_COUNT                      4u
#define S32_NVIC_IP_COUNT                        123u



typedef struct {
 volatile uint32_t ISER[S32_NVIC_ISER_COUNT];         /**< Interrupt Set Enable Register n, array offset: 0x0, array step: 0x4 */
          uint8_t RESERVED_0[112];
volatile  uint32_t ICER[S32_NVIC_ICER_COUNT];         /**< Interrupt Clear Enable Register n, array offset: 0x80, array step: 0x4 */
          uint8_t RESERVED_1[112];
volatile  uint32_t ISPR[S32_NVIC_ISPR_COUNT];         /**< Interrupt Set Pending Register n, array offset: 0x100, array step: 0x4 */
          uint8_t RESERVED_2[112];
volatile  uint32_t ICPR[S32_NVIC_ICPR_COUNT];         /**< Interrupt Clear Pending Register n, array offset: 0x180, array step: 0x4 */
          uint8_t RESERVED_3[112];
volatile  uint32_t IABR[S32_NVIC_IABR_COUNT];         /**< Interrupt Active bit Register n, array offset: 0x200, array step: 0x4 */
          uint8_t RESERVED_4[240];
volatile  uint8_t IP[S32_NVIC_IP_COUNT];              /**< Interrupt Priority Register n, array offset: 0x300, array step: 0x1 */
       	  uint8_t RESERVED_5[2693];
volatile  uint32_t STIR;                              /**< Software Trigger Interrupt Register, offset: 0xE00 */
} S32_NVIC_Type, *S32_NVIC_MemMapPtr;

#define S32_NVIC_BASE                            (0xE000E100u)

#define S32_NVIC                                 ((S32_NVIC_Type *)S32_NVIC_BASE)



/*******************************____LPIT____*******************/

typedef struct {
  volatile  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  volatile  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  volatile  uint32_t MCR;                               /**< Module Control Register, offset: 0x8 */
  volatile  uint32_t MSR;                               /**< Module Status Register, offset: 0xC */
  volatile  uint32_t MIER;                              /**< Module Interrupt Enable Register, offset: 0x10 */
  volatile  uint32_t SETTEN;                            /**< Set Timer Enable Register, offset: 0x14 */
  volatile  uint32_t CLRTEN;                            /**< Clear Timer Enable Register, offset: 0x18 */
       	    uint8_t RESERVED_0[4];
  struct {                                         /* offset: 0x20, array step: 0x10 */
    	   volatile  uint32_t TVAL;                              /**< Timer Value Register, array offset: 0x20, array step: 0x10 */
    	   volatile  uint32_t CVAL;                              /**< Current Timer Value, array offset: 0x24, array step: 0x10 */
    	   volatile  uint32_t TCTRL;                             /**< Timer Control Register, array offset: 0x28, array step: 0x10 */
    	   	   	   	 uint8_t RESERVED_0[4];
  } TMR[4];
} LPIT_Type, *LPIT_MemMapPtr;

#define LPIT0_BASE                               (0x40037000u)

#define LPIT0                                    ((LPIT_Type *)LPIT0_BASE)

#define LPIT_MSR_TIF0_MASK                       (0x1u << 0) // MSR TIMER 0
#define LPIT_MSR_TIF1_MASK                       (0x1u << 1) // MSR TIMER 1


/*******************************____SCG____*******************/
typedef struct {
  volatile  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  volatile  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
       	   uint8_t RESERVED_0[8];
  volatile  uint32_t CSR;                               /**< Clock Status Register, offset: 0x10 */
  volatile uint32_t RCCR;                              /**< Run Clock Control Register, offset: 0x14 */
  volatile uint32_t VCCR;                              /**< VLPR Clock Control Register, offset: 0x18 */
  volatile uint32_t HCCR;                              /**< HSRUN Clock Control Register, offset: 0x1C */
  volatile uint32_t CLKOUTCNFG;                        /**< SCG CLKOUT Configuration Register, offset: 0x20 */
       	   uint8_t RESERVED_1[220];
  volatile uint32_t SOSCCSR;                           /**< System OSC Control Status Register, offset: 0x100 */
  volatile uint32_t SOSCDIV;                           /**< System OSC Divide Register, offset: 0x104 */
  volatile uint32_t SOSCCFG;                           /**< System Oscillator Configuration Register, offset: 0x108 */
       	   uint8_t RESERVED_2[244];
  volatile uint32_t SIRCCSR;                           /**< Slow IRC Control Status Register, offset: 0x200 */
  volatile uint32_t SIRCDIV;                           /**< Slow IRC Divide Register, offset: 0x204 */
  volatile uint32_t SIRCCFG;                           /**< Slow IRC Configuration Register, offset: 0x208 */
       	   uint8_t RESERVED_3[244];
  volatile uint32_t FIRCCSR;                           /**< Fast IRC Control Status Register, offset: 0x300 */
  volatile uint32_t FIRCDIV;                           /**< Fast IRC Divide Register, offset: 0x304 */
  volatile uint32_t FIRCCFG;                           /**< Fast IRC Configuration Register, offset: 0x308 */
       	   uint8_t RESERVED_4[756];
  volatile uint32_t SPLLCSR;                           /**< System PLL Control Status Register, offset: 0x600 */
  volatile uint32_t SPLLDIV;                           /**< System PLL Divide Register, offset: 0x604 */
  volatile uint32_t SPLLCFG;                           /**< System PLL Configuration Register, offset: 0x608 */
} SCG_Type, *SCG_MemMapPtr;


#define SCG_BASE                                 (0x40064000u)

#define SCG                                      (( SCG_MemMapPtr)SCG_BASE)

#define SCG_CSR_SCS_MASK                         0xF000000u
#define SCG_CSR_SCS_SHIFT                        24u

#define SCG_RCCR_SCS_MASK                        0xF000000u
#define SCG_RCCR_SCS_SHIFT                       24u
#define SCG_RCCR_SCS(x)                          (((uint32_t)(((uint32_t)(x))<<SCG_RCCR_SCS_SHIFT))&SCG_RCCR_SCS_MASK)

#define SCG_SPLLCSR_LK_MASK                      0x800000u
#define SCG_SOSCCSR_LK_MASK                      0x800000u
#define SCG_SPLLCSR_SPLLVLD_MASK                 0x1000000u
#define SCG_SOSCCSR_SOSCVLD_MASK                 0x1000000u


#define SCG_RCCR_DIVCORE(x)                      (((uint32_t)(((uint32_t)(x))<<SCG_RCCR_DIVCORE_SHIFT))&SCG_RCCR_DIVCORE_MASK)
#define SCG_RCCR_DIVCORE_MASK                    0xF0000u
#define SCG_RCCR_DIVCORE_SHIFT                   16u

#define SCG_VCCR_DIVBUS(x)                       (((uint32_t)(((uint32_t)(x))<<SCG_VCCR_DIVBUS_SHIFT))&SCG_VCCR_DIVBUS_MASK)
#define SCG_VCCR_DIVBUS_MASK                     0xF0u
#define SCG_VCCR_DIVBUS_SHIFT                    4u

#define SCG_RCCR_DIVSLOW_MASK                    0xFu
#define SCG_RCCR_DIVSLOW_SHIFT                   0u
#define SCG_RCCR_DIVSLOW(x)                      (((uint32_t)(((uint32_t)(x))<<SCG_RCCR_DIVSLOW_SHIFT))&SCG_RCCR_DIVSLOW_MASK)

#define SCG_RCCR_DIVBUS(x)                       (((uint32_t)(((uint32_t)(x))<<SCG_RCCR_DIVBUS_SHIFT))&SCG_RCCR_DIVBUS_MASK)
#define SCG_RCCR_DIVBUS_MASK                     0xF0u
#define SCG_RCCR_DIVBUS_SHIFT                    4u
#endif /* EMBEDDED101_H_ */
