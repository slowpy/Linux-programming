#Makefile

export BUILD_PATH=$(shell pwd)/build
export CC=gcc
APP_SRC_DIR   := $(shell ls -d ./app_src/*/)
LIB_SRC_DIR	:= $(shell ls -d ./lib_src/*/)
DRV_SRC_DIR	:= $(shell ls -d ./drv_src/*/)
SRC_DIR	:=$(DRV_SRC_DIR) $(LIB_SRC_DIR) $(APP_SRC_DIR)

$(warning APP_SRC_DIR=====>$(APP_SRC_DIR))
$(warning LIB_SRC_DIR=====>$(LIB_SRC_DIR))
$(warning DRV_SRC_DIR=====>$(DRV_SRC_DIR))

all:
	@mkdir -p $(BUILD_PATH)
	for sdir in $(SRC_DIR) ; do \
    		make -C $$sdir ; \
	done

clean:
	@rm -rf $(BUILD_PATH)
	for sdir in $(SRC_DIR) ; do \
    		make -C $$sdir clean ; \
	done
