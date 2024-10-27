// Grocery.cpp
#include "Grocery.h"

Grocery::Grocery(const std::string& name, double price, const std::string& expiry_date)
    : Item(name, price), expiry_date(expiry_date) {}

void Grocery::display() const {
    Item::display();
    std::cout << ", Expiry Date: " << expiry_date << std::endl;
}

void Grocery::persist(std::ofstream& out) const {
    out << "Grocery " << name << " " << price << " " << expiry_date << std::endl;
}

Item* Grocery::restore(std::ifstream& in) {
    std::string name, expiry_date;
    double price;
    in >> name >> price >> expiry_date;
    return new Grocery(name, price, expiry_date);
}
