#include<stdio.h>
#define max 100 
int recur(int , int []);
int i=0;
int main(void)
{
	int count;
	int arr[max];
	printf("Enter how many elements to insert : ");
	scanf("%d",&count);
	recur(count , arr);

return 0;
}

int recur(int count ,  int arr[])
{
	
	if(i < count)
	{
		
		printf("Enter array element no %d :" , i+1 );
		scanf("%d",&arr[i]);
		i++;
		return recur(count , arr);
	}
	i = 0;
	 if (i < count)
		{
			printf("array element no %d= %d " ,i+1 , arr[i]);
			i++;
			return recur(count , arr);
		}
	 return 0;
}