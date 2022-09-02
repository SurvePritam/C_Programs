#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int **p=NULL;
	int row,column,counter1,counter2;
	
	printf("Enter the No of Rows : ");
	scanf("%d",&row);
	printf("Enter the No of columns : ");
	scanf("%d",&column);

	p=(int **) malloc (row*sizeof(int *));
	if(p==NULL)
	{
		printf("Memory Allocation FAILED");
		return -1;
	}
	for(counter1=0;counter1<row;counter1++)
	{
		p[counter1]=(int *)malloc(column*sizeof(int));
		if(p[counter1]==NULL)
		{
			printf("Memory Allocation FAILED");
			return -1;
		}
		for (counter2=0;counter2<column;counter2++)
		{
			printf("Enter element [%d][%d] : ",counter1,counter2);
			scanf("%d",&p[counter1][counter2]);
		}

	}
	printf(" Entered matrix \n");
	for(counter1=0;counter1<row;counter1++)
	{
		for(counter2=0;counter2<column;counter2++)
			printf(" %d ",p[counter1][counter2]);
		printf("\n");
	}
	if(p!=NULL)
	{
		for(counter1=0;counter1<row;counter1++)
		{
			p[counter1]=NULL;
			free(p[counter1]);
		}
	}
	
	free(p);
	p=NULL;

return 0;
}