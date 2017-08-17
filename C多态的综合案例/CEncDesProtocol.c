#include <stdio.h>
#include "CEncDesProtocol.h"

//加解密结构体成员变量初始化
void setED(CEncDesProtocol *ED, PENCFILE enc, PDESFILE des)
{
	if (ED == NULL || enc == NULL || des == NULL)
		return;
	ED->enc_file = enc;
	ED->des_file = des;
}