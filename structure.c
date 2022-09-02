#include<stdio.h>
 struct demo 
	 {
		 int i;
		 double d;
	 }d1={1,81.80};
 int main(void)
 {
	 struct demo d2= {2 , 56.00};
	 struct demo d4 = d2;
	 union demo 
	 {
		 int i;
		// double i;
		 double d;
	 };
	 typedef union demo dd;
	 dd d3;
	 d3.i = 3;
	 d3.d = 61.16;

	 printf("size = %d \n", sizeof(d1));
	 printf("size = %d \n", sizeof(d2));
	 printf("d1.i = %d d1.d =  %lf \n", d1.i , d1.d);
	  printf("d2.i = %d d2.d =  %lf \n", d2.i , d2.d);
	  printf("copy of d2 : d4.i = %d d4.d =  %lf \n", d4.i , d4.d);

	 printf("size = %d\n", sizeof(union demo)); // size wirhout creating object
	 printf("size = %d\n", sizeof(d3));
	  printf("d3.i = %d d3.d =  %lf", d3.i , d3.d); // d3.i is garbage because at a time 1 i.e. union rule
	
	 
	 return 0;
 }