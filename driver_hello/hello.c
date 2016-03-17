/* hello.c */
#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

static int hello_init(void) {
    printk("<1>hello_driver: init\n");
    return 0;
}

static void hello_exit(void) {
    printk("<1>hello_driver: exit\n");
}

module_init(hello_init);
module_exit(hello_exit);

