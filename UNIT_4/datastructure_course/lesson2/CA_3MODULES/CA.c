/*
 * CA.c
 *
 *  Created on: Sep 20, 2022
 *      Author: MOSTAFA
 */
#include"CA.h"
int CA_distance=0;
int CA_speed=0;
int CA_threshold=50;



STATE_define(CA_DRIVING)
{
	printf("CA_DRIVING: distance is: %d\n",CA_distance);
	CA_id=CA_DRIVING;
	interface_B_M_CA(30);
}

STATE_define(CA_WAITING)
{
	printf("CA_WAITING: distance is: %d\n",CA_distance);
	CA_id=CA_WAITING;
	interface_B_M_CA(0);
}

void interface_B_US_CA(int d)
{
	CA_distance=d;
	printf("SENSOR-----> distance = %d -----> CA\n",CA_distance);
	(CA_distance <= CA_threshold)? (ca_s_p=STATE(CA_WAITING)):(ca_s_p=STATE(CA_DRIVING));
}
