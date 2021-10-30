#include <iostream>

using namespace std;

template <typename Type>
bool equal(Type a, Type b) {
    return a == b;
}

bool equal(double a, double b) {
    return a-b < 0.00001;
}

int main() {
    int a = 1;
    int b = 2;
    cout << a << " = " << b << " is: " << equal(a, b) << endl;

    b = 1;
    cout << a << " = " << b << " is: " << equal(a, b) << endl;

    double c = 5;
    double d = 4.99999;
    cout << c << " = " << d << " is: " << equal(c, d) << endl;

    d = 4.99998;
    cout << c << " = " << d << " is: " << equal(c, d) << endl;
}