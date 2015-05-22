/*
  wiring_analog.c - analog input and output
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2005-2006 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  Modified 28 September 2010 by Mark Sproul

  $Id: wiring.c 248 2007-02-03 15:36:30Z mellis $
*/
#include "Arduino.h"
#include "wiring_private.h"
#include "pins_arduino.h"


uint8_t analog_reference = DEFAULT;
unsigned char ad_initialized = 0;

void analogReference(uint8_t mode)
{
	// can't actually set the register here because the default setting
	// will connect AVCC and the AREF pin, which would cause a short if
	// there's something connected to AREF.
	analog_reference = mode;
}




// ------------------------------------------------------------------------------
// --------------------- AnalogRead
// ------------------------------------------------------------------------------

int analogRead(uint8_t pin)
{
	// we don't allow analog read on USB pins
	if (pin == 9 || pin == 10) { return -1; }

	DDRA &= ~(1 << pin);                                            // set pin to input
 	ADMUX = (ADMUX & ~ADC_MUX_MASK) | (pin & ADC_MUX_MASK);		// set channel

	// start the conversion
	ADCSRA |= (1 << ADIF);			// clear hardware "conversion complete" flag
	ADCSRA |= (1 << ADSC);			// start conversion

	// ADSC is cleared when the conversion finishes
	while (bit_is_set(ADCSRA, ADSC)){
		doPeriodical();
	};

	// we have to read ADCL first; doing so locks both ADCL
	// and ADCH until ADCH is read.  reading ADCL second would
	// cause the results of each conversion to be discarded,
	// as ADCL and ADCH would be locked when it completed.
	return (ADCL | ADCH << 8);
}

// Right now, PWM output only works on the pins with
// hardware support.  These are defined in the appropriate
// pins_*.c file.  For the rest of the pins, we default
// to digital output.
void analogWrite(uint8_t pin, int val)
{
	// We need to make sure the PWM output is enabled for those pins
	// that support it, as we turn it off when digitally reading or
	// writing with them.  Also, make sure the pin is in output mode
	// for consistenty with Wiring, which doesn't require a pinMode
	// call for the analog output pins.
	pinMode(pin, OUTPUT);
	if (val == 0)
	{
		digitalWrite(pin, LOW);
	}
	else if (val == 255)
	{
		digitalWrite(pin, HIGH);
	}
	else
	{
		switch(digitalPinToTimer(pin))
		{
			// XXX fix needed for atmega8
			#if defined(TCCR0) && defined(COM00) && !defined(__AVR_ATmega8__)
			case TIMER0A:
				// connect pwm to pin on timer 0
				sbi(TCCR0, COM00);
				OCR0 = val; // set pwm duty
				break;
			#endif

			#if defined(TCCR0A) && defined(COM0A1)
			case TIMER0A:
				// connect pwm to pin on timer 0, channel A
				sbi(TCCR0A, COM0A1);
				OCR0A = val; // set pwm duty
				break;
			#endif

			#if defined(TCCR0A) && defined(COM0B1)
			case TIMER0B:
				// connect pwm to pin on timer 0, channel B
				sbi(TCCR0A, COM0B1);
				OCR0B = val; // set pwm duty
				break;
			#endif

            /*
			case TIMER1B:
				// connect pwm to pin on timer 1, channel B
				sbi(GTCCR, COM1B1);
				sbi(GTCCR, PWM1B);
				OCR1B = val; // set pwm duty
				break;
            */
            #if defined(TCCR1A) && defined(COM1A1)
            case TIMER1A:
                // connect pwm to pin on timer 1, channel A
                sbi(TCCR1A, COM1A1);
                OCR1A = val; // set pwm duty
                break;
            #endif

            #if defined(TCCR1A) && defined(COM1B1)
            case TIMER1B:
                // connect pwm to pin on timer 1, channel B
                sbi(TCCR1A, COM1B1);
                OCR1B = val; // set pwm duty
                break;
            #endif

			case NOT_ON_TIMER:
			default:
				if (val < 128) {
					digitalWrite(pin, LOW);
				} else {
					digitalWrite(pin, HIGH);
				}
		}
	}
}

