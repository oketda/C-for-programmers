#include <iostream>

using namespace std;

int find_sum(const int *table, int length) {
    int sum = 0;

    for (size_t i = 0; i < length; i++)
    {
        sum += table[i];
    }

    return sum;
}

int main() {
    int size = 20;
    int table[size];

    for (size_t i = 0; i < size; i++) {
        table[i] = i+1;
    }

    //10 first
    int sum = find_sum(table, 10);
    cout << "Sum of first 10 numbers is: " << sum << endl;

    //Next 5
    sum = find_sum(&table[10], 5);
    cout << "Sum of next 5 numbers is: " << sum << endl;

    //5 last
    sum = find_sum(&table[15], 5);
    cout << "Sum of last 5 numbers is: " << sum << endl;
    
}