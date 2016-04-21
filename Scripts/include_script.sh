#!/bin/bash
. library.sh

#case 1:
port=4AE0
is_hex $port
show_result $?

#case 2:
port=xyz
is_hex $port
show_result $?

