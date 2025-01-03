#include <iostream>
#include <vector>
#include <string>

using namespace std;

//define the data structure
struct Product {
    int id;
    string name;
    double price;

    //Display product details
    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Price: $" << price << endl;
    }
};

void createProduct(vector<Product>& products){
    Product newProduct;
    cout << "Enter Product ID: ";
    cin >> newProduct.id;
    cin.ignore();
    cout << "Enter Product Name: ";
    getline(cin, newProduct.name);
    cout << "Enter Product Price: ";
    cin >> newProduct.price;
    products.push_back(newProduct);
    cout << "Product added successfully!\n";
}

void displayProducts(const vector<Product>& products){
    if (products.empty())
    {
        cout << "No products available.\n";
        return;
    }
    
    for (const auto& product :products)
    {
        product.display();
    }  
}

void updateProduct(vector<Product>& products){
    int id;
    cout << "Enter Product ID to update: ";
    cin >> id;
    for (auto& product: products)
    {
      if(product.id == id) {
          cin.ignore();
          cout << "Enter new Product Name: ";
          getline(cin, product.name);
          cout << "Enter new product Price: ";
          cin >> product.price;
          cout << "Product updated successfully!\n";
          return;
      }   
    }
    cout << "Product not found.\n";
}

void deleteProduct(vector<Product>& products){
    int id;
    cout << "Enter Product ID to delete: ";
    cin >> id;
    for (auto it = products.begin(); it != products.end(); ++it)
    {
       if(it->id == id ){
           products.erase(it);
           cout << "Product deleted successfully!\n";
           return;
       }
    }

    cout << "Product not found.\n";
}

int main(){
    vector<Product> products;
    int choice;

do{
    cout << "\n --- Product Management Menu --- \n";
    cout << "1. Add Product\n";
    cout << "2. Display Products\n";
    cout << "3. Update Products\n";
    cout << "4. Delete Product\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            createProduct(products);
            break;
        case 2:
            displayProducts(products);
            break;
        case 3:
            updateProduct(products);
            break;
        case 4:
            deleteProduct(products);
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Exiting program.\n";
    }
} while (choice != 5);
return 0;
}