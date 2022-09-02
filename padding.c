#include<stdio.h>
int main (void)
{
	// before padding
	struct demo1
	{
		char ch;
		double d;
	}obj1;
	printf("Size before padding : %d\n" , sizeof(obj1));
	
	// after padding
#pragma pack(1)
	{
	struct demo2
	{
		char ch;
		double d;
	}obj2;
	printf("Size after padding with packsize 1 : %d \n" , sizeof(obj2));
	}
#pragma pack(2)
	{
	struct demo3
	{
		char ch;
		double d;
	}obj3;
	printf("Size after double padding with packsize 2 : %d \n" , sizeof(obj3));
	}
	return 0;
}