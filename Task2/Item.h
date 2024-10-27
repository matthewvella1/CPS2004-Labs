// Item.h
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <fstream>

class Item {
protected:
    std::string name;
    double price;

public:
    Item(const std::string& name, double price);
    virtual ~Item();

    virtual void display() const;
    virtual void persist(std::ofstream& out) const;

    static Item* restore(std::ifstream& in);
};

#endif // ITEM_H
