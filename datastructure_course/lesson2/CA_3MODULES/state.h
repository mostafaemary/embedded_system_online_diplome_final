/*
 * state.h
 *
 *  Created on: Sep 17, 2022
 *      Author: MOSTAFA
 */

#ifndef STATE_H_
#define STATE_H_
#include "stdio.h"
#include "stdlib.h"
#define STATE_define(_stateFUNC_) void ST_##_stateFUNC_()
#define STATE(_stateFUNC_) ST_##_stateFUNC_
void interface_B_US_CA(int d);
void interface_B_M_CA(int s);
#endif /* STATE_H_ */
