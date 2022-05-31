#include "util.hpp"
#include <iterator>
#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

struct Request {
	bool valid;
	string method;
	string route;
};

Request parse_request(string buffer);