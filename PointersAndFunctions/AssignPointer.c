#include<stdio.h>

int main()
{
	  int *ip,*iq,i=10;

	  ip = &i;
	  printf("ip = %d.\n",*ip);
	  iq = ip;
	  printf("iq = %d.\n",*iq);

	  return 0;
}

