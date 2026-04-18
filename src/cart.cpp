#include "../includes/cart.h"
#include "../includes/catalog.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int addToCart(Product p[100], int pCount, Product cart[100], int cartCount)
{
    int id, qty;
    cout << "\nEnter Product ID: ";
    cin >> id;
    int index = -1;
    for (int i = 0; i < pCount; i++)
    {
        if (p[i].productID == id)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Product not found.\n";
        return cartCount;
    }

    cout << "Enter quantity: ";
    cin >> qty;
    if (qty <= 0 || qty > p[index].stock)
    {
        cout << "Invalid or Not Enough quantity (Available: " << p[index].stock << ").\n";
        return cartCount;
    }

    cart[cartCount] = p[index];
    cart[cartCount].stock = qty;

    cartCount++;
    p[index].stock -= qty;
    cout << "\n Added to cart successfully.\n";
    return cartCount;
}

int removeFromCart(Product p[100], int pCount, Product cart[100], int cartCount)
{
    if (cartCount == 0)
    {
        cout << "Cart empty.\n";
        return cartCount;
    }
    int id;
    cout << "Enter Product ID to remove: ";
    cin >> id;
    int index = -1;
    for (int i = 0; i < cartCount; i++)
    {
        if (cart[i].productID == id)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        cout << "Not in cart.\n";
        return cartCount;
    }

    for (int i = 0; i < pCount; i++)
    {
        if (p[i].productID == id)
        {
            p[i].stock += cart[index].stock;
            break;
        }
    }
    for (int i = index; i < cartCount - 1; i++)
    {
        cart[i] = cart[i + 1];
    }
    cartCount--;
    cout << "\n Removed from cart.\n";
    return cartCount;
}

void viewCart(Product cart[100], int cCount)
{
    if (cCount == 0)
    {
        cout << "\nCart is empty.\n";
        return;
    }
    double total = 0;
    cout << "\n============== YOUR CART ==============\n";
    cout << left << setw(10) << "ID" << setw(15) << "Company" << setw(20) << "Model Name" << setw(10) << "Qty" << setw(12) << "Subtotal" << endl;
    cout << "----------------------------------------------------------------\n";
    for (int i = 0; i < cCount; i++)
    {
        double sub = cart[i].price * cart[i].stock;
        total += sub;
        cout << left << setw(10) << cart[i].productID << setw(15) << cart[i].company << setw(20) << cart[i].model << setw(10) << cart[i].stock << setw(12) << fixed << setprecision(2) << sub << endl;
    }
    cout << "----------------------------------------------------------------\n";
    cout << "Total = " << fixed << setprecision(2) << total << endl;
}

bool checkout(Product p[100], int pCount, Product cart[100], int cCount)
{
    if (cCount == 0)
    {
        cout << "Cart empty.\n";
        return false;
    }
    viewCart(cart, cCount);
    char x;
    cout << "\nConfirm purchase (y/n): ";
    cin >> x;
    if (x != 'y' && x != 'Y')
    {
        cout << "\nCancelled. Restoring stock.\n";
        for (int i = 0; i < cCount; i++)
        {
            for (int j = 0; j < pCount; j++)
            {
                if (cart[i].productID == p[j].productID)
                {
                    p[j].stock += cart[i].stock;
                    break;
                }
            }
        }
        return false;
    }
    double total = 0;
    for (int i = 0; i < cCount; i++)
        total += cart[i].price * cart[i].stock;
    double discount = (total > 500000) ? total * 0.20 : 0;
    double finalAmount = total - discount;

    cout << fixed << setprecision(2);
    cout << "\n\n";
    cout << "\t*******************************************\n";
    cout << "\t* PAYMENT SUMMARY             *\n";
    cout << "\t*******************************************\n";
    cout << "\t" << left << setw(25) << "Total Amount:" << right << setw(12) << total << " PKR\n";
    cout << "\t" << left << setw(25) << "Discount:" << right << setw(12) << discount << " PKR\n";
    cout << "\t-------------------------------------------\n";
    cout << "\t" << left << setw(25) << "FINAL PAYABLE:" << right << setw(12) << finalAmount << " PKR\n";
    cout << "\t*******************************************\n";

    saveProducts(p, pCount);
    generateReceipt(cart, cCount, total, discount, finalAmount);
    cout << "\n\t>>> Purchase Successful! Receipt Generated. <<<\n";
    return true;
}

void generateReceipt(Product cart[100], int cCount, double total, double discount, double finalAmount)
{
    string name;
    string phone;
    cin.ignore();
    cout << "\nEnter your Name: ";
    getline(cin, name);
    do {
        cout << "Enter your Phone Number (11 digits): ";
        cin >> phone;
        if(phone.length() != 11) {
            cout << "Invalid number. Must be exactly 11 digits.\n";
        }
    } while(phone.length() != 11);

    ofstream receipt("receipt.txt");
    receipt << fixed << setprecision(2);
    receipt << "****************************************************************\n";
    receipt << "                      ELECTRO STORE RECEIPT                     \n";
    receipt << "****************************************************************\n";
    receipt << " Customer Name : " << name << "\n";
    receipt << " Phone Number  : " << phone << "\n";
    receipt << "****************************************************************\n";
    receipt << left << setw(10) << "ID" << setw(25) << "Product" << setw(10) << "Qty" << setw(15) << "Subtotal" << endl;
    receipt << "----------------------------------------------------------------\n";

    for (int i = 0; i < cCount; i++)
    {
        double sub = cart[i].price * cart[i].stock;
        string fullName = cart[i].company + " " + cart[i].model;
        receipt << left << setw(10) << cart[i].productID << setw(25) << fullName << setw(10) << cart[i].stock << setw(15) << sub << endl;
    }

    receipt << "----------------------------------------------------------------\n";
    receipt << right << setw(45) << "Total Amount : " << setw(10) << total << " PKR\n";
    receipt << right << setw(45) << "Discount     : " << setw(10) << discount << " PKR\n";
    receipt << "----------------------------------------------------------------\n";
    receipt << right << setw(45) << "FINAL PAYABLE: " << setw(10) << finalAmount << " PKR\n";
    receipt << "****************************************************************\n";
    receipt << "                    THANK YOU FOR SHOPPING!                     \n";
    receipt << "****************************************************************\n";

    receipt.close();
}