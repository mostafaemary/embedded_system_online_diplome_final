#ifndef _ALARM_H_
#define _ALARM_H_
#include"state.h"
void (*A_M_P)();
void call_ALARM();
STATE_DEFINE(ALARM_ON);
STATE_DEFINE(ALARM_OFF);
#endif /*_ALARM_H_*/
