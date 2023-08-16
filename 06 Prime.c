#include<stdio.h>
int main()
{
	int a,c=0;
	printf("Enter a number= ");
	scanf("%d", &a);
	for(int i=1;i<=a;i++)
	{
	   if(a%i==0){
	   
	   c++; 
}
	}
	if(c==2)
	    	printf("The number %d is prime",a);
	    else
	        printf("The number %d is not prime",a);
	return 0;
}