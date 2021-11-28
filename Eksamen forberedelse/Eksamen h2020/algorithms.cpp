#include <iostream>
#include <vector>
#include <thread>
#include <map>
#include <functional>

using namespace std;

class Map {
public:
    function<int(int)> func;
    
    Map (const function<int(int)> &func) : func(func) {}
};

std::vector<int> operator|(const std::vector<int> &input, const Map &map) {
    vector<int> result;

    for (auto &e : input) {
        result.emplace_back(map.func(e));
    }
    return result;
}

class Filter {
public:
    function<bool(int)> func;

    Filter (const function<bool(int)> &func) : func(func) {}
};

vector<int> operator|(const vector<int> &input, const Filter &filter) {
    vector <int> result;

    for (auto &e : input) {
        if (filter.func(e)) {
            result.emplace_back(e);
        }
    }
    return result;
}

std::ostream &operator<<(std::ostream &os, const vector<int> &vec) {
    os << '{';

    for (size_t i = 0; i < vec.size(); i++) {
        os << vec[i];
        if (i != vec.size()-1) {
            os << ", ";
        }
    }
    os << '}';

    return os;
}

int main() {
    vector<int> vec = {1, 2, 3};
    vector<int> vecMultipliedBy2 = vec | Map([](int e) { return e * 2; });
    cout << vecMultipliedBy2 << endl;
    vector<int> vecFiltered = vec | Filter([](int e) { return e % 2 == 1; });
    cout << vecFiltered << endl;
}