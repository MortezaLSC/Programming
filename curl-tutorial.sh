curl tutorial with examples of usage
Curl is a linux utility that is used to make HTTP requests to a given url. It outputs HTTP response to standard 
output and is actually very easy to use. Here are some examples to show its usage:

Make a GET request without any data:
curl http://yilmazhuseyin.com/blog/dev/
curl --request GET 'http://yilmazhuseyin.com/blog/dev/'
Both usages are actually the same. However, I try to use second one all the time. With --request (or -X) parameter,
we choose our http method to use for our requests. Its values can be GET, POST, DELETE, PUT etc.. If we don't
specify this parameter, GET method will be used by default. That is why first version works same as the second one.

Make requests with different HTTP method type without data:
 curl --request POST 'http://www.somedomain.com/'
 curl --request DELETE 'http://www.somedomain.com/'
 curl --request PUT 'http://www.somedomain.com/'
Make requests with data:
Since we learn how to make POST, GET, PUT, DELETE requests, we can now make same requests with data. In order to
send data with those requests, we should use --data parameter. Here are some examples:

::::/bin/bash
# send login data with POST request
curl --request POST 'http://www.somedomain.com/login/' \
--data 'username=myusername&password=mypassword'

# send search data to with get request
curl --request GET 'http://www.youtube.com/results?search_query=my_keyword'

# send PUT request with data
curl --request PUT 'http://www.somedomain.com/rest-api/user/12345/'\
--data 'email=myemail@gmail.com'

# same thing but this one get data from a file named data.txt
curl --request PUT 'http://www.somedomain.com/rest-api/user/12345/'\
--data @data.txt
Make requests with extra headers
Sometimes you need to add HTTP headers to your requests. This is done by --header parameter.

curl --request GET 'http://www.somedomain.com/user/info/' \
--header 'sessionid:1234567890987654321'
Notice that we are using semicolon(":") to separate header name from its value.

Get response with HTTP headers
If you need to get HTTP headers with your response, --include parameter can be used

 curl --request GET 'http://somedomain.com/' --include
Those examples cover most of the stuff curl is needed for. If you need more functionality, you can use following
two commands as a reference

# gives  brief description of parameters
curl --help

# curl manual page
man curl
