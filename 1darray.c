#include<stdio.h>

struct demo
{
	int i;
	char c;
}arr3[3]={1,'A'};

int main(void)
{
	int arr1[] = {10,20,30,40,50};
	int arr2[5];
	struct demo arr4[4];
	
	int arr5[5];
	int counter;

	for(counter=0;counter<=4;counter++)
	{
		printf("enter 2ndarry element no [ %d ] :", counter+1);
		scanf("%d",&arr2[counter]);
	}
	// i can definately print this with for loop but just to look good
		printf(" arr2 all elements: %d %d %d %d %d \n\n",arr2[0],arr2[1],arr2[2],arr2[3],arr2[4]);
	
	for(counter=0;counter<=4;counter++)
	{
		printf(" arr1 all elements(with for loop) : %d\n",arr1[counter]);
	}
	arr4[0].i = 10;
	
	printf(" printing 1st array 1st element : %d\n",arr1[0]);

	printf(" printing 2nd struct array 1st element : %d \t %c\n",arr3[0]);
	printf(" printing 2nd struct array 1st element : %d \t %c\n",arr4[0]);

	return 0;
}

//printf(" printing array name : %d\n",arr1);
	//printf(" printing array name with & : %d\n",&arr1);