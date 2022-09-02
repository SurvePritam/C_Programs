#include<stdio.h>

int mystrcmp(const char *,const char *);
int main(void)
{
	char string1[20],string2[20];
	int ch;

	printf("\n\nEnter String1:\t");
	gets(string1);
	printf("\n\nEnter String2:\t");
	gets(string2);

	ch=mystrcmp(string1,string2);

	if(ch==0)
		printf("\n\nBoth Strings Are Same\n");
	else
		printf("\n\nBoth String Are Different\n");

	return 0;
}
int mystrcmp(const char *str1,const char *str2)
{
	int counter;
	for(counter=0;counter<20;counter++)
		if(str1[counter]!=str2[counter])
			return 1;
	return 0;
}