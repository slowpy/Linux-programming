/* drv_callee.c */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include "chardev_callee.h"

MODULE_LICENSE("Dual BSD/GPL");

int export_hello(void) {
    printk("<1>drv_callee: export_hello() is called");
    return 0;
} 

static int drv_callee_init(void) {
    
    int result=0;
    printk("<1>drv_callee: init\n");
    return 0;
}

static void drv_callee_exit(void) {
    printk("<1>drv_callee: exit\n");
}

/*Export symbol*/
EXPORT_SYMBOL(export_hello);

module_init(drv_callee_init);
module_exit(drv_callee_exit);

