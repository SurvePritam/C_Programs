#include<stdio.h>
#include<string.h>
char * mystrstr(const char * , const char * );
int main(void)
{
	char string1[20] , string2[20] , *ptr ;
	

	printf("\n\nEnter The String:\t");
	gets(string1);
	printf("\n\nEnter The String To Be Found:\t");
	gets(string2);
	
	
	ptr=mystrstr(string1 , string2);
	
	if(ptr==NULL)
	{
		puts("\n\nString Is Not Found\n");
	}
	else
	{
		printf("\n\nString Is Found At %d Location\n",(ptr-string1)+1);
		printf("\n\nString Found In '%s'\n",ptr);
	}
	
	return 0;
}

char * mystrstr(const char *str1, const char *str2)
{
	int counter1 , temp;
	int counter2=0;
	for(counter1=0;str1[counter1]!=NULL;counter1++)
	{
		temp=counter1;
		if(str1[temp]==str2[counter2])
		{
			counter2=0;
			while(str1[temp]==str2[counter2] && str2[counter2]!=NULL && str1[temp]!=NULL)
			{
				temp++;
				counter2++;
			}
			if(str2[counter2]==NULL)
					return &str1[counter1];
		}
	}
	return NULL;
}








