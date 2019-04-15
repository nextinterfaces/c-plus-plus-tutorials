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

void makeMeYoung(int* age) {
    cout << "I used to be" << *age << endl;
    *age = 21;
}

void actYourAge(int* age) {
    *age = 39;
}

class Animal {
    private:
        int height;
        int weight;
        string name;

        static int numOfAnimals;

    public:
        int getHeight(){ return height; }
        int getWeight(){ return weight; }
        string getName(){ return name; }
        void setHeight(int h){ height = h; }
        void setName(string name){ this -> name = name; }

    // prototype of a function
    void setAll(int, int, string);
    // prototype of constructor
    Animal(int, int, string);

    // destructor
    ~Animal();

    // overloaded constructor
    Animal();

    static int getNumOfAnimals() {return numOfAnimals;}

    void toString();
};

// ---- declare the class variables
int Animal::numOfAnimals = 0;
void Animal::setAll(int height, int w, string n) {
    this -> height = height;
    this -> weight = w;
    this -> name = n;
    Animal::numOfAnimals++;
}

Animal::Animal(int h, int w, string n) {
    this -> setAll(h,  w,  n);
}

Animal::~Animal() {
    cout << "Animal " << this -> name << " destroyed. Num of animals: "  << Animal::numOfAnimals << endl;
}

Animal::Animal() {
    Animal::numOfAnimals++;
}

void Animal::toString() {
    cout << "Animal(" << (this -> name) << ", " << (this -> height) << "cm, " << (this -> weight) << "kg)" << endl;
}

// --- Overriding Animal class
class Dog : public Animal {

private:
    string sound = "Woof";

public:
    void getSound() { cout << sound << endl; }

    // new constructor
    Dog(int, int, string, string);

    // override parent constructor
    Dog() : Animal(){};

    void toString();
};

//// Implementing Dog
//Dog::Dog(int height, int weight, int name, string bark) :
//Animal(height, weight, name) {
//    this -> sound = bark;
//}

void Dog::toString() {
    cout << "Dog(" << (this -> getName()) << ", " << (this -> getHeight()) << "cm, " << (this -> getWeight()) << "kg)" << endl;
}


//============================
//---- Mutliple inheritance
class LivingThing {
protected:
    void breathe() {
        std::cout << "I'm breathing as a LivingThing." << std::endl;
    }
};

class LivingAnimal : protected LivingThing {
protected:
    void breathe() {
        std::cout << "I'm breathing as an LivingAnimal." << std::endl;
    }
};

class Reptile : protected LivingThing {
protected:
    void crawl() {
        std::cout << "I'm crawling as a Reptile." << std::endl;
    }
};

class Snake : protected LivingAnimal, protected Reptile {
public:
    void breathe() {
        std::cout << "I'm breathing as a Snake." << std::endl;
    }

    void crawl() {
        std::cout << "I'm crawling as a snake." << std::endl;
    }
};


// This is a comment
int main() {

    cout << "Hello, World!" << endl;

    const double PI = 3.14;

    char myChar = 'A';

    int myAge = 39;

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

    // Exception handling
    int aNum = 0;
    try {
        if(aNum != 0) cout << " no exception, num is:" << aNum;
        else throw(aNum);
    } catch (int number) {
        cout << "ERROR: division by zero: " << number << endl;
    }

    // Pointers
    // a number
    int pNum = 39;
    cout << "'pNum' is located at: " << &pNum << endl;
    // a number by pointer
    int* pNumPointer = &pNum;
    cout << "'pNumPointer' address of pointer located at: " << pNumPointer << endl;
    // a dereferenced pointer
    cout << "Dereferenced data '*pNumPointer' at memory address: " << *pNumPointer << endl;

    int pArr[5] = {5, 46, 77, 99, 88};
    int* pArrPointer = pArr;
    cout << "Address: " << pArrPointer << ", Value: " << *pArrPointer << endl;
    pArrPointer ++;
    cout << "Changed pointer, Address: " << pArrPointer << ", Value: " << *pArrPointer << endl;

    cout << "Address: " << pArr << ", Value: " << *pArr << endl;

    makeMeYoung(&myAge);
    cout << "Iam " << myAge << endl;

    int& ageRef = myAge;
    cout << "my Age:" << myAge << endl;

    ageRef++;
    cout << "my Age:" << myAge << endl;

    actYourAge(&ageRef);
    cout << "my Age:" << myAge << endl;

    Animal fred;
    fred.setHeight(33);
    fred.setName("Fred");
    fred.toString();

    Animal tom(36, 15, "Tom");
    tom.toString();

//    Dog sparky(36, 15, "Sparky", "Woof Woof");
//    sparky.toString();
//    // calling super class
//    sparky.Animal::toString();
//    cout << "num of animals:" << Animal::getNumOfAnimals() << endl;


    // -- Multiple inheritance
    Snake snake;
    // could be instantiated this way too
//    Snake *snake2 = new Snake;
    snake.breathe();
    snake.crawl();




    //--------------------
    cout << "\n----- END -----" << endl;
    
    return 0;
}

