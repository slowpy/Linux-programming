#Hello driver Makefile
obj-m := hello.o

ifeq ($(KERNELDIR),)
KERNELDIR=/lib/modules/$(shell uname -r)/build
endif

all:
	make -C $(KERNELDIR) M=$(shell pwd) modules
	gcc -o ioctl ioctl.c

clean:
	make -C $(KERNELDIR) M=$(shell pwd) clean
	rm -rf ./*.o ioctl
