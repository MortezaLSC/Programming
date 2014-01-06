#!/usr/bin/env bash
#This script is written by "MortezaLSC" on Sunday, 13 January 2013 at 8:56 PM

echo "**********************************************************************"
echo "**********************************************************************"
echo "   [directory] [knock-port] [ssh-port] [user-name] [ip-address]"
echo "**********************************************************************"
echo "**********************************************************************"

read -p "Enter your values: " DIR KNOCK SSH USER IPADDRESS
telnet $IPADDRESS $KNOCK 1>/dev/null 2>&1 &
pkill -KILL $!
scp -P $SSH -r $DIR $USER@$IPADDRESS:/tmp
exit 0
