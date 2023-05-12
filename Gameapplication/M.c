
#include "ECUAL/BTN/button.h"
#include "ECUAL/LED/LED.h"
#include "ECUAL/MTR/Motor.h"
#define F_CPU 1000000UL
#include <util/delay.h>



int m(void)
{
    /* Replace with your application code */
	DIO_init(PORT_A,0,HIGH); //RED
	DIO_init(PORT_A,1,HIGH); //YELLOW
	DIO_init(PORT_A,2,HIGH); //GREEN
	DIO_init(PORT_B,0,HIGH); //MOTOR IN1
	DIO_init(PORT_B,1,HIGH); //MOTOR IN2
	BTN_init(BTN_1);
	MTR_init(1);
	LED_init(LED_RED);
    while (1) 
    {
		int x= BTN_read(BTN_1);
		if (x==1){LED_toggle(LED_RED);
		MTR_ON_CW(MTR1);}
		/*DIO_write(PORT_A,0,HIGH); //RED
		DIO_write(PORT_A,1,LOW); //YELLOW
		DIO_write(PORT_B,0,HIGH); 
		DIO_write(PORT_B,1,LOW);
		_delay_ms(5000);
		DIO_write(PORT_B,0,LOW);
		_delay_ms(15000);
		DIO_write(PORT_A,1,HIGH); //YELLOW
		DIO_write(PORT_A,0,LOW); //RED
		_delay_ms(5000);
		DIO_write(PORT_A,2,HIGH); //GREEN
		DIO_write(PORT_A,1,LOW); //YELLOW
		DIO_write(PORT_B,0,LOW);
		DIO_write(PORT_B,1,HIGH);
		_delay_ms(5000);
		DIO_write(PORT_B,1,LOW);
		_delay_ms(15000);
		DIO_write(PORT_A,1,HIGH); //YELLOW
		DIO_write(PORT_A,2,LOW); //GREEN
		_delay_ms(5000);
		*/
    }
}

