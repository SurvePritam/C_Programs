#include<stdio.h>
int main(void)
{
	const int no=10;
	int no2=20;
	int *p= &no;
	p++;  // allowed cause pointr thinks it is a non constant value
	
	int * const p2=&no2;
		 //p2--;	Error cause pointer is a constant value

	const int *p3=&no2; 
		// p3++; Error cause pointer thinks its a constant value


	
	//printf("%d",*p+5);

	return 0;
}