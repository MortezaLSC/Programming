#!/bin/bash
#This scripts is written by "MortezaLSC" on Monday, 20 January 2014 at 1:00 PM
#It prepares and installs everything you need to have for SSL on your centOS machine.

#Usage: ./ssl-conf <<EOF
#0:     What you need to assign        EXAMPLE
###     =======================       ===========
#1:     > <CountryNmane>                US
#2:     > <StateName>                   something
#3:     > <LocalityName>                newyork
#4:     > <OrganizationName>            test
#5:     > <OrganizationUnitName>        test1
#6:     > <CommonName>                  test2
#7:     > <EmailAddress>                test3
#8:     > <ChallengePassword>           challengepassword
#9:     > <CompanyName>                 test4
#       >EOF
#


SSLPATH="/etc/httpd/conf.d/ssl.conf"
HTTPPATH="/etc/httpd/conf/httpd.conf"


yum update -y
yum install httpd curl php mod_ssl openssl -y

openssl genrsa -out ca.key 1024 &
openssl req -new -key ca.key -out ca.csr &
openssl x509 -req -days 365 -in ca.csr -signkey ca.key -out ca.crt &
cp ca.crt /etc/pki/tls/certs &
cp ca.key /etc/pki/tls/private/ca.key &
cp ca.csr /etc/pki/tls/private/ca.csr &
echo

echo ServerName localhost >> $HTTPPATH


sed -i 's|SSLCertificateFile /etc/pki/tls/certs/localhost.crt|SSLCertificateFile /etc/pki/tls/certs/ca.crt|' $SSLPATH &
sed -i 's|SSLCertificateKeyFile /etc/pki/tls/private/localhost.key|SSLCertificateKeyFile /etc/pki/tls/private/ca.key|' $SSLPATH &
echo "SSL configurations finished"
echo

if [ -a /etc/init.d/iptables ]; then
    /etc/init.d/iptables stop &
    if [ $? -eq o ]; then
	echo "iptables stopped successfully"
    else
	echo "iptables stopping failed"
    fi
else 
    echo "iptables service not found"
fi
echo

if [ -a /etc/init.d/httpd ]; then
    /etc/init.d/httpd restart &
    if [ $? -eq 0 ]; then
	echo "httpd restarted successfully"
    else
	echo "httpd restarting failed"
    fi
else
    echo "httpd not found"
fi
echo
