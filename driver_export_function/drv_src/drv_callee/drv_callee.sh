#!/bin/bash
CHARDEV_H=../drv_src/drv_caller/chardev_callee.h
MODULE_NAME=`cat $CHARDEV_H | grep "#define MODULE_NAME" | cut -d "\"" -f 2`
MODULE=$MODULE_NAME.ko
DEVICE_FILE=`cat $CHARDEV_H | grep "#define DEVICE_FILE" | cut -d "\"" -f 2`
DRV_MAJOR_NUM=`cat $CHARDEV_H | grep "#define MAJOR_NUM" | cut -d " " -f 3`

case "$1" in
    "uninstall" )
        echo "uninstall..."
        sudo rmmod $MODULE_NAME
        sudo rm -rf $DEVICE_FILE ;;
    "install" )
        echo "install..."
        echo driver_major_number=$DRV_MAJOR_NUM
        sudo insmod $MODULE
	sudo mknod $DEVICE_FILE c $DRV_MAJOR_NUM 0
        sudo chmod 666 $DEVICE_FILE ;;
     *)
     echo "help : 'mk.sh install' to install driver or 'mk.sh uninstall' to uninstall driver" ;;
esac

