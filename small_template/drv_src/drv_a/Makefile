#Hello driver Makefile
obj-m := hello.o

ifeq ($(KERNELDIR),)
KERNELDIR=/lib/modules/$(shell uname -r)/build
endif

all:
	make -C $(KERNELDIR) M=$(shell pwd) modules
	@cp -rf hello.ko $(BUILD_PATH)

clean:
	make -C $(KERNELDIR) M=$(shell pwd) clean
