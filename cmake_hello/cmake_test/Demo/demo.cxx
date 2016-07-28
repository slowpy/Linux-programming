#include <stdio.h>
#include "demo_b.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "demo_c.h"

#ifdef __cplusplus
}
#endif

int main( int argc, char* argv[])
{
    printf("Hello World\n");
    testFuncB();
    testFuncC();

    return 0;
}
