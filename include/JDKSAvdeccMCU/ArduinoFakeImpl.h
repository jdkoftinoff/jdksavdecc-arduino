#pragma once

#include "JDKSAvdeccMCU/Arduino.hpp"

#if JDKSAVDECCMCU_ARDUINO == 1 && JDKSAVDECCMCU_BARE_METAL == 0 && !defined( _WIN32 )

Serial_ Serial( stdin, stdout );

extern "C" {

void init( void ) {}
void initVariant( void ) {}

void pinMode( uint8_t, uint8_t ) {}
void digitalWrite( uint8_t, uint8_t ) {}
int digitalRead( uint8_t pin )
{
    (void)pin;
    return 0;
}
int analogRead( uint8_t pin )
{
    (void)pin;
    return 0;
}
void analogReference( uint8_t mode ) { (void)mode; }
void analogWrite( uint8_t, int ) {}

unsigned long millis( void ) { return JDKSAvdeccMCU::getTimeInMilliseconds(); }
unsigned long micros( void ) { return JDKSAvdeccMCU::getTimeInMilliseconds() * 1000; }
void delay( unsigned int t ) { usleep( t * 1000 ); }
void delayMicroseconds( unsigned int us ) { usleep( us ); }
unsigned long pulseIn( uint8_t pin, uint8_t state, unsigned long timeout )
{
    (void)pin;
    (void)state;
    (void)timeout;
    return 0;
}

void shiftOut( uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val )
{
    (void)dataPin;
    (void)clockPin;
    (void)bitOrder;
    (void)val;
}
uint8_t shiftIn( uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder )
{
    (void)dataPin;
    (void)clockPin;
    (void)bitOrder;
    return 0;
}

void attachInterrupt( uint8_t, void ( * )( void ), int mode ) { (void)mode; }
void detachInterrupt( uint8_t ) {}

void tone( uint8_t _pin, unsigned int frequency, unsigned long duration )
{
    (void)_pin;
    (void)frequency;
    (void)duration;
}
void noTone( uint8_t _pin ) { (void)_pin; }
}

#endif
