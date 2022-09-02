#include<stdio.h>
void fun(void);
int no = 10;
int main(void)
{
	int no = 20;
	printf("  %d  \n", no);
	{
		char no = 'a';
		printf("  %d \n", no);
	}
	printf("  %d \n",no);
	fun();
return 0;
}
void fun (void)
{
	printf("  %d \n",no);
}



