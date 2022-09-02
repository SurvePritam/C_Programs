#include<stdio.h>
int main(void)
{
	int n=10;
	int *p=&n;
	int **q=&p;
	int ***r=&q;

	printf("%d \n",n);
	printf("%d \n",&n);
	printf("%d \n",p);
	printf("%x \n",&p);
	printf("%x \n",q);
	printf("%d \n",*q);
	printf("%d \n",**q);
	printf("%d \n",&(**q));
	printf("%d \n",**r);
	printf("%d \n",***r);
	printf("%d \n",++(*p));
	printf("%d \n",*(&(*p)));
	return 0;
}

/*  pointer ha ek derived data type ahe jo address store krto, 
	pointer jya chya kde point krto to datatype ahe , jo datatypr ahe tyachyakde fakt pointer ch point kru shkto. 
	pointer mde adress ch asto , adress ha fakt pointer mdech asto.
	pointer 2 resons sathi vaprla jato. 1. jya memory la nav nahi tila axess krnyasathi 2. je memory scope mde nahi ti access krnyasathi
	pointer cha type hA , pointer ch asto , to jyala point krto tyach nav int , char , void vegere ast.
	pointer size he fixed aste karan to fakt addresch store krto , he size eka range mde aste jiki machine/processor vr depend aste , jr 16 bit astel 2byte. 
*/