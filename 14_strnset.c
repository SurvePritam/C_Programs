#include<stdio.h>

char *mystrnset(char * , char,int);
int main(void)
{
	char str[20], ch;
	int n;

	printf("\n\nEnter The String:\t");
	gets(str);
	printf("\n\nEnter The Character To Set:\t");
	scanf("%c",&ch);
	printf("\n\nEnter The Value Of n:\t");
	scanf("%d",&n);
	
	mystrnset(str,ch,n);

	printf("\n\nNow String Is:\t");
	puts(str);

	return 0;
}

char * mystrnset(char * str , char ch , int n)
{
	int counter;
	for(counter=0;str[counter]!=NULL;counter++);
	if(counter<n)
		n=counter;
	for(counter=0;counter<n;counter++)
		str[counter]=ch;
}








