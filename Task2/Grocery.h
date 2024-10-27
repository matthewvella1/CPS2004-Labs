// Grocery.h
#ifndef GROCERY_H
#define GROCERY_H

#include "Item.h"

class Grocery : public Item {
    std::string expiry_date;

public:
    Grocery(const std::string& name, double price, const std::string& expiry_date);

    void display() const override;
    void persist(std::ofstream& out) const override;

    static Item* restore(std::ifstream& in);
};

#endif // GROCERY_H
