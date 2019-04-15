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

    char arr[5][2] = {
            {'B', 'C'},
            {'A', 'B'},
            {'M', 'A'},
            {'Q', 'C'},
            {'O', 'N'}
    };

    cout << arr << "\n 2 nd letter in 4 row: " << arr[3][1] << endl;
    cout << "Index out of bounds: " << arr[333][1111] << endl;

//    for (int i = 0; i < sizeof(arr); ++i) {
//        cout << arr[i] << endl;
//        for (int j = 0; j < sizeof(arr[i][j]); ++j) {
//            cout << "i is: " << i << ", j is: " << j << arr[i][j] << endl;
//        }
//    }


    char chars[7] = { 'H', 'a', 'p', 'p', 'y' };
    string someStr = " Birthday!";

    cout << chars + someStr << endl;

    string yourName;

//    cout << "What is your name (type it here): ";
//    getline(cin, yourName);
//    cout << "hello " << yourName;

    int randNum = (rand() % 100) +1;

    cout << "\n random num is: " << randNum << endl;


    return 0;
}