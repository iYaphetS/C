#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main01()
{
	char s[10] = {0};

	gets(s);
	for (int i = 0; i < 10; i++)
	{	
		printf("%d\n", s[i]);
	}
	printf("--------------\n");
	printf("%s\n", s);
	return 0;
}

//gets�� scanf�����ڻ�������������⣬�������������ַ�����������ĳ���
//�ͻᵼ�³������
//scanf���ո񵱳ɽ�����־����gets����

//fgets�����Ƕ�ȡ�ļ�������˻��������������

//���������ַ�����������Ч���ܱ����鳤����һ������Ϊ�ַ�������0��β�ģ�ռһλ

int main02()
{
	char s[10] = {0};
	fgets(s, sizeof(s) - 1, stdin);

	for (int i = 0; i < 10; i++)
	{	
		printf("%d\n", s[i]);
	}
	printf("-----------");
	printf("%s\n", s);
	return 0;
}

int main03()
{
	//put������printf��ͬ�������ַ���β���Զ����ϡ�\n��
	char s[] = "hello world";
	puts(s);
	//fput�Ƕ��ļ����������
	fputs(s, stdout);


	return 0;
}


//�ַ�������������string.h �ļ���
int main04()
{
	char s[100] = "leo hello";

	int len = strlen(s);//�õ��ַ������ȣ����ص����ַ��� ��Ч�ַ����������������ַ�����β��0

	printf("len = %d, slen = %d\n", len, sizeof(s));


	return 0;
}

int main05()
{
	char s1[1024] = "hello adu";

	char s2[] = " how are you";
	strcat(s1, s2);



	printf("%s\n", s1);

	return 0;
}

int main06()
{
	char s1[1024] = "sfuhua";
	char s2[1000] = "fjhudquha";

	strncat(s1, s2, 5);

	puts(s1);
	return 0;
}

int main07()
{	
	char s1[100] = "abcd";
	char s2[10] = "abcdf";
	if (!strcmp(s1, s2))
	{
		printf("s1, s2�ַ�����ͬ\n");
	}else
	{
		printf("s1, s2�ַ�������ͬ\n");
	}
	return 0;
}

int main08()
{
	char s1[100] = "suhaufu";
	char s2[10] = "suhau";

	if (!strncmp(s1, s2, 5))
	{	
		printf("s1, s2�ַ�����ͬ\n");
	}else
	{
		printf("s1, s2�ַ�������ͬ\n");
	}
	return 0;
}

int main09()
{
	char s1[1024] = "ahdu7u";

	char s2[100] = {0};

	strcpy(s2, s1);

	puts(s2);

	return 0;
}

int main10()
{
	char s1[100] = "jjdiajduq";
	char s2[100] = {0};

	strncpy(s2, s1, 5);

	puts(s2);

	return 0;
}

int main11()
{
	char s1[100] = "i";
	char s2[100] = "csdn";

	

	char s[1024] = {0};

	sprintf(s,"%s love %s", s1, s2);

	puts(s);

	sprintf(s, "%10.3f", 3.141592);//%m.nf�����ʽ�ǽ�����������С��nλ��mλ�����

	//���а���С���㣩���Ҷ���ķ�ʽ������mλ��ǰ����ո�

	puts(s);

	return 0;

}

//�ص�sscanf���÷�
int main()
{

	char *string;
	int num = 0;

	int ret = 0;

	char  buf1[100] = { 0 };
	char  buf2[100] = { 0 };
	char  buf3[100] = { 0 };
	char  buf4[100] = { 0 };
	//1.��ȡ���ַ����еĶ��ַ���
	string = "i love china 123";
	ret = sscanf(string, "%s %s %s %d", buf1, buf2, buf3, &num);

	printf("%d, %s, %s, %s, %d\n\n", ret, buf1, buf2, buf3, num);

	//2.ȡָ�����ȵ��ַ���
	string = "helloworld";
	ret = sscanf(string, "%9s", buf1);

	printf("%d, %s\n\n", ret, buf1);

	//3.ȡ��ָ���ַ�Ϊֹ���ַ���
	string = "share/hehe";
	ret = sscanf(string, "%[^/]", buf1);

	printf("%d, %s\n\n", ret, buf1);

	//4.ȡ��ָ���ַ���Ϊֹ���ַ���
	string = "12345ABabc";
	ret = sscanf(string, "%[^A-Z]", buf1);

	printf("%d, %s\n\n", ret, buf1);

	//5.ȡ������ָ���ַ������ַ���
	string = "0234ASDazx";
	ret = sscanf(string, "%[0-9]%[A-Z]%[a-z]", buf1, buf2, buf3);

	printf("%d %s, %s, %s\n\n", ret, buf1, buf2, buf3);

	ret = sscanf(string, "%d%[A-Z]%[a-z]", &num, buf2, buf3);
	printf("%d, %d, %s, %s\n\n", ret, num, buf2, buf3);

	//6.��ȡָ���ַ��м���ַ���
	string = "sss<hah>qeb";
	ret = sscanf(string, "%*[^<]<%[^>]", buf1);//%*[^<]ȥ��*������ֱ��<

	printf("%d, %s\n\n", ret, buf1);

	//7.ָ��Ҫ�������ַ���
	string = "djauhABjdku";
	//ret = sscanf(string, "%sAB%s", buf1, buf2);ERRO
	ret = sscanf(string, "%[a-z]AB%[a-z]", buf1, buf2);

	printf("%d, %s, %s\n\n", ret, buf1, buf2);

	//8.�ָ���ĳ���ַ��������ַ���

	string = "tom-sary-tim123";
	ret = sscanf(string, "%[^-]-%[^-]-%[^-]", buf1, buf2, buf3);

	printf("%d, %s, %s, %s\n\n", ret, buf1, buf2, buf3);

	//9.��ȡ����ĵ�ַ
	string = "Email:wencheng20@126.com";
	ret = sscanf(string, "%*[^:]:%s", buf1);

	printf("%d, %s\n\n", ret, buf1);

	ret = sscanf(string, "%*[^:]:%[^@]@%[^.]",buf1, buf2);

	printf("%d, %s, %s\n\n", ret, buf1, buf2);

	//10���˵���Ҫ���ַ���
	string = "android iphone wp";
	ret = sscanf(string, "%s %*s %s", buf1, buf2);

	printf("%d, %s, %s\n\n", ret, buf1, buf2);


	//��7��10���бȽ�,���ǿ��Կ�����sscanf��%s��������������scanf����ͬ�ģ��������ո�ʱ�����ַ����Ľ���
	//�����Ϊʲô10������%s��7ȴҪʹ��%[a-z]



	return 0;
}