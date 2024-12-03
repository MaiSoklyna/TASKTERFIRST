#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

class Boxing {
private:
    static const int MAX_CUSTOMERS = 20;
    int customerNum[MAX_CUSTOMERS];
    string customerName[MAX_CUSTOMERS];
    string timeGetFruit[MAX_CUSTOMERS];
    int choice[MAX_CUSTOMERS];
    string fruit[MAX_CUSTOMERS];
    string type[MAX_CUSTOMERS];
    float price[MAX_CUSTOMERS];
    int quantity[MAX_CUSTOMERS];
    float totalPrice[MAX_CUSTOMERS];
    int count; // Number of customers

public:
    Boxing() : count(0) {}

    void LoadBoxingFromFile(const string& customer) {
        ifstream file("customer.txt");
        if (!file.is_open()) {
            cout << "Unable to open file" << endl; 
            return;
        }

        while (file >> customerNum[count] >> customerName[count] >> timeGetFruit[count] 
                     >> choice[count] >> fruit[count] >> type[count] >> price[count] >> quantity[count]) {
            totalPrice[count] = price[count] * quantity[count];
            count++;
            if (count >= MAX_CUSTOMERS) break; // Avoid exceeding the array size
        }
        file.close();
    }

    void AddBoxingFruit() {
        if (count >= MAX_CUSTOMERS) {
            cout << "Customer array is full!" << endl;
            return;
        }

        cout << "Enter customer number: ";
        cin >> customerNum[count];
        cout << "Enter customer name: ";
        cin >> customerName[count];
        cout << "Enter time you got the fruit: ";
        cin >> timeGetFruit[count];
        cout << "Enter choice (1. Apple, 2. Banana, 3. Cherry): ";
        cin >> choice[count];

        switch (choice[count]) { 
            case 1:
                fruit[count] = "Apple";
                type[count] = "Fresh";
                price[count] = 1.5;
                break;
            case 2:
                fruit[count] = "Banana";
                type[count] = "Fresh";
                price[count] = 0.8;
                break;
            case 3:
                fruit[count] = "Cherry";
                type[count] = "Fresh";
                price[count] = 2.0;
                break;
            default:
                cout << "Invalid choice!!!" << endl;
                return;
        }

        cout << "Enter quantity: ";
        cin >> quantity[count];
        totalPrice[count] = price[count] * quantity[count]; 
        count++;

        cout << "Fruit information added successfully!!!" << endl;
    }

    void DisplayBoxingFruit() const {
        if (count == 0) {
            cout << "No data to display." << endl;
            return;
        }

        cout << "Customer Number | Name | Time | Fruit | Type | Price | Quantity | Total Price" << endl;
        for (int i = 0; i < count; i++) {
            cout << customerNum[i] << " | "
                 << customerName[i] << " | "
                 << timeGetFruit[i] << " | "
                 << fruit[i] << " | "
                 << type[i] << " | "
                 << price[i] << " | "
                 << quantity[i] << " | "
                 << totalPrice[i] << endl;
        }
    }

    void SearchCustomer(int searchNum) const {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (customerNum[i] == searchNum) {
                cout << "Customer Number | Name | Time | Fruit | Type | Price | Quantity | Total Price" << endl;
                cout << customerNum[i] << " | "
                     << customerName[i] << " | "
                     << timeGetFruit[i] << " | "
                     << fruit[i] << " | "
                     << type[i] << " | "
                     << price[i] << " | "
                     << quantity[i] << " | "
                     << totalPrice[i] << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Customer not found." << endl;
        }
    }

    void SaveBoxingToFile(const string& customer) const {
        ofstream file("customer.txt");
        if (!file.is_open()) {
            cout << "Unable to open file for writing" << endl;
            return;
        }

        for (int i = 0; i < count; i++) {
            file << customerNum[i] << " "
                 << customerName[i] << " "
                 << timeGetFruit[i] << " "
                 << choice[i] << " "
                 << fruit[i] << " "
                 << type[i] << " "
                 << price[i] << " "
                 << quantity[i] << endl;
        }
        file.close();
        cout << "Data saved to file successfully." << endl;
    }
}; 

int main() {
    Boxing box;
    box.LoadBoxingFromFile("customer.txt");

    int choice;
    do {
        cout << "Welcome to the system for your fruit purchase information!" << endl;
        cout << "Please select an option:" << endl;
        cout << "1. Add your fruit purchase" << endl;
        cout << "2. Display your fruit purchases" << endl;
        cout << "3. Search for a customer" << endl;
        cout << "4. Save data to file" << endl;
        cout << "5. Exit" << endl;
        cout << "----------------------------------" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                box.AddBoxingFruit();
                box.SaveBoxingToFile("customer.txt");
                break;
            case 2:
                box.DisplayBoxingFruit();
                break;
            case 3: {
                int searchNum;
                cout << "Enter customer number to search: ";
                cin >> searchNum;
                box.SearchCustomer(searchNum);
                break;
            }
            case 4:
                box.SaveBoxingToFile("customer.txt");
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice!!!" << endl;
        }

    } while (choice != 5);

    return 0;
}

