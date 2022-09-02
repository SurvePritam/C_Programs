#include<stdio.h>

void recurssion1(int);
void recurssion2(int);
int main(void)
{
	int no;
	printf("Enter the number");
	scanf("%d",&no);		
	recurssion1(no);		
	recurssion2(no);		
	return 0;
}
void recurssion1(int no) 
{
	printf(" %d ", no);
	if (no==0)
	{
		printf("\n");
		return;
	}
	 recurssion1(no-1);
}

void recurssion2(int no)
{
	if(no>=0)
		recurssion2(no-1);
	else
		return;

printf(" %d ",no);
}
