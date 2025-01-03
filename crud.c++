#include <iostream>   // Include the iostream library for input/output operations
#include <vector>     // Include the vector library for using std::vector
#include <string>     // Include the string library for using std::string

using namespace std;  // Use the standard namespace to avoid prefixing std::

// Define a structure for an Item
struct Item {
    int id;          // Item ID
    string name;     // Item Name
    double price;    // Item Price

    // Display the item details
    void display() const {  // Member function to display an item's details
        cout << "ID: " << id << ", Name: " << name << ", Price: $" << price << endl;
    }
};

// Function prototypes
void createItem(vector<Item>& items);  // Function to create a new item
void readItems(const vector<Item>& items);  // Function to read and display all items
void updateItem(vector<Item>& items);  // Function to update an existing item
void deleteItem(vector<Item>& items);  // Function to delete an item

int main() {
    vector<Item> items;  // Vector to store items
    int choice;          // Variable to store user's menu choice

    do {
        // Display menu options
        cout << "\n--- CRUD Operations Menu ---\n";
        cout << "1. Create Item\n";  // Option to create a new item
        cout << "2. Read Items\n";  // Option to read and display items
        cout << "3. Update Item\n";  // Option to update an item
        cout << "4. Delete Item\n";  // Option to delete an item
        cout << "5. Exit\n";         // Option to exit the program
        cout << "Enter your choice: ";
        cin >> choice;  // Get the user's choice

        // Execute the corresponding action based on the choice
        switch (choice) {
            case 1:
                createItem(items);  // Call createItem to add a new item
                break;
            case 2:
                readItems(items);  // Call readItems to display all items
                break;
            case 3:
                updateItem(items);  // Call updateItem to modify an existing item
                break;
            case 4:
                deleteItem(items);  // Call deleteItem to remove an item
                break;
            case 5:
                cout << "Exiting the program.\n";  // Exit message
                break;
            default:
                cout << "Invalid choice. Please try again.\n";  // Handle invalid input
        }
    } while (choice != 5);  // Repeat until the user selects exit

    return 0;  // Indicate successful program execution
}

// Create a new item
void createItem(vector<Item>& items) {
    Item newItem;  // Temporary variable to hold the new item

    cout << "\nEnter Item ID: ";
    cin >> newItem.id;  // Input item ID
    cin.ignore();       // Clear input buffer to avoid issues with getline
    cout << "Enter Item Name: ";
    getline(cin, newItem.name);  // Input item name
    cout << "Enter Item Price: ";
    cin >> newItem.price;  // Input item price

    items.push_back(newItem);  // Add the new item to the vector
    cout << "Item created successfully!\n";  // Confirmation message
}

// Read and display all items
void readItems(const vector<Item>& items) {
    if (items.empty()) {  // Check if the vector is empty
        cout << "\nNo items found.\n";  // Message if no items are available
    } else {
        cout << "\n--- Item List ---\n";  // Header for the item lists
        for (const auto& item : items) {  // Iterate through each item in the vector
            item.display();  // Call the display function to show item details
        }
    }
}

// Update an existing item
void updateItem(vector<Item>& items) {
    int id;  // Variable to hold the ID of the item to update
    cout << "\nEnter Item ID to update: ";
    cin >> id;  // Input the item ID

    for (auto& item : items) {  // Iterate through the vector to find the item
        if (item.id == id) {  // Check if the current item matches the ID
            cin.ignore();  // Clear input buffer
            cout << "Enter new Item Name: ";
            getline(cin, item.name);  // Input the new item name
            cout << "Enter new Item Price: ";
            cin >> item.price;  // Input the new item price
            cout << "Item updated successfully!\n";  // Confirmation message
            return;  // Exit the function after updating
        }
    }

    cout << "Item with ID " << id << " not found.\n";  // Message if ID not found
}

// Delete an existing item
void deleteItem(vector<Item>& items) {
    int id;  // Variable to hold the ID of the item to delete
    cout << "\nEnter Item ID to delete: ";
    cin >> id;  // Input the item ID

    for (auto it = items.begin(); it != items.end(); ++it) {  // Iterate through the vector
        if (it->id == id) {  // Check if the current item matches the ID
            items.erase(it);  // Remove the item from the vector
            cout << "Item deleted successfully!\n";  // Confirmation message
            return;  // Exit the function after deleting
        }
    }

    cout << "Item with ID " << id << " not found.\n";  // Message if ID not found
}
