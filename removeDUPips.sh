#!/usr/bin/env bash
#This script is written by "MortezaLSC" on Saturday, 11 January 2014 at 8:20 AM
#If you want to remove duplicated IPs from your file using sed command just run this script

cat FILE1.txt | while read IP ; do sed -i "/^${IP}$/d" FILE2.txt ; done
