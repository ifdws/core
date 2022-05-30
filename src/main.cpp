#include "request.hpp"
#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

int main(int argc, char** argv) {
	string buffer;
	string response_buffer;

	std::map<string, string> response_headers;

	response_headers["Server"] = "ifsfs";
	response_headers["Content-type"] = get_mime_header(HTML_MIMETYPE, CHARSET_UTF8);

	for (;;) {
		getline(cin, buffer);

		response_buffer = handle_input(buffer, response_headers);

		if (response_buffer == CLOSE_CONNECTION) {
			return -1;
		}

		cout << response_buffer;
	}

	// Clean up memory...

	free(&buffer);

	return 0;
}