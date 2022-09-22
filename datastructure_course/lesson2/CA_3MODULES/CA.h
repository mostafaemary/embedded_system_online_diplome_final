/*
 * CA.h
 *
 *  Created on: Sep 20, 2022
 *      Author: MOSTAFA
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"
enum {
	CA_DRIVING,CA_WAITING
}CA_id;

STATE_define(CA_DRIVING);
STATE_define(CA_WAITING);
void(*ca_s_p)();
#endif /* CA_H_ */
