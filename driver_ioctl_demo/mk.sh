#!/bin/bash
MODULE_NAME=`cat ./chardev.h | grep "#define MODULE_NAME" | cut -d "\"" -f 2`
MODULE=$MODULE_NAME.ko
DEVICE_FILE=`cat ./chardev.h | grep "#define DEVICE_FILE" | cut -d "\"" -f 2`
DRV_MAJOR_NUM=`cat ./chardev.h | grep "#define MAJOR_NUM" | cut -d " " -f 3`

case "$1" in
    "clean" )
        echo "make clean..."
        make clean
        sudo rmmod $MODULE_NAME
        sudo rm -rf $DEVICE_FILE ;;
    "build" )
        echo "make..."
        make
        echo driver_major_number=$DRV_MAJOR_NUM
        sudo insmod $MODULE
	sudo mknod $DEVICE_FILE c $DRV_MAJOR_NUM 0
        sudo chmod 666 $DEVICE_FILE ;;
     *)
     echo "help : 'mk.sh build' to build code or 'mk.sh clean' to remove all build result" ;;
esac

