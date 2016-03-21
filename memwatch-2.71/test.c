
/*
**  NOTE: Running this program in a Win32 or Unix environment
**  will probably result in a segmentation fault or protection
**  error. These errors may be caused by MEMWATCH when it is
**  looking at memory to see if it owns it, or may be caused by
**  the test program writing to memory it does not own.
**
**  MEMWATCH has two functions called 'mwIsReadAddr()' and
**  'mwIsSafeAddr()', which are system-specific.
**  If they are implemented for your system, and works
**  correctly, MEMWATCH will identify garbage pointers and
**  avoid causing segmentation faults, GP's etc.
**
**  If they are NOT implemented, count on getting the core
**  dumped when running this test program! As of this writing,
**  the safe-address checking has been implemented for Win32
**  and ANSI-C compliant systems. The ANSI-C checking traps
**  SIGSEGV and uses setjmp/longjmp to resume processing.
**
**  Note for Win95 users: The Win32 IsBadReadPtr() and its
**  similar functions can return incorrect values. This has
**  not happened under WinNT, though, just Win95.
**
**  991009 Johan Lindh
**
*/

#include <stdio.h>
#include "string.h"
#include "memwatch.h"


int main()
{
    char *p;
    char *p1;
      
    p = malloc(3);
    strcpy(p,"1234");

    p1 = malloc(100);

    return 0;
}

