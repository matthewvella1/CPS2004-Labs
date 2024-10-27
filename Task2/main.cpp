// main.cpp
#include <iostream>
#include <vector>
#include <fstream>
#include "Item.h"
#include "Grocery.h"
#include "Electronics.h"

// Function to add items
void addItem(std::vector<Item*>& items) {
    std::string type;
    std::cout << "Enter item type (Grocery, Electronics): ";
    std::cin >> type;

    if (type == "Grocery") {
        std::string name, expiry_date;
        double price;
        std::cout << "Enter name, price, and expiry date: ";
        std::cin >> name >> price >> expiry_date;
        items.push_back(new Grocery(name, price, expiry_date));
    } else if (type == "Electronics") {
        std::string name;
        double price;
        int warranty_years;
        std::cout << "Enter name, price, and warranty (years): ";
        std::cin >> name >> price >> warranty_years;
        items.push_back(new Electronics(name, price, warranty_years));
    }
}

// Function to save items to file
void saveItems(const std::vector<Item*>& items, const std::string& filename) {
    std::ofstream out(filename);
    for (const auto& item : items) {
        item->persist(out);
    }
}

// Function to load items from file
void loadItems(std::vector<Item*>& items, const std::string& filename) {
    std::ifstream in(filename);
    while (in) {
        Item* item = Item::restore(in);
        if (item) items.push_back(item);
    }
}

// Function to display all items
void displayItems(const std::vector<Item*>& items) {
    for (const auto& item : items) {
        item->display();
    }
}

// Clean up dynamically allocated memory
void cleanUp(std::vector<Item*>& items) {
    for (auto& item : items) {
        delete item;
    }
    items.clear();
}

int main() {
    std::vector<Item*> items;
    std::string command;

    loadItems(items, "items.txt");

    while (true) {
        std::cout << "Enter 'add' to add item, 'show' to display all items, 'exit' to save and exit: ";
        std::cin >> command;

        if (command == "add") {
            addItem(items);
        } else if (command == "show") {
            displayItems(items);
        } else if (command == "exit") {
            saveItems(items, "items.txt");
            break;
        }
    }

    cleanUp(items); // Free allocated memory before exit
    return 0;
}
