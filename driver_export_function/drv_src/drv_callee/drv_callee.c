/* drv_callee.c */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include "chardev_callee.h"

MODULE_LICENSE("Dual BSD/GPL");


static int drv_callee_open(struct inode *inode, struct file *filp) {
    printk("<1>drv_callee: open\n");
    return 0;
}

static int drv_callee_close(struct inode *inode, struct file *filp) {
    printk("<1>drv_callee: close\n");
    return 0;
}

static int drv_callee_ioctl(struct inode *inode, struct file *filp, unsigned int ioctl_num, unsigned long ioctl_param) {
    
    printk("<1>drv_callee: ioctl\n");
    
    /* 
     * Switch according to the ioctl called  
     */
    switch (ioctl_num) {
	case IOCTL_SET_MSG:
		printk("drv_callee: enter IOCTL_SET_MSG\n");
		break;

	case IOCTL_GET_MSG:
		printk("drv_callee: enter IOCTL_GET_MSG\n");
		break;

	case IOCTL_GET_NTH_BYTE:
		printk("drv_callee: enter IOCTL_GET_NTH_BYTE\n");
		break;
    }

    return 0;
}

static ssize_t drv_callee_read(struct file *filp, char *buf, size_t size, loff_t *f_pos) {
    printk("<1>drv_callee: read  (size=%zu)\n", size);
    return 0;
}

static ssize_t drv_callee_write(struct file *filp, const char *buf, size_t size, loff_t *f_pos) {
    printk("<1>drv_callee: write  (size=%zu)\n", size);
    return size;
}

static struct file_operations caller_fops = {
    .open = drv_callee_open,
    .release = drv_callee_close,
    //.ioctl = drv_callee_ioctl,
    .read = drv_callee_read,
    .write = drv_callee_write,
};

static int drv_callee_init(void) {
    
    int result=0;
    printk("<1>drv_callee: init\n");

    /* Register character device */
    result = register_chrdev(MAJOR_NUM, MODULE_NAME, &caller_fops);
    if (result < 0) {
        printk("<1>driver_callee: Failed to register character device\n");
        return result;
    }
    return 0;
}

static void drv_callee_exit(void) {
    printk("<1>drv_callee: exit\n");

    /* Unregister character device */
    unregister_chrdev(MAJOR_NUM, MODULE_NAME);
}

module_init(drv_callee_init);
module_exit(drv_callee_exit);

