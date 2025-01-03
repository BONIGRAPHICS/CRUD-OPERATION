CRUD Operations in C++

Overview
This project implements a simple console-based CRUD (Create, Read, Update, Delete) application in C++ to manage a list of products. It allows users to add new products, view all products, update product details, and delete products using a menu-driven interface.

Features
1. Create: Add new products by entering their ID, name, and price.
2. Read: Display all the products in the inventory with their details.
3. Update: Modify the name and price of an existing product by its ID.
4. Delete: Remove a product from the list by its ID.


How It Works
- The application uses a `std::vector` to store a dynamic list of `Product` objects.
- Each `Product` has:
  - `id` (integer): Unique identifier.
  - `name` (string): Name of the product.
  - `price` (double): Price of the product.
- Functions are implemented to handle each CRUD operation, working directly on the `std::vector`.



How to Run
1. Compile the code using a C++ compiler:
   ```bash
   g++ -o crud_app crud.cpp
  
2. Run the compiled program:
   bash
   ./crud_app
  
3. Follow the on-screen menu to perform CRUD operations.


Example Usage
1. Add a Product
   Input: `ID: 1, Name: Laptop, Price: 800.50`  
   Output: `Product added.`

2. View Products
   Output:
   ```
   ID: 1, Name: Laptop, Price: $800.50
   
3. Update a Product
   Input: `ID: 1, New Name: Gaming Laptop, New Price: 1200.00`  
   Output: `Product updated.`

4. Delete a Product
   Input: `ID: 1`  
   Output: `Product deleted successfully.`

Dependencies
- C++ Standard Library (`<iostream>`, `<vector>`, `<string>`).


Future Enhancements
- Add input validation for better user experience.
- Implement persistent storage using files or databases.
- Add support for searching products by name or price.
