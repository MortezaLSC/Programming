#!/usr/bin/env bash
#This script is written by "MortezaLSC" on Saturday, 11 January 2014 at 8:20 AM
#If you want remove duplicated IPs from your file using sed command just run on of the following solutions in this script

##sed
#cat file.txt | while read IP ; do sed -i "/^${IP}$/d" duplicated.txt ; done

##uniq and sort
#sort -u file.txt > out.txt

##uniq without sorting
#uniq file.txt > out.txt

##awk
#awk '!a[$0]++' input.txt > out.txt
