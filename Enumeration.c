#include<stdio.h>
enum SWITCH{off , on };
enum COMBINATION{series=1 , parallel};

int main(void)
{
	enum COMBINATION ckt;
	enum SWITCH s1 , s2 ;
	printf(" Enter switch1 & switch2 ");
	scanf("%d%d",&s1 , &s2);
	printf("Enter The Combination Circuit SWITCH=1  PARALLEL=2: ");
	scanf("%d",&ckt);
	if(ckt == series)
	{
		if(s1==on && s2==on)
			printf("Bulb Will Glow");
		else 
			printf("Bulb Will Not Glow");
	}
	
	if(ckt == parallel)
	{
		if(s1==on || s2==on)
			printf("Bulb Will Glow");
		else 
			printf("Bulb Will Not Glow");
	}
	return 0;
}