#include<stdio.h>
int mystrlen(const char *);
int main(void)
{
	char *ptr="Hello";
	char str[]="Good";

	printf("\nThe Length Of Hello Is %d\n",mystrlen(ptr));
	printf("The Length Of Good Is %d\n",mystrlen(str));
	printf("The length of Morning Is %d\n",mystrlen("morning"));

	return 0;
}
int mystrlen(const char *str)
{
	int counter;
	for(counter=1;str[counter]!=NULL;counter++);
	return counter;
}