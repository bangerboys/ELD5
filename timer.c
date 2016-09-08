#include <avr/io.h>
#include <avr/interrupt.h>
int main()
{
	PRR |= (unsigned char)((1<<PRADC)|(1<<PRTIM0)|(1<<PRTIM2)|(1<<PRSPI)|(1<<PRTWI)|(0<<PRUSART0));
	DDRB |= 1 << 5;
	TCCR1B = 1 << WGM12;
	OCR1A = 7812.5;
	TIMSK1 = 1 << OCIE1A;
	sei();
	TCCR1B |= (1 << CS12) | (1 << CS10);
	PORTB ^= 1 << 5; 
	while(1)
	{

	}
}