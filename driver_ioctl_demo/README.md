# Driver Ioctl Sample
This is a driver sample code to demo how to add and call driver ioctl: (test on Ubuntu 10.04)

# How to setup build code environment
1. install build code tools
<pre>
sudo apt-get install build-essential
</pre>
2. check wehether kernel header files exist.
<pre>
ls /lib/modules/$(uname -r)/build
</pre>
you will see result like below:
![result link](http://139.162.35.49/image/Linux-Programming/small_template_20160414.png)

3. if kernel header files doesn't exist, try to install them.
<pre>
sudo apt-get install linux-headers-$(uname -r)
</pre>


# Code Description
1.define driver `major number`, `device file` and `module name`: [chardev.h](https://github.com/ivan0124/Linux-programming/blob/master/driver_ioctl_demo/chardev.h)
<pre>
...
#define MAJOR_NUM 100
#define MODULE_NAME "hello"
#define DEVICE_FILE "/dev/hello"
...
</pre>

2.register `ioctl` function and `major number` in the driver: [hello.c](https://github.com/ivan0124/Linux-programming/blob/master/driver_ioctl_demo/hello.c)
<pre>
static struct file_operations hello_fops = {
    .open = hello_open,
    .release = hello_close,
    .ioctl = hello_ioctl,
    .read = hello_read,
    .write = hello_write,
};

static int hello_init(void) {
    
    int result=0;
    printk("<1>hello_driver: init\n");

    /* Register character device */
    result = register_chrdev(MAJOR_NUM, MODULE_NAME, &hello_fops);
</pre>

3.implement `ioctl` function: [hello.c](https://github.com/ivan0124/Linux-programming/blob/master/driver_ioctl_demo/hello.c)
<pre>
static int hello_ioctl(struct inode *inode, struct file *filp, unsigned int ioctl_num, unsigned long ioctl_param) {
  
    switch (ioctl_num) {
	case IOCTL_SET_MSG:
		printk("driver_hello: enter IOCTL_SET_MSG\n");
        copy_from_user(pData,(char*)ioctl_param,strlen((char*)ioctl_param));
       	printk("msg from user space: %s",pData);
		break;

	case IOCTL_GET_MSG:
		printk("driver_hello: enter IOCTL_GET_MSG\n");
		copy_to_user((char*)ioctl_param,msg,strlen(msg)+1);
		break;

	case IOCTL_GET_NTH_BYTE:
		printk("driver_hello: enter IOCTL_GET_NTH_BYTE\n");
		copy_to_user((char*)ioctl_param,msg,strlen(msg)+1);
		break;
    }


    return 0;
}
</pre>

4.install driver by `insmod` `module name` and create driver `device file` for user space app to access: [mk.sh](https://github.com/ivan0124/Linux-programming/blob/master/driver_ioctl_demo/mk.sh)
<pre>
...
 "build" )
        sudo insmod $MODULE
	    sudo mknod $DEVICE_FILE c $DRV_MAJOR_NUM 0
        sudo chmod 666 $DEVICE_FILE ;;
...        
</pre>

5.use space app open `device file`of the driver and set `ioctl` command to the driver.: [ioctl.c](https://github.com/ivan0124/Linux-programming/blob/master/driver_ioctl_demo/ioctl.c)
<pre>
ioctl_get_nth_byte(int file_desc)
{
...
         ret_val = ioctl(file_desc, IOCTL_GET_NTH_BYTE, message);
...         
}
...
main()
{
	int file_desc, ret_val;
	char *msg = "Message passed by ioctl\n";

	file_desc = open("/dev/hello", 0);
	if (file_desc < 0) {
		printf("Can't open device file: %s\n", MODULE_NAME);
		exit(-1);
	}

	ioctl_get_nth_byte(file_desc);
</pre>

6.uninstall driver by `rmmod` `module name`and delete driver `device file`: [mk.sh](https://github.com/ivan0124/Linux-programming/blob/master/driver_ioctl_demo/mk.sh)
<pre>
...
 "clean" )
        sudo rmmod $MODULE_NAME
        sudo rm -rf $DEVICE_FILE ;;
...        
</pre>

# How To Test 
1.build code and install driver
<pre>
$ ./mk.sh build 
</pre>

2.run ioctl to test
<pre>
$ ./ioctl
</pre>

3.uninstall driver
<pre>
$ mk.sh clean
</pre>

4.check the printk() log by typing `dmesg`
![test result link](http://139.162.35.49/image/Linux-Programming/20160327_driver_iotcl_demo.png)
