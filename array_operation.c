#include<stdio.h>
int main(void)
{
	int arr[5] = {10,20,30,40,50};

	printf("%d\n" , arr);
	printf("%d\n",&arr);

	printf("%d\n",arr + 1);
	printf("%d\n",&arr + 1);
	
	printf("%d\n",&arr[0]);
	printf("%d\n",arr[0]);
	printf("%d\n",arr[0] + 1);
	printf("%d\n",&arr[0] + 1);

	printf("%d\n",arr[1]);
	printf("%d\n",arr[1]+1);
	
	printf("%d\n",&arr[1]);
	printf("%d\n",&arr[1]+1);

	printf("%d\n",++arr[1]);
	printf("%d\n",arr[1]++);

	return 0;
}