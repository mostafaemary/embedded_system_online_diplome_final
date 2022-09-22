/*
 * DC_M.h
 *
 *  Created on: Sep 20, 2022
 *      Author: MOSTAFA
 */

#ifndef DC_M_H_
#define DC_M_H_
#include"stdio.h"
#include "state.h"
enum {
	DC_idel,DC_busy
}DC_M_id;
void DC_init();
STATE_define(DC_idle);
STATE_define(DC_busy);

void (* DC_P_State)();

#endif /* DC_M_H_ */
