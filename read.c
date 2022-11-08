// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void string2hexString(char* input, char* output)
{
    int loop;
    int i; 
    
    i = 0;
    loop = 0;
    
    while(input[loop] != '\0')
    {
        sprintf((char*)(output+i),"%02X", input[loop]);
        loop += 1;
        i += 2;
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
    int count = 0;
    int i, j;
    int len;
    int conversionCount = 0;
 
    ptr = fopen("test1.hex", "r");
 
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
 
    printf("content of this file are \n");
 
    do {
        //Load in data in strings of 8 bytes
        for(i = 0; i < 16; i++){
            ch = fgetc(ptr);
            strncat(str, &ch, 1);
        }

        int len = strlen(str);
        char hex_str[(len * 2) + 1];
        
        //converting ascii string to hex string
        string2hexString(str, hex_str);

        //Count the occurances of F, FF is empty space in HEX.
        for(j = 0; hex_str[j]; j++){
            if(hex_str[j] == 'F'){
            count++;
            }
        }

        //These need to be removed from the HEX str before being sent.
        len = strlen(hex_str);
        hex_str[len-count] = '\0';

        printf("hex_str: %s\n", hex_str);

        strcpy(str, "");

        conversionCount++;
        
    } while (ch != EOF);

    conversionCount = 0;

    return 0;
}
