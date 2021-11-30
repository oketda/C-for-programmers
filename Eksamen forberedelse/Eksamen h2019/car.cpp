#include <iostream>
#include <vector>
#include <thread>

using namespace std;

class Gasoline {
public:
    static string str() {return "gasoline";}
};

class Electric {
public:
    static string str() {return "electric";}
};

class Car {
public:
    virtual ~Car() {}

    virtual string brand() const = 0;
    virtual string engine() const = 0;

    friend ostream &operator<<(ostream &os, const Car &car) {
        return os << car.brand() << " with " << car.engine() << " engine";
    }
};

template <class Motor>
class Saab : public Car {
public:
    Saab() : Car() {}

    string brand() const override {
        return "Saab";
    }

    string engine() const override {
        return Motor::str();
    }
};

template <class Motor>
class Volvo : public Car {
public:
    Volvo() : Car() {}

    string brand() const override {
        return "Volvo";
    }

    string engine() const override {
        return Motor::str();
    }
};

int main() {
    vector<unique_ptr<Car>> cars;

    cars.emplace_back(new Saab<Electric>());
    cars.emplace_back(new Saab<Gasoline>());
    cars.emplace_back(new Volvo<Electric>());

    for (auto &car : cars) {
        cout << *car << endl;
    }

}
