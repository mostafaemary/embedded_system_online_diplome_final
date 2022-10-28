#ifndef _S_H_
#define _S_H_
//#include "stdint.h"
//#include"stdio.h"
#include "driver.h"
#define STATE_DEFINE(_stateFUNC_) void ST_##_stateFUNC_()
#define STATE_SYMBOL(_FUNC_NAME_) ST_##_FUNC_NAME_
void interface_B_PS_MA(int val);

void interface_B_AM_DRIVER(int val);
#endif /*_P_S_H_*/
