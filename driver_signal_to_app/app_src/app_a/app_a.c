/*app_a.c*/
#include "chardev.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>		/* open */
#include <unistd.h>		/* exit */
#include <sys/ioctl.h>		/* ioctl */


/* 
 * Functions for the ioctl calls 
 */

ioctl_set_msg(int file_desc)
{
	int ret_val;
        app_info app_a_info;
         
        app_a_info.pid=getpid();
        printf("pid:%d\n", app_a_info.pid);
        
	ret_val = ioctl(file_desc, IOCTL_SET_MSG, &app_a_info);

	if (ret_val < 0) {
		printf("ioctl_set_msg() failed:%d\n", ret_val);
		exit(-1);
	}
}


/* 
 * Main - Call the ioctl functions 
 */
main()
{
	int file_desc, ret_val;
        char device_file[256]={0};  
       
        get_shell_cmd_result("cat ../drv_src/drv_caller/chardev.h | grep '#define DEVICE_FILE' | cut -d '\"' -f 2", device_file, sizeof(device_file));
        printf("device file = %s\n",device_file);
	file_desc = open(device_file, 0);
	if (file_desc < 0) {
		printf("Can't open device file: %s\n", MODULE_NAME);
		exit(-1);
	}

	ioctl_set_msg(file_desc);

	close(file_desc);
}
