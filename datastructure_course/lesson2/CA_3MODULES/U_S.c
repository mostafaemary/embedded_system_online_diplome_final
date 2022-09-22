/*
 * U_S.c
 *
 *  Created on: Sep 20, 2022
 *      Author: MOSTAFA
 */

#include "U_S.h"
int distance;
void US_init()
{
	us_s_p = STATE(US_busy);
}

STATE_define(US_busy)
{
	US_id=US_busy;
	distance = get_rand(45,55,1);
	interface_B_US_CA(distance);
	us_s_p = STATE(US_busy);
}


int get_rand(int l,int r,int count )
{
	int rand_num,i;
	for(i=0;i<count;i++)
	{
		rand_num=(rand()%(r-l+1))+l;
	}
	return rand_num;
}
