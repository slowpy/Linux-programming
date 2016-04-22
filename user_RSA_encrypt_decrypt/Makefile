#Makefile

export BUILD_PATH=$(shell pwd)/build
export CC=gcc
APP_SRC_DIR   := $(shell ls -d ./app_src/*/)
SRC_DIR	:=$(COM_LIB_SRC_DIR) $(APP_SRC_DIR)

$(warning APP_SRC_DIR=====>$(APP_SRC_DIR))

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
