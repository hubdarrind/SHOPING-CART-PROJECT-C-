# 🛒 Console-Based E-Commerce Application (Electro Store)

A professional, modular console-based e-commerce application developed in C++. The project simulates a complete online store experience, allowing users to authenticate, browse a catalog, manage a shopping cart, and generate a final receipt.

---

## ✨ Features

* **🔐 Secure Authentication:** User login, registration (with unique email checking), and password recovery via `users.txt`.
* **🛍️ Product Catalog:** View dynamic product categories, check stock, and search for products by name.
* **🛒 Shopping Cart:** Add or remove items, validate available stock quantities, and view a realtime subtotal.
* **💳 Checkout System:** Process payments, calculate discounts (e.g., 20% off for large orders), and automate stock reduction after purchase.
* **🧾 Receipt Generation:** Dynamically generates a detailed bill text file (`receipt.txt`) for the customer.
* **📂 Modular Architecture:** Cleanly organized into professional `src/` and `includes/` directories.

---

## 🏗️ Project Structure

```text
SHOPING-CART-PROJECT-C-/
├── includes/               # Header files (Declarations)
│   ├── auth.h
│   ├── cart.h
│   ├── catalog.h
│   ├── product.h
│   └── utils.h
├── src/                    # Source files (Implementations)
│   ├── auth.cpp
│   ├── cart.cpp
│   ├── catalog.cpp
│   ├── main.cpp
│   └── utils.cpp
├── products.txt            # Product database (Category ID, Prod ID, Brand, Model, Price, Stock)
├── users.txt               # User credentials database
└── README.md
```

---

## 🧠 Concepts Applied

* **Modularity:** Separation of Declarations (`.h`) and Implementations (`.cpp`).
* **File Handling:** Reading and writing product data, user credentials, and receipts.
* **Data Structures:** Structs and Arrays for passing product and cart information.
* **Control Flow:** Robust while-loops, switch-cases, and input validation.

---

## ⚙️ How to Compile & Run

1. **Clone the repository:**
   ```bash
   git clone https://github.com/hubdarrind/SHOPING-CART-PROJECT-C-.git
   cd SHOPING-CART-PROJECT-C-
   ```

2. **Compile the source files:**
   ```bash
   g++ src/*.cpp -o StoreApp.exe
   ```
   *(Note: For Windows PowerShell, you may need to specify the files explicitly: `g++ src/main.cpp src/auth.cpp src/cart.cpp src/catalog.cpp src/utils.cpp -o StoreApp.exe`)*

3. **Run the application:**
   * **Windows:** `.\StoreApp.exe`
   * **Linux/Mac:** `./StoreApp.exe`

---

## 📌 Important Notes

* Ensure that a valid `products.txt` exists in the root directory before running the application, otherwise, the catalog will fail to load.
* Product IDs must match the `products.txt` inventory to add them to the cart successfully.

---

## 🚀 Future Improvements

* Refactor the current functional code into an Object-Oriented Programming (OOP) structure.
* Replace arrays with dynamic data structures like `std::vector`.
* Implement a GUI or web-based framework integration.

---

## 👨‍💻 Author

**Hubdar Ali**  
Computer Science Student – Salim Habib University
