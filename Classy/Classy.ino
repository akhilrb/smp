#include "Classy.h"
volatile uint8_t timeOff = 20;

// instantiate LEDs
Classy LED1(7);
Classy LED2(8);

void setup()
{
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
    attachInterrupt(0, dec, FALLING);
    attachInterrupt(1, inc, FALLING);
}

void loop()
{
    LED1.update();
    LED2.update();
}

void dec()
{
    timeOff--;
    LED1.setOffTime(timeOff);
    timeOff--;
    LED2.setOffTime(timeOff);
}

void inc()
{
    timeOff++;
    LED1.setOffTime(timeOff);
    timeOff++;
    LED2.setOffTime(timeOff);
}
