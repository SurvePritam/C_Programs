#include<stdio.h>
int main(void)
{
	int choice , ans , no1 , no2;
	printf("1 . ADDITION \n2 . SUBTRACTION \n3 . MULTIPLICATION \n4 . DIVISION \n");
	printf("Enter The No of Action To Perform \t");
	scanf("%d", &choice);
	if(choice==1)
	{
		printf("Enter two no");
		scanf("%d%d" ,&no1,&no2);
		ans = add(no1,no2);
		printf(" addition is \t %d \n",ans);
	}
	else if(choice==2)
	{
		printf("Enter two no");
		scanf("%d%d" ,&no1,&no2);
		ans=sub(no1,no2);
		printf("subtraction is \t %d \n",ans);
	}
	else if(choice==3)
	{
		printf("Enter two no");
		scanf("%d%d" ,&no1,&no2);
		ans=mult(no1,no2);
		printf("multiplication is \t %d \n",ans);
	}
	else if(choice==4)
	{
		printf("Enter two no");
		scanf("%d%d" ,&no1,&no2);
		ans=div(no1,no2);
		printf("Division is \t %d \n",ans);
	}
	else
	return 0;
}
int add(int no1,int no2)
{
	return no1+no2;
}
int sub(int no1, int no2)
{
	return no1-no2;
}
int mult(int no1, int no2)
{
	return no1*no2;
}
int div(int no1, int no2)
{
	return no1/no2;
}