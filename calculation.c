#include<stdio.h>
#include<conio.h>
#include"cal.h"

int main(void)
{
	int no1,no2,ans;
	
	printf("enter two no to add \t");
	scanf("%d%d",&no1 ,&no2);
	ans = add(no1 ,no2);
	printf("addition is : %d \n",ans );

	printf("enter two no subtract \t");
	scanf("%d%d",&no1 ,&no2);
	ans = sub(no1,no2);
	printf("subtraction is : %d \n",ans );

	printf("enter two no to multiply \t");
	scanf("%d%d",&no1 ,&no2);
	ans = mult(no1,no2);
	printf("Multiplication is : %d \n",ans );

	printf("enter two no divide \t");
	scanf("%d%d",&no1 ,&no2);
	ans = div(no1,no2);
	printf("Division is : %d \n",ans );

	printf("enter two for modulous \t");
	scanf("%d%d",&no1 ,&no2);
	ans = mod(no1,no2);
	printf("modulous is : %d \n",ans );
	return 0;
}
int add(int no1, int no2)
{
	return no1+no2;

}
int sub(int no1, int no2)
{
	return no1-no2;
}
int mult(int no1 ,int no2)
{
	return no1*no2;
}
int div(int no1,int no2)
{
	return no1/no2;
}
int mod(int no1,int no2)
{
	return no1%no2;
}