#driver Makefile
MODULE_NAME=hello
obj-m := $(MODULE_NAME).o

ifeq ($(KERNELDIR),)
KERNELDIR=/lib/modules/$(shell uname -r)/build
endif

all:
	make -C $(KERNELDIR) M=$(shell pwd) modules
	@cp -rf $(MODULE_NAME).ko $(BUILD_PATH)
	@cp -rf $(MODULE_NAME).sh $(BUILD_PATH)

clean:
	make -C $(KERNELDIR) M=$(shell pwd) clean
