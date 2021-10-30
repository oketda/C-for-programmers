#include <iostream>

using namespace std;

int main() {
    double number = 2;
    double *const pointer = &number;
    double &ref = number;
    cout << "Original value: " << number << endl;

    //1
    number = 3;
    cout << "Variable changed value: " << number << endl;

    //2
    *pointer = 4;
    cout << "Pointer changed value: " << number << endl;
    
    //3
    ref = 5;
    cout << "Reference changed value: " << ref << endl;
}