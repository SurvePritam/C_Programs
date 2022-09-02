#include<stdio.h>
int fibo(int);
int main(void)
{

	int no , ans;
	printf("enter the number for fibonacci series");
	scanf("%d", &no);

	ans = fibo(no);
	printf("ans = %d" , ans);
	return 0;
}

int fibo(int no)
{
	int a , b , c;
	if (no == 1)
		return 1;

		a = no + fibo(no + 1);
		printf(" ans  %d",a);

}
