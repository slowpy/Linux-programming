
#ifndef __LIB_COMMON_H__
#define __LIB_COMMON_H__

void print_app_name();
int get_shell_cmd_result(char* cmd, char* res, int res_size);

#define log(x, ...)  print_app_name();\
		     printf("[%s()]"x, __FUNCTION__,##__VA_ARGS__);

#endif
