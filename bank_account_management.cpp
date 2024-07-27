#include <iostream>
#include <string>
using namespace std;

class Customer {
protected:
    int cid;
    string cname;
    string addr;
    string addrProof;
    string idProof;
public:
    void createAccount() {
        cout << "Enter Customer ID: ";
        cin >> cid;
        cout << "Enter Customer Name: ";
        cin.ignore();
        getline(cin, cname);
        cout << "Enter Address: ";
        getline(cin, addr);
        cout << "Enter Address Proof: ";
        getline(cin, addrProof);
        cout << "Enter ID Proof: ";
        getline(cin, idProof);
    }
    void displayAccountDetails() {
        cout << "Customer ID: " << cid << endl;
        cout << "Customer Name: " << cname << endl;
        cout << "Address: " << addr << endl;
        cout << "Address Proof: " << addrProof << endl;
        cout << "ID Proof: " << idProof << endl;
    }
};

class Account : public Customer {
protected:
    float balance;
public:
    void depositAmount(float amount) {
        balance += amount;
    }
    void withdrawAmount(float amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "Insufficient balance" << endl;
        }
    }
    void checkBalance() {
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    Account a1;
    int choice;
    do {
        cout << "\n1. Create Account\n2. Display Account Details\n3. Deposit Amount\n4. Withdraw Amount\n5. Check Balance\n6. Exit\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                a1.createAccount();
                break;
            case 2:
                a1.displayAccountDetails();
                break;
            case 3:
                float depositAmount;
                cout << "Enter amount to deposit: ";
                cin >> depositAmount;
                a1.depositAmount(depositAmount);
                break;
            case 4:
                float withdrawAmount;
                cout << "Enter amount to withdraw: ";
                cin >> withdrawAmount;
                a1.withdrawAmount(withdrawAmount);
                break;
            case 5:
                a1.checkBalance();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 6);
    
    return 0;
}