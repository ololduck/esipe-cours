#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * return 0 if char is not present in string
 * @param  c the char to check
 * @param  s the string to ceck the char in
 * @return   O if char not present, 1 if present
 */
int c_is_present(char c, char* s){
    int is_present = 0;
    int i = 0;
    for(i=0; i<strlen(s); i++){
        if(c == s[i]){
            is_present = 1;
            break;
        }
    }
    return is_present;
}

void work(char* to_trim){
    int c;
    int prevChar=0;
    while((c=fgetc(stdin)) != EOF) {
        int i=0;
        if(c_is_present((char)c, to_trim)){
            if(c != prevChar){
                prevChar = c;
                fputc(c, stdout);
            }
        }
        else {
            prevChar = c;
            fputc(c, stdout);
        }
    }
}
