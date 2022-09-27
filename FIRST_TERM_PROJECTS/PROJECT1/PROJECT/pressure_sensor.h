#ifndef _P_S_H_
#define _P_S_H_
#include "state.h"
void (*PS_P)();
STATE_DEFINE(SENSOR_init);
STATE_DEFINE(READING);
STATE_DEFINE(WAITING);
int get_rand(int l,int r,int count );
#endif /*_P_S_H_*/
