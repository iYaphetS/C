#include "des.h"
//加解密函数的实现
int enc_file(unsigned char *src, int src_len,
	unsigned char *dest, int *dest_len)
{
	return DesEnc(src, src_len, dest, dest_len);
}

int des_file(unsigned char *src, int src_len,
	unsigned char *dest, int *dest_len)
{
	return DesDec(src, src_len, dest, dest_len);
}
