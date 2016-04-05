#driver Makefile
MODULE_NAME=drv_callee
obj-m := $(MODULE_NAME).o


ifeq ($(KERNELDIR),)
KERNELDIR=/lib/modules/$(shell uname -r)/build
endif

all:
	make -C $(KERNELDIR) M=$(shell pwd) modules
	@cp -rf Module.symvers ../drv_caller/
	@cp -rf $(MODULE_NAME).ko $(BUILD_PATH)
	@cp -rf $(MODULE_NAME).sh $(BUILD_PATH)

clean:
	make -C $(KERNELDIR) M=$(shell pwd) clean
