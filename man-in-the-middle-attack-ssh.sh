If you face the following WARNING in order to change your ssh key that means 
you are probabely under man-in-the-middle-attack

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@    WARNING: REMOTE HOST IDENTIFICATION HAS CHANGED!     @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
IT IS POSSIBLE THAT SOMEONE IS DOING SOMETHING NASTY!
Someone could be eavesdropping on you right now (man-in-the-middle attack)!
It is also possible that the RSA host key has just been changed.
The fingerprint for the RSA key sent by the remote host is
a7:a8:f2:97:94:33:58:b7:9d:bc:e0:a6:6b:f7:0a:29.
Please contact your system administrator.
Add correct host key in /home/ramesh/.ssh/known_hosts to get rid of this message.
Offending key in /home/ramesh/.ssh/known_hosts: 6
Permission denied (publickey,password).


If you want to have ssh connection to a remote server the rule is:
ssh user@ipaddress -p <port number>

If you want to solve it , it has two ways:
1) make a ssh connection without checking ssh key:
ssh -o 'StrictHostKeyChecking no' user@host -p <portnumber>

2)It depends on what your known_hosts is referring to: (for example 6 at 14th line)
so the solution is:
sed -i '6d' ~/.ssh/known_hosts
perl -pi -e 's/\Q$_// if ($. == 6);' ~/.ssh/known_hosts
