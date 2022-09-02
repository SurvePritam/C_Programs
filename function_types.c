#include<stdio.h>

void addition1(void); // FUNCTION HAVING NO INPUT NO OUTPUT 
void addition2(int , int); // FUNCTION HAVING INPUT NO OUTPUT 
int addition3(int , int); // FUNCTION HAVING  INPUT as well as OUTPUT 
// int addition4(int , int , &sum , &diff) // FUNCTION HAVING MULTIPLE INPUT OUTPUT (by parameterised return)

int  main(void)
{
	int no1 , no2 , ans;
	

	addition1();		// method 1


	printf("\n enter two numbers ");
	scanf("%d%d" , &no1 , &no2);
	addition2(no1 , no2);			// method 2


	printf("\n enter two numbers ");
	scanf("%d%d" , &no1 , &no2);
	ans = addition3(no1 , no2 );		// method 3
	printf(" addition = %d \n " , ans);

	return 0;
}

void addition1(void)
{
	int no1,no2,ans ;
	printf(" \n enter two numbers");
	scanf("%d%d" , &no1 , &no2);
	ans = no1+no2;
	printf(" \n addition = %d", ans);
}

void addition2(int no1 , int no2)
{
	int ans;
	ans = no1+no2;
	printf(" \n addition = %d " , ans);
}

int addition3(int no1 , int no2)
{
	int ans;
	ans = no1 + no2;
	return ans;
}

/*
	int abc , b , c , k;
	abc = printf("hello \n"); // printf as well as scanf returns the count of letters/no/signs in them
	b = printf("%d \n \t" , abc); // for \n , \t it counts as 2 and for %d it counts as 1
	 printf("%d \n" , b);
	  
	c = scanf("%d", &k); // conclusion is it only tells the count of no present inside the double quaotes

		printf("%d",c);

		*/