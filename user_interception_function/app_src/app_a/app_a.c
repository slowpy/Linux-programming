/*app_a.c*/
#include <stdio.h>
#include "interception.h"

int main( int argc, char* argv[])
{
    malloc(100);
    return 0;
}
