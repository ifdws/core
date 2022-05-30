#include <iterator>
#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

#define HTTP_NEWLINE "\r\n"
#define CLOSE_CONNECTION ""
#define RESPONSE_200 "200 OK"
#define RESPONSE_404 "404 File not found"

#define CHARSET_UTF8 "utf-8"

#define HTML_MIMETYPE "text/html"

string get_mime_header(string mimetype, string charset);
string handle_input(string buffer, std::map<string, string> response_headers);