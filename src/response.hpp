#include "util.hpp"
#include <map>
using namespace std;

#define CLOSE_CONNECTION ""
#define RESPONSE_200 "200 OK"
#define RESPONSE_404 "404 File not found"
#define CHARSET_UTF8 "utf-8"
#define HTML_MIMETYPE "text/html"

struct Response {
	bool valid;
	string status;
	string data;
	std::map<string, string> headers;
};

string get_mime_header(string mimetype, string charset);
std::map<string, string> create_headers();
Response create_response(string status, string data, std::map<string, string> headers);
string respond(Response response);