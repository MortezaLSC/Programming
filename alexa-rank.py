#!/usr/bin/env python
#This program is written by "MortezaLSC" on Monday, 8 April 2013 at 10:02 pm
#It gets url list and show alexa rank of them.

import sys
import re
import urllib2



def get_alexa_rank(url):
    try:

        data = urllib2.urlopen('http://data.alexa.com/data?cli=10&dat=snbamz&url=%s' % (url)).read()

        reach_rank = re.findall("REACH[^\d]*(\d+)", data)
        if reach_rank: reach_rank = reach_rank[0]
        else: reach_rank = -1


        country_rank = re.findall("COUNTRY[^\d]*(\d+)", data)
        if country_rank: country_rank = country_rank[0]
        else: country_rank = -1


        popularity_rank = re.findall("POPULARITY[^\d]*(\d+)", data)
        if popularity_rank: popularity_rank = popularity_rank[0]
        else: popularity_rank = -1

        return int(popularity_rank), int(reach_rank), int(country_rank)

    except (KeyboardInterrupt, SystemExit):
        raise
    except:
        return None

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print 'usage: python %s <file-urls>' % (sys.argv[0])
        sys.exit(2)



print 'Url###popularity rank###reach_rank###country_rank'

filename = sys.argv[1]
urls = open (filename)

for line in urls:
	url = line.rstrip()  
 	data = get_alexa_rank(url)
	popularity_rank, reach_rank, country_rank = -1, -1, -1
	if data:
		popularity_rank, reach_rank , country_rank = data
		print '%s###%d###%d###%d' % (url, popularity_rank, reach_rank, country_rank)
