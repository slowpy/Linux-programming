/*hello.c*/
#include <stdio.h>

int main( int argc, char* argv[])
{
    printf("Hello World\n"); 
    testFuncA();
    testFuncA1();
    //calling function in library
    test_lib_a();
    test_lib_a1();
    return 0;
}
