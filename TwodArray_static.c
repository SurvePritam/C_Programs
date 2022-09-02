// Accepting 2 2d arr1ay values and printing the addition

#include<stdio.h>
#define max 10

int main(void)
{
	int arr1[max][max];
	int arr2[max][max];
	
	int row , column , counter1 , counter2 ;

	printf(" Enter No of rows : " );
	scanf("%d",&row);
	printf(" Enter No of Columns : " );
	scanf("%d",&column);
	
	for(counter1=0;counter1<row;counter1++)
	{
		for(counter2=0;counter2<column;counter2++)
		{
			printf("Enter Array 1 Element No[%d][%d] ",counter1,counter2);
			scanf("%d",&arr1[counter1][counter2]);
		}
	}
	for(counter1=0;counter1<row;counter1++)
	{
		for(counter2=0;counter2<column;counter2++)
		{
			printf("Enter Array 2 Element No[%d][%d] ",counter1,counter2);
			scanf("%d",&arr2[counter1][counter2]);
		}
	}
	printf(" \n Elements of array 1 \n");
	for(counter1=0;counter1<row;counter1++)
	{
		for(counter2=0;counter2<column;counter2++)	
				printf(" %d ",arr1[counter1][counter2]);
		
		printf("\n");
	}
	printf(" \n Elements of array 2 \n");
	for(counter1=0;counter1<row;counter1++)
	{
		for(counter2=0;counter2<column;counter2++)	
				printf(" %d ",arr2[counter1][counter2]);
		
		printf("\n");
	}
	printf(" \n Addition of array1 & array2 \n");
	for(counter1=0;counter1<row;counter1++)
	{
		for(counter2=0;counter2<column;counter2++)	
				printf(" %d ",arr1[counter1][counter2] + arr2[counter1][counter2]);
		
		printf("\n");
	}

	return 0;
}