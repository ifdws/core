#include "request.hpp"
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

string handle_input(string buffer, std::map<string, string> response_headers) {
	string response_buffer;
	string filename;

	if (buffer.rfind("GET", 0) == 0) {
		// Response status code

		response_buffer = "HTTP/1.0 ";
		response_buffer += RESPONSE_200;
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
		response_buffer += "<h1>Hello, World!</h1";

		return response_buffer;
	}

	return CLOSE_CONNECTION;
}