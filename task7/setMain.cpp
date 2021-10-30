#include "set.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    vector<int> vec1 {1, 4, 3};
    vector<int> vec2 {4, 7};

    Set a(vec1);
    Set b(vec2);
    
    Set c;
    cout << "c: " << c.print() << endl;
    c = a + 2;
    cout << "c: " << c.print() << endl;

    cout << "a: " << a.print() << endl;
    a = b;
    cout << "a: " << a.print() << endl;

    cout << "b: " << b.print() << endl;
    b = b + 2;
    cout << "b: " << b.print() << endl;
    b = b + 4;
    cout << "b: " << b.print() << endl;
}