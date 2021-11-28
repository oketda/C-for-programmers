#include <cmath>
#include <iostream>
#include <thread>
#include <vector>
#include <functional>
#include <memory>

using namespace std;

template <typename T>
    ostream &operator<<(ostream &stream, const std::vector<T> &vec) {
        stream << "{ ";

        for (size_t i = 0; i < vec.size(); i++) {
            stream << vec[i];
            if (i + 1 != vec.size()) {
                stream << ", ";
            }
        }
        stream << " }";
        return stream;
    }


std::vector<int> operator*(const std::vector<int> &vec, int num) {
    std::vector<int> output;
    for (size_t i = 0; i < vec.size(); i++) {
        output.emplace_back(vec[i]*num);
    }
    return output;
}

std::vector<int> operator*(const std::vector<int> &vec1, const std::vector<int> &vec2) {
    std::vector<int> output;
    for (size_t i = 0; i < vec1.size(); i++) {
        output.emplace_back(vec1[i]*vec2[i]);
    }  
    return output;
}

int main() {
    cout << std::vector<int>() << endl;
    cout << std::vector<float>({1.5, 2.5}) << endl;
    
    std::vector<int> vec = {1, 2, 3};
    cout << vec << endl;
    cout << vec * 3 << endl;
    cout << vec * vec << endl;
}