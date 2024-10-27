// Electronics.cpp
#include "Electronics.h"

Electronics::Electronics(const std::string& name, double price, int warranty_years)
    : Item(name, price), warranty_years(warranty_years) {}

void Electronics::display() const {
    Item::display();
    std::cout << ", Warranty: " << warranty_years << " years" << std::endl;
}

void Electronics::persist(std::ofstream& out) const {
    out << "Electronics " << name << " " << price << " " << warranty_years << std::endl;
}

Item* Electronics::restore(std::ifstream& in) {
    std::string name;
    double price;
    int warranty_years;
    in >> name >> price >> warranty_years;
    return new Electronics(name, price, warranty_years);
}
