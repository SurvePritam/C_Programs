#include<stdio.h>

char * mystrupr(char *);
int main(void)
{
	char str[20];
	printf("\n\nEnter The String:\t");
	gets(str);

	mystrupr(str);

	printf("\nString In Upper Case Is:\t");
	puts(str);

	return 0;
}
char * mystrupr(char *str)
{
	int counter;
	for(counter=0;str[counter]!=NULL;counter++)
		if(str[counter]>=97)
			str[counter]=(char)str[counter] -32;
	
	return str;
}