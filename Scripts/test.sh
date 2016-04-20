#!/bin/bash

cat /proc/net/udp
#get list from /proc/net/udp
list=`cat /proc/net/udp`

while read line; do 
    echo "LINE: $line";
    port=`echo $line | cut -d " " -f 2 | cut -d ":" -f 2`
    #echo "port: $port"
     
    #check if it is hex number
    re='^[0-9A-Fa-f]+$'
    if [[ $port =~ $re ]] ; then
       #echo "$port is hex a number"
       #convert hex to decimal port
       decimal_port=$((0x$port))
       #echo "decimal port=$decimal_port"
    fi

    #check inode number
    inode=`echo $line | cut -d " " -f 10`
    echo "inode===:$inode"
    re='^[0-9]+$'
    if [[ $inode =~ $re ]] ; then
       echo "$inode is decimal number"

       #find belong which process id
       pid_list=`sudo ls /proc`
       #echo "pid_list=$pid_list"
       for pid in $pid_list; do
           echo "pid=$pid"
           #check pid. it must be a number
           re='^[0-9]+$'
           if [[ $pid =~ $re ]] ; then
               echo "match re pid====$pid"
               #if /proc/#pid file exist, then find out socket inode
               if [ -e "/proc/$pid" ] ; then
                   list_socket=`sudo ls /proc/$pid/fd -al`
                   echo "list_socket=$list_socket"
               fi
           fi
       done
    fi
        
done <<< "$list"
