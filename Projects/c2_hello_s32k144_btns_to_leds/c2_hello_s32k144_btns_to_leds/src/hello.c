/*
 * hello.c              Copyright NXP 2016
 * Description:  Simple program to exercise GPIO
 * 2015 Mar 31 S Mihalik/ O Romero - initial version
 *
 */

#include "S32K144.h"    /* include peripheral declarations S32K144 */

#define PTD0    0         /* Port PTD0, bit 0: FRDM EVB output to blue LED */
#define PTD15  15         /* Port PTD15, bit 15: FRDM EVB output to red LED */
#define PTD16  16         /* Port PTD16, bit 16: FRDM EVB output to green LED */

#define PTC12 12        /* Port PTC12, bit 12: FRDM EVB input from BTN0 [SW2] */
#define PTC13 13        /* Port PTC12, bit 13: FRDM EVB input from BTN1 [SW3] */

#define LED_BLUE    PTD0
#define LED_RED     PTD15
#define LED_GREEN   PTD16

#define BTN_0       PTC12
#define BTN_1       PTC13

void WDOG_disable (void){
  WDOG->CNT=0xD928C520;    /*Unlock watchdog*/
  WDOG->TOVAL=0x0000FFFF;  /*Maximum timeout value*/
  WDOG->CS = 0x00002100;   /*Disable watchdog*/
}

int main(void) {
  int counter = 0;
  WDOG_disable();             /* Disable Watchdog in case it is not done in startup code */
                              /* Enable clocks to peripherals (PORT modules) */
  PCC-> PCCn[PCC_PORTC_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock to PORT C */
  PCC-> PCCn[PCC_PORTD_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock to PORT D */
                               /* Configure port C12 as GPIO input (BTN 0 [SW2] on EVB) */
  PTC->PDDR &= ~(1<<BTN_0);    /* Port C12: Data Direction= input (default) */
  PORTC->PCR[BTN_0] = 0x00000110; /* Port C12: MUX = GPIO, input filter enabled */
  PTC->PDDR &= ~(1<<BTN_1);    /* Port C12: Data Direction= input (default) */
  PORTC->PCR[BTN_1] = 0x00000110; /* Port C12: MUX = GPIO, input filter enabled */
                               /* Configure port D0 as GPIO output (LED on EVB) */
  PTD->PDDR |= 1<<LED_GREEN;         /* Port D0: Data Direction= output */
  PORTD->PCR[LED_GREEN] = 0x00000100;  /* Port D0: MUX = GPIO */
  PTD->PDDR |= 1<<LED_RED;           /* Port D0: Data Direction= output */
  PORTD->PCR[LED_RED] = 0x00000100;  /* Port D0: MUX = GPIO */
  PTD->PDDR |= 1<<LED_BLUE;           /* Port D0: Data Direction= output */
  PORTD->PCR[LED_BLUE] = 0x00000100;  /* Port D0: MUX = GPIO */

  for(;;) {
	if ((PTC->PDIR & (1<<BTN_0)) && (PTC->PDIR & (1<<BTN_1))) {   /* If Pad Data Input = 1 (BTN0 [SW2] pushed) */
	  PTD-> PSOR |= (1<<LED_GREEN | 1<<LED_RED | 1<<LED_BLUE);        /* Set Output on port D0 (LED off) */
	  PTD-> PCOR |= 1<<LED_RED;        /* Clear Output on port D0 (LED on) */
	}
	else if (PTC->PDIR & (1<<BTN_0)) {   /* If Pad Data Input = 1 (BTN0 [SW2] pushed) */
	  PTD-> PSOR |= (1<<LED_GREEN | 1<<LED_RED | 1<<LED_BLUE);        /* Set Output on port D0 (LED off) */
      PTD-> PCOR |= 1<<LED_GREEN;        /* Clear Output on port D0 (LED on) */
    }
    else if (PTC->PDIR & (1<<BTN_1)) {   /* If Pad Data Input = 1 (BTN0 [SW2] pushed) */
    	PTD-> PSOR |= (1<<LED_GREEN | 1<<LED_RED | 1<<LED_BLUE);        /* Set Output on port D0 (LED off) */
        PTD-> PCOR |= 1<<LED_BLUE;        /* Clear Output on port D0 (LED on) */
    }
    else {                          /* If BTN0 was not pushed */
      PTD-> PSOR |= (1<<LED_GREEN | 1<<LED_RED | 1<<LED_BLUE);        /* Set Output on port D0 (LED off) */
    }
    counter++;
  }
}
