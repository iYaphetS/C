#include <stdio.h>
#include "CEncDesProtocol.h"

//�ӽ��ܽṹ���Ա������ʼ��
void setED(CEncDesProtocol *ED, PENCFILE enc, PDESFILE des)
{
	if (ED == NULL || enc == NULL || des == NULL)
		return;
	ED->enc_file = enc;
	ED->des_file = des;
}