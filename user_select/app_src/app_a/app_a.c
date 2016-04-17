#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/select.h>


#define MAX_BUF 1024

int main()
{
    int fd=0;
    char * myfifo = "/tmp/myfifo";
    char buf[MAX_BUF];
    
    /*select variable*/
    fd_set fdset;
    int ready_fd;
    int nfds=0;



    while(1){
        /* open, read, and display the message from the FIFO */
        if ( mkfifo(myfifo, 0666) < 0 ){
            printf("mkfifo fail\n");
	    sleep(1);
	    continue;
        }
        fd = open(myfifo, O_RDONLY | O_NONBLOCK);

        nfds=fd+1;
        FD_ZERO(&fdset);
        FD_SET(fd,&fdset);
        if ((ready_fd = select(nfds,&fdset,NULL,NULL,NULL))<0){
            printf("select error\n");
        }
        else{
            if (FD_ISSET(fd,&fdset)){
    	        read(fd, buf, MAX_BUF);
    	        printf("[fd=%d]Received: %s\n", fd, buf);        
                close(fd);
                FD_CLR(fd,&fdset);
                /* remove the FIFO */
                unlink(myfifo);
            }
    	    else{
	        printf("[fd=%d]not received\n");
            }
        }
    }

    return 0;
}
