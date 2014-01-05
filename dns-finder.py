#!/usr/bin/python
from multiprocessing import Lock
from optparse import OptionParser
from netaddr import *
import sys
import dns.query
import dns.message
import time
import socket
import os
import threading
import resource
from time import gmtime ,strftime
from Queue import Queue
from threading import Thread


if not os.geteuid() == 0:
	sys.exit('Run program as root')

lim=resource.getrlimit(resource.RLIMIT_NOFILE)
filim=(pow(2,14),pow(2,14))
resource.setrlimit(resource.RLIMIT_NOFILE,filim)

#filename="DNS" 
#logname="DNS-.LOG"

query = ""
ipsFileName=""


class Worker(Thread):

    def __init__(self, tasks):
        Thread.__init__(self)
        self.tasks = tasks
        self.daemon = True
        self.start()
    
    def run(self):
        while True:
            func, args, kargs = self.tasks.get()
            try: func(*args, **kargs)
            except Exception, e: print e
            self.tasks.task_done()

class ThreadPool:

    def __init__(self, num_threads):
        self.tasks = Queue(num_threads)
        for _ in range(num_threads): Worker(self.tasks)

    def add_task(self, func, *args, **kargs):

        self.tasks.put((func, args, kargs))

    def wait_completion(self):

        self.tasks.join()



#filename="DNS"
#logname="DNS-.LOG"
#result = open(filename,'w')
#logfile = open(logname,'w')

def read_file(iplist,result) :
#	result = open(logfile,'w')
#	logfile = open(logname,'w')
#	ipFile = open(ipsFileName,'r')
	#ipcnt = ipFile.readlines()
     
	#for cnt in ipcnt:
	#	iplist.append(cnt.split('\n')[0])
	#	iplist.append(cnt)
		
	#ipFile.close()

        for ip in iplist :
            try:
                dns.query.udp(query,str(ip),timeout=10)
		lock.acquire()
		msg="%s\n" % ip
		result.write(msg)
		result.flush()
#		stdrr="%s :DNS SERVER\n" % ip
#		print stdrr
		#logfile.write(stdrr)
		#logfile.flush()
		lock.release()
	    except dns.exception.Timeout:
		stdrr="%s :NOT A DNS\n" % ip
#		print stdrr
	    #   logfile.write(stdrr)
	    #   logfile.flush()
		

	    except dns.query.UnexpectedSource:
		msg="UnexpectedSource %s\n" %ip
#		print "UnexpectedSource %s\n" %ip
	    #   logfile.write("UnexpectedSource %s\n" % ip)
	        #logfile.flush()
	    except socket.error:
		msg="Socket Error %s\n"%ip
#		print "Socket Error %s\n"%ip
	    #   logfile.write("Socket Error %s\n" % ip)
	        #logfile.flush()


#	result.close()


    


#thread_log="result_range"
#logfile = open(thread_log,'w')

def gen_ip(iplist,logfile) :
#	logfile=open(thread_log_name,'w')	
	for ip in iplist :
	    
	    	
            try:
              
                dns.query.udp(query,str(ip),timeout=10)
		
		lock.acquire()
		msg="%s\n" % ip
#		stdrr1=" %s :DNS SERVER\n" % ip
		stdrr=" %s \n" % ip
#		print stdrr1
		logfile.write(stdrr)
		logfile.flush()
		lock.release()	    
		
	    except dns.exception.Timeout:
		   stdrr="%s :NOT A DNS\n" % ip
#		   print stdrr
		#   logfile.write(stdrr)
		#   logfile.flush()
	    except dns.exception.FormError:
		    stdrr="%s :FormError\n" % ip
#		    print stdrr
		    #logfile.write(stdrr)
		    #logfile.flush()
	    except dns.query.UnexpectedSource:
		   msg='UnexpectedSource %s' % ip
#		   print stdrr
		   #logfile.write(msg)
		   #sys.exit(msg)
	    except socket.error:
		   msg="Socket Error %s\n" % ip
		   print stdrr
		   #logfile.write(msg)
	           #sys.exit(msg)
	    except Exception,e:
	 	   sys.stderr("ERR on %s: %s" % (ip,e))
		#   print stdrr

	  #  logfile.close()

opt_parser = OptionParser()
opt_parser.add_option("-f","--file",dest="ipFile",
                      help="read ipList file",metavar="FILE")
opt_parser.add_option("-s","--startip",dest="startip",
                      help="give start ip",metavar="SIP")
opt_parser.add_option("-e","--endip",dest="endip",
                      help="give end ip",metavar="EIP")
opt_parser.add_option("-t","--host",dest="host",
                      help="send this host",metavar="HOST")
opt_parser.add_option("-n","--threads",dest="threads",
		      help="set number of threads",metavar="THREADS")

(options,args) = opt_parser.parse_args()


if (not options.host):
	sys.exit("ERR TYPE: %s --help" % sys.argv[0])
elif (not options.startip) and (not options.ipFile):
	sys.exit("ERR TYPE: %s --help" % sys.argv[0])
elif (options.startip) and (options.ipFile):
	sys.exit("ERR TYPE: %s --help" % sys.argv[0])





if __name__ == '__main__':
    lock = Lock()


query=dns.message.make_query(options.host,1)

if options.startip: 
    
    thread_log="result_range"
    logfile=open(thread_log,'w')
    sip=options.startip
    eip=options.endip
    tmpip = IPAddress(sip)
     
    if options.threads:
	m=int(options.threads)
    else:
	m = 4  #number of threads

    pool = ThreadPool(int(options.threads))
   
 
    while True:
        if int(IPAddress(eip)) >= int(tmpip):		
			
		if IPAddress(tmpip).is_private():
			msg="Error: Contain Private IP:%s" % tmpip
			sys.exit(msg)

        	tmplist=[]
		tmplist.append(tmpip)
       
      	  	pool.add_task(gen_ip,tmplist,logfile)
		lock.acquire()
		tmpip=tmpip+1
		lock.release()
        else:
		break 
    
    pool.wait_completion()


elif options.ipFile:
	filename="DNS"
	result=open(filename, 'w')
 	
	pool = ThreadPool(int(options.threads))
   
	ipsFileName=options.ipFile
	ipsFile=open(ipsFileName,'r')
	cnt=ipsFile.readlines()
	
	if options.threads:
		m=int(options.threads)
	else:
		m = 4  #number of threads
	
	for ipl in cnt:
		
		ip=ipl.split('\n')[0]
		tmpip=IPAddress(ip)
		if IPAddress(tmpip).is_private():
			msg="Error: Contain Private IP:%s" % tmpip
			sys.exit(msg)
		tmplist=[]
		tmplist.append(tmpip)
	#	pool.add_task(gen_ip,tmplist,filename)
		pool.add_task(read_file, tmplist,result)
		lock.acquire()
		tmpip=tmpip+1
		lock.release()
    
    	pool.wait_completion()

	
