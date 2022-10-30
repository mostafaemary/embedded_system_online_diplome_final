#ifndef _S_H_
#define _S_H_
//#include "stdint.h"
//#include"stdio.h"
#include "driver.h"
#define STATE_DEFINE(_stateFUNC_) void ST_##_stateFUNC_()
#define STATE_SYMBOL(_FUNC_NAME_) ST_##_FUNC_NAME_
void CALL_MAIN_ALGORETHM(int val);
void CALL_ALARM();
#endif /*_P_S_H_*/
