// code for printing numbers from 0 to 5

#include<stdio.h>
int main(void)
{
	// with the help of " FOR LOOP "

	 method1();		// we're printing this with the normal method
		printf("\n");
	 method2();		// we're printing this with the first expression missing
		printf("\n");
	 method3();		// we're printing this with the second expression missing
		printf("\n");
	 method4();		// we're printing this with the third epression missing
		printf("\n");
	 method5();		// we're printing this with the first and second missing 
		printf("\n");
	 method6();		// we're printing this with the first and third expression missing i.e. " while loop"
		printf("\n");

	 // with the help of " WHILE LOOP "

		 printf("\n VIA WHILE LOOP :  ");
		method7();	// printing 0 to 5 with the help of while loop
		

	// with the help of DO WHILE LOOP

		printf("\n VIA DO WHILE LOOP :  ");
		
		method8();
		printf("\n");
	return 0;
}
	int method1()
	{
		int counter;
		for(counter=0 ; counter<6; counter++)
			printf("%d", counter );
			 
		return 0;
	}

	int method2()
	{
		int counter=0;
		for (; counter<6;counter++)
			printf("%d", counter);
	}

	int method3()
	{
		int counter;
		for (counter=0 ;  ; counter++)
			if (counter <6)
			printf("%d", counter);
			else
				break;
	}

	int method4()
	{
		int counter;
		for (counter=0 ; counter<6 ; )
		{
			printf("%d", counter);
			counter++;
		}
	}

	int method5()
	{
		int counter=0;
		for ( ; ; counter++)
		{
			if(counter<6)
				printf("%d", counter);
			else
				break;
		}


	}
		
	int method6()
	{
		int counter=0;
		for ( ; counter<6 ; )
		{
			printf("%d", counter);
			counter++;
		}
	}

	int method7()
	{
		int counter=0;
		while ( counter<6 )
		{
			printf("%d", counter);
			counter++;
		}
	}

	int method8()
	{
		int counter=0;
		do 
		{
			printf("%d", counter);
			counter++;
		}while (counter<6);
	}