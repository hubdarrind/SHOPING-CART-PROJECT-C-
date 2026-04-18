#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

struct Product
{
    int categoryID;
    int productID;
    std::string company;
    std::string model;
    double price;
    int stock;
};

#endif // PRODUCT_H