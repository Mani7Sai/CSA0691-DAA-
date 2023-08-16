#include<stdio.h>
int fact(int a)
{
   if(a==0)
      return 1;
   else if(a==1)
      return 1;
  else 
      return (a*fact(a-1));
}
int main()
{
  int a,i;
  printf("Enter the number to know the factorial= ");
  scanf("%d", &a);
     printf("%d", fact(a));
  return 0;
}
