/*ioctl.c*/
/* 
 * device specifics, such as ioctl numbers and the
 * major device file. 
 */
#include "chardev.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>		/* open */
#include <unistd.h>		/* exit */
#include <sys/ioctl.h>		/* ioctl */
#include <string.h>

/* 
 * Functions for the ioctl calls 
 */

ioctl_set_msg(int file_desc, char *message)
{
	int ret_val;

	ret_val = ioctl(file_desc, IOCTL_SET_MSG, message);

	if (ret_val < 0) {
		printf("ioctl_set_msg() failed:%d\n", ret_val);
		exit(-1);
	}
}

ioctl_get_msg(int file_desc)
{
	int ret_val;
	char message[100]={0};

	/* 
	 * Warning - this is dangerous because we don't tell
	 * the kernel how far it's allowed to write, so it
	 * might overflow the buffer. In a real production
	 * program, we would have used two ioctls - one to tell
	 * the kernel the buffer length and another to give
	 * it the buffer to fill
	 */
	ret_val = ioctl(file_desc, IOCTL_GET_MSG, message);

	if (ret_val < 0) {
		printf("ioctl_get_msg() failed:%d\n", ret_val);
		exit(-1);
	}

	printf("ioctl_get_msg():%s\n", message);
}

ioctl_get_nth_byte(int file_desc)
{
	int ret_val=0;
        char message[100]={0};

        ret_val = ioctl(file_desc, IOCTL_GET_NTH_BYTE, message);
	
	if (ret_val < 0) {
		printf("ioctl_get_nth_byte() failed:%d\n", ret_val);
		exit(-1);
	}
	printf("ioctl_get_nth_byte():%s\n", message);
}

int get_shell_cmd_result(char* cmd, char* res, int res_size){

    int len=0;
    char buf[256]={0};
    FILE* fp=NULL;
    
    fp=popen(cmd,"r");

    if(fp != NULL){
        while(fgets(buf,sizeof(buf),fp)){
            strncat(res,buf,res_size-strnlen(res,res_size));
        }
        pclose(fp);
    }
    else{
	return -1;
    }
    len=strnlen(res,res_size-1);
    res[len-1]=0;
    return 0;
}
/* 
 * Main - Call the ioctl functions 
 */
main()
{
	int file_desc, ret_val;
	char *msg = "Message passed by ioctl\n";
        char device_file[256]={0};  
       
        get_shell_cmd_result("cat ../../drv_src/drv_caller/chardev.h | grep '#define DEVICE_FILE' | cut -d '\"' -f 2", device_file, sizeof(device_file));
        printf("device file = %s\n",device_file);
	file_desc = open(device_file, 0);
	if (file_desc < 0) {
		printf("Can't open device file: %s\n", MODULE_NAME);
		exit(-1);
	}

	ioctl_get_nth_byte(file_desc);
	ioctl_get_msg(file_desc);
	ioctl_set_msg(file_desc, msg);

	close(file_desc);
}
