// lesson_06.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
string abc = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
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
			//if (s.compare("абаз") == 0) continue;

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

int strcmp(const char* left, const char* right);

bool binary_search(const string& findMe, string*& arr, int length) {
	int left = 0;
	int right = length - 1;

	while (left <= right)
	{
		int middle = (right + left) / 2;
		if (strcmp(arr[middle].c_str(), findMe.c_str()) == 0) {
			return true;
		}
		else if (strcmp(arr[middle].c_str(), findMe.c_str()) > 0) {
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}
	}

	return false;
}

int countEqualLetters(const string& left, const string& right) {
	int counter = 0;
	for (int i = 0; i < left.size(); i++)
	{
		if (left[i] == right[i]) {
			counter++;
		}
	}
	return counter;
}

string* generateWords(string in, string out, int& size) {
	string* result = new string[0];
	for (int i = 0; i < in.size(); i++)
	{
		string current = in;

		if (out[i] != current[i]) {
			for (int j = 0; j < abc.size(); j++)
			{
				current[i] = abc[j];
				if (current != in && !in_array(current, history, historyLength) && binary_search(current, dict, dictLength)) {
					addElementToArray(result, size, current);
					addElementToArray(history, historyLength, current);
				}
			}
		}
		else {
			current[i] = out[i];
			if (current != in && !in_array(current, history, historyLength) && binary_search(current, dict, dictLength)) {
				addElementToArray(result, size, current);
				addElementToArray(history, historyLength, current);
			}
		}
	}
	return result;
}

void printArray(string* strs, int size) {
	cout << "[";
	for (int i = 0; i < size; i++)
	{
		cout << strs[i] << (i < size - 1 ? ", " : "");
	}
	cout << "]\n";
}

void game(const string& begin, const string& end, string* chain, int chain_length) {
	if (begin == end) {
		cout << end << "\n";
		cout << "Found!\n";
		found = true;
		string current = end;
		addElementToArray(chain, chain_length, begin);
		printArray(chain, chain_length);
		cout << "Размер цепочки = " << chain_length << endl;
		//cout << current << endl;
		//for (int i = pairsLength - 1; i >= 0; i--)
		//{
		//	if (in_array(current, pairs[i].value, pairs[i].size)) {
		//		cout << pairs[i].key << endl;
		//		current = pairs[i].key;
		//	}
		//	if (current == begin) return;
		//}
		return;
	}

	cout << begin << ": ";
	int size = 0;


	string* result = generateWords(begin, end, size);

	if (size > 0) {
		addElementToArray(chain, chain_length, begin);
	}

	addElementToArray(pairs, pairsLength, Pair(begin, result, size));
	printArray(result, size);
	for (int i = 0; i < size; i++)
	{
		if (!found) {
			game(result[i], end, chain, chain_length);
		}
	}
}

void game(const string& begin, const string& end) {
	string* chain = new string[0];
	int chain_length = 0;

	game(begin, end, chain, chain_length);
}



#ifndef TEST
int main2()
{
	setlocale(LC_ALL, "ru_RU");
	const char* filename = "dict_len4_ansi.txt";
	readDictionary(filename);

	string begin, end;
	cout << "Введите два слова из 4 букв:\n";
	//cin >> in >> out;
	begin = "муха";
	end = "слон";
	// стук - сток - стон - слон
	game(begin, end);


	return EXIT_SUCCESS;
}
#endif

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
