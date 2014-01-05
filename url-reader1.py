#!/usr/bin/python
#This program is written by "MortezaLSC" on Saturday, 30 March 2013 at 13:00 pm
#You get a list to program then it sends and requests packets to urls in each line of list then search 
#in source page.

import urllib2
f = open ("/home/lsc/test.txt")


for line in f:
        try:  
          request = urllib2.Request(line)
          request.add_header('User-agent', 'firefox')
          response = urllib2.urlopen(request)
          data = response.read(request)
          #print data
          if "word1" in data:
            with open("/home/lsc/test1.txt", "a") as myfile:
              myfile.write(line)
          elif "type=\"file\"" in data:
            with open("/home/lsc/test1.txt", "a") as myfile:
              myfile.write(line)
        except Exception:
          with opne("/home/lsc/test2.txt", "a") as myfile:
            myfile.write(line)
