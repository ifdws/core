#include "util.hpp"

bool startswith(string text, string search) {
	return text.rfind(search, 0) == 0;
}

bool endswith(string text, string search) {
	if (text.length() >= search.length()) {
		return (0 == text.compare (text.length() - search.length(), search.length(), search));
	} else {
		return false;
	}
}

vector<string> split(string text, char search) {
	vector<string> split_text;
	string buffer;

	stringstream streamBuffer(text);

	while (getline(streamBuffer, buffer, search)) {
		split_text.push_back(buffer);
	}

	return split_text;
}