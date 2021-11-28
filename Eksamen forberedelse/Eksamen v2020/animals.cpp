#include <iostream>
#include <vector>
#include <thread>

using namespace std;

class Animal {
public:
    std::string name;

    Animal(const std::string &name) : name(name) {}
    virtual ~Animal() {}

    virtual std::string type() const = 0;

    friend ostream &operator<<(ostream &stream, const Animal &animal) {
        return stream << animal.type() << " named " << animal.name;
    }
};

class Cat : public Animal {
public:
    Cat(const std::string &name) : Animal(name) {}

    std::string type() const override {
        return "Cat";
    }
};

class Dog : public Animal {
public:
    Dog(const std::string &name) : Animal(name) {}

    std::string type() const override {
        return "Dog";
    }
};

main() {
    vector<unique_ptr<Animal>> animals;
    animals.emplace_back(new Cat("Oreo"));
    animals.emplace_back(new Dog("Buddy"));
    animals.emplace_back(new Dog("Charlie"));
// animals.emplace_back(new Animal()); 
// Should causecompilation error
// animals.emplace_back(new Animal("Max")); 
// Should causecompilation                                                     
    // error
for (auto &animal : animals)
  cout << *animal << endl;

}
