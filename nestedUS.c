#include<stdio.h>
/*int main(void)
{
	struct outer
	{
		char i;
		float f;
		union inner
		{
			int c;
			double d2;
		}iobj;

	}oobj;

	printf("size of = %d",sizeof(oobj));
	return 0;
}*/

// self referential structure
int main()
{
	struct demo
	{
		int i;
		struct demo *d;
	}obj;

	printf("size = %d",sizeof(obj));
	return 0;
}