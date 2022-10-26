#include <stdio.h>

int main () {
   FILE *fp;
   char str[16];

   /* opening file for reading */
   fp = fopen("test1.hex" , "r");
   if(fp == NULL) {
      perror("Error opening file");
      return(-1);
   }
   if( fgets (str, 16, fp)!=NULL ) {
      /* writing content to stdout */
      do {
         puts(str);  
         
      } while (str != EOF);


      puts(str);
   }
   fclose(fp);
   
   return(0);
}
