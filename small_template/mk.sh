#!/bin/bash
VERBOSE=0

MAKE_START_TIME=`date +%s`

case "$1" in
	build)
	if [ "$VERBOSE" == "0" ] ; then
   	     make > make.log 2>&1
	else
   	     make
	fi ;;
	clean)
	if [ "$VERBOSE" == "0" ] ; then
   	     make clean >> make.log 2>&1
	else
   	     make clean
	fi ;;
	*)
	echo "'mk.sh build' to build code. 'mk.sh clean to clean build result'"
	exit -1;
esac

MAKE_END_TIME=`date +%s`

duration=$((MAKE_END_TIME-MAKE_START_TIME))
echo "$(($duration / 60)) minutes and $(($duration % 60)) seconds elapsed."

if [ "$?" != "0" ] ; then
    echo "make $1 Fail!!!"
else
    echo "make $1 OK."
fi
