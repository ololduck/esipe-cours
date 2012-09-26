#include "work.h"

void help(){
    perror("Error: not enough args.\nExiting.\n");
}

int main(int argc, char* argv[]){
    if(argc>1){
        work(argv[1]);
        return 0;
    }
    else{
        help();
        return 1;
    }
}
