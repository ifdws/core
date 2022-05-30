#include "request.hpp"
#include "util.hpp"
#include <iterator>
#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

string get_mime_header(string mimetype, string charset) {
	string output;

	output = mimetype;
	output += "; charset=";
	output += charset;

	return output;
}

string respond_http(string status_code, string data, std::map<string, string> response_headers) {
	string response_buffer;

	// Status code

	response_buffer = "HTTP/1.0 ";
	response_buffer += status_code;
	response_buffer += HTTP_NEWLINE;

	// Headers

	for(std::map<string, string>::iterator it = response_headers.begin(); it != response_headers.end(); ++it) {
		response_buffer += it->first;
		response_buffer += ": ";
		response_buffer += it->second;
		response_buffer += HTTP_NEWLINE;
	}

	// Contents

	response_buffer += HTTP_NEWLINE;
	response_buffer += data;

	return response_buffer;
}

string handle_input(string buffer, std::map<string, string> response_headers) {
	string response_buffer;
	string filename;

	if (startswith(buffer, "GET")) {
		return respond_http(RESPONSE_200, "<h1>Hello, World!</h1>", response_headers);
	}

	return CLOSE_CONNECTION;
}