/*app_a.c*/
#include <stdio.h>
#include "lib_log.h"

int main( int argc, char* argv[])
{ 
    log("output smart log...(%s)(number=%d)\n", "hello",238); 
    return 0;
}
