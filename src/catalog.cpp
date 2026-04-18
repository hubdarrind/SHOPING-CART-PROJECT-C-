#include "../includes/catalog.h"
#include "../includes/utils.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int loadProducts(Product p[100])
{
    ifstream file("products.txt");
    if (!file)
        return 0;
    int i = 0;
    while (file >> p[i].categoryID >> p[i].productID >> p[i].company >> p[i].model >> p[i].price >> p[i].stock)
    {
        i++;
    }
    return i;
}

void saveProducts(Product p[100], int count)
{
    ofstream file("products.txt");
    for (int i = 0; i < count; i++)
    {
        file << p[i].categoryID << " " << p[i].productID << " " << p[i].company << " " << p[i].model << " " << p[i].price << " " << p[i].stock << endl;
    }
}

void showCategories(Product p[100], int count)
{
    cout << "\n-------------- CATEGORIES --------------\n";
    cout << "1. Laptop\n2. Mouse\n3. Keyboard\n4. Charger\n";
    cout << "----------------------------------------\n";
    cout << "Choose category: ";
    int choice;
    cin >> choice;
    if (choice >= 1 && choice <= 4)
        showProductsInCategory(p, count, choice);
    else
        cout << "Invalid category choice.\n";
}

void showProductsInCategory(Product p[100], int count, int catID)
{
    cout << "\n================ Category " << catID << " ================\n";
    cout << left << setw(10) << "ID" << setw(15) << "Company" << setw(20) << "Model Name" << setw(12) << "Price" << setw(10) << "Stock" << endl;
    cout << "----------------------------------------------------------------\n";
    for (int i = 0; i < count; i++)
    {
        if (p[i].categoryID == catID)
        {
            cout << left << setw(10) << p[i].productID << setw(15) << p[i].company << setw(20) << p[i].model << setw(12) << fixed << setprecision(2) << p[i].price << setw(10) << p[i].stock << endl;
        }
    }
}

void searchProducts(Product p[100], int count)
{
    string query;
    cout << "\nEnter product name to search: ";
    cin.ignore();
    getline(cin, query);

    string lowerQuery = toLowerCase(query);
    bool foundAny = false;

    cout << "\n---------------- SEARCH RESULTS ----------------\n";
    cout << left << setw(10) << "ID"
         << setw(15) << "Company"
         << setw(20) << "Model"
         << setw(12) << "Price" << endl;
    cout << "------------------------------------------------\n";

    for (int i = 0; i < count; i++)
    {
        string fullName = p[i].company + " " + p[i].model;
        string lowerName = toLowerCase(fullName);

        if (lowerName.find(lowerQuery) != string::npos)
        {
            cout << left << setw(10) << p[i].productID
                 << setw(15) << p[i].company
                 << setw(20) << p[i].model
                 << setw(12) << p[i].price << endl;
            foundAny = true;
        }
    }

    if (!foundAny)
    {
        cout << "No products found matching '" << query << "'.\n";
    }
    cout << "------------------------------------------------\n";
}