#include "Timer.h"

/*
 *
 * This example show how to use Timer to do a 
 * task at a given interval. 
 *
 * https://github.com/stejsoftware/Arduino-Timer
 *
 */
 
#define PIN 0   // attach an LED to this pin

// simple function to turn an LED either on or off
void blinker()
{
  if( digitalRead(PIN) == HIGH )
  {
    digitalWrite(PIN, LOW);
  }
  else
  {
    digitalWrite(PIN, HIGH);    
  }
}
  
void setup() 
{
  pinMode(PIN, OUTPUT);
  digitalWrite(PIN, LOW);
  
  // creates a Timer that will execute once a second
  Timer.repeat(blinker, 1000);
}

void loop() 
{
  // checks the timer and runs the handlers of expired timers.
  Timer.run();
}
