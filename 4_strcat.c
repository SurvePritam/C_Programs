#include<stdio.h>

char * mystrcat(char * , const char *);
int main(void)
{
	char source[20],destination[40];
	
	printf("\n\nEnter Destination String:\t");
	gets(destination);
	printf("\n\nEnter Source String:\t");
	gets(source);

	mystrcat(destination,source);
	
	printf("\n\nConcatenated String Is:\t");
	puts(destination);

	return 0;
}
char * mystrcat(char *destination , const char *source)
{
	int counter,counter1;
	for(counter=0;destination[counter]!=NULL;counter++);
	for(counter1=0;source[counter1]!=NULL;counter1++,counter++)
		destination[counter]=source[counter1];
	
	destination[counter]=NULL;
	return destination;

}