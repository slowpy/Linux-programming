#!/bin/bash

hello(){
    echo "hello, fn."
    return 10
}

hello_a(){
    echo "input param=$1"
}

hello_b(){
    return 10
}

#hello() function return string
result="$(hello)"
echo "hello() return string ===> $result"

#hello_a() function input param
result="$(hello_a 123)"
echo "hello_a() return string ===> $result"

#function return code
hello_b
ret=$?
echo "hello_b() return code ===> $ret"
