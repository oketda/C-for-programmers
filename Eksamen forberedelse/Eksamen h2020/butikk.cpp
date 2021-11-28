#include <iostream>
#include <vector>
#include <thread>

using namespace std;

class Vare {
public:
    std::string navn;
    unsigned antall;

    Vare(const std::string &navn, unsigned antall) : navn(navn), antall(antall) {}
    virtual ~Vare() {}

    virtual double mva() const {
        return 0.25;
    }
};

class MatVare : public Vare {
public:
    MatVare(const std::string &navn, unsigned antall) : Vare(navn, antall) {}

    double mva() const override {
        return 0.15;
    }
};

class Butikk {
public:
    std::vector<std::unique_ptr<Vare>> varer;
};

main() {
    Butikk butikk;
    butikk.varer.emplace_back(new MatVare("NTNU-nistepakken", 5));
    butikk.varer.emplace_back(new Vare("NTNU-koppen", 10));

    for (auto &v : butikk.varer) {
        std::cout << v->navn << ", "
        << v->antall << ", "
        << v->mva() << std::endl;
    }
}