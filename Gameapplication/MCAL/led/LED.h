/*
 * LED.h
 *
 * Created: 21-Nov-22 10:56:21 PM
 *  Author: Mahmoud
 */ 


#ifndef LED_H_
#define LED_H_

// Driver Inclusions
#include "../REG.h"
#include "../../Library/STD.h"
#include "../../Library/BIT_MATH.h"

// Driver Macros

#define LED_RED_PORT		PORT_A
#define LED_YLW_PORT		PORT_A
#define LED_GRN_PORT		PORT_A

#define LED_RED_PIN			PIN0
#define LED_YLW_PIN			PIN2
#define LED_GRN_PIN			PIN3


#define LED_RED				1
#define LED_YLW				2
#define LED_GRN				3


#define IN		 0
#define OUT	 	 1

#define LOW		 0
#define HIGH 	 1


// Driver Functions Prototypes

void LED_init    (u8 LedNum);
void LED_on      (u8 LedNum);
void LED_off     (u8 LedNum);
void LED_toggle  (u8 LedNum);



#endif /* LED_H_ */
