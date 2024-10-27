// Electronics.h
#ifndef ELECTRONICS_H
#define ELECTRONICS_H

#include "Item.h"

class Electronics : public Item {
    int warranty_years;

public:
    Electronics(const std::string& name, double price, int warranty_years);

    void display() const override;
    void persist(std::ofstream& out) const override;

    static Item* restore(std::ifstream& in);
};

#endif // ELECTRONICS_H
