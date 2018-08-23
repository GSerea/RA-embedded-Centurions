/*
 * functions.c
 *
 *  Created on: 6 Aug 2018
 *      Author: User
 */

#include "embedded101.h"


void WDOG_disable (void){
  ((WDOG_Type *)(0x40052000u))->CNT=0xD928C520;    /*Unlock watchdog*/
  ((WDOG_Type *)(0x40052000u))->TOVAL=0x0000FFFF;  /*Maximum timeout value*/
  ((WDOG_Type *)(0x40052000u))->CS = 0x00002100;   /*Disable watchdog*/
}
