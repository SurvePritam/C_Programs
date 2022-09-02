#include<stdio.h>

int addition(int , int);
int subtraction(int , int);
int multiplication(int , int);
int division(int , int);
int modulous(int , int);

int main(void)
{
	int no , no1 , no2;
	do
	{
		printf(" Enter no of action to perform \n 1 . Addition \n 2 . Subtraction \n 3 . Multiplication \n 4 . Division \n 5 . Modulous \n 6 . Exit \n");
		scanf("%d",&no);
		if(no>0 && no<6)
		{
			printf("Enter two numbers");
			scanf("%d%d",&no1,&no2);
		}

		switch(no)
		{	
			case 1:
				printf("addition = %d \n",addition(no1 , no2));
				break;
			case 2:
				printf("Subtraction = %d \n",subtraction(no1 , no2));
				break;
			case 3:
				printf("Muliplication = %d \n", multiplication(no1 , no2));
				break;
			case 4:
				printf("Division = %d \n", division(no1 , no2));
				break;
			case 5:
				printf("Modulous = %d \n", modulous(no1 , no2));
				break;
			case 6:
				break;
			default:
				printf("Please enter valid entry \n");
		}
	}while(no!=6);

	return 0;
}
 
int addition(int no1 , int no2)
{
	return no1 + no2 ;
}
int subtraction(int no1 , int no2)
{
	return no1 - no2 ;
}
int multiplication(int no1 , int no2)
{
	return no1 * no2 ;
}
int division(int no1 , int no2)
{
	return no1 / no2 ;
}
int modulous(int no1 , int no2)
{
	return no1 % no2 ;
}