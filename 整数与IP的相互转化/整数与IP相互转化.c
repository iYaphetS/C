#include <stdio.h>
#pragma warning(disable:4996)


int ip_to_num(char *buf, int *n)
{
	//ip转整数192.168.0.1 -------
	if (buf == NULL)
		return -1;

	int num = *n;
	int a, b, c, d;
	sscanf(buf, "%d.%d.%d.%d", &a, &b, &c, &d);
	unsigned char *temp = (unsigned char *)&num;
	//整数和数组高地位正好相反
	temp[0] = d;
	temp[1] = c;
	temp[2] = b;
	temp[3] = a;
	*n = num;
	return 0;
}

int num_to_ip(int num, char *buf)
{
	unsigned char *temp = (unsigned char *)&num;
	//-1062731775
	int a, b, c, d;
	d = temp[0];
	c = temp[1];
	b = temp[2];
	a = temp[3];

	//整数和数组高地位正好相反
	sprintf(buf, "%d.%d.%d.%d", a, b, c, d);
	return 0;
}

int main()
{
	char ip[] = "192.168.0.1";
	int num = 0;
	ip_to_num(ip, &num);
	printf("%d\n", num);

	int n = -1062731775;
	char IP[100] = {0};
	num_to_ip(num, IP);
	printf("%s\n", IP);

	return 0;
}