#include<stdio.h>

char * mystrlwr(char *);
int main(void)
{
	char str[20];
	printf("\n\nEnter The String:\t");
	gets(str);

	mystrlwr(str);

	printf("\nString In Lower Case:\t");
	puts(str);

	return 0;
}
char * mystrlwr(char *str)
{
	int counter;
	for(counter=0;str[counter]!=NULL;counter++)
		if(str[counter]>=65&&str[counter]<=90)
			str[counter]=(char)str[counter] +32;
	
	return str;
}