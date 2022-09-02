#include<stdio.h>

void recurssion(int);

int main(void)
{
	int no;
	printf("Enter the number");
	scanf("%d",&no);
	recurssion(no);
	
	return 0;
}
/*void recurssion(int no)
{
	printf("%d ", no);
	if (no==0)
		return;

	return recurssion(no-1);
}*/
void recurssion(int no)
{
	int i=0;
	if (i <= no)
	{
		printf("%d ",i);
		recurssion(i+1);
	}
	return ;
}