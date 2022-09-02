#include<stdio.h>
typedef struct comp
{
	char ch;
	int i;
}comp;

int compair(comp , comp);
int main(void)
{
	comp c1 , c2;
	int ans;
	printf("Enter a Character & a Number for First Object to compair  ");
	scanf(" %c%d", &c1.ch , &c1.i);

	printf("\n Enter a character & a Number for Second Object to compair  ");
	scanf(" %c%d", &c2.ch , &c2.i);
	//printf("Elements of the First object \n Character : %c  Number : %d" , c1.ch , c1.i);
	//printf("Elements of the Second  object \n Character : %c  Number : %d" , c2.ch , c2.i);

	ans = compair(c1 , c2);
	if (ans == 1)
		printf("Both are Equal \n");
	else
		printf("Not Equal \n");

	return 0;
}
int compair(comp c1 , comp c2)
{
	if ( c1.ch == c2.ch && c1.i==c2.i )
		return 1;
	return 0;
}