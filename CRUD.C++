#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Product structure
struct Product {
    int id;
    string name;
    double price;

    // Display product details
    void display() const {
        cout << "ID: " << id << "\nName: " << name << "\nPrice: $" << price << "\n\n";
    }
};

// Function prototypes
void createProduct();
void readProducts();
void updateProduct();
void deleteProduct();
vector<Product> loadProducts();
void saveProducts(const vector<Product>& products);

const string filename = "products.txt";

int main() {
    int choice;

    do {
        cout << "\n--- Product Management System ---\n";
        cout << "1. Create Product\n";
        cout << "2. Read Products\n";
        cout << "3. Update Product\n";
        cout << "4. Delete Product\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createProduct(); break;
            case 2: readProducts(); break;
            case 3: updateProduct(); break;
            case 4: deleteProduct(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// Create a new product
void createProduct() {
    vector<Product> products = loadProducts();
    Product p;

    cout << "Enter Product ID: ";
    cin >> p.id;
    cin.ignore(); // Clear the input buffer
    cout << "Enter Product Name: ";
    getline(cin, p.name);
    cout << "Enter Product Price: ";
    cin >> p.price;

    products.push_back(p);
    saveProducts(products);
    cout << "Product added successfully!\n";
}

// Read all products
void readProducts() {
    vector<Product> products = loadProducts();

    if (products.empty()) {
        cout << "No products found.\n";
    } else {
        cout << "\n--- Product List ---\n";
        for (const auto& p : products) {
            p.display();
        }
    }
}

// Update an existing product
void updateProduct() {
    vector<Product> products = loadProducts();
    int id;
    bool found = false;

    cout << "Enter Product ID to update: ";
    cin >> id;

    for (auto& p : products) {
        if (p.id == id) {
            found = true;
            cin.ignore(); // Clear the input buffer
            cout << "Enter new Product Name: ";
            getline(cin, p.name);
            cout << "Enter new Product Price: ";
            cin >> p.price;

            saveProducts(products);
            cout << "Product updated successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "Product with ID " << id << " not found.\n";
    }
}

// Delete a product
void deleteProduct() {
    vector<Product> products = loadProducts();
    int id;
    bool found = false;

    cout << "Enter Product ID to delete: ";
    cin >> id;

    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->id == id) {
            found = true;
            products.erase(it);
            saveProducts(products);
            cout << "Product deleted successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "Product with ID " << id << " not found.\n";
    }
}

// Load products from the file
vector<Product> loadProducts() {
    vector<Product> products;
    ifstream file(filename);

    if (file.is_open()) {
        Product p;
        while (file >> p.id) {
            file.ignore(); // Ignore newline after ID
            getline(file, p.name);
            file >> p.price;
            file.ignore(); // Ignore newline after price
            products.push_back(p);
        }
        file.close();
    }

    return products;
}

// Save products to the file
void saveProducts(const vector<Product>& products) {
    ofstream file(filename, ios::trunc); // Overwrite the file

    if (file.is_open()) {
        for (const auto& p : products) {
            file << p.id << "\n" << p.name << "\n" << p.price << "\n";
        }
        file.close();
    }
}
