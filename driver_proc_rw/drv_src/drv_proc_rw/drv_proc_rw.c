/* drv_proc_rw.c */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>

MODULE_LICENSE("Dual BSD/GPL");

static struct proc_dir_entry *proc_rw;

static int proc_rw_read_proc (char *page, char **start, off_t off, int count,
			  int *eof, void *data_unused)
{
	printk("<1>drv_proc_rw: proc_rw_read_proc() enter\n");
/*
	int len=0;
	len = sprintf(page, "[pbi] nat type = %d\n", g_pesi_nat_type);
	return len;
*/
        return 0;
}

static int proc_rw_write_proc(struct file *file, const char *buffer, unsigned long count, void *data)
{
	printk("<1>drv_proc_rw: proc_rw_write_proc() enter\n");
    
/*
    char buf[8]={0};
    int len=count;

    if (copy_from_user(buf, buffer, len))
    {
        return -EFAULT;
    }	
	buf[len] = '\0';
	if ( buf[0] == '1'){
		g_pesi_nat_type=1;
		nvram_set(1,"NAT_TYPE","1");
		nvram_commit(1);
	}
	
	if ( buf[0] == '2' ){
		g_pesi_nat_type=2;
		nvram_set(1,"NAT_TYPE","2");
		nvram_commit(1);
	}
	
	if ( buf[0] == '3' ){
		g_pesi_nat_type=3;
		nvram_set(1,"NAT_TYPE","3");
		nvram_commit(1);
	}
	
	printk("[pbi] conntrack_write_proc, buf = %s(len=%d), nat type=%d\n",buf,len,g_pesi_nat_type);
	
	return len;
*/

    return 1;

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

