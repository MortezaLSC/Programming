#!/bin/bash
if [ "$#" -ne "1" ]; then
    echo "Usage: `basename $0` <input-file>"
    exit 1
fi
FILE=$1

{
echo "========:========:=======:=========="
echo "Username:Realname:Homedir:Loginshell"
echo "========:========:=======:=========="

IFS=:
while read line; do
    fields=($line)
    echo "${fields[0]}:${fields[4]}:${fields[5]}:${fields[6]}"
done < "$FILE"
} | column -nts:
