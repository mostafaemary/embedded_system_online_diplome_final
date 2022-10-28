//#include <stdint.h>
//#include <stdio.h>
//#include "driver.h"
#include"main_algorithm.h"
#include "pressure_sensor.h"
#include "alarm_monitor.h"
int main ()
{
	GPIO_INITIALIZATION() ;
	while (1)
	{
		STATE_SYMBOL(SENSOR_init());
		Delay(50000);
		//Implement your Design 
	}
}
