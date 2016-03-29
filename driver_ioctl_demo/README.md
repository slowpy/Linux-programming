# Driver Ioctl Sample
This is a driver sample code to demo how to add and call driver ioctl: (test on Ubuntu 10.04)

1.register ioctl function in the driver: check the code in the ./driver_ioctl_demo/hello.c
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

2.implement ioctl function: check the code in the ./driver_ioctl_demo/hello.c
<pre>
static int hello_ioctl(struct inode *inode, struct file *filp, unsigned int ioctl_num, unsigned long ioctl_param) {
  
    switch (ioctl_num) {
	    case IOCTL_SET_MSG:
		    printk("driver_hello: enter IOCTL_SET_MSG\n");
		    break;

	    case IOCTL_GET_MSG:
		    printk("driver_hello: enter IOCTL_GET_MSG\n");
		    break;

	    case IOCTL_GET_NTH_BYTE:
		    printk("driver_hello: enter IOCTL_GET_NTH_BYTE\n");
		    break;
    }

    return 0;
}
</pre>
3.calling ioctl: check the code int the ./driver_ioctl_demo/ioctl.c
<pre>
ioctl_get_nth_byte(int file_desc)
{
	printf("get_nth_byte message:");

  ioctl(file_desc, IOCTL_GET_NTH_BYTE, 0);

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
