#!/usr/bin/env bash
#This script is written by "MortezaLSC" on Sunday, 13 January 2013 at 9:00 PM

echo "**********************************************************************"
echo "**********************************************************************"
echo "   args     : [knock-port] [ssh-port] [user-name] [ip-address]"
echo "**********************************************************************"
echo "**********************************************************************"

read -p "Enter your values : " KNOCK SSH USER IPADDRESS
telnet $IPADDRESS $KNOCK 1>/dev/null 2>&1 &
pkill $!
ssh $USER@$IPADDRESS -p $SSH
exit 0	
