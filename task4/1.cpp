#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    vector<double> numbers;

    numbers.emplace_back(2.4);
    numbers.emplace_back(6.8);
    numbers.emplace_back(1.5);
    numbers.emplace_back(8.2);
    numbers.emplace_back(12);

    // for (size_t i = 0; i < numbers.size(); i++)  {
    //     cout << numbers[i] << endl;
    // }
    

    double front = numbers.front();
    double back = numbers.back();

    cout << "front: " << front << endl;
    cout << "back: " << back << endl;

    numbers.emplace(numbers.begin()+1, 2.1);
    cout << "front: " << numbers.front() << endl;
    //cout << "position 1: " << numbers[1] << endl; //Where 2.1 is placed

    auto found = find(numbers.begin(), numbers.end(), 2.1);

    if (found != numbers.end()) {
        cout << "Element found in numbers: " << *found << endl;
    } else {
        cout << "Element not found in numbers." << endl;
    }

}