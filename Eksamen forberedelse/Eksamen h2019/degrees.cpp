#include <iostream>

using namespace std;

class Hot {
public:
    friend ostream &operator<<(ostream &os, const Hot &) {
        os << "hot";
        return os;
    }
};

class Cold {
public:
    friend ostream &operator<<(ostream &os, const Cold &) {
        os << "cold";
        return os;
    }
};

class Degrees {
public:
    Hot operator+() {
        return Hot();
    }

    Cold operator-() {
        return Cold();
    }
};


int main() {
    Degrees degrees;
    cout << +degrees << endl;
    cout << -degrees << endl;
}