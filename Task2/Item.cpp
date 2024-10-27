// Item.cpp
#include "Item.h"
#include "Grocery.h"
#include "Electronics.h"

Item::Item(const std::string& name, double price) : name(name), price(price) {}

Item::~Item() {}

void Item::display() const {
    std::cout << "Name: " << name << ", Price: $" << price;
}

void Item::persist(std::ofstream& out) const {
    out << "Item " << name << " " << price << std::endl;
}

Item* Item::restore(std::ifstream& in) {
    std::string type;
    in >> type;
    if (type == "Grocery") {
        return Grocery::restore(in);
    }
    if (type == "Electronics") {
        return Electronics::restore(in);
    }
    return nullptr;
}
