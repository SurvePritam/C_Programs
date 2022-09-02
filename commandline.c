#include<stdio.h>
int main(int argc , char *argv[])
{
	int ans;
	if (argc!=3)
	{
		printf("Parameter Count Is Wrong : progname no1 no2");
		return 0;
	}
	ans = atoi(argv[1]) + atoi(argv[2]);
	printf("Addition Is %d\n",ans);
	return 0;
}