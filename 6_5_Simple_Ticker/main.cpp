#include "mbed.h"
using namespace std::chrono;

Ticker flipper;
DigitalOut led3(LED3);
DigitalOut led2(LED2);

void flip()
{
   led2 = !led2;
}

int main()
{
   led2 = 1;
   flipper.attach(&flip, 2s); // the address of the function to be attached (flip) and the interval (2 seconds)

   // spin in a main loop. flipper will interrupt it to call flip
   while (1)
   {
      led3 = !led3;
      ThisThread::sleep_for(500ms);
   }
}