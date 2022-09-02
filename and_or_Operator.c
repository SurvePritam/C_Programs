#include<stdio.h>
int main(void)
{
	// AND OPERATOR (&&)
	int no1=0;
	int no2=1;
	int no3=2;
	int ans;
	int n1=0;
	int n2=1;
	int n3=2;
	int answ;

	ans = no1&&no2++&&++no3;
	printf("\n %d \n %d \n %d \n %d\n",no1,no2,no3,ans);


	// OR OPERATOR (||)

	answ = n1||n2++||++n3;
	printf("\n %d \n %d \n %d \n %d\n",n1,n2,n3,answ);
	return 0;
// ans = 1 because ans is stoaring the result of && || operation so the ans will be in boolean format 
	// the second term n2++ got neglected because in && operation the result can be concluded with the first operand
	// so if the first operand is 0 it dont even check the other operand 

}
