#include<stdio.h>
int main(void)
{
	int counter ,a;
	do 
	{
		printf("enter a number between 1 to 3");
		scanf("%d",&counter);
	
		switch (counter)
		{
			case 1:
				printf("one");
				break;
			case 2: 
				printf("two");
		
			case 3:
				printf("three");
				break;
			default :
				printf("wrong input");

		}

		printf("press 0 to continue \n");
		scanf("%d", &a);
	
	}while(a==0);
	
		
		return 0;
}