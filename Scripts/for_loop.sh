#!/bin/bash

cat /proc/net/udp
#get port list from /proc/net/udp
port_list=`cat /proc/net/udp | awk -F":" '{print $3}' | awk '{print $1}'`
echo "port_list=$port_list"

#transform hex to decimal number 
for hex_port in $port_list; do
    if [ -n "$hex_port" ] ; then
        dec_port=$((0x$hex_port))
        echo "hex port: $hex_port ===> decimal port=$dec_port"
    fi
done
