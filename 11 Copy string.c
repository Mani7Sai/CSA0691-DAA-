#include<stdio.h>
#include<conio.h>
int main()
{
    char str1[20], str2[20];
    printf("Enter the string: ");
    scanf("%s", str1);
    printf("\nString 1 = %s", str1);
    strcpy(str2, str1);
    printf("\nString 2 = %s", str2);
    getch();
    return 0;
}