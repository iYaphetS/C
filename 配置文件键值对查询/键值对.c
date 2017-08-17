#include <stdio.h>
#include <ctype.h>
#include <string.h>
#pragma warning(disable:4996)
/*
键值对（"key = value"）字符串，在开发中经常使用
要求1：请自己定义一个接口，实现根据key获取
要求2：编写测试用例
要求3：键值对中间可能有n多空格，请去除空格

参考库函数：strncpy(), strlen(), strstr(), 不能使用sscanf()函数


功能：
键值对（“key = value”）字符串更加键key查找对应的值value
参数：
keyval：键值对（“key = value”）字符串
pkey：键
buf：匹配键所对应的内容
len：匹配键所对应内容的长度
返回值：
成功：0
失败：非0
*/
int getKeyByValue(char *keyvaluebuf, char *keybuf, char *  valuebuf, int * valuebuflen)
{
	int keylen = 0;//键的长度
	int keyvallen = 0;//值的长度
	//查找键值对字符串中是否有对应的键字符串，没有找到返回-1
	char *s = strstr(keyvaluebuf, keybuf);
	if (s == NULL)
		return -1;
	//得到键字符串的长度
	char *temp = s;
	while (!isspace(*temp))
	{
		keylen++;
		temp++;
	}
	s += keylen;
	//找到值字符串的首地址
	while (isspace(*s) || *s == '=')		
		s++;
	temp = s;
	//得到值字符串的长度
	while (!isspace(*temp) && *temp)
	{
		keyvallen++;
		temp++;
	}
	//*temp = '\0';s指向的字符串是常量字符串不能修改
	
	strncpy(valuebuf, s, keyvallen);
	*(valuebuf + keyvallen) = '\0';
	*valuebuflen = keyvallen;

	return 0;
}

int main(void)
{
	char buf[128] = { 0 };
	int len = 0;

	// 在"key1 =    valude1"中查找"key1"匹配的字符串，
	//如果找到，获取=后面的字符串，而且去掉多余空格
	int ret = getKeyByValue("key1 =    valude1   ", "key1", buf, &len);
	//调用函数后：buf="valude1", len=7
	if (ret != 0)
	{
		printf("没有找到键对应的值\n");
	}
	printf("%s, %d\n", buf, len);

	return 0;
}
