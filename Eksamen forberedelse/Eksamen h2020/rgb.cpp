#include <iostream>
#include <vector>
#include <thread>

using namespace std;

template <typename T>
class RGB {
    int norm(int val) {
        if (val > 255) {
            return 255;
        } else {
            return val;
        }
    }

    double norm(double val) {
        if (val > 1) {
            return 1;
        } else {
            return val;
        }
    }

public:
    T r, g, b;
    
    RGB(T r, T g, T b) : r(norm(r)), g(norm(g)), b(norm(b)) {}
    RGB(T val) : r(norm(val)), g(norm(val)), b(norm(val)) {}

    RGB operator+(const RGB &rgb) const {
        return RGB(r + rgb.r, g + rgb.g, b + rgb.b);
    }

    RGB operator+(const T val) const {
        return RGB(r + val, g + val, + b + val);
    }

    friend ostream &operator<<(ostream &stream, const RGB &rgb) {
        return stream << "(" << rgb.r << ", " << rgb.g << ", " << rgb.b << ")";
    }

};

int main() {
    {
        RGB<double> rgb(0.5);
        std::cout << rgb << std::endl;
        std::cout << rgb + 0.3 << std::endl;
        std::cout << rgb + 0.3 + RGB<double>(0.5, 0.1, 0.1) << std::endl;
    }
    {
        RGB<int> rgb(130);
        std::cout << rgb << std::endl;
        std::cout << rgb + 60 << std::endl;
        std::cout << rgb + 60 + RGB<int>(100, 30, 30) << std::endl;
    }
}
