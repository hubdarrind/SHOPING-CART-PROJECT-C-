#ifndef CATALOG_H
#define CATALOG_H

#include "product.h"

int loadProducts(Product p[100]);
void saveProducts(Product p[100], int count);
void showCategories(Product p[100], int count);
void showProductsInCategory(Product p[100], int count, int catID);
void searchProducts(Product p[100], int count);

#endif // CATALOG_H