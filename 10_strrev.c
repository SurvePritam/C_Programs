#include<stdio.h>
char * mystrrev(char *);
int main(void)
{
	char string[20];

	printf("\n\nEnter The String:\t");
	gets(string);

	mystrrev(string);

	printf("\n\nReverce String Is:\t");
	puts(string);

	return 0;
}
char * mystrrev(char * str)
{
	int count , n=0;
	char destination[20];
	
	for(count=0;str[count]!=NULL;count++);	
	count--;

	while(count>=0)
	{
	destination[n]=str[count];
	n++;
	count--;
	};
	destination[n]=NULL;

	for(count=0;destination[count]!=NULL;count++)
		str[count]=destination[count];
	str[count]=NULL;

	return str;
}