#include<stdio.h>
int main(void)
{
	int no=10;
	int i=10;
	int ans;
	int pre , post;
	int ii=10;
	int answer;
	printf("%d\n",no);
	no++;
	printf("%d\n",no);
	++no;
	printf("%d\n",no);
	ans=++no;
	printf("%d\n",no);
	printf("%d\n",ans);
	ans=no++;
	printf("%d\n",no);
	printf("%d\n",ans);
	printf("%d\n",++no);
	printf("%d\n",no++);


	post= i++; // ithe i chi value vadhli pn adhi assign zali
	printf("%d post :\n",post); // 10
	pre=++i;
	printf("%d pre : \n",pre); // mhnun yach output he 12 aal


	printf("%d\n",+ +post);
	printf("%d\n",+ +10);
	
	// BEGINING OF DECREMENT OPERATOR ( - - )
	printf("\n\n\n this is minus operatoe\n\n\n");
	
	printf("%d\n",ii);
	--ii;
	printf("%d\n",ii);
	ii--;
	printf("%d\n",ii);
	answer=ii--;
	printf("%d\n",ii);
	printf("%d\n",answer);
	answer=--ii;
	printf("%d\n",ii);
	printf("%d\n",answer);
	printf("%d\n",ii--);
	printf("%d\n",ii);
	printf("%d\n",--ii);
	printf("%d\n",ii);


	return 0;
}