#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

#define HTTP_NEWLINE "\r\n"

bool startswith(string text, string search);
bool endswith(string text, string search);
vector<string> split(string text, char search);