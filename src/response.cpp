#include "response.hpp"

string get_mime_header(string mimetype, string charset) {
	string output;

	output = mimetype;
	output += "; charset=";
	output += charset;

	return output;
}

std::map<string, string> create_headers() {
	std::map<string, string> headers;

	headers["Server"] = "ifsfs";
	headers["Content-type"] = get_mime_header("text/plain", CHARSET_UTF8);

	return headers;
}

Response create_response(string status, string data, std::map<string, string> headers) {
	return Response {true, status, data, headers};
}

string respond(Response response) {
	if (!response.valid) {
		return "";
	}

	string response_buffer;

	// Status code

	response_buffer = "HTTP/1.0 ";
	response_buffer += response.status;
	response_buffer += HTTP_NEWLINE;

	// Headers

	for(std::map<string, string>::iterator it = response.headers.begin(); it != response.headers.end(); ++it) {
		response_buffer += it->first;
		response_buffer += ": ";
		response_buffer += it->second;
		response_buffer += HTTP_NEWLINE;
	}

	// Contents

	response_buffer += HTTP_NEWLINE;
	response_buffer += response.data;
	response_buffer += HTTP_NEWLINE;

	return response_buffer;
}