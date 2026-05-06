#include "Array.h"
#include <iostream>
using namespace std;

int main() {

    Array a1(5);

    cout << "Fill array a1:" << endl;
    a1.fill();

    cout << "Array a1: ";
    a1.show();

    a1.showMin();
    a1.showMax();

    a1.sort();
    cout << "Sorted array a1: ";
    a1.show();

    cout << "Resize array to 7 elements:" << endl;
    a1.resize(7);

    cout << "Fill new elements:" << endl;
    a1.fill();

    cout << "Array after resize: ";
    a1.show();

    Array a2 = a1;

    cout << "Copied array a2: ";
    a2.show();

    cout << "Min of a2: ";
    a2.showMin();

    cout << "Max of a2: ";
    a2.showMax();


    cout << "a1[0] = " << a1[0] << endl;
    a1[0] = 999;
    cout << "After a1[0] = 999: ";
    a1.show();

    cout << "Add 10 to all elements: a1(10)" << endl;
    a1(10);
    a1.show();

    int sum = a1;
    cout << "Sum of a1: " << sum << endl;

    cout << "Array as string: " << (char*)a1 << endl;
}