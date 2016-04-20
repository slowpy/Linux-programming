/* mmap.c */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include "lib_common.h"

int main(int argc, char* argv[]){
    struct stat sb;
    off_t len;
    char* p;
    int fd;
    
 
    log("open test.txt\n");
    fd = open("./test.txt", O_RDONLY);
    if (fd == -1){
        log("open test.txt...[FAIL]\n");
	return -1;
    }
    log("open test.txt...[OK]\n");

    if ( fstat(fd, &sb) == -1 ){
        log("get file information(sb.st_size, sb.st_mode...)...[FAIL]\n");
	return -1;
    }
    log("get file information(sb.st_size, sb.st_mode...)...[OK]\n");

    if (!S_ISREG(sb.st_mode)){
        log("check if the file is regular file... [FAIL]\n");
	return -1;
    }
    log("check if the file is regular file... [OK]\n");

    p = mmap(0, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (p==MAP_FAILED){
        log("memory mapping file... [FAIL]\n");
	return -1;
    }
    log("memory mapping file... [OK]\n");

    if (close(fd) == -1){
	return -1;
    }

    log("starting read file and show content ======>\n");
    for (len=0; len < sb.st_size; len++)
        putchar(p[len]);
    log("finishing read file and show content <======\n");

    if (munmap(p, sb.st_size) == -1){
	return -1;
    }

    return 0;
}
