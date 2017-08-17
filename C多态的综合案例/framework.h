#pragma once

//框架函数的声明
#include "CSocketProtocol.h"
#include "CEncDesProtocol.h"

int framework(CSocketProtocol *sp, CEncDesProtocol *ed, 
	char *send_buf, int send_len, char *recv_buf, int *recv_len);

