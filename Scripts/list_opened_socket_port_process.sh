#!/bin/bash
. library.sh

list_opened_socket_port_process_info /proc/net/tcp
list_opened_socket_port_process_info /proc/net/udp
