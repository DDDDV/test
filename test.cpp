#include <stdio.h>
#include <iostream>
void Fputs(){
    char line[20] = "xuliang\n";
    fputs(line, stdout);
}

void byteorder(){
    union{
        short s;
        char c[sizeof(short)];
    }un;
    un.s = 0x0102;
    if(sizeof(short) == 2){
        if(un.c[0] == 1&& un.c[1] == 2){
            std::cout << "big end" << std::endl; 
        }
        else if(un.c[0] == 2&& un.c[1] == 1){
            std::cout << "little end" << std::endl; 
        }
    }
    std::cout << "sizeof(short)" << sizeof(short) << std::endl;
}

int main(){
    byteorder();
    return 0;
}