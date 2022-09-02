#include<stdio.h>
#define max 10
void show(int * , int *, int);
int main(void)
{
	int arr1[max];
	int arr2[max];
	int n , counter;

	printf("Enter how many elements you want to insert (0 - 10) : ");
	scanf("%d",&n);
	
	for (counter=0; counter<n; counter++)
	{
		printf("Enter Element No [ %d ] : " , counter+1);
		scanf("%d",&arr1[counter]);
	}
	 show(arr1 , arr2 , n);
	 for(counter = 0;counter < n;counter++)
		 {
			 printf("  Array 1 Element no [ %d ] : %d \t Array 2 Element no [ %d ] : %d \n",counter+1 ,arr1[counter],counter+1 ,arr2[counter]);
		 }
	return 0;
}
void show(int *p1 , int *p2 , int n)
{
	int counter;
	for(counter=0 ; counter<n; counter++)
	{
		*p2=*p1;
		p1++;
		p2++;
	}
}