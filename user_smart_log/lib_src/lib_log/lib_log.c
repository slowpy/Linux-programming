#include <stdio.h>

void print_app_name() {
 size_t linknamelen;
 char file[256], cmdline[256] = {0};

 sprintf(file, "/proc/%d/exe", getpid());
 linknamelen = readlink(file, cmdline, sizeof(cmdline) / sizeof(*cmdline) - 1);
 cmdline[linknamelen + 1] = 0;

 printf("[LOG][%s]", cmdline);
}

