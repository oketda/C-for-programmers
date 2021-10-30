#include <iostream>

using namespace std;

int main() {
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    //a)
    cout << "i: Address: " << &i << ", content: " << i << endl;
    cout << "j: Address: " << &j << ", content: " << j << endl;
    cout << "p: Address: " << &p << ", content: " << p << endl;
    cout << "q: Address: " << &q << ", content: " << q << endl;
    
    //b)
    *p = 7; //i = 7
    *q += 4; //j = 9
    *q = *p + 1; //j = 8
    p = q; //p points to j
    cout << *p << " " << *q << endl; //Both prints 8

    int &b = i;
}