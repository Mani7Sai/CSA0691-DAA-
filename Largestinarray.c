#include<stdio.h>
int main()
{
  int a[1000];
  int i,n;
  printf("Enter the size of the array= ");
  scanf("%d",&n);
  for (i=0;i<n;i++)
{
  scanf("%d", &a[i]);
}
  for (i=0;i<n;i++){
  printf("%d", a[i]);
}
  for (int i = 1; i < n; ++i) {
    if (a[0] < a[i]) {
      a[0] = a[i];
    }
  }

  printf("Largest element = %d", a[0]);


return 0;
}
