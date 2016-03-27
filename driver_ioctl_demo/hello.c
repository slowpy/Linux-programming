/* hello.c */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include "chardev.h"

MODULE_LICENSE("Dual BSD/GPL");


static int hello_open(struct inode *inode, struct file *filp) {
    printk("<1>hello_driver: open\n");
    return 0;
}

static int hello_close(struct inode *inode, struct file *filp) {
    printk("<1>hello_driver: close\n");
    return 0;
}

static int hello_ioctl(struct inode *inode, struct file *filp, unsigned int ioctl_num, unsigned long ioctl_param) {
    
    printk("<1>hello_driver: ioctl\n");

    /* 
     * Switch according to the ioctl called  
     */
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

static ssize_t hello_read(struct file *filp, char *buf, size_t size, loff_t *f_pos) {
    printk("<1>hello_driver: read  (size=%zu)\n", size);
    return 0;
}

static ssize_t hello_write(struct file *filp, const char *buf, size_t size, loff_t *f_pos) {
    printk("<1>hello_driver: write  (size=%zu)\n", size);
    return size;
}

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
    if (result < 0) {
        printk("<1>hello_driver: Failed to register character device\n");
        return result;
    }
    return 0;
}

static void hello_exit(void) {
    printk("<1>hello_driver: exit\n");

    /* Unregister character device */
    unregister_chrdev(MAJOR_NUM, MODULE_NAME);
}

module_init(hello_init);
module_exit(hello_exit);

