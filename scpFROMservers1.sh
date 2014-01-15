#!/usr/bin/env bash
#This script is written by "MortezaLSC" on Tuesday, 14 January 2014 10:55 PM
#It scps file from some servers to my machine.

while read ip dir; do
     sshpass -fpass1.txt scp -r root@$ip:/tmp/dir/test /user/path/to/$dir/
     wc -l /user/path/to/$dir/test
done <<____HERE
    1.1.1.1  1
    2.2.2.2  2
    3.3.3.3  3
    4.4.4.4  4
____HERE

while read ip dir; do
    sshpass -fpass2.txt scp -r root@$ip:/tmp/dir/test /user/path/to/$dir/
    wc -l /user/path/to/$dir/test
done <<____HERE
    5.5.5.5  5
    6.6.6.6  6
    7.7.7.7  7
    8.8.8.8  8
____HERE
