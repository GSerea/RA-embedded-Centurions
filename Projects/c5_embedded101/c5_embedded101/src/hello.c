/*
 * hello.c              Copyright NXP 2016
 * Description:  Simple program to exercise GPIO
 * 2015 Mar 31 S Mihalik/ O Romero - initial version
 *
 */

/*	Include headers */
#include "features.h"	 /* include features flags */
#include "embedded101.h" /* include peripheral declarations S32K144 */
#include "functions.h"   /* include functions */

void LPIT0_Ch0_IRQHandler (void);
void NVIC_init_IRQs (void);
void LPIT0_init (void);
void PORT_init (void);
void LPIT1_init (void);


int lpit0_ch0_flag_counter = 0;
int lpit0_ch1_flag_counter = 0;

int main(void) {

  int counter = 0;
  WDOG_disable();             /* Disable Watchdog in case it is not done in startup code */

  /* When you want to enable an input/output port
   * 1) enable clock  ---> PCC
   * 2) pin direction ---> PDDR
   * 3) Port function ---> PCR
   * 4) turn on LED   ---> PSOR/PCOR
   */

  // 1) Port clock control ---> enable
  *(PCC_PORT_C) |= PCC_ENABLE_PORT_MASK;
  *(PCC_PORT_D) |= PCC_ENABLE_PORT_MASK;

  // 2) Pin Direction
  (((GPIO_map_tp) PORT_C)->PDDR) &= ~((1<<12U)|(1<<13));
  (((GPIO_map_tp) PORT_D)->PDDR) |= LED_RED | LED_BLUE | LED_GREEN;

  // 3) Port function
  PCR_PORT_C[12U] |= PCR_GPIO_MODE_MASK;
  PCR_PORT_C[13U] |= PCR_GPIO_MODE_MASK;

  PCR_PORT_D[PTD15] |= PCR_GPIO_MODE_MASK;
  PCR_PORT_D[PTD0] |= PCR_GPIO_MODE_MASK;
  PCR_PORT_D[PTD16] |= PCR_GPIO_MODE_MASK;


  // 4) Turn on LED
  (((GPIO_map_tp) PORT_D)->PCOR) |= LED_RED;
  (((GPIO_map_tp) PORT_D)->PDDR) |= LED_BLUE;
  (((GPIO_map_tp) PORT_D)->PDDR) |= LED_GREEN;


  //5)Turn off LED
  ((GPIO_map_tp) PORT_D)->PSOR |= (LED_RED);
  ((GPIO_map_tp) PORT_D)->PSOR |=(LED_BLUE);
  ((GPIO_map_tp) PORT_D)->PSOR |=(LED_GREEN);

  /*When you want to enable an input port
   * 1)enable clock  --->PCC
   * 2)pin direction --->PDDR
   * 3)port function --->PCR
   */

  /*_____________TIMER________________*/
  //PORT_init();
   SOSC_init_8MHz();
   SPLL_init_160MHz();
   NormalRUNmode_80MHz();
   NVIC_init_IRQs();
   LPIT0_init();
   LPIT1_init();

   while (1)
   {
	   counter++;
   }

   return 0;
}



void LPIT0_Ch0_IRQHandler (void) {
  LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
         /* Perform read-after-write to ensure flag clears before ISR exit */
  lpit0_ch0_flag_counter++;         /* Increment LPIT0 timeout counter */
  ((GPIO_map_tp) PORT_D)->PTOR |= 1<<16;                /* Toggle output on port D0 (blue LED) */
}


void LPIT0_Ch1_IRQHandler (void) {
  LPIT0->MSR |= LPIT_MSR_TIF1_MASK; /* Clear LPIT0 timer flag 0 */
         /* Perform read-after-write to ensure flag clears before ISR exit */
  lpit0_ch1_flag_counter++;         /* Increment LPIT0 timeout counter */
  ((GPIO_map_tp) PORT_D)->PTOR |= 1<<0;                /* Toggle output on port D0 (blue LED) */
}

void LPIT1_init (void) {
  *(PCC_LPIT) |= PCC_PCCn_PCS(6);    /* Clock Src = 6 (SPLL2_DIV2_CLK)*/
  *(PCC_LPIT) |= PCC_PCCn_CGC_MASK; /* Enable clk to LPIT0 regs */
  LPIT0->MCR = 0x00000001;    /* DBG_EN-0: Timer chans stop in Debug mode */
                              /* DOZE_EN=0: Timer chans are stopped in DOZE mode */
                              /* SW_RST=0: SW reset does not reset timer chans, regs */
                           /* M_CEN=1: enable module clk (allows writing other LPIT0 regs)*/


  LPIT0->MIER |= 0x00000002;   /* TIE0=1: Timer Interrupt Enabled fot Chan 0 */
  LPIT0->TMR[1].TVAL = 20000000;    /* Chan 0 Timeout period: 40M clocks */
  LPIT0->TMR[1].TCTRL = 0x00000001; /* T_EN=1: Timer channel is enabled */
                              /* CHAIN=0: channel chaining is disabled */
                              /* MODE=0: 32 periodic counter mode */
                              /* TSOT=0: Timer decrements immediately based on restart */
                              /* TSOI=0: Timer does not stop after timeout */
                              /* TROT=0 Timer will not reload on trigger */
                              /* TRG_SRC=0: External trigger soruce */
                              /* TRG_SEL=0: Timer chan 0 trigger source is selected*/
}

void LPIT0_init (void) {
  *(PCC_LPIT) |= PCC_PCCn_PCS(6);    /* Clock Src = 6 (SPLL2_DIV2_CLK)*/
  *(PCC_LPIT) |= PCC_PCCn_CGC_MASK; /* Enable clk to LPIT0 regs */
  LPIT0->MCR = 0x00000001;    /* DBG_EN-0: Timer chans stop in Debug mode */
                              /* DOZE_EN=0: Timer chans are stopped in DOZE mode */
                              /* SW_RST=0: SW reset does not reset timer chans, regs */
                           /* M_CEN=1: enable module clk (allows writing other LPIT0 regs)*/
  LPIT0->MIER |= 0x00000001;   /* TIE0=1: Timer Interrupt Enabled fot Chan 0 */
  LPIT0->TMR[0].TVAL = 40000000;    /* Chan 0 Timeout period: 40M clocks */
  LPIT0->TMR[0].TCTRL = 0x00000001; /* T_EN=1: Timer channel is enabled */


 // LPIT0->MIER = 0x00000001;   /* TIE0=1: Timer Interrupt Enabled fot Chan 0 */
  //LPIT0->TMR[1].TVAL = 20000000;    /* Chan 0 Timeout period: 40M clocks */
  //LPIT0->TMR[1].TCTRL = 0x00000001; /* T_EN=1: Timer channel is enabled */
                              /* CHAIN=0: channel chaining is disabled */
                              /* MODE=0: 32 periodic counter mode */
                              /* TSOT=0: Timer decrements immediately based on restart */
                              /* TSOI=0: Timer does not stop after timeout */
                              /* TROT=0 Timer will not reload on trigger */
                              /* TRG_SRC=0: External trigger soruce */
                              /* TRG_SEL=0: Timer chan 0 trigger source is selected*/
}


void NVIC_init_IRQs (void) {
  S32_NVIC->ICPR[49 / 32] |= 1 << (49 % 32);  /* IRQ48-LPIT0 ch1: clr any pending IRQ*/
  S32_NVIC->ISER[49 / 32] |= 1 << (49 % 32);  /* IRQ48-LPIT0 ch1: enable IRQ */
  S32_NVIC->IP[49] = 0xB0;             /* IRQ48-LPIT0 ch1: priority 10 of 0-15*/

  S32_NVIC->ICPR[48 / 32] |= 1 << (48 % 32);  /* IRQ48-LPIT0 ch0: clr any pending IRQ*/
  S32_NVIC->ISER[48 / 32] |= 1 << (48 % 32);  /* IRQ48-LPIT0 ch0: enable IRQ */
  S32_NVIC->IP[48] = 0xA0;             /* IRQ48-LPIT0 ch0: priority 10 of 0-15*/
}
void PORT_init (void) {
	*(PCC_PORT_D) |= PCC_ENABLE_PORT_MASK; /* Enable clock for PORT D */
	(((GPIO_map_tp) PORT_D)->PDDR) |= LED_RED | LED_BLUE | LED_GREEN;          /* Port D0:  Data Direction= output */
	PCR_PORT_D[PTD0] |= PCR_GPIO_MODE_MASK;  /* Port D0:  MUX = ALT1, GPIO (to blue LED on EVB) */
}











