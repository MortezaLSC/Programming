cat test
pass = 324234
pass = 23423453455
.
.
.


1) cut command:
cut -d= -f2 test | cut -c 2-

2) awk command:
awk < test -F= '{ print $2 }' | cut -c 2-

3) sed command:
cat test | sed "s/.* = //"
