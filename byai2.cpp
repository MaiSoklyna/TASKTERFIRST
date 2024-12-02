#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib> // Add this line for atoi and atof functions

using namespace std;

// Classes
class Cake {
public:
    int cake_id;
    string name;
    int quantity;
    float price;

    Cake(int cake_id, string name, int quantity, float price)
        : cake_id(cake_id), name(name), quantity(quantity), price(price) {}

    void save() {
        ofstream out("cakes.txt", ios::app);
        out << cake_id << "," << name << "," << quantity << "," << price << "\n";
        out.close();
    }

    static vector<Cake> load_all() {
        vector<Cake> cakes;
        ifstream in("cakes.txt");
        string line;

        while (getline(in, line)) {
            stringstream ss(line);
            string token;
            int cake_id, quantity;
            string name;
            float price;

            getline(ss, token, ',');
            cake_id = atoi(token.c_str()); // atoi requires <cstdlib>
            getline(ss, name, ',');
            getline(ss, token, ',');
            quantity = atoi(token.c_str()); // atoi requires <cstdlib>
            getline(ss, token, ',');
            price = atof(token.c_str()); // atof requires <cstdlib>

            cakes.push_back(Cake(cake_id, name, quantity, price));
        }
        in.close();
        return cakes;
    }
};

class Customer {
public:
    int customer_id;
    string name;
    string phone_number;
    string email;
    string address;
    string birthday;

    Customer(int customer_id, string name, string phone_number, string email, string address, string birthday)
        : customer_id(customer_id), name(name), phone_number(phone_number), email(email), address(address), birthday(birthday) {}

    void save() {
        ofstream out("customers.txt", ios::app);
        out << customer_id << "," << name << "," << phone_number << "," << email << "," << address << "," << birthday << "\n";
        out.close();
    }

    static vector<Customer> load_all() {
        vector<Customer> customers;
        ifstream in("customers.txt");
        string line;

        while (getline(in, line)) {
            stringstream ss(line);
            string token;
            int customer_id;
            string name, phone_number, email, address, birthday;

            getline(ss, token, ',');
            customer_id = atoi(token.c_str()); // atoi requires <cstdlib>
            getline(ss, name, ',');
            getline(ss, phone_number, ',');
            getline(ss, email, ',');
            getline(ss, address, ',');
            getline(ss, birthday, ',');

            customers.push_back(Customer(customer_id, name, phone_number, email, address, birthday));
        }
        in.close();
        return customers;
    }

    void update_birthday(const string& new_birthday) {
        birthday = new_birthday;
        vector<Customer> customers = Customer::load_all();
        ofstream out("customers.txt");
        for (size_t i = 0; i < customers.size(); i++) {
            Customer &c = customers[i];
            if (c.customer_id == customer_id) {
                c.birthday = new_birthday;
            }
            out << c.customer_id << "," << c.name << "," << c.phone_number << "," << c.email << "," << c.address << "," << c.birthday << "\n";
        }
        out.close();
    }
};

// Functions
void display_menu() {
    cout << "\n\t\t\t\t\t________________OPTION__________________" << endl
         << "\t\t\t\t\t|                                      |" << endl
         << "\t\t\t\t\t|   ---------> 1. Customer<---------   |" << endl
         << "\t\t\t\t\t|   ---------> 2. Stock   <---------   |" << endl
         << "\t\t\t\t\t|   ---------> 3. Exit   <---------   |" << endl
         << "\t\t\t\t\t|______________________________________|" << endl;
}

void display_customer_menu() {
    cout << "\t\t\t\t\t_____________________________Customer________________________________|" << endl
         << "\t\t\t\t\t|                                    					 |" << endl
         << "\t\t\t\t\t|   ---------> 1. Your Information to List 	<---------   |" << endl
         << "\t\t\t\t\t|   ---------> 2. Booking Cake Birthdays    	<---------   |" << endl
         << "\t\t\t\t\t|   ---------> 3. Show List and Cake BOKING 	<---------   |" << endl
         << "\t\t\t\t\t|   ---------> 4. Update List Information  	<---------   |" << endl
         << "\t\t\t\t\t|   ---------> 5. Update Birthday  		<---------   |" << endl;
}

// Main program
int main() {
    int choice;
    while (true) {
        display_menu();
        cout << "\nChoose an option: ";
        cin >> choice;

        if (choice == 1) {
            int customer_choice;
            display_customer_menu();
            cout << "\nChoose an option for customers: ";
            cin >> customer_choice;

            switch (customer_choice) {
                case 1: {
                    vector<Customer> customers = Customer::load_all();
                    for (size_t i = 0; i < customers.size(); i++) {
                        Customer &c = customers[i];
                        cout << "ID: " << c.customer_id << "\nName: " << c.name << "\nPhone: " << c.phone_number
                             << "\nEmail: " << c.email << "\nAddress: " << c.address << "\nBirthday: " << c.birthday << "\n" << endl;
                    }
                    break;
                }
                case 2: {
                    string name, phone, email, address, birthday;
                    int customer_id;

                    cout << "Enter customer ID: ";
                    cin >> customer_id;
                    cin.ignore();
                    cout << "Enter customer name: ";
                    getline(cin, name);
                    cout << "Enter phone number: ";
                    getline(cin, phone);
                    cout << "Enter email: ";
                    getline(cin, email);
                    cout << "Enter address: ";
                    getline(cin, address);
                    cout << "Enter birthday (YYYY-MM-DD): ";
                    getline(cin, birthday);

                    Customer new_customer(customer_id, name, phone, email, address, birthday);
                    new_customer.save();

                    cout << "Customer booking and birthday information saved!\n";
                    break;
                }
                case 3: {
                    vector<Customer> customers = Customer::load_all();
                    vector<Cake> cakes = Cake::load_all();

                    cout << "Customers:\n";
                    for (size_t i = 0; i < customers.size(); i++) {
                        Customer &c = customers[i];
                        cout << "ID: " << c.customer_id << "\nName: " << c.name << "\nPhone: " << c.phone_number
                             << "\nEmail: " << c.email << "\nAddress: " << c.address << "\nBirthday: " << c.birthday << "\n" << endl;
                    }

                    cout << "Cakes:\n";
                    for (size_t i = 0; i < cakes.size(); i++) {
                        Cake &cake = cakes[i];
                        cout << "Cake ID: " << cake.cake_id << "\nName: " << cake.name << "\nQuantity: " << cake.quantity
                             << "\nPrice: $" << cake.price << "\n" << endl;
                    }
                    break;
                }
                case 4: {
                    int customer_id;
                    cout << "Enter customer ID to update: ";
                    cin >> customer_id;

                    vector<Customer> customers = Customer::load_all();
                    bool found = false;

                    for (size_t i = 0; i < customers.size(); i++) {
                        Customer &c = customers[i];
                        if (c.customer_id == customer_id) {
                            found = true;
                            string new_name, new_phone, new_email, new_address;
                            cout << "Updating information for customer ID " << customer_id << endl;

                            cin.ignore();
                            cout << "Enter new name (leave empty to keep the same): ";
                            getline(cin, new_name);
                            if (!new_name.empty()) {
                                c.name = new_name;
                            }

                            cout << "Enter new phone number (leave empty to keep the same): ";
                            getline(cin, new_phone);
                            if (!new_phone.empty()) {
                                c.phone_number = new_phone;
                            }

                            cout << "Enter new email (leave empty to keep the same): ";
                            getline(cin, new_email);
                            if (!new_email.empty()) {
                                c.email = new_email;
                            }

                            cout << "Enter new address (leave empty to keep the same): ";
                            getline(cin, new_address);
                            if (!new_address.empty()) {
                                c.address = new_address;
                            }

                            ofstream out("customers.txt");
                            for (size_t j = 0; j < customers.size(); j++) {
                                Customer &updated_customer = customers[j];
                                out << updated_customer.customer_id << "," << updated_customer.name << "," << updated_customer.phone_number
                                    << "," << updated_customer.email << "," << updated_customer.address << "," << updated_customer. birthday 
                                   << "\n";
                            }
                            out.close();

                            cout << "Customer information updated successfully!\n";
                            break;
                        }
                    }

                    if (!found) {
                        cout << "Customer with ID " << customer_id << " not found.\n";
                    }
                    break;
                }
                case 5: { // Update customer birthday
                    int customer_id;
                    string new_birthday;

                    cout << "Enter customer ID to update birthday: ";
                    cin >> customer_id;
                    cin.ignore();
                    cout << "Enter new birthday (YYYY-MM-DD): ";
                    getline(cin, new_birthday);

                    vector<Customer> customers = Customer::load_all();
                    bool found = false;

                    for (size_t i = 0; i < customers.size(); i++) {
                        Customer &c = customers[i];
                        if (c.customer_id == customer_id) {
                            found = true;
                            c.update_birthday(new_birthday);
                            cout << "Customer birthday updated successfully!\n";
                            break;
                        }
                    }

                    if (!found) {
                        cout << "Customer with ID " << customer_id << " not found.\n";
                    }
                    break;
                }
                default:
                    cout << "Invalid option for customer menu.\n";
                    break;
            }
        } else if (choice == 2) {
            vector<Cake> cakes = Cake::load_all();
            for (size_t i = 0; i < cakes.size(); i++) {
                Cake &cake = cakes[i];
                cout << "Cake ID: " << cake.cake_id << "\nName: " << cake.name << "\nQuantity: " << cake.quantity
                     << "\nPrice: $" << cake.price << "\n" << endl;
            }
        } else if (choice == 3) {
            cout << "Exiting program.\n";
            break;
        } else {
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}

