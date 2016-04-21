#!/bin/bash
. library.sh

cat /proc/net/udp
#get list from /proc/net/udp
list=`cat /proc/net/udp`

while read line; do 
    #echo "LINE: $line";
    port=`echo $line | cut -d " " -f 2 | cut -d ":" -f 2`
    #echo "port: $port"
     
    port_valid=0;
    inode_valid=0;
    #check if it is hex number
    is_hex $port 
    if [ $? -eq 0 ] ; then
       #echo "$port is hex a number"
       #convert hex to decimal port
       decimal_port=$((0x$port))
       #echo "decimal port=$decimal_port"
       port_valid=1
    fi

    #check inode number
    inode=`echo $line | cut -d " " -f 10`
    #echo "inode===:$inode"
    is_decimal $inode
    if [ $? -eq 0 ] ; then
       #echo "$inode is decimal number"
       inode_valid=1
    fi

    #if port and indoe both valid, then find out process id
    if [ "$port_valid" == "1" ] && [ "$inode_valid" == "1" ] ; then
        #echo "both valid"
        find_pid $inode
        if [ "$?" != "0" ] ; then
            echo "inode is $inode,pid $pid. open port=$decimal_port"
        fi
    fi
        
done <<< "$list"
