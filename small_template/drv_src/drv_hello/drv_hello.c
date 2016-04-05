/* drv_hello.c */
#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

static int drv_hello_init(void) {
    printk("<1>drv_hello: init\n");
    return 0;
}

static void drv_hello_exit(void) {
    printk("<1>drv_hello: exit\n");
}

module_init(drv_hello_init);
module_exit(drv_hello_exit);

