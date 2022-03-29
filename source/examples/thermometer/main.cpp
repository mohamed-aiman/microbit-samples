#include "MicroBit.h"

MicroBit uBit;
MicroBitStorage storage; 
MicroBitThermometer thermometer(storage); 

int main()
{
    // Initialise the micro:bit runtime.
    uBit.init();

    ManagedString s(thermometer.getTemperature()); 
    // Insert your code here!
    uBit.display.scroll(s);

    // If main exits, there may still be other fibers running or registered event handlers etc.
    // Simply release this fiber, which will mean we enter the scheduler. Worse case, we then
    // sit in the idle task forever, in a power efficient sleep.
    release_fiber();
}

