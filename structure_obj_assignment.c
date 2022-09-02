#include<stdio.h>

typedef struct result
	{
		char grade;
		float per;		
	}result;

result fun1(result);
result fun2(result);

int main(void)
{	
	result stud1 , stud2 , stud3;

	printf("Enter 1st students  Grade :  ");
	scanf("%c",&stud1.grade);
	printf("Enter 1st students Percentage :  ");
	scanf("%f",&stud1.per);

	printf(" Stud 1 data :  Grade = %c \t Percentage = %f \n",stud1.grade , stud1.per);

	stud2 = fun1(stud1);			// student 2 data. (copy from student 1) [direct assign = ]
	printf(" Stud 2 data :  Grade = %c \t Percentage = %f \n", stud2.grade , stud2.per);
	
	stud3 = fun2(stud2);			// student 3 data. (copy from student 2) [member by member assign]
	printf(" Stud 3 data :  Grade = %c \t Percentage = %f \n",stud3.grade , stud3.per);
	return 0;
}

result fun1(result stud1)
{
	result stud2;
	stud2 = stud1;	
	return stud2;
}
result fun2(result stud2)
{
	result stud3;
	stud3.grade = stud2.grade ;
	stud3.per = stud2.per;
	return stud3;
}