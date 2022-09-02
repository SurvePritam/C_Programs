#include<stdio.h>
#define max 10
int comp(int[] ,int[], int ,int);
int main(void)
{
	int arr1[max];
	int arr2[max];
	int n ,n2,counter , ans;
		
	printf("Enter how many elements you want to insert in array no. 1 : ");
	scanf("%d",&n);			
	for (counter=0;counter<n;counter++)
	{
		printf("Enter element no %d :",counter+1);
		scanf("%d",&arr1[counter]);		
	}
	printf("Enter how many elements you want to insert in array no. 2 : ");
	scanf("%d",&n2);			
	for (counter=0;counter<n2;counter++)
	{
		printf("Enter element no %d :",counter+1);
		scanf("%d",&arr2[counter]);		
	}
	ans = comp(arr1 , arr2 ,n ,n2);
		if(ans==0)
			printf(" Is equal  ");
		else
			printf(" Is not equal  ");

	for(counter=0;counter<n;counter++)
		printf("\n array 1 element no[%d] : %d",counter+1 , arr1[counter]);
	for(counter=0;counter<n2;counter++)
		printf("\n array 2 element no[%d] : %d",counter+1 , arr2[counter]);	
	return 0;
}
int comp(int arr1[],int arr2[] ,int n ,int n2)
{
	int counter;
	if( n==n2 )
		{
		for(counter=0;counter<n;counter++)
		{
			if(arr1[counter]!=arr2[counter])
				return 1;
		}
			return 0;
		}
	return 1;
}