# Linux user space daemon sample
This is a simple linux daemon for demo.

step1: fork and terminate parent: [daemon.c](https://github.com/ivan0124/Linux-programming/blob/master/user_daemon/daemon.c)
<pre>
  if ( (pid = fork()) != 0)
  exit(0);
</pre>
step2: become session leader (child has different group ID from parent): [daemon.c](https://github.com/ivan0124/Linux-programming/blob/master/user_daemon/daemon.c)
<pre>
setsid();
</pre>
refs: http://applezu.netdpi.net/2014/02/setsid.html

step3:ignore SIGHUP signal: [daemon.c](https://github.com/ivan0124/Linux-programming/blob/master/user_daemon/daemon.c)
<pre>
signal(SIGHUP, SIG_IGN);
</pre>
step4: fork and terminate parent to avoid zmobie process: [daemon.c](https://github.com/ivan0124/Linux-programming/blob/master/user_daemon/daemon.c)
<pre>
if ( (pid = fork()) != 0)
        exit(0);   
</pre>
step5:change working directory as (/): [daemon.c](https://github.com/ivan0124/Linux-programming/blob/master/user_daemon/daemon.c)
<pre>
chdir("/");
</pre>
step6:clear our file mode creation mask: [daemon.c](https://github.com/ivan0124/Linux-programming/blob/master/user_daemon/daemon.c)
<pre>
umask(0);
</pre>
step7:close all file description: [daemon.c](https://github.com/ivan0124/Linux-programming/blob/master/user_daemon/daemon.c)
<pre>
for (i=0; i < MAXFD;i++)
    close(i);
</pre>
step8:print log in syslog
<pre>
syslog(LOG_INFO, "daemon example ... %d", ii--);
</pre>

# How To Test
1. type `make` to build code.
2. run daemon
3. check /var/log/syslog, then you can see log like below...
![daemon test result link](http://139.162.35.49/image/Linux-Programming/Screenshot 2016-03-17_1.png)

