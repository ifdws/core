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

	vector<string> lines = split(buffer, '\n');

	if (lines.size() == 0) {
		return CLOSE_CONNECTION; // Empty request
	}

	vector<string> firstline = split(lines[0], ' ');

	if (firstline.size() != 3) {
		return CLOSE_CONNECTION; // Not a valid request
	}

	if (firstline[0] == "GET") {
		string html = "<head><title>ifsfs!</title></head><body>";
		html += "<h1>ifsfs is working!</h1>";
		html += "<p>Route: ";
		html += firstline[1];
		html += "</p>";
		html += "</body>";

		return respond_http(RESPONSE_200, html, response_headers);
	}

	return CLOSE_CONNECTION; // Unknown/Unhandled method
}