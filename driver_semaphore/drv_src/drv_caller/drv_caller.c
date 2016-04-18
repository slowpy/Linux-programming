/* drv_caller.c */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <asm/siginfo.h>//siginfo
#include "chardev.h"

MODULE_LICENSE("Dual BSD/GPL");

int g_pid=0;

static DECLARE_MUTEX(nvram_sem);

static int drv_caller_open(struct inode *inode, struct file *filp) {
    printk("<1>drv_caller: open\n");
    return 0;
}

static int drv_caller_close(struct inode *inode, struct file *filp) {
    printk("<1>drv_caller: close\n");
    return 0;
}

static int drv_caller_ioctl(struct inode *inode, struct file *filp, unsigned int ioctl_num, unsigned long ioctl_param) {
    
    int size=sizeof(app_info);
    app_info* pData=(app_info*)kmalloc(size,GFP_KERNEL);
    
    printk("<1>drv_caller: ioctl\n");
    
    if (!pData){
	printk("<1>hello_driver: kmalloc fail\n");
	return -1;
    } 
    
    /* 
     * Switch according to the ioctl called  
     */
    switch (ioctl_num) {
	case IOCTL_SET_MSG:
		down(&nvram_sem);
                printk("<1>drv_caller:===>%s(pid=%d)lock semaphore\n", current->comm, current->pid);
		copy_from_user(pData,(app_info*)ioctl_param,size);
		g_pid=(int)(pData->pid);
		printk("<1>drv_caller:set %s pid data=%d\n",current->comm, g_pid);
                printk("drv_caller:<===%s(pid=%d)unlock semaphore\n", current->comm, current->pid);
                up(&nvram_sem);
		break;

	case IOCTL_GET_MSG:
		printk("drv_caller: enter IOCTL_GET_MSG\n");
		break;

	case IOCTL_GET_NTH_BYTE:
		printk("drv_caller: enter IOCTL_GET_NTH_BYTE\n");
		break;
    }

    kfree(pData);
    return 0;
}

static ssize_t drv_caller_read(struct file *filp, char *buf, size_t size, loff_t *f_pos) {
    printk("<1>drv_caller: read  (size=%zu)\n", size);
    return 0;
}

static ssize_t drv_caller_write(struct file *filp, const char *buf, size_t size, loff_t *f_pos) {
    printk("<1>drv_caller: write  (size=%zu)\n", size);
    return size;
}


static struct file_operations caller_fops = {
    .open = drv_caller_open,
    .release = drv_caller_close,
    .ioctl = drv_caller_ioctl,
    .read = drv_caller_read,
    .write = drv_caller_write,
};

static int drv_caller_init(void) {
    
    int result=0;
    printk("<1>drv_caller: init\n");

    init_MUTEX(&nvram_sem);
    
    /* Register character device */
    result = register_chrdev(MAJOR_NUM, MODULE_NAME, &caller_fops);
    if (result < 0) {
        printk("<1>driver_caller: Failed to register character device\n");
        return result;
    }


    return 0;
}

static void drv_caller_exit(void) {
    printk("<1>drv_caller: exit\n");

    /* Unregister character device */
    unregister_chrdev(MAJOR_NUM, MODULE_NAME);
}

module_init(drv_caller_init);
module_exit(drv_caller_exit);

