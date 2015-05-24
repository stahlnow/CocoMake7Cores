# CocoMake7
A jugaad ultra low-cost clone to the Makey Makey, but based on QTouchADC sensing, local manufacturing and coconuts.
It's based on the ATMEL ATtiny84 and arduino IDE compatible.

There are three different kind of CocoMake7 boards: CocoMake7, KeysCocoMake7 and MIDICocoMake7. The MIDI core is based on the babygnusbuino by a.n.y.m.a.

## Installation

* Download the zip file and unpack it into the hardware folder of your arduino sketchbook folder. The resulting folder structure should be something like ~/your-sketchbook-folder/hardware/MIDICocoMake7Cores-master

* Install the [CocoMake7](https://github.com/CocoMake7/CocoMake7) library.

* For the MIDICocoMake7 you need to install the [MIDICocoMake7](https://github.com/CocoMake7/MIDICocoMake7) library.


## Programming

CocoMake7 boards are programmed via ISP (In-System-Programming).

If you don't have an ISP programmer, you can use an arduino as ISP.

![arduino_as_isp](/../documentation/documentation/Programming-attiny44-attiny84-with-arduino-uno.png?raw=true "arduino_as_isp")

## Pinout

// ATMEL ATTINY84 / COCOMAKE7 USB

//

//                   __  __

//            VCC  1|° \/  |14  GND

//   10  XTAL PB0  2|      |13  PA0  A0  0

//    9  XTAL PB1  3|      |12  PA1  A1  1

//       RST  PB3  4|      |11  PA2  A2  2

//   ~8       PB2  5|      |10  PA3  A3  3

//   ~7  USB+ PA7  6|      |9   PA4  A4  4

//   ~6  USB- PA6  7|      |8   PA5  A5  5~

//                   ------

## Example sketch


## License



## Contributors

* [dusjagr](https://github.com/dusjagr)
* [stahl](https://github.com/stahlnow)

## Credits

* [mirdej](https://github.com/mirdej)
