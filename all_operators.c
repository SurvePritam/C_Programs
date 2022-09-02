#include<stdio.h>
int main(void)
{
	int no1=0;
	int no2=1;
	int no3=2;
	int ans;
	int ans2; // for bitwise
	int ans3; // for comma operator
 
	// combination of arithmatic increment and logical AND operator 
	// the term no2++ got neglacted caus of AND && and doesent check the remain i.e operand 2
	
	ans=no1&&no2++ && ++no3; 
	printf("%d\n%d\n%d\n%d\n", no1,no2,no3,ans);
	
	// combination of arithmatic increment and logical AND , OR operator 
	
	ans2 =no1 && no2++ || ++no3;
	printf("%d\n%d\n%d\n%d\n", no1,no2,no3,ans2);

	// lets try the bitwise operators 
	// outputs are getting wrong need to figure out why

	printf("%d\n  20 AND 14 : ", 20 & 14); // this is suppose to be 4
	printf("%d\n  20 OR 14 : " , 20 | 14); // this one 30
	printf("%d\n  20 XOR : " , 20 ^ 14); // this one 26
	printf("%d\n  NOT : ", ~20); // at least something

	// lets just move to the next one , comma operator
	
	ans3= ++no1 || ++no2 && no3++;
	printf("\n%d\n%d\n%d\n%d\n", no1,no2,no3,ans3);
	return 0;
}