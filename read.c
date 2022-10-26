// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Driver code
void string2hexString(char* input, char* output)
{
    int loop;
    int i; 
    
    i=0;
    loop=0;
    
    while(input[loop] != '\0')
    {
        sprintf((char*)(output+i),"%02X", input[loop]);
        loop+=1;
        i+=2;
    }
    //insert NULL at the end of the output string
    output[i++] = '\0';
}

int main()
{
    FILE* ptr;
    char ch;
    char str[16];
    int ch_count = 0;
 
    ptr = fopen("test1.hex", "r");
 
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
 
    printf("content of this file are \n");
 
    do {
        for(int i = 0; i < 16; i++){
            ch = fgetc(ptr);
            strncat(str, &ch, 1);
        }
        // printf("%s\n", str);
        int len = strlen(str);
        char hex_str[(len*2)+1];
        
        //converting ascii string to hex string
        string2hexString(str, hex_str);

        printf("hex_str: %s\n", hex_str);
        strcpy(str, "");
        
    } while (ch != EOF);

    fclose(ptr);
    return 0;
}
