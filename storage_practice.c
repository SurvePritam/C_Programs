#include<stdio.h>
void fun (void);
int main(void)
{
	
	extern int no;
	//int no = 30; // error 
	printf(" In Main No is :  %d \n ", no);
	fun();
	//printf(" %d \n", no);
	
	return 0;
}

// int no = 20; error , multiple definaion

int no = 20;