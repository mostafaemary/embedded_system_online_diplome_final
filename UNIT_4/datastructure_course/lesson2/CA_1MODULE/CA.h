/*
 * CA.h
 *
 *  Created on: Sep 17, 2022
 *      Author: MOSTAFA
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"
enum{

	CA_waiting,
	CA_driving
}CA_state_id;

STATE_define(CA_waiting);
STATE_define(CA_driving);
extern void(*CA_state)();
#endif /* CA_H_ */
