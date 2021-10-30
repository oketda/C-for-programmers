#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &table) {
  for (auto &e : table)
    out << e << " ";
  return out;
}

bool biggerThan15(int i) {
    return i > 15;
}

bool max2InDifference(int a, int b) {
  return abs(a-b) <= 2;
}

bool isOdd(int i) {
  return (i%2) == 1;
}

int main() {
    vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
    cout << "v1: " << v1 << endl;

    vector<int> v2 = {2, 3, 12, 14, 24};
    cout << "v2: " << v2 << endl;

    auto pos = find_if(v1.begin(), v1.end(), biggerThan15);

    cout << "a) " << *pos << endl;

    auto b = equal(v1.begin(), v1.begin()+5, v2.data(), max2InDifference);
    cout << "b1) " << b << endl;

    b = equal(v1.begin(), v1.begin()+4, v2.begin(), max2InDifference);
    cout << "b2) " << b << endl;

    replace_copy_if(v1.begin(), v1.end(), v1.begin(), isOdd, 100);
    cout << "c) " << v1 << endl;
}