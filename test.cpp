#include <stdio.h>
#include <iostream>
void Fputs(){
    char line[20] = "xuliang\n";
    fputs(line, stdout);
}
/**
 * @brief 当多个数据需要共享内存或者多个数据每次只取其一时，可以利用联合体(union)。在C Programming Language 一书中对于联合体是这么描述的：

     1)联合体是一个结构；

     2)它的所有成员相对于基地址的偏移量都为0；

     3)此结构空间要大到足够容纳最"宽"的成员；

     4)其对齐方式要适合其中所有的成员；

下面解释这四条描述：

     由于联合体中的所有成员是共享一段内存的，因此每个成员的存放首地址相对于于联合体变量的基地址的偏移量为0，即所有成员的首地址都是一样的。为了使得所有成员能够共享一段内存，
     因此该空间必须足够容纳这些成员中最宽的成员。对于这句“对齐方式要适合其中所有的成员”是指其必须符合所有成员的自身对齐方式。
 * 
 */
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