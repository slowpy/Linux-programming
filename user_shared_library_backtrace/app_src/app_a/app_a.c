#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

 
void dump(int signo)
{
    void *array[30];
    size_t size;
    char **strings;
    size_t i;

    char cmd[1024]={0};
    snprintf(cmd,sizeof(cmd),"cat /proc/%d/maps",getpid());
    system(cmd);
 
    size = backtrace (array, 30);
    strings = backtrace_symbols (array, size);
 
    fprintf (stderr,"Obtained %zd stack frames.nm\n", size);
 
    for (i = 0; i < size; i++)
        fprintf (stderr,"%sn\n", strings[i]);
 
    free (strings);
 
    exit(0);
}


int main(){
    /*handle segmentation fault signal*/
    signal(SIGSEGV, dump);

    test_lib_a();    
}
