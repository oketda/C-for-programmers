#include <vector>
#include <string>

#pragma once

class Set{
    public:
        std::vector<int> set;

        Set();
        Set(std::vector<int> set);
        Set operator+(const Set &other) const;
        Set operator+(const int &number) const;
        Set &operator=(const Set &other);
        int operator[](const int &i) const;
        int operator[](const size_t &i) const;
        bool includes(const int &number) const;
        size_t size() const;
        std::string print() const;
};