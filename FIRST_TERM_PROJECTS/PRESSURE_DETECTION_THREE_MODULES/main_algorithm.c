#include "main_algorithm.h"

int threshold=20;
int M_P_VAL=0;
//MA_P=STATE_SYMBOL(DETECTION);
STATE_DEFINE(DETECTION)
{
	M_P_VAL=getPressureVal();
	if(getPressureVal()>=threshold)
	{
		call_ALARM();
	}
	else
	{
		Set_Alarm_actuator(1);
	}
}
/*void interface_B_PS_MA(int val)
{
	//printf("pressure value from sensor >> main algorithm is: %d\n",M_P_VAL);
	M_P_VAL = val;
	if(M_P_VAL<threshold)
	{}
	else
	{
		//printf("pressure value will sent to >> alarm monitor: %d\n",M_P_VAL);
		interface_B_MA_ALARM(M_P_VAL);
	}
	MA_P=(int*)STATE_SYMBOL(DETECTION);
}*/
