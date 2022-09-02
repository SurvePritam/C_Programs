#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int *p , n , counter;
	printf("Enter How many elements you want to insert");
	scanf("%d",&n);
	p = (int *) malloc(n*sizeof(int));
	if(p==NULL)
	{
		printf("Memory allocation FAILED");
		return -1;
	}
	for(counter=0;counter<n;counter++)
	{
		printf("Enter element no [%d]: " , counter+1);
		scanf("%d",&p[counter]);
	}

	for(counter=0;counter<n;counter++)
	{
		printf(" element no [%d] : %d \n" , counter+1 , p[counter]);	
	}
	free(p);
	p=NULL;
	
	return 0; 
}