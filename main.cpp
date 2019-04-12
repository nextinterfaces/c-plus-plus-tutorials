#include <iostream>
#include <vector>

using namespace std;

// This is a comment
int main() {

    cout << "Hello, World!" << endl;

    const double PI = 3.14;

    char myChar = 'A';

    int myAge = 123;

    cout << "My age is: " << myAge << endl;

    cout << "Sife of int: " << sizeof(myAge)
                            << endl;

    char provinces[5][2] = {
            {'B', 'C'},
            {'A', 'B'},
            {'M', 'A'},
            {'Q', 'C'},
            {'O', 'N'}
    };

    cout << provinces << "\n2nd letter in 4 row: " << provinces[3][1] << endl;
    cout << "Index out of bounds: " << provinces[333][1111] << endl;

    return 0;
}