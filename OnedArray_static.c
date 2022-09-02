#include<stdio.h>
#define max 10

int main(void)
{
	int arr[max];	
	int n , counter;
	
	printf("Enter how many elements you want to insert (0 - 10) : ");
	scanf("%d",&n);
	
	for (counter=0; counter<n; counter++)
	{
		printf("Enter Element No [ %d ] : " , counter+1);
		scanf("%d",&arr[counter]);
	}
	
	for (counter=0; counter<n; counter++)
		printf(" Element No [ %d ] : %d \n" , counter+1 , arr[counter]);

	return 0;
}