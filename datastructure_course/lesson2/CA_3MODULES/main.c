/*
 * main.c
 *
 *  Created on: Sep 20, 2022
 *      Author: MOSTAFA
 */
#include "U_S.h"
#include "CA.h"
#include "DC_M.h"
void setup()
{
	ca_s_p=STATE(CA_WAITING);
	US_init();
	DC_init();
}
int main()
{

	setup();
	while (1)
	{
		us_s_p();
		ca_s_p();
		DC_P_State();
	}
	return 0;
}
