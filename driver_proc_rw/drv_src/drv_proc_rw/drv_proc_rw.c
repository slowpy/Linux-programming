/* drv_proc_rw.c */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h> //for copy_from_user()

MODULE_LICENSE("Dual BSD/GPL");

char g_proc_rw_type[256]={0};
static struct proc_dir_entry *proc_rw;

static int proc_rw_read_proc (char *page, char **start, off_t off, int count,
			  int *eof, void *data_unused)
{
	printk("<1>drv_proc_rw: proc_rw_read_proc() enter\n");

	int len=0;
	len = sprintf(page,"<1>drv_proc_rw: proc_rw_type=%s\n", g_proc_rw_type);
	return len;

}

static int proc_rw_write_proc(struct file *file, const char *buffer, unsigned long count, void *data)
{
    printk("<1>drv_proc_rw: proc_rw_write_proc() enter\n");
    
    char buf[256]={0};
    int len=count;

    memset(g_proc_rw_type,0,sizeof(g_proc_rw_type));
    if (copy_from_user(g_proc_rw_type, buffer, len))
    {
        printk("<1>drv_proc_rw: copy_from_user fail\n");
        return -EFAULT;
    }	

    g_proc_rw_type[len-1]=0;	
    printk("<1>drv_proc_rw: input buffer = %s(len=%d), set proc_rw_type OK.\n",g_proc_rw_type, strlen(g_proc_rw_type));
	
    return len;
}

static int drv_proc_rw_init(void) {
    printk("<1>drv_proc_rw: init\n");
    if ((proc_rw = create_proc_entry( "proc_rw_type", 0, NULL ))){
        proc_rw->read_proc = proc_rw_read_proc;
        proc_rw->write_proc = proc_rw_write_proc;
    }
    return 0;
}

static void drv_proc_rw_exit(void) {
    printk("<1>drv_proc_rw: exit\n");
    remove_proc_entry("proc_rw_type", NULL);
}

module_init(drv_proc_rw_init);
module_exit(drv_proc_rw_exit);

