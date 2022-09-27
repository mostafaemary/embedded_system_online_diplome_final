#include "pressure_sensor.h"
int PS_P_VAL=0;
STATE_DEFINE(SENSOR_init)
{
	Set_Alarm_actuator(1);
	STATE_SYMBOL(READING());
}
STATE_DEFINE(READING)
{
	PS_P_VAL=getPressureVal();/*get_rand(15,25,1 )*/
	CALL_MAIN_ALGORETHM(PS_P_VAL);
	STATE_SYMBOL(WAITING());
}
STATE_DEFINE(WAITING)
{
	int i=0;
	Delay(50000);
	STATE_SYMBOL(READING());
}
/*int get_rand(int l,int r,int count )
{
	int rand_num,i;
	for(i=0;i<count;i++)
	{
		rand_num=(rand()%(r-l+1))+l;
	}
	return rand_num;
}*/
