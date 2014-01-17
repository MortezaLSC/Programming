#!/bin/bash
#This script is written by "MortezaLSC" on Teusday, 29 January 2013 at 5:05 PM
#Short description: This script gives a logfile usually from /var/log/YourLogFile and then check if it is modified or not.
#After that it shows you the modifications.

GAP=10     #How long to wait
LOGFILE=$1 #File to log to

if [ "$#" -ne "1" ]
    then
    echo "USAGE: ./watch-log.sh <file with absolute path>"
exit 1
fi


#Get current long of the file
len=`wc -l $LOGFILE | awk '{ print $1 }'`
echo "Current size is $len lines."

while :
do
    if [ -N $LOGFILE ] 
        then
        echo "`date`: New Entries in $LOGFILE: "
        newlen=`wc -l $LOGFILE | awk ' { print $1 }'`
        newlines=`expr $newlen - $len`
        tail -$newlines $LOGFILE
        len=$newlen
        fi
sleep $GAP
done
exit 0
