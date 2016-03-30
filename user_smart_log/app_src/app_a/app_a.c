/*app_a.c*/
#include <stdio.h>
/*
void print_app_name();

#define log(x, ...)  print_app_name();\
		     printf("[%s()]"x, __FUNCTION__,##__VA_ARGS__);

void print_app_name() {
 size_t linknamelen;
 char file[256], cmdline[256] = {0};

 sprintf(file, "/proc/%d/exe", getpid());
 linknamelen = readlink(file, cmdline, sizeof(cmdline) / sizeof(*cmdline) - 1);
 cmdline[linknamelen + 1] = 0;

 printf("[LOG][%s]", cmdline);
}
*/
int main( int argc, char* argv[])
{ 
    log("output smart log...(%s)(number=%d)\n", "hello",238); 
    //test_lib_a();
    return 0;
}
