#include <iostream>
#include <string>
using namespace std;

struct Medicine {
    int id;
    string name;
    float price;
    string expiryDate;
    string manufacturer;
};

class MedicalShop {
private:
    Medicine medicines[5];
    int count;

public:
    MedicalShop() : count(0) {}

    void addMedicine() {
        if (count >= 5) {
            cout << "Storage Full. Cannot add more medicines." << endl;
            return;
        }
        cout << "Enter Medicine ID, Name, Price, Expiry Date, Manufacturer: " << endl;
        cin >> medicines[count].id >> medicines[count].name >> medicines[count].price >> medicines[count].expiryDate >> medicines[count].manufacturer;
        count++;
        cout << "Medicine added successfully." << endl;
    }

    void displayMedicines() {
        if (count == 0) {
            cout << "No medicines recorded." << endl;
            return;
        }
        for (int i = 0; i < count; i++) {
            cout << "ID: " << medicines[i].id << ", Name: " << medicines[i].name << ", Price: " << medicines[i].price << ", Expiry Date: " << medicines[i].expiryDate << ", Manufacturer: " << medicines[i].manufacturer << endl;
        }
    }

    void updateMedicine(int id) {
        for (int i = 0; i < count; i++) {
            if (medicines[i].id == id) {
                cout << "Enter new details (Name, Price, Expiry Date, Manufacturer): ";
                cin >> medicines[i].name >> medicines[i].price >> medicines[i].expiryDate >> medicines[i].manufacturer;
                cout << "Medicine updated successfully." << endl;
                return;
            }
        }
        cout << "Medicine with ID " << id << " not found." << endl;
    }

    void deleteMedicine(int id) {
        for (int i = 0; i < count; i++) {
            if (medicines[i].id == id) {
                for (int j = i; j < count - 1; j++) {
                    medicines[j] = medicines[j + 1];
                }
                count--;
                cout << "Medicine deleted successfully." << endl;
                return;
            }
        }
        cout << "Medicine with ID " << id << " not found." << endl;
    }

    void searchMedicine(int id) {
        for (int i = 0; i < count; i++) {
            if (medicines[i].id == id) {
                cout << "ID: " << medicines[i].id << ", Name: " << medicines[i].name << ", Price: " << medicines[i].price << ", Expiry Date: " << medicines[i].expiryDate << ", Manufacturer: " << medicines[i].manufacturer << endl;
                return;
            }
        }
        cout << "Medicine with ID " << id << " not found." << endl;
    }
};

int main() {
    MedicalShop shop;
    int choice, id;

    do {
        cout << "\n=== Medical Shop Menu ===" << endl;
        cout << "1. Record Medicine" << endl;
        cout << "2. Display Medicines" << endl;
        cout << "3. Update Medicine Record" << endl;
        cout << "4. Delete Medicine Record" << endl;
        cout << "5. Search Medicine Record" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                shop.addMedicine();
                break;
            case 2:
                shop.displayMedicines();
                break;
            case 3:
                cout << "Enter Medicine ID to update: ";
                cin >> id;
                shop.updateMedicine(id);
                break;
            case 4:
                cout << "Enter Medicine ID to delete: ";
                cin >> id;
                shop.deleteMedicine(id);
                break;
            case 5:
                cout << "Enter Medicine ID to search: ";
                cin >> id;
                shop.searchMedicine(id);
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
        }
    } while (choice != 6);

    return 0;
}