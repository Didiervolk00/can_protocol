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
        ch = fgetc(ptr);
        strncat(str, &ch, 1);
        ch_count++;
            
    } while (ch_count < sizeof(str));

    // char ascii_str[] = "Hello world!";
    //declare output string with double size of input string
    //because each character of input string will be converted
    //in 2 bytes
    int len = strlen(str);
    char hex_str[(len*2)+1];
    
    //converting ascii string to hex string
    string2hexString(str, hex_str);
    
    printf("ascii_str: %s\n", str);
    printf("hex_str: %s\n", hex_str);

    // printf("%s\n", str);
    // printf("%ld\n", sizeof(str));

    fclose(ptr);
    return 0;
}
