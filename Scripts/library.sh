#!/bin/bash

#usage: is_hex A2
is_hex(){
    # set regular expresion'
    local reg_exp='^[0-9A-Fa-f]+$'

    # =~ means 'match'
    if [[ $1 =~ $reg_exp ]] ; then
        return 0
    else
        return 1
    fi
}

#usage: is_decimal 123
is_decimal(){
    # set regular expresion'
    local reg_exp='^[0-9]+$'

    # =~ means 'match'
    if [[ $1 =~ $reg_exp ]] ; then
        return 0
    else
        return 1
    fi
}

#usage: find_pid $indoe
#success: return pid
#fail: return 0
find_pid(){
   
    local inode=$1 
    local pid_valid=0

    #find belong which process id
    local pid_list=`sudo ls /proc`
    for pid in $pid_list; do
        echo -ne "inode is $1,checking pid=$pid...\r"
        #check pid. it must be a number
        pid_valid=0
        is_decimal $pid
        if [ $? -eq 0 ] ; then
            pid_valid=1
        fi

        #if /proc/#pid file exist, then find out socket inode
        if [ "$pid_valid" == "1" ] && [ -e "/proc/$pid" ] ; then
            #echo "inode=$inode"
            is_inode_found $pid socket $inode
            if [ $? -eq 0 ] ; then
                return $pid
            fi
        fi
    done
   
    return 0
}

<<COMMENT
usage: is_inode_found $pid $fd_type $inode
return code:
0: found 
1: not found
COMMENT

is_inode_found(){
    
    local list=`sudo ls /proc/$1/fd -al | grep $2`
    while read line; do 
        #echo "LINE: $line";
        local inode=`echo $line | cut -d " " -f 10 | cut -d "[" -f 2 | cut -d "]" -f 1`
        #echo "inode: $inode"
        if [ "$inode" == "$3" ] ; then
            return 0 #inode is found
        fi
    done <<< "$list"
    
    return 1 #inode not found
}

show_result(){

    if [ $1 -eq 0 ] ; then
        echo "function return SUCESS."
    else
        echo "function return FAIL"
    fi
}


#usage: list_opened_socket_port_process_info /proc/net/tcp
list_opened_socket_port_process_info(){
   
    echo "cat $1"
    cat $1
    local list=`cat $1`

    while read line; do 
        #echo "LINE: $line";
        local port=`echo $line | cut -d " " -f 2 | cut -d ":" -f 2`
        #echo "port: $port"
     
        local port_valid=0;
        local inode_valid=0;
        #check if it is hex number
        is_hex $port 
        if [ $? -eq 0 ] ; then
            #echo "$port is hex a number"
            #convert hex to decimal port
            local decimal_port=$((0x$port))
            #echo "decimal port=$decimal_port"
            port_valid=1
        fi

        #check inode number
        local inode=`echo $line | cut -d " " -f 10`
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
                local ps_name=`ps -p $pid -o comm=`
                echo "inode is $inode,$ps_name(pid=$pid). open socket port=$decimal_port(hex:$port)"
            fi
        fi
        
    done <<< "$list"
}

