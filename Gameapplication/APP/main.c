#include "main.h"
#include <stdbool.h>  // standard boolean library

int posXP = 0;
int posXE = 0;

int main ()
{
	int timeEnemy = 0;
	int timeBullet = 0;
	int posx = 0;
	int i = 0;
	bool bulletB = false;
	
	LCD_4_bit_init();  // intializing the lcd 4_bit mode

	// arrays to generate custom characters on lcd

	u8 man1[] = {0x04, 0x0A, 0x04, 0x1F, 0x14, 0x0E, 0x11, 0x00};
	u8 man1Die[] = {0x00, 0x00, 0x18, 0x00, 0x00, 0x0E, 0x1F, 0x1F};
	u8 man2[] = {0x04, 0x0A, 0x04, 0x1F, 0x05, 0x0E, 0x11, 0x11};
	u8 man2Die[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x1F, 0x1F};
	u8 bullet[] = {0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00};

	// generating custom character using function lcd_createcustomcharater()
	LCD_createCustomCharacter(man1, 0);
	LCD_createCustomCharacter(man1Die, 1);
	LCD_createCustomCharacter(man2, 2);
	LCD_createCustomCharacter(man2Die, 3);
	LCD_createCustomCharacter(bullet, 4);
	
	// man1 will be in position 0 & man1Die character will be in position 15
	LCD_4_bit_GoToPos(0,0);
	LCD_4_bit_sendChar(0);
	LCD_4_bit_GoToPos(0,15);
	LCD_4_bit_sendChar(2); 
	

	//
	BTN_init(BTN_1);
	BTN_init(BTN_2);
	BTN_init(BTN_3);
	BTN_init(BTN_4);
	while(1){
		int x0 = BTN_read(BTN_1);
		int x1 = BTN_read(BTN_2);
		int y = BTN_read(BTN_3);
		int start = BTN_read(BTN_4);
		if (x0 == 0)
		{
			LCD_4_bit_GoToPos(1,0);
			LCD_4_bit_sendChar(' ');
			LCD_4_bit_GoToPos(0,0);
			posXP = 0;
			LCD_4_bit_sendChar(0);
		}
		else if (x1 == 0)
		{
			LCD_4_bit_GoToPos(0,0);
			LCD_4_bit_sendChar(' ');
			LCD_4_bit_GoToPos(1,0);
			posXP = 1;
			LCD_4_bit_sendChar(0);
		}
		if (y == 0)
		{
			//shoot(posXP);
			posx = posXP;
			bulletB = true;
		}
		
		if (start == 0)
		{
			posXE = 0;
			posXP = 0;
			LCD_4_bit_GoToPos(posXP,0);
			LCD_4_bit_GoToPos(posXE,15);
			LCD_4_bit_sendChar(0);
			LCD_4_bit_sendChar(2);
			bulletB = false;
			timeBullet = 0;
			timeEnemy = 0;
			LCD_4_bit_GoToPos(0,6);
			LCD_4_bit_sendString("    ");
		}
		
		if (bulletB == true)
		{
			if(i < 14 && timeBullet == 1500){
				i++;
				LCD_4_bit_GoToPos(posx,i);
				LCD_4_bit_sendChar(4);
				if(i != 1 ) {
					LCD_4_bit_GoToPos(posx,i-1);
					LCD_4_bit_sendChar(' ');
				}
			}else if(i == 14){
				i++;
				LCD_4_bit_GoToPos(posx,i-1);
				LCD_4_bit_sendChar(' ');
				if(posx == posXE){
					 LCD_4_bit_sendChar(3);
					 LCD_4_bit_GoToPos(0,6);
					 LCD_4_bit_sendString(">Win");
					 posXE = 2;
				}
				i = 0;
				bulletB = false;
			}else{
				timeBullet++;
			}
		}
		
		if(posXE == 0 && timeEnemy == 1000){
			LCD_4_bit_GoToPos(posXE,15);
			LCD_4_bit_sendChar(' ');
			posXE = 1;
			LCD_4_bit_GoToPos(posXE,15);
			LCD_4_bit_sendChar(2);
			timeEnemy = 0;
		}else if(posXE == 1 && timeEnemy == 1000){
			LCD_4_bit_GoToPos(posXE,15);
			LCD_4_bit_sendChar(' ');
			posXE = 0;
			LCD_4_bit_GoToPos(posXE,15);
			LCD_4_bit_sendChar(2);
			timeEnemy = 0;
		}else{
			timeEnemy ++;
		}
	}

	return 0;
}

void shoot(int posx){
	if(posx == posXE) LCD_4_bit_sendChar(3);
}

