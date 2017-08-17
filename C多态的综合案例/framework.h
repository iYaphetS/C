#pragma once

//¿ò¼Üº¯ÊýµÄÉùÃ÷
#include "CSocketProtocol.h"
#include "CEncDesProtocol.h"

int framework(CSocketProtocol *sp, CEncDesProtocol *ed, 
	char *send_buf, int send_len, char *recv_buf, int *recv_len);

