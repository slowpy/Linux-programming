#!/bin/bash
VERBOSE=0

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


if [ "$?" != "0" ] ; then
    echo "make $1 Fail!!!"
else
    echo "make $1 OK."
fi
