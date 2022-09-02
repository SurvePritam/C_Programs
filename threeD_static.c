#include<stdio.h>
#define MAX 10
int main(void)
{
	int arr[MAX][MAX][MAX];
	int plane,row,column,counter1,counter2,counter3;

	printf("Enter How many Planes :");
	scanf("%d",&plane);
	printf("Enter How many Rows :");
	scanf("%d",&row);
	printf("Enter How many Columns :");
	scanf("%d",&column);
	
	for(counter1=0;counter1<plane;counter1++)
		for(counter2=0;counter2<row;counter2++)
			for(counter3=0;counter3<column;counter3++)
			{
				printf("Enter The Element No [%d][%d][%d] :",counter1,counter2,counter3);
				scanf("%d",&arr[counter1][counter2][counter3]);
			}
	
	printf("Entered Elements Are : \n");
	for(counter1=0;counter1<plane;counter1++)
		for(counter2=0;counter2<row;counter2++)
		{
			for(counter3=0;counter3<column;counter3++)
				printf(" %d ",arr[counter1][counter2][counter3]);
				
			printf("\n");
		}

	return 0;
}