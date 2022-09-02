#include<stdio.h>
int main(void)
{
	// UNARY OPERATOR (++ , --)
	/*int arr[]={10,20,30,40,50};
	int *p=arr;
	printf("%d \n",&p);
	printf("%d \n",p);
	printf("%d \n",*p);

	p++;

	printf("%d \n",&p);
	printf("%d \n",p);
	printf("%d \n",*p);

	p--;
	
	printf("%d \n",&p);
	printf("%d \n",p);
	printf("%d \n",*p);*/

	// ADDITION OPERATOR ( pointer with literal constant)

	char arr[]={'A','B','C','D','E'};
	char *p=&arr[0];
	char *p2=&arr[4];

	printf(" %d \n",p);
	printf(" %d \n",*p);
	printf(" %d \n",p+3);
	printf(" %c \n",*p+3);
	printf(" %d \n",p);
	printf(" %d \n",*p);

	// ADDITION OPERATOR ( pointer with pointer)
	//printf(" %d \n",p+p2); -> Error address+address not possible

	//SUBTRACTION OPERATOR ( pointer with literal constant )
	printf(" %d \n",p);
	printf(" %d \n",*p);
	printf(" %d \n",p2-3);
	printf(" %c \n",*p2-3);
	printf(" %d \n",p);
	printf(" %d \n",*p);
	
	//SUBTRACTION OPERATOR( pointer with pointer )
	
	printf(" %d \n",p2-p);

	//MULTIPLICATION , DIVISION , MODULOUS
	//error same as addition of pointer
	return 0;
}