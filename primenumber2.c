// CHECK WEATHER THE PRIME NUMBER OR NOT
#include<stdio.h>
void fun1(void);
void fun2(int);
int fun3(int);

int main(void)
{
	int no , ans;
	fun1();						//NO INPUT NO OUTPUT 

	printf("Enter Number : ");
	scanf("%d",&no);
	fun2(no);					//INPUT NO OUTPUT

	printf("Enter Number : ");
	scanf("%d",&no);
	ans = fun3(no);				// INPUT OUTPUT
	if(ans==0)
		printf("It is a prime number \n ");
	else
		printf("It is not a prime number \n ");
	return 0;
}

void fun1(void)
{
	int i , no;
	int j = 0;
	printf("Enter Number : ");
	scanf("%d",&no);	
	for(i=2;i<= no/2;i++)
	{
		if (no%i==0)
		{
			printf("It is not a prime number \n ");
			j = 1;
			break;
		}
	}
	if(j==0)
	printf("It is a prime number \n ");
}
void fun2(int no)
{
	int i ,j=0;	
	for(i=2;i<= no/2;i++)
	{
		if (no%i==0)
		{
			printf("It is not a prime number \n ");
			j=1;
			break;		
		}
	}
	if(j==0)
		printf("It is a prime number \n ");
}
int fun3(int no)
{
	int i ,j=0;	
	for(i=2;i<= no/2;i++)
	{
		if (no%i==0)
		{
			j=1;
			break;		
		}
	}
	if(j==0)
		return 0;
return 1;
}