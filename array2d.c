// Accepting 2 2d arr1ay values  and printing the addition
#include<stdio.h>
#define max 10
int main(void)

{
	int arr1[max][max];
	int arr2[max][max];
	int arr3[max][max];
	int n , i ,j , k;

	printf(" Enter Matrix size ( R * C ) " );
	scanf("%d",&n);
	
	for(k=0;k<2;k++)
	{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(k<1)
					{
						printf("Enter the Element of arr1ay 1 [%d] [%d]",i , j);
						scanf("%d",&arr1[i][j]);
					}
					if(k==1)
					{
						printf("Enter the Element of arr1ay 2 [%d] [%d]",i , j);
						scanf("%d",&arr2[i][j]);
					}
				}
			}
	}
	printf(" \n The First matrix  \n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf(" %d ",arr1[i][j]);
			}
			printf("\n");
		}
	printf(" \n The Second matrix  \n");
	for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf(" %d ",arr2[i][j]);
			}
			printf("\n");
		}
	printf(" \n The Addition of First and Second matrix  \n");
	for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			arr3[i][j]=arr1[i][j]+arr2[i][j];

	for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf(" %d ",arr3[i][j]);
			}
			printf("\n");
		}

	return 0;
}