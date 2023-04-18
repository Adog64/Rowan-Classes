/* 
	Editor: https://www.visualmicro.com/
			This file is for intellisense purpose only.
			Visual micro (and the arduino ide) ignore this code during compilation. This code is automatically maintained by visualmicro, manual changes to this file will be overwritten
			The contents of the _vm sub folder can be deleted prior to publishing a project
			All non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
			Note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Arduino Nano RP2040 Connect, Platform=mbed_nano, Package=arduino
*/

#if defined(_VMICRO_INTELLISENSE)

#ifndef _VSARDUINO_H_
#define _VSARDUINO_H_
#define _VMDEBUG 1
#define ARDUINO_ARCH_RP2040
#define ARDUINO 108015
#define ARDUINO_NANO_RP2040_CONNECT
#define ARDUINO_ARCH_MBED_NANO
#define ARDUINO_ARCH_MBED
#define ARDUINO_LIBRARY_DISCOVERY_PHASE 0
#define __cplusplus 201103L
#define __GNUC__ 7
#define _Pragma(x)
#define __ARMCC_VERSION 6010050

#define __PTRDIFF_TYPE__ int
#define __ARM__
//#define __arm__ 1
#define always_inline
#define __inline__
#define __asm__(x)
#define __attribute__(x)
#define __extension__
#define __ATTR_PURE__
#define __ATTR_CONST__
#define __inline__
#define __volatile__
#define _Pragma(x)
#define __ASM
#define __INLINE

#define __INT32_TYPE__ long int
#define __INTMAX_MAX__ 0x7fffffffffffffffLL
#define STM32H747xx 1
#define CORE_CM7
#define __INTPTR_TYPE__ int
#define __SIZE_TYPE__ unsigned int


#define __ARM_COMPAT_H
#undef __cplusplus
#define __cplusplus 201103L
#define __cplusplus__ 1
#define DOXYGEN_ONLY 1

typedef void* common_type_t;
typedef  int PinName;
#define PinName int
typedef  int PinMode;
#define PinMode int
#define _GLIBCXX_CSTRING 1
#define _BASIC_IOS_H 1
#define __COMPAT_H__ 1
//#define  _STDLIB_H_ 1
typedef void* __builtin_va_list;

#include "arduino.h"
#include <mbed_config.h> 
#include <nina_pins.h> 
#include <pinmode_arduino.h> 
#include <pins_arduino.h> 
#include <double_tap_usb_boot.cpp> 
#include <nina_pins.cpp> 
#include <variant.cpp> 
#undef INPUT
#define INPUT 0x0
#undef OUTPUT
#define OUTPUT 0x1
#undef LOW
#define LOW 0u
#undef HIGH
#define HIGH 1u

// Additions to override the introduced code from overrides.h which confuses intellisense
#undef _GLIBCXX_DEFAULT_ABI_TAG
#define _GLIBCXX_DEFAULT_ABI_TAG 
#undef _GLIBCXX_HOSTED
#define _GLIBCXX_HOSTED 0

void pinMode(int pinNumber, int pinMode);
void pinMode(int pinNumber, int pinMode) {}
void digitalWrite(unsigned int pinNumber, PinStatus status);
void digitalWrite(unsigned int pinNumber, PinStatus status) {}
void digitalWrite(unsigned int pinNumber, unsigned int status);
void digitalWrite(unsigned int pinNumber, unsigned int status) {}
PinStatus digitalRead(unsigned int pinNumber);
PinStatus digitalRead(unsigned int pinNumber) {}
int analogRead(int pinNumber);
int analogRead(int pinNumber) {}
void analogWrite(int pinNumber, int value) {}
unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout) {}
unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout) {}
void shiftOut(int dataPin, int clockPin, BitOrder bitOrder, uint8_t val) {}
uint8_t shiftIn(int dataPin, int clockPin, BitOrder bitOrder) {}
void attachInterrupt(int interruptNumber, voidFuncPtr callback, PinStatus mode) {}
void attachInterruptParam(int interruptNumber, voidFuncPtrParam callback, PinStatus mode, void* param) {}
void detachInterrupt(int interruptNumber) {}

#include "ECE101 Helping the Blind See Project.ino"
#endif
#endif
