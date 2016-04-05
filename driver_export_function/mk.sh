#!/bin/bash
VERBOSE=0

MAKE_START_TIME=`date +%s`

case "$1" in
	build)
	echo "make building..."
	if [ "$VERBOSE" == "0" ] ; then
   	     make > make.log 2>&1
	else
   	     make
	fi ;;
	clean)
	echo "make cleaning..."
	if [ "$VERBOSE" == "0" ] ; then
   	     make clean >> make.log 2>&1
	else
   	     make clean
	fi ;;
	install)
	cd ./build
	./drv_callee.sh install
	./drv_caller.sh install
	cd .. ;;
	uninstall)
	cd ./build
	./drv_caller.sh uninstall
	./drv_callee.sh uninstall
	cd .. ;;
	test)
	cd ./build
        export LD_LIBRARY_PATH=$(pwd)
	./app_a
	cd .. ;;
	*)
	echo "step1:'mk.sh build' to build code."
	echo "step2:'mk.sh install' to install drivers, then type 'dmesg' to see logs"
	echo "step3:'mk.sh test' to test, then type 'dmesg' to see logs"
	echo "step4:'mk.sh test' to test, then type 'dmesg' to see logs "
	echo "step2:'mk.sh clean to clean build result."
	exit -1 ;;
esac

if [ "$?" != "0" ] ; then
    echo "make $1 Fail!!!"
    echo "please check the make.log to debug"
else
    echo "make $1 OK."
fi

MAKE_END_TIME=`date +%s`
duration=$((MAKE_END_TIME-MAKE_START_TIME))
echo "$(($duration / 60)) minutes and $(($duration % 60)) seconds elapsed."
