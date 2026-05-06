#include "Array.h"
#include <iostream>
using namespace std;

Array::Array() {
	size = 5;
	arr = new int[size];
}

Array::Array(int size) {
	this->size = size;
	arr = new int[size];
}

Array::Array(const Array& other) {
    size = other.size;
    arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = other.arr[i];
    }
}

Array::~Array() {
    delete[] arr;
}

void Array::fill() {
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
}

void Array::show() {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Array::resize(int newSize) {
    int* temp = new int[newSize];

    int minSize = (newSize < size) ? newSize : size;

    for (int i = 0; i < minSize; i++) {
        temp[i] = arr[i];
    }

    delete[] arr;
    arr = temp;
    size = newSize;
}

void Array::sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void Array::showMin() {
    int min = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    cout << "Min: " << min << endl;
}

void Array::showMax() {
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    cout << "Max: " << max << endl;
}

int& Array::operator[](int index) {
    return arr[index];
}

void Array::operator()(int value) {
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] + value;
    }
}

Array::operator int() {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum = sum + arr[i];
    }
    return sum;
}

Array::operator char* () {
    static char buffer[1000];

    int pos = 0;

    for (int i = 0; i < size; i++) {

        int num = arr[i];

        if (num == 0) {
            buffer[pos++] = '0';
            buffer[pos++] = ' ';
            continue;
        }
        if (num < 0) {
            buffer[pos++] = '-';
            num = -num;
        }
        int div = 1;
        while (num / div >= 10) {
            div = div * 10;
        }
        while (div > 0) {
            int digit = num / div;
            buffer[pos++] = digit + '0';
            num = num % div;
            div = div / 10;
        }

        buffer[pos++] = ' ';
    }

    buffer[pos] = '\0';

    return buffer;
}