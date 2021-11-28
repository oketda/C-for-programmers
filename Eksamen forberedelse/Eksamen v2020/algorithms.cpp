#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>

using namespace std;

int main() {
    vector<int> vec = {2, 5, 2, 5, 1, 5, 1};

    std::swap_ranges(vec.begin(), vec.begin() + 3, vec.end() - 3);
    cout << "a)" << endl;
    for (auto &e : vec)
        cout << e << endl;
    
    vec = {2, 5, 2, 5, 1, 5, 1};

    std::rotate(vec.begin(), vec.begin() + 1, vec.end());
    cout << "\nb)" << endl;
    for (auto &e : vec)
        cout << e << endl;

    vec = {2, 5, 2, 5, 1, 5, 1};

    std::transform(vec.begin(), vec.end(), vec.begin(), [] (int i) {return i*2;} );
    cout << "\nc)" << endl;
    for (auto &e : vec)
        cout << e << endl;

}