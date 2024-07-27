#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex() : real(0), imag(0) {}

    void input() {
        cout << "Enter real and imaginary parts: ";
        cin >> real >> imag;
    }

    Complex operator+(const Complex& obj) const {
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }

    void display() const {
        cout << "Result: " << real << " + " << imag << "i" << endl;
    }
};

class Names {
private:
    string names[5];

public:
    void inputNames() {
        cout << "Enter five names: " << endl;
        for (int i = 0; i < 5; ++i) {
            cin >> names[i];
        }
    }

    bool operator>(const Names& obj) const {
        for (int i = 0; i < 5; ++i) {
            if (names[i] > obj.names[i]) {
                return true;
            } else if (names[i] < obj.names[i]) {
                return false;
            }
        }
        return false; // Equal names
    }
};

void addComplexNumbers() {
    Complex c1, c2, result;
    c1.input();
    c2.input();
    result = c1 + c2;
    result.display();
}

void compareNames() {
    Names n1, n2;
    n1.inputNames();
    n2.inputNames();

    if (n1 > n2) {
        cout << "First object's names are lexicographically greater." << endl;
    } else {
        cout << "Second object's names are lexicographically greater or equal." << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\n=== Menu ===" << endl;
        cout << "1. Add Complex Numbers" << endl;
        cout << "2. Compare Names" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;

    
        switch (choice) {
            case 1:
                addComplexNumbers();
                break;
            case 2:
                compareNames();
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            case 4:
                display();
                break;
            default:
                cout << "Invalid choice. Please enter 1, 2, 3, or 4." << endl;
        }
    } while (choice != 3);

    return 0;
}