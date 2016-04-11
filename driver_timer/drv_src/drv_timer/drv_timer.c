/* drv_timer.c */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/timer.h>

MODULE_LICENSE("Dual BSD/GPL");

static struct timer_list my_timer;
static int g_count=0;

void my_timer_callback( unsigned long data )
{
    /* do your timer stuff here */
    printk("<1>drv_timer: timer triggered(count=%d)\n",g_count);
    g_count++;

    /* setup your timer to call my_timer_callback */
    setup_timer(&my_timer, my_timer_callback, 0);
    /* setup timer interval to 1000 msecs */
    mod_timer(&my_timer, jiffies + msecs_to_jiffies(1000));

}


static int drv_timer_init(void) {
    printk("<1>drv_timer: init\n");
    /* setup your timer to call my_timer_callback */
    setup_timer(&my_timer, my_timer_callback, 0);
    /* setup timer interval to 1000 msecs */
    mod_timer(&my_timer, jiffies + msecs_to_jiffies(1000));
    return 0;
}

static void drv_timer_exit(void) {
    printk("<1>drv_timer: exit\n");
    /* remove kernel timer when unloading module */
    del_timer(&my_timer);
}

module_init(drv_timer_init);
module_exit(drv_timer_exit);

