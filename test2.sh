#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Usage: `basename $0` <absolute-path> <number>"
    exit 1
fi

if [ "$(id -u)" != "0" ]; then
    echo "This script must be run as root" 1>&2
    exit 1
fi


find $1 >> /tmp/test
for line in $(cat `/tmp/test`); do
    echo $line | mv $2 awk -F"/" `'{for (i = 1; i < NF; i++) if ($i == "$2") print $(i-1)}'`
done
