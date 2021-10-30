#include "set.hpp"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

Set::Set(){
   this->set = std::vector<int>(); 
}

Set::Set(std::vector<int> set){
    for (size_t i = 0; i < set.size(); i++){
        this->set.emplace_back(set[i]);
    }
}

Set Set::operator+(const Set &other) const {
    Set tmp_set = *this;
    for (size_t i = 0; i < other.size(); i++) {
        if (!tmp_set.includes(other[i])) {
            tmp_set.set.emplace_back(other[i]);
        }
    }
    return tmp_set;
}

Set Set::operator+(const int &number) const {
    Set tmp_set = *this;
    if (!tmp_set.includes(number)) {
        tmp_set.set.emplace_back(number);
    }
    return tmp_set;
}

Set &Set::operator=(const Set &other) {
    this->set.clear();

    for (size_t i = 0; i < other.size(); i++) {
        this->set.emplace_back(other[i]);
    }
    return *this;
}

int Set::operator[](const int &i) const {
    return this->set[i];
}

int Set::operator[](const size_t &i) const {
    return this->set[i];
}

bool Set::includes(const int &number) const {
    for (size_t i = 0; i < this->set.size(); i++){
        if (this->set[i] == number){
            return true;
        }
    }
    return false;
}

size_t Set::size() const {
    return this->set.size();
}

std::string Set::print() const {
    std::string returnValue = "{";
    for (size_t i = 0; i < this->size(); i++) {
        int num = this->operator[](i);
        if (i+1 == this->size()) {
            returnValue += std::to_string(num);
        } else {
            returnValue += std::to_string(num);
            returnValue += ", ";
        }
    }
    returnValue += "}";
    return returnValue;
}