#Driver signal to app sample code
This sampe demo the driver how to signal information to user sapce app.

# How to setup build code environment
1. install build code tools
<pre>
sudo apt-get install build-essential
</pre>
2. check wehether kernel header files exist.
<pre>
ls /lib/modules/$(uname -r)/build
</pre>
3. if kernel header files doesn't exist, try to install them.
<pre>
sudo apt-get install linux-headers-$(uname -r)
</pre>

#Code Description
1. the driver `drv_caller.ko` has ioctl for `app_a` to set app_a process id: in the code ./driver_signal_to_app/drv_src/drv_caller/drv_caller.c
<pre>
static int drv_caller_ioctl(struct inode *inode, struct file *filp, unsigned int ioctl_num, unsigned long ioctl_param) {
...
        switch (ioctl_num) {
	        case IOCTL_SET_MSG:
		        printk("<1>drv_caller: enter IOCTL_SET_MSG\n");
		        copy_from_user(pData,(app_info*)ioctl_param,size);
		        g_pid=(int)(pData->pid);
...
} 
</pre>

2.  the driver `drv_caller.ko` has ioctl for `app_a` to setup timer to send signal: in the code: in the code ./driver_signal_to_app/drv_src/drv_caller/drv_caller.c
<pre>
...
    switch (ioctl_num) {
	    case IOCTL_SET_MSG:
....
		    setup_timer(&my_timer, my_timer_callback, 0);
            mod_timer(&my_timer, jiffies + msecs_to_jiffies(1000));
...
</pre>

3. the driver `drv_caller.ko` send signal to `app_a` pid: in the code ./driver_signal_to_app/drv_src/drv_caller/drv_caller.c
<pre>
void my_timer_callback( unsigned long data )
{
...
        p = pid_task(find_vpid(g_pid),PIDTYPE_PID);
...
	    ret = send_sig_info(SIG_TEST, &info, p);    //send the signal
...
</pre>
4.`app_a` register handler to receive `drv_caller.ko` signal:in the code ./driver_signal_to_app/app_src/app_a/app_a.c
<pre>
main(){
...
	    struct sigaction sig;
	    sig.sa_sigaction = receiveData;
	    sig.sa_flags = SA_SIGINFO;
	    sigaction(SIG_TEST, &sig, NULL);
...
</pre>

5. `app_a` set ioctl to `drv_caller.ko` to set pid and trigger timer: in the code ./driver_signal_to_app/app_src/app_a/app_a.c
<pre>
ioctl_set_msg(int file_desc)
{
	    int ret_val;
        app_info app_a_info;
         
        app_a_info.pid=getpid();
        log("pid:%d\n", app_a_info.pid);
        
	    ret_val = ioctl(file_desc, IOCTL_SET_MSG, &app_a_info);
...
</pre>
6. `app_a` use `pasue()` to wait driver signal:in the code ./driver_signal_to_app/app_src/app_a/app_a.c
<pre>
main(){
...
        while(1){
	        pause();
            count++;
        }
...
</pre>
 

#How to test
1. build code
<pre>$ mk.sh build</pre>
2. check `build` directory and find out build result 
<pre>
app_a - application which receive signal from drv_caller.ko
drv_caller.ko - driver which send signal to app_a
drv_caller.sh - script for install and uninstall driver
</pre>
3. install driver drv_caller.ko
<pre>
$ mk.sh install
</pre>
type `dmesg`, you will see below logs
<pre>
drv_caller: init
</pre>

4. run app_a to test
<pre>$ mk.sh test </pre>
type `dmesg`, you will see below logs
<pre>
drv_caller: ioctl
drv_caller: enter IOCTL_SET_MSG
drv_callee: export_hello() is called
drv_caller: close
</pre>

5. uninstall drivers
<pre>
$ mk.sh uninstall
</pre>
type `dmesg`, you will see below logs
<pre>
drv_caller: exit
</pre>

6. remove all build result
<pre>
$ mk.sh clean
</pre>


