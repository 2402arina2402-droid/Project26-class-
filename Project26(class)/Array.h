#pragma once
#include <iostream>
using namespace std;

class Array {
private:
	int* arr;
	int size;
public: 
	Array();
	Array(int size);
	Array(const Array& other);
	~Array();

	void fill();
	void show();
	void resize(int newSize);
	void sort();
	void showMin();
	void showMax();
};
