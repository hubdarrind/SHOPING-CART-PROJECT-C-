#ifndef CART_H
#define CART_H

#include "product.h"

int addToCart(Product p[100], int pCount, Product cart[100], int cartCount);
int removeFromCart(Product p[100], int pCount, Product cart[100], int cartCount);
void viewCart(Product cart[100], int cCount);
bool checkout(Product p[100], int pCount, Product cart[100], int cCount);
void generateReceipt(Product cart[100], int cCount, double total, double discount, double finalAmount);

#endif // CART_H