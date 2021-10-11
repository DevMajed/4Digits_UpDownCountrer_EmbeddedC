
#include <avr/io.h>
 
#include <avr/interrupt.h>
#define F_CPU 16000000
#include <util/delay.h>
void DisplayDigit(uint8_t what, uint8_t where);

uint8_t segtab[]= {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71 };
volatile uint16_t	val = 0;
uint8_t strobereg = 0;

int main(void)
{
	uint8_t	switches;
	DDRB |= 0x0F; PORTB = 0;  // lower 4 bits PORTB output and set to 0;
	DDRD = 0xFF; PORTD = 00; // all bits PORTD output and set to 0

	// timer 0 CTC mode 4.167 ms, normal, /1024, count of 65 yields 4.167 mS
	TCCR0A = (0b00<<COM0A0)|(0b00<<COM0B0)|(0b10<<WGM00);
	TCCR0B = (0b0<<WGM02)|(0b101<<CS00);
	OCR0A = 65;
	TIMSK0 = 1<<OCIE0A;
	sei();		// enable interrupts

	while(1)	 
	{
		 
		
		
			if((PINE&0B00000001)==0X00)
			{
				val++;
				_delay_ms(500);
			}
			else if ((PINE&0B00000100)==0X00)
			{
				val--;
				_delay_ms(500);
			}
			
				else if ((PINE&0B00000010)==0X00)
				{
					 val=0;
					_delay_ms(500)
				;}
		
	}
	
}

ISR (TIMER0_COMPA_vect)
{
	uint8_t d;
	switch (strobereg)
	{
		case 0: d=val%10; break;
		case 1: d=val/10%10; break;
		case 2: d=val/100%10; break;
		case 3: d=val/1000%10; break;
		default: d=15; break;
	}
	DisplayDigit(d,strobereg);
	strobereg = (strobereg+1)&3;
}

void DisplayDigit(uint8_t what, uint8_t where)
{
	PORTB = 0;
	PORTD = segtab[what];
	PORTB = 1<<(3-where);
}
