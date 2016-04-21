#!/bin/bash

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

show_result(){

    if [ $1 -eq 0 ] ; then
        echo "$port is hex number"
    else
        echo "$port is NOT hex number"
    fi
}

#case 1:
port=4AE0
is_hex $port
show_result $?

#case 2:
port=xyz
is_hex $port
show_result $?

