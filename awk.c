why awk?

awk is small, fast, and simple, unlike, say, perl. awk also has a clean comprehensible C-like input language, 
unlike, say, perl. And while it can't do everything you can do in perl, it can do most things that are actually 
text processing, and it's much easier 
to work with.
what do you do?

In its simplest usage awk is meant for processing column-oriented text data, such as tables, presented to it on 
standard input. The variables $1, $2, and so forth are the contents of the first, second, etc. column of the 
current input line. For example, to print the second column of a file, you might use the following simple awk 
script:
        awk < file '{ print $2 }'
This means "on every line, print the second field".
To print the second and third columns, you might use

        awk < file '{ print $2, $3 }'
Input separator

By default awk splits input lines into fields based on whitespace, that is, spaces and tabs. You can change this 
by using the -F option to awk and supplying another character. For instance, to print the home directories of all
users on the system, you might do
        awk < /etc/passwd -F: '{ print $6 }'
since the password file has fields delimited by colons and the home directory is the 6th field.
Arithmetic

Awk is a weakly typed language; variables can be either strings or numbers, depending on how they're referenced.
All numbers are floating-point. So to implement the fahrenheit-to-celsius calculator, you might write
        awk '{ print ($1-32)*(5/9) }'
which will convert fahrenheit temperatures provided on standard input to celsius until it gets an end-of-file.
The selection of operators is basically the same as in C, although some of C's wilder constructs do not work.
String concatenation is accomplished simply by writing two string expressions next to each other. '+' is always
addition. Thus

        echo 5 4 | awk '{ print $1 + $2 }'
prints 9, while
        echo 5 4 | awk '{ print $1 $2 }'
prints 54. Note that
        echo 5 4 | awk '{ print $1, $2 }'
prints "5 4".
Variables

awk has some built-in variables that are automatically set; $1 and so on are examples of these. The other builtin 
variables that are useful for beginners are generally NF, which holds the number of fields in the current input line
($NF gives the last field), and $0, which holds the entire current input line.
You can make your own variables, with whatever names you like (except for reserved words in the awk language) just
by using them. You do not have to declare variables. Variables that haven't been explicitly set to anything have 
the value "" as strings and 0 as numbers.

For example, the following code prints the average of all the numbers on each line:

        awk '{ tot=0; for (i=1; i<=NF; i++) tot += $i; print	tot/NF; }'
Note the use of $i to retrieve the i'th variable, and the for loop, which works like in C. The reason tot is 
explicitly initialized at the beginning is that this code is run for every input line, and when starting work on
the second line, tot will have the total value from the first line.
Blocks

It might seem silly to do that. Probably, you have only one set of numbers to add up. Why not put each one on its
own line? In order to do this you need to be able to print the results when you're done. The way you do this is 
like this:
        awk '{ tot += $1; n += 1; }  END { print tot/n; }'
Note the use of two different block statements. The second one has END in front of it; this means to run the block
once after all input has been processed. In fact, in general, you can put all kinds of things in front of a block,
and the block will only run if they're satisfied. That is, you can say
        awk ' $1==0 { print $2 }'
which will print the second column for lines of input where the first column is 0. You can also supply regular 
expressions to match the whole line against:
        awk ' /^test/ { print $2 }'
If you put no expression, the block is run on every line of input. If multiple blocks have conditions that are
true, they are all run. There is no particularly clean way I know of to get it to run exactly one of a bunch 
of possible blocks of code.
The block conditions BEGIN and END are special and are run before processing any input, and after processing
all input, respectively.

Other language constructs

As hinted at above, awk supports loop and conditional statements like in C, that is, for, while, do/while, if, 
and if/else.
printf

awk includes a printf statement that works essentially like C printf. This can be used when you want to format 
output neatly or combine things onto one line in more complex ways (print implicitly adds a newline; 
printf doesn't.)
Here's how you strip the first column off:

        awk '{ for (i=2; i<=NF; i++) printf "%s ", $i; printf "\n"; }'
Note the use of NF to iterate over all the fields and the use of printf to place newlines explicitly.
Combining awk with other tools

The strength of shell scripting is the ability to combine lots of tools together. Some things are most readily 
done with successive awk processes pipelined together. awk is also often combined with the sed utility, which does
regular expression matching and substitution. You can actually do most common sed operations in awk, but 
it's usually more convenient to use sed.
In combination with sed, sort, and some other useful shell utilities like paste, awk is quite satisfactory for 
a lot of numerical data processing, as well as the maintenance of simple databases kept in column-tabular formats.

awk is also extremely useful in a certain style of makefile writing for generating pieces of makefile to include.

Do not script in csh. Use sh, or if you must, ksh.

More stuff

This introduction intentionally covers only the absolute basics of awk. awk can do lots of other useful and
powerful things. The manual page for GNU awk (gawk) is a reasonably good reference for looking things up once
you know the basics.
The only thing seriously lacking in awk that I've yet run into is that there's no way to tell awk not to do
buffering on its input and output, which makes it useless for assorted interactive or network-oriented applications 
it would otherwise be ideally suited for.

#Show the length of output and sort them
ls -a | awk '{print length($0), $0}' | sort -n

#show the main result of wc command and if there are multiple wc command add them together
wc -l /user/path/to/$dir/test #| awk '{sum += $1} END {print sum}'


=================================================================================================
=================================================================================================
=================================================================================================
8 Powerful Awk Built-in Variables – FS, OFS, RS, ORS, NR, NF, FILENAME, FNR
This article is part of the on-going Awk Tutorial Examples series. Awk has several powerful built-in variables. 
There are two types of built-in variables in Awk.

Variable which defines values which can be changed such as field separator and record separator.
Variable which can be used for processing and reports such as Number of records, number of fields.

1. Awk FS Example: Input field separator variable.

Awk reads and parses each line from input based on whitespace character by default and set the variables $1,$2 
and etc. Awk FS variable is used to set the field separator for each record. Awk FS can be set to any single 
character or regular expression. You can use input field separator using one of the following two options:

Using -F command line option.
Awk FS can be set like normal variable.
Syntax:

$ awk -F 'FS' 'commands' inputfilename

(or)

$ awk 'BEGIN{FS="FS";}'
Awk FS is any single character or regular expression which you want to use as a input field separator.
Awk FS can be changed any number of times, it retains its values until it is explicitly changed. If you want to 
change the field separator, its better to change before you read the line. So that change affects the line what
you read.
Here is an awk FS example to read the /etc/passwd file which has “:” as field delimiter.

$ cat etc_passwd.awk
BEGIN{
FS=":";
print "Name\tUserID\tGroupID\tHomeDirectory";
}
{
	print $1"\t"$3"\t"$4"\t"$6;
}
END {
	print NR,"Records Processed";
}
$awk -f etc_passwd.awk /etc/passwd
Name    UserID  GroupID        HomeDirectory
gnats	41	41	/var/lib/gnats
libuuid	100	101	/var/lib/libuuid
syslog	101	102	/home/syslog
hplip	103	7	/var/run/hplip
avahi	105	111	/var/run/avahi-daemon
saned	110	116	/home/saned
pulse	111	117	/var/run/pulse
gdm	112	119	/var/lib/gdm
8 Records Processed
2. Awk OFS Example: Output Field Separator Variable

Awk OFS is an output equivalent of awk FS variable. By default awk OFS is a single space character. Following is 
an awk OFS example.

$ awk -F':' '{print $3,$4;}' /etc/passwd
41 41
100 101
101 102
103 7
105 111
110 116
111 117
112 119
Concatenator in the print statement “,” concatenates two parameters with a space which is the value of awk OFS 
by default. So, Awk OFS value will be inserted between fields in the output as shown below.

$ awk -F':' 'BEGIN{OFS="=";} {print $3,$4;}' /etc/passwd
41=41
100=101
101=102
103=7
105=111
110=116
111=117
112=119
3. Awk RS Example: Record Separator variable

Awk RS defines a line. Awk reads line by line by default.

Let us take students marks are stored in a file, each records are separated by double new line, and each fields
are separated by a new line character.

$cat student.txt
Jones
2143
78
84
77

Gondrol
2321
56
58
45

RinRao
2122
38
37
65

Edwin
2537
78
67
45

Dayan
2415
30
47
20
Now the below Awk script prints the Student name and Rollno from the above input file.

$cat student.awk
BEGIN {
	RS="\n\n";
	FS="\n";

}
{
	print $1,$2;
}

$ awk -f student.awk  student.txt
Jones 2143
Gondrol 2321
RinRao 2122
Edwin 2537
Dayan 2415
In the script student.awk, it reads each student detail as a single record,because awk RS has been assigned to
double new line character and each line in a record is a field, since FS is newline character.

4. Awk ORS Example: Output Record Separator Variable

Awk ORS is an Output equivalent of RS. Each record in the output will be printed with this delimiter. Following 
is an awk ORS example:

$  awk 'BEGIN{ORS="=";} {print;}' student-marks
Jones 2143 78 84 77=Gondrol 2321 56 58 45=RinRao 2122 38 37 65=Edwin 2537 78 67 45=Dayan 2415 30 47 20=
In the above script,each records in the file student-marks file is delimited by the character “=”.

5. Awk NR Example: Number of Records Variable

Awk NR gives you the total number of records being processed or line number. In the following awk NR example, 
NR variable has line number, in the END section awk NR tells you the total number of records in a file.

$ awk '{print "Processing Record - ",NR;}END {print NR, "Students Records are processed";}' student-marks
Processing Record -  1
Processing Record -  2
Processing Record -  3
Processing Record -  4
Processing Record -  5
5 Students Records are processed
6. Awk NF Example: Number of Fields in a record

Awk NF gives you the total number of fields in a record. Awk NF will be very useful for validating whether all 
the fields are exist in a record.

Let us take in the student-marks file, Test3 score is missing for to students as shown below.

$cat student-marks
Jones 2143 78 84 77
Gondrol 2321 56 58 45
RinRao 2122 38 37
Edwin 2537 78 67 45
Dayan 2415 30 47
The following Awk script, prints Record(line) number, and number of fields in that record. So It will be very
simple to find out that Test3 score is missing.

$ awk '{print NR,"->",NF}' student-marks
1 -> 5
2 -> 5
3 -> 4
4 -> 5
5 -> 4
7. Awk FILENAME Example: Name of the current input file

FILENAME variable gives the name of the file being read. Awk can accept number of input files to process.

$ awk '{print FILENAME}' student-marks
student-marks
student-marks
student-marks
student-marks
student-marks
In the above example, it prints the FILENAME i.e student-marks for each record of the input file.

8. Awk FNR Example: Number of Records relative to the current input file

When awk reads from the multiple input file, awk NR variable will give the total number of records relative
to all the input file. Awk FNR will give you number of records for each input file.

$ awk '{print FILENAME, FNR;}' student-marks bookdetails
student-marks 1
student-marks 2
student-marks 3
student-marks 4
student-marks 5
bookdetails 1
bookdetails 2
bookdetails 3
bookdetails 4
bookdetails 5
In the above example, instead of awk FNR, if you use awk NR, for the file bookdetails the you will get 
from 6 to 10 for each record.

===================================================
===================================================
===================================================


25 Best AWK Commands / Tricks
November 26, 2010Tricksawk
AWK is a data driven programming language designed for processing text-based data, either in files or data streams. 
It is an example of a programming language that extensively uses the string datatype, associative arrays 
(that is, arrays indexed by key strings), and regular expressions. 

1)  List of commands you use most often

history | awk ‘{a[$2]++}END{for(i in a){print a[i] ” ” i}}’ | sort -rn | head

2) Display a block of text with AWK

awk ‘/start_pattern/,/stop_pattern/’ file.txt

I find this terribly useful for grepping through a file, looking for just a block of text. There’s 
“grep -A # pattern file.txt” to see a specific number of lines following your pattern, but what if you want
to see the whole block? Say, the output of “dmidecode” (as root):

dmidecode | awk '/Battery/,/^$/'Will show me everything following the battery block up to the next block of text. Again, I find this extremely useful when I want to see whole blocks of text based on a pattern, and I don’t care to see the rest of the data in output. This could be used against the ‘/etc/securetty/user’ file on Unix to find the block of a specific user. It could be used against VirtualHosts or Directories on Apache to find specific definitions. The scenarios go on for any text formatted in a block fashion. Very handy.

3) Graph # of connections for each hosts.

netstat -an | grep ESTABLISHED | awk ‘{print $5}’ | awk -F: ‘{print $1}’ | sort | uniq -c | awk ‘{ printf(“%s\t%s\t”,$2,$1) ; for (i = 0; i < $1; i++) {printf(“*”)}; print “” }’

Written for linux, the real example is how to produce ascii text graphs based on a numeric value 
(anything where uniq -c is useful is a good candidate).

4) Check your unread Gmail from the command line

curl -u username:password –silent “https://mail.google.com/mail/feed/atom” | tr -d ‘\n’ | awk -F ” ‘{for (i=2; i<=NF; i++) {print $i}}’ | sed -n “s/\(.*\)<\/title.*name>\(.*\)<\/name>.*/\2 – \1/p”

Checks the Gmail ATOM feed for your account, parses it and outputs a list of unread messages.

For some reason sed gets stuck on OS X, so here’s a Perl version for the Mac:

curl -u username:password --silent "https://mail.google.com/mail/feed/atom" | tr -d '\n' | awk -F '<entry>' '{for (i=2; i<=NF; i++) {print $i}}' | perl -pe 's/^<title>(.*)<\/title>.*<name>(.*)<\/name>.*$/$2 - $1/'If you want to see the name of the last person, who added a message to the conversation, change the greediness of the operators like this:

curl -u username:password --silent "https://mail.google.com/mail/feed/atom" | tr -d '\n' | awk -F '<entry>' '{for (i=2; i<=NF; i++) {print $i}}' | perl -pe 's/^<title>(.*)<\/title>.*?<name>(.*?)<\/name>.*$/$2 - $1/'
5) Remove duplicate entries in a file without sorting.

awk ‘!x[$0]++’ <file>

Using awk, find duplicates in a file without sorting, which reorders the contents. 
awk will not reorder them, and still find and remove duplicates which you can then redirect into another file.

6) find geographical location of an ip address

lynx -dump http://www.ip-adress.com/ip_tracer/?QRY=$1|grep address|egrep ‘city|state|country’|awk ‘{print $3,$4,$5,$6,$7,$8}’|sed ‘s\ip address flag \\’|sed ‘s\My\\’

I save this to bin/iptrace and run “iptrace ipaddress” to get the Country, City and State of an ip address using the http://ipadress.com service.

I add the following to my script to get a tinyurl of the map as well:

URL=`lynx -dump http://www.ip-adress.com/ip_tracer/?QRY=$1|grep details|awk ‘{print $2}’`

lynx -dump http://tinyurl.com/create.php?url=$URL|grep tinyurl|grep “19. http”|awk ‘{print $2}’

7) Block known dirty hosts from reaching your machine

wget -qO – http://infiltrated.net/blacklisted|awk ‘!/#|[a-z]/&&/./{print “iptables -A INPUT -s “$1″ -j DROP”}’

Blacklisted is a compiled list of all known dirty hosts (botnets, spammers, bruteforcers, etc.) which is updated on an hourly basis. This command will get the list and create the rules for you, if you want them automatically blocked, append |sh to the end of the command line. It’s a more practical solution to block all and allow in specifics however, there are many who don’t or can’t do this which is where this script will come in handy. For those using ipfw, a quick fix would be {print “add deny ip from “$1″ to any}. Posted in the sample output are the top two entries. Be advised the blacklisted file itself filters out RFC1918 addresses (10.x.x.x, 172.16-31.x.x, 192.168.x.x) however, it is advisable you check/parse the list before you implement the rules

8) Display a list of committers sorted by the frequency of commits

svn log -q|grep “|”|awk “{print \$3}”|sort|uniq -c|sort -nr

Use this command to find out a list of committers sorted by the frequency of commits.

9) List the number and type of active network connections

netstat -ant | awk ‘{print $NF}’ | grep -v ‘[a-z]‘ | sort | uniq -c

10) View facebook friend list [hidden or not hidden]

lynx -useragent=Opera -dump ‘http://www.facebook.com/ajax/typeahead_friends.php?u=4&__a=1′ |gawk -F’\”t\”:\”‘ -v RS=’\”,’ ‘RT{print $NF}’ |grep -v ‘\”n\”:\”‘ |cut -d, -f2

There’s no need to be logged in facebook. I could do more JSON filtering but you get the idea…

Replace u=4 (Mark Zuckerberg, Facebook creator) with desired uid.

Hidden or not hidden… Scary, don’t you?

11) List recorded formular fields of Firefox

cd ~/.mozilla/firefox/ && sqlite3 `cat profiles.ini | grep Path | awk -F= ‘{print $2}’`/formhistory.sqlite “select * from moz_formhistory” && cd – > /dev/null

When you fill a formular with Firefox, you see things you entered in previous formulars with same field names. This command list everything Firefox has registered. Using a “delete from”, you can remove anoying Google queries, for example ;-)

12) Brute force discover

sudo zcat /var/log/auth.log.*.gz | awk ‘/Failed password/&&!/for invalid user/{a[$9]++}/Failed password for invalid user/{a["*" $11]++}END{for (i in a) printf “%6s\t%s\n”, a[i], i|”sort -n”}’

Show the number of failed tries of login per account. If the user does not exist it is marked with *.

13) Show biggest files/directories, biggest first with ‘k,m,g’ eyecandy

du –max-depth=1 | sort -r -n | awk ‘{split(“k m g”,v); s=1; while($1>1024){$1/=1024; s++} print int($1)” “v[s]“\t”$2}’

I use this on debian testing, works like the other sorted du variants, but i like small numbers and suffixes :)

14) Analyse an Apache access log for the most common IP addresses

tail -10000 access_log | awk ‘{print $1}’ | sort | uniq -c | sort -n | tail

This uses awk to grab the IP address from each request and then sorts and summarises the top 10
15) copy working directory and compress it on-the-fly while showing progress

tar -cf – . | pv -s $(du -sb . | awk ‘{print $1}’) | gzip > out.tgz

What happens here is we tell tar to create “-c” an archive of all files in current dir “.” (recursively) and output the data to stdout “-f -”. Next we specify the size “-s” to pv of all files in current dir. The “du -sb . | awk ?{print $1}?” returns number of bytes in current dir, and it gets fed as “-s” parameter to pv. Next we gzip the whole content and output the result to out.tgz file. This way “pv” knows how much data is still left to be processed and shows us that it will take yet another 4 mins 49 secs to finish.

Credit: Peteris Krumins http://www.catonmat.net/blog/unix-utilities-pipe-viewer/

16) List of commands you use most often

history | awk ‘{print $2}’ | sort | uniq -c | sort -rn | head

17) Identify long lines in a file

awk ‘length>72′ file

This command displays a list of lines that are longer than 72 characters. I use this command to identify those lines in my scripts and cut them short the way I like it.

18) Makes you look busy

alias busy=’my_file=$(find /usr/include -type f | sort -R | head -n 1); my_len=$(wc -l $my_file | awk “{print $1}”); let “r = $RANDOM % $my_len” 2>/dev/null; vim +$r $my_file’

This makes an alias for a command named ‘busy’. The ‘busy’ command opens a random file in /usr/include to a random line with vim. Drop this in your .bash_aliases and make sure that file is initialized in your .bashrc.

19) Show me a histogram of the busiest minutes in a log file:

cat /var/log/secure.log | awk ‘{print substr($0,0,12)}’ | uniq -c | sort -nr | awk ‘{printf(“\n%s “,$0) ; for (i = 0; i<$1 ; i++) {printf(“*”)};}’

20) Analyze awk fields

awk ‘{print NR”: “$0; for(i=1;i<=NF;++i)print “\t”i”: “$i}’

Breaks down and numbers each line and it’s fields. This is really useful when you are going to parse something with awk but aren’t sure exactly where to start.

21) Browse system RAM in a human readable form

sudo cat /proc/kcore | strings | awk ‘length > 20′ | less

This command lets you see and scroll through all of the strings that are stored in the RAM at any given time. Press space bar to scroll through to see more pages (or use the arrow keys etc).

Sometimes if you don’t save that file that you were working on or want to get back something you closed it can be found floating around in here!

The awk command only shows lines that are longer than 20 characters (to avoid seeing lots of junk that probably isn’t “human readable”).

If you want to dump the whole thing to a file replace the final ‘| less’ with ‘> memorydump’. This is great for searching through many times (and with the added bonus that it doesn’t overwrite any memory…).

Here’s a neat example to show up conversations that were had in pidgin (will probably work after it has been closed)…

sudo cat /proc/kcore | strings | grep '([0-9]\{2\}:[0-9]\{2\}:[0-9]\{2\})'(depending on sudo settings it might be best to run

sudo sufirst to get to a # prompt)

22) Monitor open connections for httpd including listen, count and sort it per IP

watch “netstat -plan|grep :80|awk {‘print \$5′} | cut -d: -f 1 | sort | uniq -c | sort -nk 1″

It’s not my code, but I found it useful to know how many open connections per request I have on a machine to debug connections without opening another http connection for it.

You can also decide to sort things out differently then the way it appears in here.

23) Purge configuration files of removed packages on debian based systems

sudo aptitude purge `dpkg –get-selections | grep deinstall | awk ‘{print $1}’`

Purge all configuration files of removed packages

24) Quick glance at who’s been using your system recently

last  | grep -v “^$” | awk ‘{ print $1 }’ | sort -nr | uniq -c

This command takes the output of the ‘last’ command, removes empty lines, gets just the first field ($USERNAME), sort the $USERNAMES in reverse order and then gives a summary count of unique matches.

25) Number of open connections per ip.

netstat -ntu | awk ‘{print $5}’ | cut -d: -f1 | sort | uniq -c | sort -n

Here is a command line to run on your server if you think your server is under attack. It prints our a list of open connections to your server and sorts them by amount.

BSD Version:

netstat -na |awk '{print $5}' |cut -d "." -f1,2,3,4 |sort |uniq -c |sort -nr
And there you have it killer awk usages. Now I know you might be thinking these are NOT awk commands. Maybe not, but awk was used to filter out data.

===================================================
===================================================
===================================================



Remove Duplicated lines:
awk '!a[$0]++' input.txt > output.txt

Sorting a file:
awk '{ print $1 |  "sort" }' input.txt > output.txt


#Remove strings at the end of file:
cat input.txt
dfsd-sdf-1234fgfg
eswr-ewref-23243fsdf
hgh-jh45h-78j78
hgh-jh45h-sdf7878
hgh-jh45h-7878j

awk '{sub(/[[:alpha:]]$/,"")}8' input.txt
OR
awk '{sub(/[^0-9]$/,"")}8' input.txt
