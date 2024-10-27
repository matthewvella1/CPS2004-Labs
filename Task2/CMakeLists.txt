cmake_minimum_required(VERSION 3.5.0)
project(ShoppingItems VERSION 0.1.0 LANGUAGES C CXX)

add_executable(ItemManager
    main.cpp
    Item.cpp
    Grocery.cpp
    Electronics.cpp
)
