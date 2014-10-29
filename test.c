

#include "stdio.h"


int g;

void A(int n)
{
  g = n;
}

int x;

void R(int m)
{
  printf("%d\n",x);
  x = x /2;
  if(x >1)
    R(m+1);
  else
    A(m);
}

void B(int a)
{
  //int x;
  x = a*a;
  R(1);
}


int main()
{
    B(3);
    printf("%d\n",g);
    return 0;
}

