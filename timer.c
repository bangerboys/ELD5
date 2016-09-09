#include <avr/io.h>
#include <avr/interrupt.h>
int main()
{
	PRR |= (unsigned char)((1 << PRSPI)|(1 << PRTIM2)|(1 << PRTIM0)|(1 << PRADC)|(1 << PRTWI));	 // Setting all the other registers off
	DDRB |= 1 << 5;	//Setting fifth pin as output
	TCCR1B = 1 << WGM12;	
	OCR1A = 7812.5; // Setting timer ticks
	TIMSK1 = 1 << OCIE1A;
	sei();	//Enable global interrupt
	TCCR1B |= (1 << CS12) | (1 << CS10);
	PORTB ^= 1 << 5; //toggle the led
	while(1)
	{

	}
}