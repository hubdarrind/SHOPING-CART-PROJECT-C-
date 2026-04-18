#include <iostream>
#include "../includes/product.h"
#include "../includes/auth.h"
#include "../includes/catalog.h"
#include "../includes/cart.h"

using namespace std;

int main()
{
    if (!authSystem())
    {
        cout << "Exiting program. Goodbye!\n";
        return 0;
    }

    Product products[100], cart[100];
    int productCount = loadProducts(products);
    int cartCount = 0;

    if (productCount == 0)
    {
        cout << "Unable to load products. Make sure 'products.txt' exists.\n";
        return 0;
    }

    cout << "\n============================================\n";
    cout << "          WELCOME TO ELECTRO STORE\n";
    cout << "============================================\n";

    int choice;

    do
    {
        cout << "\n------------- MAIN MENU -------------\n";
        cout << "1. View Categories\n";
        cout << "2. Search Products\n";
        cout << "3. Add to Cart\n";
        cout << "4. Remove From Cart\n";
        cout << "5. View Cart\n";
        cout << "6. Checkout\n";
        cout << "7. Exit\n";
        cout << "-------------------------------------\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            showCategories(products, productCount);
        }
        else if (choice == 2)
        {
            searchProducts(products, productCount);
        }
        else if (choice == 3)
        {
            cartCount = addToCart(products, productCount, cart, cartCount);
        }
        else if (choice == 4)
        {
            cartCount = removeFromCart(products, productCount, cart, cartCount);
        }
        else if (choice == 5)
        {
            viewCart(cart, cartCount);
        }
        else if (choice == 6)
        {
            if (checkout(products, productCount, cart, cartCount))
            {
                cout << "\nExiting Program. Have a nice day!\n";
                break;
            }
        }
        else if (choice != 7)
        {
            cout << "Invalid choice.\n";
        }

    } while (choice != 7);

    return 0;
}