/*app_a.c*/
#include "chardev.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>		/* open */
#include <unistd.h>		/* exit */
#include <sys/ioctl.h>		/* ioctl */
#include <signal.h>
#include "lib_common.h"

/* 
 * Functions for the ioctl calls 
 */

ioctl_set_msg(int file_desc)
{
	int ret_val;
        app_info app_a_info;
         
        app_a_info.pid=getpid();
        log("pid:%d\n", app_a_info.pid);
        
	ret_val = ioctl(file_desc, IOCTL_SET_MSG, &app_a_info);

	if (ret_val < 0) {
		log("ioctl_set_msg() failed:%d\n", ret_val);
		exit(-1);
	}
}

void receiveData(int n, siginfo_t *info, void *unused)
{
	log("received value %d\n", info->si_int);
}

/* 
 * Main - Call the ioctl functions 
 */
main()
{

	int file_desc, ret_val;
        char device_file[256]={0};

	struct sigaction sig;
	sig.sa_sigaction = receiveData;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIG_TEST, &sig, NULL);
 
        get_shell_cmd_result("cat ../drv_src/drv_caller/chardev.h | grep '#define DEVICE_FILE' | cut -d '\"' -f 2", device_file, sizeof(device_file));
        log("device file = %s\n",device_file);
	file_desc = open(device_file, 0);
	if (file_desc < 0) {
		log("Can't open device file: %s\n", MODULE_NAME);
		exit(-1);
	}

	ioctl_set_msg(file_desc);

	close(file_desc);
        
        int count=0;
        while(1){
	    pause();
            count++;
        }

}
