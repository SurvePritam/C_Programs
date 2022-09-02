#include<stdio.h>

char * mystrchr(const char * , char );
int main(void)
{
	char str[20], ch;
	char *ptr;

	printf("\n\nEnter The String:\t");
	gets(str);
	printf("\n\nEnter The Character To Be Found:\t");
	scanf("%c",&ch);
	
	ptr=mystrchr(str , ch);

	if(ptr==NULL)
		printf("\n\nCharacter Is Not Found\n");
	else
		printf("\n\nCharacter Is Found At %d Location\n",(ptr-str)+1);

	return 0;
}

char * mystrchr(const char *str , char ch)
{
	int counter;
	for(counter=0;str[counter]!=NULL;counter++)
		if (str[counter]==ch)
			return &str[counter];

	return NULL;

	
}








