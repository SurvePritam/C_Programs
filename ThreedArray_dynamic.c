#include<stdio.h>
#include<malloc.h>
int main(void)
{
	int plane , row , column , counter1 , counter2, counter3;
	int ***p=NULL;
	printf("Enter no of plane  : ");
	scanf("%d",&plane);
	printf("Enter no of rows   : ");
	scanf("%d",&row);
	printf("Enter no of columns: ");
	scanf("%d",&column);
	

	p=(int ***) malloc(plane*sizeof(int **));				// Memory allocation Start.
	if(p==NULL)
	{
		printf("Memory Allocation FAILED");
		return -1;
	}
	for(counter1=0;counter1<plane;counter1++)
	{
		p[counter1]=(int **) malloc(row*sizeof(int *));
		if(p[counter1]==NULL)
		{
			printf("Memory Allocation FAILED");
			return -1;
		}
		for(counter2=0;counter2<row;counter2++)
		{
			p[counter1][counter2]=(int *)malloc(column*sizeof(int));
			if(p[counter1][counter2]==NULL)
			{
				printf("Memory Allocation FAILED");
				return -1;
			}
			for(counter3=0;counter3<column;counter3++)			
			{
				printf("Enter the Element No [%d][%d][%d] : ", counter1,counter2,counter3);		
				scanf("%d",&p[counter1][counter2][counter3]);					   //Memory Allocation,Assignment complete.
			}																	

		}
	
	}
	
	printf("Entered Elements : \n");					// Display.
	for(counter1=0;counter1<plane;counter1++)
		for(counter2=0;counter2<row;counter2++)
			{
				for(counter3=0;counter3<column;counter3++)
				{
					printf(" %d ",p[counter1][counter2][counter3]);					
				}
				printf("\n");
			}
		
											//Memory deallocation start.

		for(counter1=0;counter1<plane;counter1++)
		{
			for(counter2=0;counter2<row;counter2++)
				{
					free(p[counter1][counter2]);
					p[counter1][counter2]=NULL;
				}
			free(p[counter1]);
			p[counter1]=NULL;
		}

		free(p);						// Memory Deallocation Complete.
		p=NULL;		

	return 0;
}