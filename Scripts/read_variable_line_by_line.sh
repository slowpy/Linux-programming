#!/bin/bash

cat /proc/net/udp
#get list from /proc/net/udp
list=`cat /proc/net/udp`

while read line; do 
    echo LINE: "$line";
done <<< "$list"
