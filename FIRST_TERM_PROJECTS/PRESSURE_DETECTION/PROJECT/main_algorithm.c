#include "main_algorithm.h"

int threshold=20;
int M_P_VAL=0;



STATE_DEFINE(DETECTION)
{
	CALL_ALARM();
}
void CALL_MAIN_ALGORETHM(int val)
{
	//printf("pressure value from sensor >> main algorithm is: %d\n",M_P_VAL);
	M_P_VAL = val;
	if(M_P_VAL<threshold)
	{}
	else
	{
		//printf("pressure value will sent to >> alarm monitor: %d\n",M_P_VAL);
		STATE_SYMBOL(DETECTION());
	}
}
