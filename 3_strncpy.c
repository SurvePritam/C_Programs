#include<stdio.h>
#include<string.h>
char * mystrncpy(char * , const char *);
int main(void)
{
	int n;
	char source[20];
	char destination[20];

	printf("\n\nEnter Source String: \t");
	gets(source);
	printf("\n\nEnter Value Of n:\t");
	scanf("%d",&n);

	printf("\n\nSource String Is:\t");
	puts(source);

	mystrncpy(destination,source,n);
	
	printf("\n\nDestination String Is:\t");
	puts(destination);

	return 0;
}
char * mystrncpy(char *dest , const char *src, int n)
{
	int counter;
	for(counter=0;counter<n;counter++)
		dest[counter]=src[counter];
	dest[counter]=NULL;
	return dest;
}