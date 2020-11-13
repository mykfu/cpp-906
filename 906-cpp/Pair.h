#pragma once
#include <string>
using namespace std;

struct Pair {
	string key;
	string* value;
	int size;

	Pair(string key, string* value, int size) : key(key), value(value), size(size) {}

	Pair() {
		Pair("", nullptr, 0);
	}
};
