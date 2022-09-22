/*
 * main.c
 *
 *  Created on: Sep 17, 2022
 *      Author: MOSTAFA
 */
#include "CA.h"
void setup()
{
	CA_state=STATE(CA_waiting);
}
void main()
{
	setup();
	while(1)
	{
		CA_state();
	}
}
