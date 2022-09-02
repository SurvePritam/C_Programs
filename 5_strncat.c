#include<stdio.h>

char * mystrncat(char * , const char *,int);
int main(void)
{
	char source[20],destination[40];
	int n;
	
	printf("\n\nEnter Destination String:\t");
	gets(destination);
	printf("\n\nEnter Source String:\t");
	gets(source);
	printf("\n\nEnter Value Of n:\t");
	scanf("%d",&n);
	
	mystrncat(destination,source,n);
	
	printf("\n\nConcatenated String Is:\t");
	puts(destination);

	return 0;
}
char * mystrncat(char *destination , const char *source, int n)
{
	int counter,counter1;
	for(counter=0;destination[counter]!=NULL;counter++);
	for(counter1=0;counter1<n;counter1++,counter++)
		destination[counter]=source[counter1];
	
	destination[counter]=NULL;
	return destination;

}