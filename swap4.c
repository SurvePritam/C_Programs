
#include<stdio.h>
void swap4(int * ,int *);

int main(void)
{
	int a , b ;			

	printf("Enter values of A and B to Swap : ");	// INPUT NO OUTPUT
	scanf("%d%d",&a,&b);
	swap4(&a,&b);
	printf(" After  swapping A = %d  B = %d \n", a, b );
	return 0;
}
void swap4(int *a , int *b)
{
	printf("Before swapping A = %d  B = %d \n", *a, *b);
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
