#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


// - sample func
int addNumbers(int firstNum, int secNum = 0) {
    int combinedVal = firstNum + secNum;
    return combinedVal;
}

// - overloaded func
int addNumbers(int firstNum, int secNum, int thirdNum) {
    return firstNum + secNum + thirdNum;
}

int getFactorial(int num) {
    int sum;

    if(num == 1)  {
        sum = 1;
    } else {
        sum = getFactorial(num - 1) * num;
    }
    return sum;
}

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

    //----- Vectors
    vector <int> myVector(10);

    int myNumArr[5] = {5, 46, 77, 99, 88};

    myVector.insert(myVector.begin(), myNumArr, myNumArr+3);

    cout << "myVector.at(2):" << myVector.at(2) << endl;
    cout << "myVector.size:" << myVector.size() << endl;

    for (auto it = begin (myVector); it != end (myVector); ++it) {
//        it->doSomething ();
        cout << ' ' << *it;
    }
    cout << '\n';

    for (std::vector<int>::iterator it = myVector.begin() ; it != myVector.end(); ++it) {
        cout << ' ' << *it;
    }
    cout << '\n';

    // - functions
    cout << addNumbers(10) << endl;
    // - overloading func
    cout << addNumbers(10, 20, 30) << endl;

    // recursive func
    cout << "\n getFactorial(2): " << getFactorial(2);
    cout << "\n getFactorial(3): " << getFactorial(3);


    // file IO
    string myQuote = "Horse went into to the ditch";
    string _fileName = "myquote.txt";

    // writting
    ofstream writer(_fileName);
    if(!writer) {
        cout << "Error opening file: " << endl;
        return -1;
    } else {
        writer << myQuote << endl;
        writer.close();
    }
    ofstream writer2(_fileName, ios::app);


    cout << '\n';
    char letter;
    ifstream reader(_fileName);
    if(!reader) {
        cout << "Error reading file: " << endl;
        return -1;
    } else {
        for(int i = 0; !reader.eof(); i++) {
            reader.get(letter);
            cout << letter;
        }
        cout << '\n';
        reader.close();
    }

    cout << "\n----- END -----" << endl;
    
    return 0;
}

