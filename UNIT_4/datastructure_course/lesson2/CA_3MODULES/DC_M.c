/*
 * DC_M.c
 *
 *  Created on: Sep 20, 2022
 *      Author: MOSTAFA
 */
#include "DC_M.h"

int DC_speed=0;

void DC_init()
{
	DC_P_State= STATE(DC_idle);
}
void interface_B_M_CA(int s)
{
	DC_speed=s;
	printf("CA---SPEED = %d ---> DC\n",DC_speed);
	DC_P_State=STATE(DC_busy);
}
STATE_define(DC_idle)
{
	DC_M_id=DC_idel;
	printf("Dc:speed idle state\t:%d\n",DC_speed);
}
STATE_define(DC_busy)
{
	DC_M_id=DC_busy;
	printf("Dc speed: busy state\t:%d\n",DC_speed);
	DC_P_State=STATE(DC_idle);
}

