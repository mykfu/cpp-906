
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

bool binary_search(const int& findMe, int*& arr, int length) {
	int left = 0;
	int right = length - 1;

	while (left <= right)
	{
		int middle = (right + left) / 2;
		if (arr[middle] == findMe || arr[left] == findMe || arr[right] == findMe) {
			return true;
		}
		else if (arr[middle] > findMe) {
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}
	}

	return false;
}

bool binary_search(const string& findMe, string*& arr, int length);

//
//strcmp(огон, угон) = > -1
//strcmp(стон, слон) = > 1
//strcmp(стон, стон) = > 0
//strcmp(сто, стон) = > -1
//strcmp(ёж, ель) = > 1
int strcmp(string left, string right) {
	//todo

}

#define TEST
#ifdef TEST
int main()
{
	test_in_array();
	test_pair();

	// O(n)
	int length = 10;

	// O(log(n))
	//98					 0, 1  2  3  4
	// in_array(98, nums)
	// binary_search(98, nums)
	// 12 < 98  middle = 4
	// 23, 42, 67, 76, 98 
	// 67 ? 98
	// 76, 98
	// 76 ? 98
	// 98
	// 98 ? 98 
	int* nums = new int[10]{ 1, 3, 5, 7, 12, 23, 42, 67, 76, 98 };

	cout << (binary_search(98, nums, 10) ? "Found!" : "Not found!") << endl;
	cout << (binary_search(97, nums, 10) ? "Found!" : "Not found!") << endl;

	string* strs = new string[10]{ "asdf", "azdf", "bgfd", "jgf", "kopl", "mlot", "qioa", "ras", "tfas", "xasd" };
	string* strs2 = new string[]{ "ель", "ежик", "ёжик", "ёлка", "клён",  "туман" };


	cout << (binary_search("jgf", strs, 10) ? "Found!" : "Not found!") << endl;
	cout << (binary_search("ежик", strs2, 5) ? "Found!" : "Not found!") << endl;


	return EXIT_SUCCESS;
}
#endif