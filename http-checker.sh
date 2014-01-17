#! /bin/bash

trap bashtrap INT
bashtrap()
{
    echo
    echo "CTRL+C Detected"
    kill 0
    exit
}

sitedns="yoursite.dns"
siteip="1.1.1.1" #not required for browser check

varagent="Mozilla/5.0 (Macintosh; Intel Mac OS X 10_7_2) AppleWebKit/535.1 (KHTML, like Gecko) Chrome/14.0.835.202 Safari/535.1"
TIMEOUT=4

cookie_header="Cookie: __atuvc=19%7C23; NIXSESSID=3f5d178f0ce66213c512e512b65269008c365038;" #random cookie

phpsiteprase="any fucking text"

function ping_http {
# <p>$phpsiteprase</p>/nArray
#    [Accept] => text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
#    [Accept-Charset] => ISO-8859-1,utf-8;q=0.7,*;q=0.7
#    [Accept-Encoding] => gzip,deflate
#    [Accept-Language] => en-us,en;q=0.5
#    [Connection] => close
#    [Host] => yoursitedns.com
#    [User-Agent] => Mozilla/5.0 (Android; Tablet; rv:12.0) Gecko/12.0 Firefox/12.0
#    [Via] => 1.1 89.28.122.140 (Mikrotik HttpProxy)
#    [X-Forwarded-For] => 1.1.1.1
#    [X-Proxy-Id] => 1773250874
#    [X-Real-Ip] => 89.28.122.140
    local proxyip=$1

    local http_check_var=`curl -s -A "$varagent" -x "$proxyip" --connect-timeout $TIMEOUT \
    --url "http://""$sitedns""/tmp/" -m 5`                   #Proxies for browser
#    --header "Host: "$sitedns"" --url "http://"$siteip"/tmp/" -L -m 5`
    local check1_phrase=`echo "$http_check_var" | grep -o "$phpsiteprase"`
    local check2_forwarded=`echo "$http_check_var" | grep -o "Forwarded"`
    local check3_clientip=`echo "$http_check_var" | grep -o "Client-Ip"`
    local check4_proxy=`echo "$http_check_var" | grep -o "Proxy"`
    local check5_via=`echo "$http_check_var" | grep -o "Via"`
    if [[ -n "$check1_phrase" ]]; then    #-n not zero # working
#        local http_check_var_connect=`curl -s -A "$varagent" -p -x "$proxyip" --connect-timeout $TIMEOUT \
#        --header "Host: "$sitedns"" --url "http://"$siteip"/tmp/" -m 5 | grep -o "$phpsiteprase"`  #Http Connect check
        if [[ -z "$check2_forwarded" && -z "$check3_clientip" ]]; then  #  -z - if null #Elite without cookie
            local http_check_var=`curl -s -A "$varagent" -x "$proxyip" --connect-timeout $TIMEOUT --header "$cookie_header" --header "Cache-Control: no-cache"\
            --url "http://""$sitedns""/tmp/" -m 5` #second check with cookie now
            local check1_phrase=`echo "$http_check_var" | grep -o "$phpsiteprase"`
            local check2_forwarded=`echo "$http_check_var" | grep -o "Forwarded"`
            local check3_clientip=`echo "$http_check_var" | grep -o "Client-Ip"`
            local check44_proxy_2=`echo "$http_check_var" | grep -o "Proxy"`
            local check55_via_2=`echo "$http_check_var" | grep -o "Via"`
            if [[ -n "$check1_phrase" && -z "$check2_forwarded" && -z "$check3_clientip" ]]; then #Elite with cookie
                local check6_vk=`curl -s -A "$varagent" -x "$proxyip" --url vk.com -m 1 | grep -o "vklogin"` #check for speed

                # I check country for elite. Move it where u want.
                local prip=$(echo "$line" | sed 's/:.*//')
                local whoisvar=$(whois "$prip" )
                local countryvar=$(echo "$whoisvar" | grep "country:" | sed 's/country: \{1,\}//' | head -n 1)
                [[ -z "$countryvar" ]] && local countryvar=$(echo "$whoisvar" | grep "Country-Code" | sed 's/.*:\{1,\}//' | head -n 1)
                [[ -z "$countryvar" ]] && local countryvar=$(echo "$whoisvar" | grep "Nameserver" | sed 's/.*\.\{1,\}//' | head -n 1)
                    #case $countryvar in
                    #"RU" | "UA" | "BY" | "KZ" | "KG")
                        #echo...
                        #;;
                    #esac
                #if [[ "$countryvar" != "CN" && "$countryvar" != "cn" ]]; then
                    echo -ne "\t\t\t\tElite\r"
                    echo -ne "\t\t\t\t\t\t"${countryvar:0:13}"\r"
                    if [[ -z "$check4_proxy" && -z "$check5_via" && -z "$check44_proxy_2" && -z "$check55_via_2" ]]; then
                        echo -ne "\t\t\t\t\tSuperEl\r"
                    fi
                    [[ -n "$check6_vk" ]] && echo -ne "\t\t\t\t\t\t\t\t\tSpeedVK \r"

                    echo "$proxyip""      "
                #fi
            fi
        fi
        #if [[ -n "$http_check_var_connect" ]]; then    #-n not zero  #HTTP Connect
            #echo -ne "\t\t\t\t\t\t\t\tConn \r"
        #fi
    fi
    echo -ne "process $count finished    \r"
}

function check_alive_http {
    ##### check loop #####
    local count=1
    for line in $( cat $1 )
    do    
        ping_http "$line" &
        sleep 0.2

    let count++
    done
    wait
    echo 
}

### MAIN ####
TOTAL_HTTP=`cat $1 | wc -l`
[ "$TOTAL_HTTP" == 0 ] && { echo "Found 0 proxies"; exit; }
echo "Checking "$TOTAL_HTTP" HTTP proxies"
check_alive_http $1

#            # DNS to IP
#            local ipold=$(echo "$proxyip" | sed 's/:.*//')
#            local ip=$(dig +short "$ipold")
#            if [[ "$ip" != "" ]]; then
#                local proxyip=$ip:$(echo "$proxyip" | sed 's/.*://')
#            fi
#            #
