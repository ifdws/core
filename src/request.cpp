#include "request.hpp"

Request parse_request(string buffer) {
	string response_buffer;
	string filename;

	vector<string> lines = split(buffer, '\n');

	if (lines.size() == 0) {
		return Request {false, "", ""}; // Empty request
	}

	vector<string> firstline = split(lines[0], ' ');

	if (firstline.size() != 3) {
		return Request {false, "", ""}; // Not a valid request
	}

	return Request {true, firstline[0], firstline[1]};
}

/*string handle_input(string buffer, std::map<string, string> response_headers) {

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
}*/