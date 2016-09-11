#include "Timer.h"

/*
 *
 * This example show how to use Timer to do a 
 * task after a given amount of time. 
 *
 * https://github.com/stejsoftware/Arduino-Timer
 *
 */
 
#define PIN 0   // attach an LED to this pin

// simple function to fade an LED on
void fader()
{
  int x;
  
  for(x = 0; x <= 255; x++)
  {
    analogWrite(PIN, x);
    delay(10);
  }  
}
  
void setup() 
{
  pinMode(PIN, OUTPUT);
  digitalWrite(PIN, LOW);
  
  // creates a Timer that will execute after 5 seconds
  Timer.delay(fader, 5000);
}

void loop() 
{
  // checks the timer and runs the handlers of expired timers.
  Timer.run();
}
