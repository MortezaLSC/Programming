I am trying to replace Config Files with the UnixCommandline without using an Editor like vi or nano.

An example could be:

ServerAdmin mail@example.com
I want to find the first or all lines that start with ServerAdmin and replace them with:

ServerAdmin secret@secret.com
Is there any command to do something like this? It should be possible with the standart UNIX tools also available
in CygWin.

using sed:
sed -i 's/^ServerAdmin .*$/ServerAdmin secret@secret.com/' in-filename

using perl:
perl -p -i -e 's/ServerAdmin/ServerAdmin secret@secret.com/g' your_file_name


#Removing all blank lines:
sed -i '/^$/d' input.txt


#Remove strings at the end of file:
cat input.txt
dfsd-sdf-1234fgfg
eswr-ewref-23243fsdf
hgh-jh45h-78j78
hgh-jh45h-sdf7878
hgh-jh45h-7878j

sed -r 's/[^0-9]+$//' input.txt
dfsd-sdf-1234
eswr-ewref-23243
hgh-jh45h-78j78
hgh-jh45h-sdf7878
hgh-jh45h-7878

#Adding word at the first of all lines:
sed 's/^/newBeginning/' filename

#Removing word from all lines:
sed 's/\<word\>//g' input
OR
sed -e 's/\<regex-for-word\>//g' input > output
 EX:
   echo 'This is a foo test' | sed -e 's/\<foo\>//g'
