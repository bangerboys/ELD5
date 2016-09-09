#include <avr/io.h>
#include <avr/interrupt.h>
int main()
{
	PRR |= (unsigned char)((1 << PRSPI)|(1 << PRTIM2)|(1 << PRTIM0)|(1 << PRADC)|(1 << PRTWI)); // Setting all the other registers off
	cli();			//Reset Watchdog Timer
	MCUSR = 0;
	DDRB |= 1 << 5;	//Setting fifth pin as output
	WDTCSR |= (1<<WDCE) | (1<<WDE);	//Start timed sequence
	WDTCSR = (0 << WDP3 | 1 <<  WDP2 | 0 << WDP1 | 1 << WDP0 | 1 << WDIE);	// Setting registers for 0.5sec and set watchdog timer in interrupt mode
	WDTCSR |= 0 << WDE;
	sei(); 			//Enable global interrupt
	while(1);
}
ISR(WDT_vect) 
{
	PORTB ^= 1<<5;	// Toggling the LED
}
