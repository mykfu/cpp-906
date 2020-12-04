
#include <iostream>
#include <string>
#include <algorithm>
#include "Pair.h"
using namespace std;

bool in_array(const string& needle, string*& haystack, int length);

void test_in_array() {
	string* strs = new string[2]{ "asdf", "asdf2" };
	int strsLength = 2;
	string needle = "asdf";
	string needle2 = "asdf3";
	cout << (in_array(needle, strs, strsLength) ? "OK" : "ERROR") << endl;
	cout << (!in_array(needle2, strs, strsLength) ? "OK" : "ERROR") << endl;
}

void test_pair() {
	Pair pair;
	pair.key = "asdf";
	pair.value = new string[2]{ "asdff", "asdfff" };
	Pair pair2;
	pair.key = "asdf2";
	pair.value = new string[2]{ "asdff2", "asdfff2" };

	Pair pair3("asdf3", new string[1]{ "asdf" }, 1);

	cout << pair3.key << endl;

	//Pair pair = { string("asdf"), new string[]{ "asdff", "asdfff" } };
	//Pair pair2 = { string("asdf"), new string[]{ "asdff", "asdfff" } };
	Pair* pairs = new Pair[2]{pair, pair2};


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
int strcmp(const char* left, const char* right) {
	int length = min(strlen(left), strlen(right));

	for (int i = 0; i < length; i++)
	{
		char c1 = left[i];
		char c2 = right[i];

		if (c1 == 'ё') {
			if (c2 >= 'а' && c2 <= 'е') {
				return 1;
			}
			else if (c2 >= 'ж' && c2 <= 'я') {
				return -1;
			}
		}

		if (c2 == 'ё') {
			if (c1 >= 'а' && c1 <= 'е') {
				return -1;
			}
			else if (c1 >= 'ж' && c1 <= 'я') {
				return 1;
			}
		}

		if (c1 != c2) return c1 - c2;
		//if (c1 < c2) return -1;
		//if (c1 > c2) return 1;
	}

	return strlen(left) - strlen(right);
}

//
//strcmp(огон, угон) = > -1
//strcmp(стон, слон) = > 1
//strcmp(стон, стон) = > 0
//strcmp(сто, стон) = > -1
//strcmp(ёж, ель) = > 1
int strcmp2(const char* left, const char* right) {



	const unsigned char* s1 = (const unsigned char*) left;
	const unsigned char* s2 = (const unsigned char*) right;

	unsigned char c1, c2;
	do {
		c1 = (unsigned char)*s1++;
		c2 = (unsigned char)*s2++;


		if (c1 == 'ё') {
			if (c2 >= 'а' && c2 <= 'е') {
				return 1;
			}
			else if (c2 >= 'ж' && c2 <= 'я') {
				return -1;
			}
		}

		if (c2 == 'ё') {
			if (c1 >= 'а' && c1 <= 'е') {
				return -1;
			}
			else if (c1 >= 'ж' && c1 <= 'я') {
				return 1;
			}
		}

		if (c1 == '\0' || c2 == '\0');

	} while (c1 == c2);
	return c1 - c2;
}

void test_binary() {

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
	string* strs2 = new string[6]{ "ель", "ежик", "ёжик", "ёлка", "клён",  "туман" };


	cout << (binary_search("jgf", strs, 10) ? "Found!" : "Not found!") << endl;
	cout << (binary_search("ежик", strs2, 5) ? "Found!" : "Not found!") << endl;

	cout << "expected 1, actual = strcmp(\"ёж\", \"еж\") = " << strcmp("ёж", "еж") << endl;
	cout << "expected -1, actual = strcmp(\"еж\", \"ёж\") = " << strcmp("еж", "ёж") << endl;
	cout << "expected -1, actual = strcmp(\"asdf\", \"bsdf\") = " << strcmp("asdf", "bsdf") << endl;
	cout << "expected -1, actual = strcmp(\"asdf\", \"bsdf\") = " << strcmp2("asdf", "bsdf") << endl;

}

void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

int part(int* arr, int left, int right) {
	int pivot = arr[right];
	for (int i = left; i < right; i++)
	{
		if (arr[i] <= pivot) {
			swap(arr[i], arr[left]);
			left++;
		}
	}
	swap(arr[right], arr[left]);
	return left;
}

void quickSort(int* arr, int left, int right) {
	if (left < right) {
		int pi = part(arr, left, right);
		quickSort(arr, left, pi - 1);
		quickSort(arr, pi + 1, right);
	}

}

void quickSort(int* arr, int size) {
	quickSort(arr, 0, size - 1);
}


void swap(string& a, string& b) {
	string t = a;
	a = b;
	b = t;
}

int getSameLetters(const string& left, const string& right) {
	int counter = 0;
	for (int i = 0; i < min(left.length(), right.length()); i++)
	{
		if (left[i] == right[i]) counter++;
	}
	return counter;
}

int part(const string& with, string* arr, int left, int right) {
	int pivot = getSameLetters(with, arr[right]);
	for (int i = left; i < right; i++)
	{
		if (getSameLetters(with, arr[i]) >= pivot) {
			swap(arr[i], arr[left]);
			left++;
		}
	}
	swap(arr[right], arr[left]);
	return left;
}

void quickSortSameLetters(const string& with, string* arr, int left, int right) {
	if (left < right) {
		int pi = part(with, arr, left, right);
		quickSortSameLetters(with, arr, left, pi - 1);
		quickSortSameLetters(with, arr, pi + 1, right);
	}

}

void quickSortSameLetters(const string& with, string* arr, int size) {
	quickSortSameLetters(with, arr, 0, size - 1);
}

//#define TEST
#ifdef TEST
int main()
{
	setlocale(LC_ALL, "russian");
	//test_in_array();
	//test_pair();
	//test_binary();

	int length = 10;
	int* arr = new int[length];

	for (int i = 0; i < length; i++)
	{
		arr[i] = rand() % 100;
		cout << " " << arr[i];
	}
	cout << endl;
	quickSort(arr, length);
	for (int i = 0; i < length; i++)
	{
		cout << " " << arr[i];
	}

	cout << endl;
	string sim = "asdf";
	cout << sim << ": ";
	string* strs = new string[4]{"asda", "fdas", "asdf", "afds"};
	quickSortSameLetters(sim, strs, 4);
	 
	for (int i = 0; i < 4; i++)
	{
		cout << " " << strs[i];
	}
	return EXIT_SUCCESS;
}
#endif