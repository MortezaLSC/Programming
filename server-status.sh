#!/bin/bash 
#This script is written by "MortezaLSC" at Sunday, 2 February 2014 at 3:16 PM

rm -f /tmp/whole.txt      1>/dev/null 2>/dev/null
rm -f /tmp/res-ok.txt     1>/dev/null 2>/dev/null
rm -f /tmp/res-failed.txt 1>/dev/null 2>/dev/null

echo "***********************************************"
echo "*+++++++++++++++++++++++++++++++++++++++++++++*"
echo "*+                                           +*"
echo "*+      PINGING SERVERS: Is UP OR DOWN       +*"
echo "*+                                           +*"
echo "*+++++++++++++++++++++++++++++++++++++++++++++*"
echo "***********************************************"

echo " ================                 ============ "
echo "|   IP ADDRESS   |               |   STATUS   |"
echo " ================                 ============ "

while read ip; do
    ping $ip -s 1 -c 1 1>/dev/null 2>&1
    if [ $? -eq 0 ]; then
        echo "  $ip                      UP"
        echo $ip >> /tmp/res-ok.txt
    elif [ $? -ne 0 ]; then
        echo "  $ip                      DOWN"
        echo $ip >> /tmp/res-failed.txt
    fi
echo "-----------------------------------------------"

done <<____HERE

____HERE

cat /tmp/res-ok.txt >> /tmp/whole.txt
cat /tmp/res-failed.txt >> /tmp/whole.txt

total=`wc -l /tmp/whole.txt | awk '{sum += $1} END {print sum}'`
ok=`wc -l /tmp/res-ok.txt | awk '{sum += $1} END {print sum}'`
failed=`wc -l /tmp/res-failed.txt | awk '{sum += $1} END {print sum}'`

echo "TOTAL: $total"
echo "UP:    $ok"
echo "DOWN:  $failed"
