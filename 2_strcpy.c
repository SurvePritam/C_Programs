#include<stdio.h>
char * mystrcpy(char * , const char *);
int main(void)
{
	char source[20];
	char destination[20];

	printf("\n\nEnter Source String: \t");
	gets(source);
	printf("\n\nSource String Is:\t");
	puts(source);

	mystrcpy(destination,source);
	
	printf("\n\nDestination String Is:\t");
	puts(destination);

	return 0;
}
char * mystrcpy(char *dest , const char *src)
{
	int counter;
	for(counter=0;src[counter]!=NULL;counter++)
		{
			*dest=*src;
			dest++;
			src++;
		}
	dest[counter]=NULL;
	return dest;
}