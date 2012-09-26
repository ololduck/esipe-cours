#include <stdio.h>
#include <stdlib.h>

void work(void){
    int c;
    while((c=fgetc(stdin)) != EOF) {
        fputc(toupper(c), stdout);
    }
}
