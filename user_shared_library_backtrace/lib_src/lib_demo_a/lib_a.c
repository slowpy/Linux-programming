#include <stdio.h>
#include "lib_common.h"

test_lib_a(){
    log("test_lib_a() is called (in lib_a.c)\n");
    * ((volatile char *) 0x0) = 0x999;
    log("test_lib_a() is done (in lib_a.c)\n");
}

