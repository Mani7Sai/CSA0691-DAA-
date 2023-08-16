#include<stdio.h>
int fibbno(int n)
{
 if(n==0)
  return 0;
 else if(n==1)
  return 1;
 else
  return fibbno(n - 1) + fibbno(n- 2);
}
int main()
{
   int n,i;
   printf("Enter the range =");
   scanf("%d", &n);
   for(i=0;i<n;i++)
   {
   printf("%d",fibbno(i));
   }
   return 0;
}

