//
//  main.c
//  4.2.1
//
//  Created by Дима Гузерчук on 19.04.21.
//

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main(int argc, const char * argv[]) {
//
//    char line[255];
//
//    while ((fgets(line,256,file)) != NULL) {
//        fputs(line, file);
//        printf("%s",line);
//    }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int check (char str[])
{
   int i,length;
    
   length=(int)strlen(str);
    
   for (i=0;i<length;i++)
      if (str[i]!=str[(length-1)-i]) return 0;
   return 1;
}
 
int main(void)
{
   FILE *file = fopen("test.txt", "r");
   char str[256];
   char* t;
   
    while ((fgets(str,256,file)) != NULL) {
            fputs(str, file);
        }
   t=strtok(str," ,");
   printf("\n");
    
   while (t != NULL) {
   if (check(t)==1) {
      printf("\nSlovo: %s",t);
      printf(" - Palindrome");
   }
   else {
      printf("\nSlovo: %s",t); printf(" - Not Palindrome");
   }
      t = strtok (NULL, " ,");
   }
    printf("\n");
    
    fclose(file);
   return 0;
}
