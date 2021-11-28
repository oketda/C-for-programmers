#include <cmath>
#include <iostream>
#include <thread>
#include <vector>
#include <functional>
#include <memory>

using namespace std;

template <typename T>
class Angle {

    int norm(int val) {
        while(val > 360) {
            val = val-360;
        }
        return val;
    }

    double norm(double val) {
        while(val > 3.14159265359) {
            val = val-3.14159265359;
        }
        return val;
    }

public:

    T value;

    Angle(T value) : value(norm(value)) {}

    friend ostream &operator<<(ostream &stream, const Angle &angle) {
        return stream << angle.value;
    }
};

int main() {
    Angle<int> angle1(30);
    cout << angle1 << endl;
    Angle<int> angle2(390);
    cout << angle2 << endl;
    Angle<double> angle3(3.14159265359 / 2);
    cout << angle3 << endl;
    Angle<double> angle4(3.14159265359 * 1.5);
    cout << angle4 << endl;
}