#Show the length of output and sort them
ls -a | awk '{print length($0), $0}' | sort -n

#show the main result of wc command and if there are multiple wc command add them together
wc -l /user/path/to/$dir/test #| awk '{sum += $1} END {print sum}'
