#include<stdio.h>

char *mystrset(char * , char);
int main(void)
{
	char str[20], ch;

	printf("\n\nEnter The String:\t");
	gets(str);
	printf("\n\nEnter The Character To Set:\t");
	scanf("%c",&ch);

	mystrset(str , ch);

	printf("\n\nNow String Is:\t");
	puts(str);

	return 0;
}

char * mystrset(char * str , char ch)
{
	int counter=0;
	while(str[counter]!=NULL)
	{
		str[counter]=ch;
		counter++;
	}
	str[counter]=NULL;
}








