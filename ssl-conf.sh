#!/usr/bin/env bash
#This scripts is written by "MortezaLSC" on Monday, 20 January 2014 at 1:00 PM
#Usage: ./ssl-conf <<EOF
#1:     > <CountryNmane>
#2:     > <StateName>
#3:     > <LocalityName>
#4:     > <OrganizationName>
#5:     > <OrganizationUnitName>
#6:     > <CommonName>
#7:     > <EmailAddress>
#8:     > <ChallengePassword>
#9:     > <CompanyName>
#       >EOF
#


SSLPATH="/etc/httpd/conf.d/ssl.conf"
HTTPPATH="/etc/httpd/conf/httpd.conf"


yum update -y
yum install httpd curl php mod_ssl openssl -y

openssl genrsa -out ca.key 1024
openssl req -new -key ca.key -out ca.csr
openssl x509 -req -days 365 -in ca.csr -signkey ca.key -out ca.crt
cp ca.crt /etc/pki/tls/certs
cp ca.key /etc/pki/tls/private/ca.key
cp ca.csr /etc/pki/tls/private/ca.csr

cat ServerName localhost >> $HTTPPATH

sed -i 's|SSLCertificateFile /etc/pki/tls/certs/localhost.crt|SSLCertificateFile /etc/pki/tls/certs/ca.crt|' $SSLPATH
sed -i 's|SSLCertificateKeyFile /etc/pki/tls/private/localhost.key|SSLCertificateFile /etc/pki/tls/private/ca.key|' $SSLPATH

service httpd restart
