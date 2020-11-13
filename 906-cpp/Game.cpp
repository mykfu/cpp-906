// lesson_06.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Pair.h"
using namespace std;

string* dict;
int dictLength = 0;
string* history;
int historyLength = 0;
string abc = "��������������������������������";
bool found = false;
Pair* pairs;
int pairsLength = 0;

void readDictionary(const char* filename) {
	ifstream file(filename);
	string s;
	if (file.is_open()) {
		dictLength = 0;
		while (getline(file, s)) {
			dictLength++;
		}
		cout << dictLength << endl;
		dict = new string[dictLength];

		file.clear();
		file.seekg(0);
		// for(init; test; update)
		for (int i = 0; getline(file, s); i++) {
			dict[i] = s;
			//if (s.compare("����") == 0) continue;

			//cout << dict[i] << endl;
			//if (i > 5) break;
		}
		file.close();
	}
	else {
		cerr << "File not found.\n";
		exit(EXIT_FAILURE);
	}
}

template<typename T>
void addElementToArray(T*& strs, int& size, T newValue) {
	T* result = new T[size + 1];

	for (int i = 0; i < size; i++)
	{
		result[i] = strs[i];
	}
	result[size] = newValue;
	strs = result;
	size++;
}

void removeElementToArray(string*& strs, int& size, string remove) {
	string* result = new string[--size];
	for (int i = 0, j = 0; i <= size; i++)
	{
		if (result[i] == remove) continue;
		result[j] = strs[i];
		j++;
	}
	strs = result;
}


bool in_array(const string& needle, string*& haystack, int length) {
	for (int i = 0; i < length; i++)
	{
		if (needle == haystack[i]) return true;
	}

	return false;
}


string* generateWords(string in, int& size) {
	string* result = new string[0];
	for (int i = 0; i < in.size(); i++)
	{
		string current = in;
		for (int j = 0; j < abc.size(); j++)
		{
			current[i] = abc[j];

			for (int k = 0; k < dictLength; k++)
			{
				//if (current.replace(i, 1, abc.substr(j, 1)) == dict[k] && current != in) {
				current[i] = abc[j];
				if (current == dict[k] && current != in) {
					//cout << current << endl;
					addElementToArray(result, size, current);
					break;
				}
			}
		}
	}
	return result;
}

void printArray(string* strs, int size) {
	cout << "[";
	for (int i = 0; i < size; i++)
	{
		cout << strs[i] << (i < size - 1 ? ", " : "]\n");
	}
}

void game(string begin, string end) {
	if (begin == end) {
		cout << "Found!\n";
		found = true;
		return;
	}
	if (found) {
		string current = end;
		cout << current << endl;
		for (int i = pairsLength - 1; i >= 0; i--)
		{
			if (in_array(current, pairs[i].value, pairs[i].size)) {
				cout << pairs[i].key << endl;
				current = pairs[i].key;
			}
			if (current == begin) return;
		}

		return;
	}

	cout << begin << ": ";
	int size = 0;
	addElementToArray(history, historyLength, begin);


	string* result = generateWords(begin, size);
	addElementToArray(pairs, pairsLength, Pair(begin, result, size));
	printArray(result, size);
	for (int i = 0; i < size; i++)
	{
		if (!in_array(result[i], history, historyLength)) game(result[i], end);
	}
}

int main()
{
	setlocale(LC_ALL, "ru_RU");
	const char* filename = "dict_len4_ansi.txt";
	readDictionary(filename);

	string begin, end;
	cout << "������� ��� ����� �� 4 ����:\n";
	//cin >> in >> out;
	begin = "����";
	end = "����";
	game(begin, end);


	return EXIT_SUCCESS;
}

// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"

// ������ �� ������ ������ 
//   1. � ���� ������������ ������� ����� ��������� ����� � ��������� ���.
//   2. � ���� Team Explorer ����� ������������ � ������� ���������� ��������.
//   3. � ���� "�������� ������" ����� ������������� �������� ������ ������ � ������ ���������.
//   4. � ���� "������ ������" ����� ������������� ������.
//   5. ��������������� �������� ������ ���� "������" > "�������� ����� �������", ����� ������� ����� ����, ��� "������" > "�������� ������������ �������", ����� �������� � ������ ������������ ����� ����.
//   6. ����� ����� ������� ���� ������ �����, �������� ������ ���� "����" > "�������" > "������" � �������� SLN-����.
