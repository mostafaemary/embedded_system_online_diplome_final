/*
 * CA.c
 *
 *  Created on: Sep 17, 2022
 *      Author: MOSTAFA
 */
#include "CA.h"
#include "math.h"
int US_generate_random(int l,int r,int count);
int CA_speed=0;
int CA_distance=0;
int CA_threshold=50;
void(*CA_state)();
STATE_define(CA_waiting)
{
	CA_state_id = CA_waiting;
	CA_speed = 0;
	CA_distance=US_generate_random(45,55,1);
	(CA_distance<=CA_threshold)? (CA_state=STATE(CA_waiting)): (CA_state=STATE(CA_driving));
	printf("CA_waiting:distance= %d  speed= %d \n",CA_distance,CA_speed);
}
STATE_define(CA_driving)
{
	CA_state_id = CA_driving;
	CA_speed = 30;
	CA_distance=US_generate_random(45,55,1);
	(CA_distance<=CA_threshold)? (CA_state=STATE(CA_waiting)): (CA_state=STATE(CA_driving));
	printf("CA_driving: distance= %d, speed= %d \n",CA_distance,CA_speed);
}
int US_generate_random(int l,int r,int count)
{

	int i,rand_num;
	for (i=0;i<count;i++)
	{
		rand_num =(rand() % ( r - l + 1 )) + l;
	}
	return rand_num;
}

