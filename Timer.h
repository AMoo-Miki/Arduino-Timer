/* 
 * Timer.h ~ yet another software timer
 * by Jonathan Meyer <jon@stejsofware.com>
 *
 */
 
#ifndef __Timer_h_
#define __Timer_h_

#include "Arduino.h"
#include "List.h"

typedef void (*TimerEventHandler)();

class Alarm
{
public:
  Alarm(TimerEventHandler handler, uint16_t interval, bool repeat);
  ~Alarm();

  void reset();
  void stop();

  bool isTime() const;
  bool isRepeat() const;
  void execute() const;

private:
  Alarm(const Alarm & rhs);
  Alarm & operator=(const Alarm & rhs);

  TimerEventHandler m_handler;
  bool m_repeat;
  uint16_t m_interval;
  uint32_t m_timeout;
};

class TimerClass
{
public:
  TimerClass();
  ~TimerClass();

  // creates a Timer that executes at the given interval
  Alarm * repeat(TimerEventHandler handler, uint16_t interval);
  
  // creates a Timer that executes once after the given timeout
  Alarm * delay(TimerEventHandler handler, uint16_t timeout);

  // should be placed in the loop() function to check of a timer has elapsed.
  void run();

private:
  TimerClass(const TimerClass & rhs);
  TimerClass & operator=(const TimerClass & rhs);

  List<Alarm*> m_alarms;
};

extern TimerClass Timer;

#endif // __Timer_h_
