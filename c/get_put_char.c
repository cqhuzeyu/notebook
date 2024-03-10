#include <stdio.h>
#include <stdlib.h>

int main ()
{
   char c;
 
   system("stty raw");
   printf("请输入字符：");
   c = getchar();
 
   printf("输入的字符：");
   putchar(c);
   system("stty cooked");

   return(0);
}
