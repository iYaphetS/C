#pragma once

//加解密函数的声明

int enc_file(unsigned char *src, int src_len, unsigned char *dest, int *dest_len);

int des_file(unsigned char *src, int src_len, unsigned char *dest, int *dest_len);
