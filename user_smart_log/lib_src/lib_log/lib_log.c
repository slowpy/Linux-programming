#include <stdio.h>
#include <string.h>

#define LOG_PREFIX "[LOG]"
static char g_app_name[256]={0};

void print_app_name() {

 if (strnlen(g_app_name,sizeof(g_app_name)-1) != 0 ){
     printf("%s[%s]", LOG_PREFIX, g_app_name);
     return;
 }

 size_t linknamelen;
 char file[256], cmdline[256] = {0};

 snprintf(file,sizeof(file), "/proc/%d/exe", getpid());
 linknamelen = readlink(file, cmdline, sizeof(cmdline) / sizeof(*cmdline) - 1);
 cmdline[linknamelen + 1] = 0;

 strncpy(g_app_name,cmdline,sizeof(g_app_name)-1);
 printf("%s[%s]", LOG_PREFIX, cmdline);
 
}

