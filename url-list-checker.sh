#This script is written by "MortezaLSC" on Saturdy, 18 January 2014 at 1:15 PM
#It gives url numbers from list file and download contents of each page in to the file and zip them.

#! /usr/bin/env bash

#yum install zip -y

num=`wc -l /tmp/list.txt | awk '{sum += $1} END {print sum}'`

for i in $(seq $num)
do
    touch /tmp/pages/$i.txt
done

#OR:
#awk '{system("touch /tmp/pages/"NR".txt")}' /tmp/list.txt  >> It touches files 

#Other command:
#awk '{print > NR".txt"}' list.txt

i=1
for line in $(cat list.txt)
do
   	wget $line --no-check-certificate -O /tmp/pages/$i.txt
	let i=i+1
done

#OR:
#i=1
#while read line
#do
#    wget $line --no-check-certificate -O /tmp/pages/$i.txt
#    let i=i+1
#done < list.txt

cd /tmp
zip -r pages.zip pages
