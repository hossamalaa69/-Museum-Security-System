/*
 * GccApplication5.c
 *
 * Created: 2019-02-25 2:31:32 PM
 * Author : user
 */ 
//el code el asly
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL
int main(void)
{
  DDRA=0xFE;                               //make all pins output except pin0 is input
  PORTA|=(1<<0);                          //turn on internal pull_up resistor for pin0 >>"input coming form signal"
	while (1) 
    {
		if(!(PINA&(1<<0)))                         //checking sensor input in pin0
		{
		PORTA|=(1<<2);                            //turn on Buzzer in pin2
		for (unsigned char x =0 ; x<100;x++)      //rotate 90° (closing the gate)
		   {
		   PORTA|=(1<<1);                         //pin1 for motor
		   _delay_ms(1.5);
		   PORTA&=~(1<<1);
		   _delay_ms(18.5);
		   }
	
		_delay_ms(3000);                          //delay 3 sec. until we catch the f*ckin. thief
		
		for(unsigned char x =0 ; x<100;x++)       //return back to 0°(opening gate)
		    {
		     PORTA|=(1<<1);
		     _delay_ms(1);
		     PORTA&=~(1<<1);
		     _delay_ms(19);	
		    }	
		PORTA=0;                                 //turn off Buzzer & motor
	    }
	}
}

