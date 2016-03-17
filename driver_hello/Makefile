#Hello driver Makefile
obj-m := hello.o

ifeq ($(KERNELDIR),)
KERNELDIR=/lib/modules/4.4.0-13-generic/build
endif

all:
	make -C $(KERNELDIR) M=$(PWD) modules

clean:
	make -C $(KERNELDIR) M=$(PWD) clean
