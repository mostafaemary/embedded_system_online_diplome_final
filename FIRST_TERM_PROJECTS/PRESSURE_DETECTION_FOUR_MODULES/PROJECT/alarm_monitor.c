#include"alarm_monitor.h"
void CALL_ALARM()
{
	//printf("main algorithm detect a high pressure value: %d and send signal to alarm \n",A_M_P_VAL);
	STATE_SYMBOL(ALARM_ON());
}
STATE_DEFINE(ALARM_ON)
{
	Set_Alarm_actuator(0);
	Delay(500000);
	STATE_SYMBOL(ALARM_OFF());
}
STATE_DEFINE(ALARM_OFF)
{
	Set_Alarm_actuator(1);
}
