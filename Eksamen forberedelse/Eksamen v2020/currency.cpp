#include <iostream>
#include <vector>
#include <thread>

using namespace std;

class NorwegianKrone {
public:
    static double rate;
};
double NorwegianKrone::rate = 0.1;

class Euro {
public:
    static double rate;
};
double Euro::rate = 1.0;

template <class CurrencyType>
class Currency {
public:
    double amount;

    Currency(double amount) : amount(amount * CurrencyType::rate) {}

    template <class CurrencyType2>
    Currency operator+(const Currency<CurrencyType2> &other) {
        auto current = *this;
        current.amount += other.amount;
        return current;
    }

    friend ostream &operator<<(ostream &stream, const Currency &currency) {
        return stream << "€" << currency.amount;
    }
};

int main() {
    cout << Currency<NorwegianKrone>(1) << endl;
    cout << Currency<Euro>(1) << endl;
    cout << Currency<NorwegianKrone>(10) + Currency<Euro>(10) + Currency<NorwegianKrone>(10) << endl;
}
