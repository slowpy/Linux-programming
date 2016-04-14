#Makefile

export BUILD_PATH=$(shell pwd)/build
export CC=gcc
DRV_SRC_DIR	:= $(shell ls -d ./drv_src/*/)
SRC_DIR	:=$(DRV_SRC_DIR)

$(warning DRV_SRC_DIR=====>$(DRV_SRC_DIR))

all:
	@mkdir -p $(BUILD_PATH)
	for sdir in $(SRC_DIR) ; do \
    		make -C $$sdir || exit $?; \
	done

clean:
	@rm -rf $(BUILD_PATH)
	@rm -rf ./make.log
	for sdir in $(SRC_DIR) ; do \
    		make -C $$sdir clean || exit $?; \
	done
