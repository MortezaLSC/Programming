#!/bin/bash
#This script is written by "MortezaLSC" on Friday, 24 January 2014 at 1:00 PM
#First of all it creates files for each server. After that it connects to all of them automatically and copy file2 from
#them to file1 on my machine.

while read file1 pass port user host file2; do
    touch /tmp/$file1 
    sshpass -p$pass scp -P $port $user@$host:/tmp/$file2 /tmp/$file1
done <<___HERE
file1 pass port user host file2
___HERE
