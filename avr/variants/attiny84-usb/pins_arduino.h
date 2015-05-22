/*
  pins_arduino.h - Pin definition functions for ATMEGA644
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis
  2012 Michael Egger

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

  $Id: wiring.h 249 2007-02-03 16:52:51Z mellis $
*/


// ATMEL ATTINY84 / COCOMAKE7 USB
//
//                   __  __
//            VCC  1|° \/  |14  GND
//   10  XTAL PB0  2|      |13  PA0  A0  0
//    9  XTAL PB1  3|      |12  PA1  A1  1
//       RST  PB3  4|      |11  PA2  A2  2
//   ~8       PB2  5|      |10  PA3  A3  3
//   ~7  USB- PA7  6|      |9   PA4  A4  4
//   ~6  USB+ PA6  7|      |8   PA5  A5  5~
//                   ------

#ifndef Pins_Arduino_h
#define Pins_Arduino_h


#include <avr/pgmspace.h>

#define NUM_DIGITAL_PINS            11
#define NUM_ANALOG_INPUTS           8
#define analogInputToDigitalPin(p)  (p)
#define digitalPinHasPWM(p)         ((p==5) || (p==8))  // (p==6)) || (p==7)

static const uint8_t SS   = 7; // could also be 2
static const uint8_t MOSI = 6;
static const uint8_t MISO = 5;
static const uint8_t SCK  = 4;

static const uint8_t SDA = 6;
static const uint8_t SCL = 4;
static const uint8_t LED_BUILTIN = 8;

static const uint8_t A0 = 0;
static const uint8_t A1 = 1;
static const uint8_t A2 = 2;
static const uint8_t A3 = 3;
static const uint8_t A4 = 4;
static const uint8_t A5 = 5;
static const uint8_t A6 = 6;
static const uint8_t A7 = 7;


#ifdef ARDUINO_MAIN


#define PB 1


const uint16_t PROGMEM port_to_mode_PGM[] = {
	NOT_A_PORT,
    (uint8_t) &DDRA,
	(uint8_t) &DDRB,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
	NOT_A_PORT,
    (uint8_t) &PORTA,
	(uint8_t) &PORTB,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PORT,
    (uint8_t) &PINA,
	(uint8_t) &PINB,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	// PORTLIST
	// -------------------------------------------
	PA, // 0
    PA,
    PA,
    PA,
    PA,
    PA,
    PA,
    PA,
    PB, // 8
    PB,
    PB,
};

//ok
const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	// PIN IN PORT
	// -------------------------------------------
	_BV(0), // port A
    _BV(1),
    _BV(2),
    _BV(3),
    _BV(4),
    _BV(5),
    _BV(6),
    _BV(7),
    _BV(2), // port B
    _BV(1),
    _BV(0),
};

//ok
const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	// TIMERS
	// -------------------------------------------
	NOT_ON_TIMER,
    NOT_ON_TIMER,
    NOT_ON_TIMER,
    NOT_ON_TIMER,
    NOT_ON_TIMER,
    TIMER1B, // OC1B
    TIMER1A, // OC1A
    TIMER0B, // OC0B
    TIMER0A, // OC0A
    NOT_ON_TIMER,
    NOT_ON_TIMER,
};

#endif

#endif