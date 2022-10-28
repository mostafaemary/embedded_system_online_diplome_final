//#include <stdint.h>
//#include <stdio.h>
#include "state.h"
#include "driver.h"
#include"main_algorithm.h"
//#include "pressure_sensor.h"
#include "alarm_monitor.h"
int main ()
{
	//ST_SENSOR_init();
	GPIO_INITIALIZATION() ;

	while (1)
	{

		Set_Alarm_actuator(1);
		STATE_SYMBOL(DETECTION());
		//MA_P();
		//PS_P();
		//A_M_P();
		Delay(50000);
		//Implement your Design 
	}
}
