#include<stdio.h>
#define max 10
int comp(int[] ,int[], int ,int);
int main(void)
{
	int arr1[max];
	int arr2[max];
	int n ,n2,count, count2;
	for (count = 0 ; count < 2; count++)
	{
		printf("Enter how many elements you want to insert in array no.[ %d ]: ", count+1);
		scanf("%d",&n);	
		if (count<1)
			n2=n;			
		for (count2=0;count2<n;count2++)
			{
				printf("Enter element no %d :",count2+1);
				scanf("%d",&arr2[count2]);		
				if(count < 1)
					arr1[count2]=arr2[count2];	
			}
	}
	
		for(count2=0;count2<n2;count2++)
		printf("\n array 1 element no[%d] : %d",count2+1 , arr1[count2]);
	
		for(count2=0;count2<n;count2++)
		printf("\n array 2 element no[%d] : %d",count2+1 , arr2[count2]);
		n = comp(arr1 , arr2 ,n ,n2);
			if(n==0)
				printf("\n  Is equal \n");
			else
				printf("\n  Not equal \n");
	return 0;
}
int comp(int arr1[],int arr2[] ,int n ,int n2)
{
	int counter;
	if( n==n2 )
		{
		for(counter=0;counter<n2;counter++)
		{
			if(arr1[counter]!=arr2[counter])
				return 1;
		}
			return 0;
		}
	return 1;
}