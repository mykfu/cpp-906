
#include <iostream>
#include <string>
#include "Pair.h"
using namespace std;

bool in_array(const string& needle, string*& haystack, int length);

void test_in_array() {
	string* strs = new string[]{ "asdf", "asdf2" };
	int strsLength = 2;
	string needle = "asdf";
	string needle2 = "asdf3";
	cout << (in_array(needle, strs, strsLength) ? "OK" : "ERROR") << endl;
	cout << (!in_array(needle2, strs, strsLength) ? "OK" : "ERROR") << endl;
}

void test_pair() {
	Pair pair;
	pair.key = "asdf";
	pair.value = new string[]{ "asdff", "asdfff" };
	Pair pair2;
	pair.key = "asdf2";
	pair.value = new string[]{ "asdff2", "asdfff2" };

	Pair pair3("asdf3", new string[]{ "asdf" }, 1);

	cout << pair3.key << endl;

	//Pair pair = { string("asdf"), new string[]{ "asdff", "asdfff" } };
	//Pair pair2 = { string("asdf"), new string[]{ "asdff", "asdfff" } };
	Pair* pairs = new Pair[]{pair, pair2};


}


int main2()
{
	test_in_array();
	test_pair();




	return EXIT_SUCCESS;
}