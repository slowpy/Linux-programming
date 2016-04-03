#driver Makefile
MODULE_NAME=drv_callee
#obj-m := -DEXPORT_SYMTAB
#obj-m := $(MODULE_NAME).o


ifneq ($(KERNELRELEASE),)
$(warning KERNELRELEASE=$(KERNELRELEASE)))
obj-m := -DEXPORT_SYMTAB #加载该参数的地方
obj-m := $(MODULE_NAME).o
else
KERNELDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)
#default:
#$(MAKE) -C $(KERNELDIR) M=$(shell pwd) modules

endif


ifeq ($(KERNELDIR),)
KERNELDIR=/lib/modules/$(shell uname -r)/build
endif

all:
	make -C $(KERNELDIR) M=$(shell pwd) modules
	@cp -rf $(MODULE_NAME).ko $(BUILD_PATH)
	@cp -rf $(MODULE_NAME).sh $(BUILD_PATH)

clean:
	make -C $(KERNELDIR) M=$(shell pwd) clean
