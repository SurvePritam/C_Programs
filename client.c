#include"server.h"

int main(void)
{
	int ans;
	struct demo obj;
	obj.no1=10;
	obj.no2=20;
	ans = obj.no1 + obj.no2;
	printf("%d" , ans);
}