#ifndef DTIME_H
#define DTIME_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class DTime {
  public:
    const unsigned long &timestamp = _timestamp;
    const unsigned short &year = _year;
    const byte &month = _month, &weekday = _weekday, &day = _day, &hour = _hour, &minute = _minute, &second = _second;

    explicit DTime() {};
    explicit DTime(unsigned long t): _timestamp(t) {
      decode();
    };
    DTime(unsigned short Y, byte M, byte D, byte h, byte m, byte s);

    DTime setDate(unsigned short Y, byte M, byte D);
    DTime setTime(byte h, byte m, byte s);
    DTime setTimestamp(unsigned long t);
    DTime tick();

  private:
    unsigned long _timestamp = 0;
    unsigned short _year = 1970;
    byte _month = 1, _weekday = 4, _day = 1, _hour = 0, _minute = 0, _second = 0;
    void decode();
    void encode();
    bool isLeapYear(unsigned short Y);
};

#endif
