#!/bin/bash

if [ -z $1 ] ; then
    echo "usage: is_hex_number.sh [number]"
    exit 1
fi

port=$1
# set regular expression'
re='^[0-9A-Fa-f]+$'

# =~ means 'match'
if ! [[ $port =~ $re ]] ; then
    echo "error: $port not a number"
else
    echo "$port is a hex number"
fi
