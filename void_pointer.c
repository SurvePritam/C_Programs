#include<stdio.h>
void fun1( void *);
void fun2(void *p);
int main(void)
{
	
	int no =10;
	printf("no = %d \n" , no);
	fun1(&no);				
	printf("no = %d \n" , no);

	return 0;
}
void fun1(int *p)		// internal typecasting
{
	printf("p = %d \n" , *p);
	fun2(&p);				
	printf("p = %d \n" , *p);
}
void fun2(void **q)		// explisite typecasting down
{
	printf("q = %d \n" , **(int **)q);		// explisite typecasting
	(**(int **)q)++;				
	printf("q = %d \n" , **(int **)q);
}