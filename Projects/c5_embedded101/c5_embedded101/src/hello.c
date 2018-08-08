/*
 * hello.c              Copyright NXP 2016
 * Description:  Simple program to exercise GPIO
 * 2015 Mar 31 S Mihalik/ O Romero - initial version
 *
 */


#include "features.h"	 /* include features flags */

#include "embedded101.h" /* include peripheral declarations S32K144 */

#include "functions.h"   /* include functions */


int main(void) {
  int counter = 0;
  WDOG_disable();             /* Disable Watchdog in case it is not done in startup code */


  GPIO_map_tp PORTC = (GPIO_map_tp) PORT_C;

  PORTC->PCC = PCC_PORT_C;

  for(;;) {

    counter++;
  }

























}
