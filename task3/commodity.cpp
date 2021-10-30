#include "commodity.hpp"
#include <iostream>
#include <string>

using namespace std;

Commodity::Commodity(const string &name_, int id_, double price_) : name(name_), id(id_), price(price_) {}

double Commodity::get_price(const double &quantity) {
    return quantity*price;
}

void Commodity::set_price(double price_) {
    price = price_;
}

double Commodity::get_price_with_sales_tax(const double &quantity) {
    return quantity*(price + (price*sales_tax));
}