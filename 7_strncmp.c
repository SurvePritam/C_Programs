#include<stdio.h>

int mystrncmp(const char *,const char *,int);
int main(void)
{
	char string1[20],string2[20];
	int ch,n;

	printf("\n\nEnter String1:\t");
	gets(string1);
	printf("\n\nEnter String2:\t");
	gets(string2);
	printf("\n\nEnter n:\t");
	scanf("%d",&n);
	ch=mystrncmp(string1,string2,n);

	if(ch==0)
		printf("\n\nBoth Strings Are Same\n");
	else
		printf("\n\nBoth String Are Different\n");

	return 0;
}
int mystrncmp(const char *str1,const char *str2,int n)
{
	int counter=0;
	while(counter<n)
	{
		if(str1[counter]!=str2[counter] )
			return 1;

		if( str1[counter]==NULL || str2[counter]==NULL)
			break;
		counter++;
	}
	
	return 0;
}