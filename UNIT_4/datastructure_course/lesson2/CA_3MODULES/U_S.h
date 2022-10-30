/*
 * US.h
 *
 *  Created on: Sep 20, 2022
 *      Author: MOSTAFA
 */

#ifndef U_S_H_
#define U_S_H_
#include "state.h"
enum {
	US_busy
}US_id;

void (*us_s_p)();
void US_init();
STATE_define(US_busy);
int get_rand(int l,int r,int count );
#endif /* U_S_H_ */
