#!/usr/bin/env python
#This program is written by "MortezaLSC" on Sunday, 31 March 2013 at 15:00 PM
#This program give a url list and then check the source of pages and also check if they are true or not

import urllib2
f = open ("./test.txt")

for line in f:
	try:
		request = urllib2.Request(line)		
   	        data = urllib2.urlopen(request).read()
                #print data
                if "word1" in data:
			with open("./test1.txt", "a") as myfile:
				myfile.write(line)
		elif "word2" in data:
      			with open("./test1.txt", "a") as myfile:
       			 	myfile.write(line)
# 	Exception part discards all kinds of error by appending URLs to file.									 
	except Exception:   
		with open("./test2.txt", "a") as myfile:
			myfile.write(line)

