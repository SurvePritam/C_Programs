// Swap using arithmatic operators

#include<stdio.h>
void swap1(void);
void swap2(int,int);
//int swap3(int,int);

int main(void)
{
	int a , b ;
	swap1();					// NO INPUT NO OUTPUT

	printf("Enter values of A and B to Swap : ");	// INPUT NO OUTPUT
	scanf("%d%d",&a,&b);
	swap2(a,b);

	return 0;
}
void swap1(void)
{
	int a, b;
	printf("Enter values of A and B to Swap : ");
	scanf("%d%d",&a,&b);
	printf("BEFORE SWAP : A = %d  B = %d \n", a, b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("AFTER SWAP : A = %d B = %d \n", a , b);
}
void swap2(int a , int b)
{
	printf(" A = %d  B = %d \n", a, b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("After swapping \n A = %d B = %d \n", a , b);
}



/*
int swap3(int a , int b)
{
	printf(" A = %d  B = %d \n", a, b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("After swapping A = %d \n", a );
	return b ;
}

*/