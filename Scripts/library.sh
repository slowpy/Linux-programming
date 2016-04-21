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
        echo "function return SUCESS."
    else
        echo "function return FAIL"
    fi
}

