//intialising 3D array
#include<stdio.h>

int main(void)
{
	int arr[3][3][3] ,i ,j,k;
	printf("Enter the Matrix Elements \n ");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			for(k=0;k<3;k++)
			{
				printf("Enter the Element [%d] [%d] [%d] : ",i,j,k);
				scanf("%d",&arr[i][j][k]);
			}

	printf("Array Element :  \n");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
				printf(" %d ",arr[i][j][k]);	
			
			printf("\n");
		}
}