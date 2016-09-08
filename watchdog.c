#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
int main()
{
	PRR |= (unsigned char)((1<<PRADC)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTIM2)|(1<<PRSPI)|(1<<PRTWI)|(0<<PRUSART0));
	MCUSR = 0;
	DDRB |= 1 << 5;
	WDTCSR = 1 << WDCE | 1 <<  WDP2 | 1 << WDP0;
	sei();
	while(1)
	{
		PORTB ^= 1 << 5; 
		_delay_ms(500);
	}
}
