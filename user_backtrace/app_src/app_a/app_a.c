#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
 
void dump(int signo)
{
    void *array[30];
    size_t size;
    char **strings;
    size_t i;
 
    size = backtrace (array, 30);
    strings = backtrace_symbols (array, size);
 
    fprintf (stderr,"Obtained %zd stack frames.nm\n", size);
 
    for (i = 0; i < size; i++)
        fprintf (stderr,"%sn\n", strings[i]);
 
    free (strings);
 
    exit(0);
}

void func_c()
{
    * ((volatile char *) 0x0) = 0x999;
}
void func_b()
{
    func_c();
}
void func_a()
{
    func_b();
}

int main(){
    /*handle segmentation fault signal*/
    signal(SIGSEGV, dump);

    func_a();
}
