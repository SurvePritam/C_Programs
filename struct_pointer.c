#include<stdio.h>

typedef struct result
	{
		char grade;
		float per;		
	}result;

void fun1(result , result * ,result *);

int main(void)
{	
	result stud1, stud2 , stud3;

	printf("Enter 1st students  Grade :  ");
	scanf("%c",&stud1.grade);
	printf("Enter 1st students Percentage :  ");
	scanf("%f",&stud1.per);
	printf(" Stud 1 data :  Grade = %c \t Percentage = %f \n",stud1.grade , stud1.per);

	fun1(stud1 , &stud2 , &stud3);	
	printf(" Stud 2 data :  Grade = %c \t Percentage = %f \n", stud2.grade , stud2.per);
	printf(" Stud 3 data :  Grade = %c \t Percentage = %f \n",stud3.grade , stud3.per);
	return 0;
}
void fun1(result stud1 , result *stud2 , result *stud3)
{
	*stud2 = stud1;
	stud3->grade = stud2->grade;
	stud3->per = stud2->per;
	
}