#include <iostream>
#include <iomanip>
#include <fstream>
#include <unistd.h>
#include <string>
using namespace std;


class Cake {
private:
    int cakeId; // Unique identifier for the cake
    string name;
    int quantity;
    float price;

public:
    Cake() {} // Default constructor

    // Getters and setters for class attributes
    int getCakeId() const { return cakeId; }
    void setCakeId(int id) { cakeId = id; }

    string getName() const { return name; }
    void setName(const string& name) { this->name = name; }

    int getQuantity() const { return quantity; }
    void setQuantity(int qty) { quantity = qty; }

    float getPrice() const { return price; }
    void setPrice(float price) { this->price = price; }

    // Additional methods as needed
    // For example:
    void input() {
        // Code to input cake details from the user
    }

    void output() {
        // Code to display cake details
    }
};
class Person {
private:
    int id, age;
    string name;
    char gender;

public:
    Person() {}

    void input() {
        cout << "\t\t\tEnter ID    :";
        cin >> id;
        cout << "\t\t\tEnter name  :";
        cin.ignore();
        getline(cin, name);
        cout << "\t\t\tEnter Gender:";
        cin >> gender;
        cout << "\t\t\tEnter Age   :";
        cin >> age;
    }

    void setId(int num) {
        this->id = num;
    }

    void setName(string str) {
        this->name = str;
    }

    void setGender(char str) {
        this->gender = str;
    }

    void setAge(int num) {
        this->age = num;
    }

    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    char getGender() {
        return gender;
    }

    int getAge() {
        return age;
    }

    static void header() {
        cout << setw(30) << "ID" << setw(12) << "NAME" << setw(12) << "GENDER" << setw(13) << "AGE" << setw(12);
    }

    void output() {
        cout << setw(30) << id << setw(12) << name << setw(12) << gender << setw(12) << age << "Y" << setw(12);
    }
};

class Store {
protected:
    int code, qty;
    string name;
    float price;

public:
    Store() {}

    void setCode(int num) {
        code = num;
    }

    int getCode() {
        return code;
    }

    void setPrice(float price) {
        this->price = price;
    }

    float getPrice() {
        return price;
    }
	string getname() {
        return name;
    }
	
    void setQty(int qty) {
        this->qty = qty;
    }

    int getQty() {
        return qty;
    }

    void input() {
        cout << "\t\t\tEnter code   :";
        cin >> code;
        cout << "\t\t\tEnter name  :";
        cin.ignore();
        getline(cin, name);
        cout << "\t\t\tEnter qty    :";
        cin >> qty;
        cout << "\t\t\tEnter price  :";
        cin >> price;
    }

    void output() {
        cout << setw(35) << code << setw(15) << name << setw(15) << qty << setw(15) << price << "$" << setw(15) << endl;
    }

    static void header() {
        cout << setw(35) << "CODE" << setw(15) << "NAME" << setw(15) << "QTY" << setw(16) << "PRICE" << endl;
    }
};

class Customer : public Store {
public:
    string name;
    string phoneNumber;
    string email;
    string address;

    Customer() : Store() {}

    void input() {
        Store::input();
    }

    float total() {
        return (qty * price);
    }

    int discount() {
        return (total() >= 0 && total() < 10)     ? 0
             : (total() >= 10 && total() < 20)  ? 5
             : (total() >= 40 && total() < 40)  ? 10
             : (total() >= 60 && total() < 60)  ? 15
             : (total() >= 70 && total() < 100) ? 20
                                                : 25;
    }

    float payment() {
        return total() - (total() * discount()) / 100;
    }

    void output() {
        cout << setw(20) << code << setw(12) << name << setw(12) << qty << setw(12) << price << "$" << setw(12)
             << total() << setw(12) << discount() << "%" << setw(12) << payment() << "$" << endl;
    }

    static void header() {
        cout << setw(20) << "CODE" << setw(12) << "NAME" << setw(12) << "QTY" << setw(13) << "PRICE" << setw(12)
             << "TOTAL" << setw(13) << "DISCOUNT" << setw(13) << "PAYMENT" << endl;
    }
};

class Staff : public Person {
private:
    string position;
    float salary;

public:
    Staff() : Person() {}

    void setPosition(string str) {
        this->position = str;
    }

    void setSalary(float num) {
        this->salary = num;
    }

    string getPosition() {
        return position;
    }

    float getSalary() {
        return salary;
    }

    void input() {
        Person::input();
        cout << "\t\t\tEnter Position :";
        cin >> position;
        cout << "\t\t\tEnter Salary   :";
        cin >> salary;
    }

    void output() {
        Person::output();
        cout << position << setw(11) << salary << "$" << setw(12) << endl;
    }

    static void header() {
        Person::header();
        cout << "POSITION" << setw(12) << "SALARY" << setw(12) << endl;
    }
};

// Helper functions for display
void styleHeader() {
    cout << "\t\t______________________________________VIEW DATA________________________________\n" << endl;
}

void style() {
    cout << "\t\t_______________________________________________________________________________" << endl;
}

// Loading screen for effect
void loading() {
    system("color 3");
    cout << "\n\n\n\n\n\n\n" << setw(30) << " ";
    for (int i = 0; i < 1; i++) {
        usleep(500000);
        cout << "E";
        usleep(500000); 
        cout << "L";
        usleep(500000);
        cout << "C";
        usleep(500000);
        cout << "O";
        usleep(500000);
        cout << " M";
        usleep(500000);
        cout << "E ";
        usleep(500000);
        cout << "T";
        usleep(500000);
        cout << "O";
        usleep(500000);
        cout << "M";
        usleep(500000);
        cout << "Y";
        usleep(500000);
        cout << "S";
        usleep(500000);
        cout << "H";
        usleep(500000);
        cout << "O";
        usleep(500000);
        cout << "P";
        usleep(500000);
    }
    system("cls");
}
void Hello() {
    system("color 3");
    cout << "\n\n\n\n\n\n\n\n" << setw(30) << " ";
    for (int i = 0; i < 1; i++) {
        cout << "W";
        usleep(500000);
        cout << "E";
        usleep(500000);
        cout << "L";
        usleep(500000);
        cout << "C";
        usleep(500000);
        cout << "O";
        usleep(500000);
        cout << "M";
        usleep(500000);
        cout << "E";
        usleep(500000);
        cout << "\tT";
        usleep(500000);
        cout << "O";
        usleep(500000);
        cout << "\tM";
        usleep(500000);
        cout << "Y";
        usleep(500000);
        cout << "\tS";
        usleep(500000);
        cout << "H";
        usleep(500000);
        cout << "O";
        usleep(500000);
        cout << "P";
        usleep(500000);
        system("cls");
    }
}

int main() {
    Staff st, st2;
    Customer cus, cus2;
    Store s, s2;
    int op, op1, op2, op3;
    int choice;
    fstream file;
    int n, i, count = 0;

    Hello();

    do {
        cout << "\t\t\t\t\t________________OPTION__________________" << endl
             << "\t\t\t\t\t|                                      |" << endl
             << "\t\t\t\t\t|   ---------> 1. Customer<---------   |" << endl
             << "\t\t\t\t\t|   ---------> 2. Stock   <---------   |" << endl
             << "\t\t\t\t\t|   ---------> 3. Exits   <---------   |" << endl
             << "\t\t\t\t\t|______________________________________|" << endl;
        cout << "\t\tEnter Option :";
        cin >> op;
        system("cls");

        // Customer
        if (op == 1) {
            do {
                cout 	<< "\t\t\t\t\t_____________________________Customer________________________________|" << endl
                         << "\t\t\t\t\t|                                    					 |" << endl
                         << "\t\t\t\t\t|   ---------> 1.YOUR INFORMATION TO LIST 	<---------   |" << endl
                         << "\t\t\t\t\t|   ---------> 2.BOKING CAKE BIRTHDAYS    	<---------   |" << endl
                         << "\t\t\t\t\t|   ---------> 3.SHOW LIST AND CAKE BOKING 	<---------   |" << endl
                         << "\t\t\t\t\t|   ---------> 4.UPDATE LIST INFORMATION  	<---------   |" << endl
                         << "\t\t\t\t\t|   ---------> 5.UPDATE BOXING CAKE 	    	<---------   |" << endl
                         << "\t\t\t\t\t|   ---------> 6.DELETE INFOEMATION 			<---------   |" << endl
                         << "\t\t\t\t\t|   ---------> 7.CANCEL TO BOKING   			<---------   |" << endl
                         << "\t\t\t\t\t|   ---------> 8.CHANGE TO MONEY 			<---------   |" << endl
                         << "\t\t\t\t\t|   ---------> 9.CLARE THIS DATA 			<---------   |" << endl
                         << "\t\t\t\t\t|   ---------> 10.EXIT THIS PROGRAM		<---------   |" << endl
                         
                         << "\t\t\t\t\t|______________________________________________________________	|" << endl;
                    cout << "\t\tWhich one :";
                    cin >> op;
                    switch (op){
                    	case 1:{
						// input
						file.open("ShopcakeFile.bin",ios::app|ios::binary); 
						if(!file){
							cout<<"\t\tError opening file..!!"<<endl;
						}
						cout << "\t\tHow many customers do you want to add: ";cin >> n;
						for(i=0;i<n;i++){
							cout<<"\t\tCustomer["<<(i+1)<<"]:"<<endl;
							cout << "\nEnter your name: ";cin.ignore();
					        getline(cin, cus.name);
					        cout << "Enter your phone number: ";
					        getline(cin, cus.phoneNumber);
					        cout << "Enter your email: ";
					        getline(cin, cus.email);
					        cout << "Enter your address: ";
					        getline(cin, cus.address);
							file.write((char*)&cus,sizeof(cus));
							cout << "\n\t\t\tCustomer Information Saved" << endl;
					        cout << "Name: " << cus.name << endl;
					        cout << "Phone Number: " << cus.phoneNumber << endl;
					        cout << "Email: " << cus.email << endl;
					        cout << "Address: " << cus.address << endl;
						}
						cout<<"\t\tData sava successfully "<<endl;
						file.close();	
					}break;
                    case 2: {
					    // Booking Cake Birthdays
					    int cakeChoice, qty;
					    char confirm;
					    cout << "\t\tAvailable Cake Options:" << endl;
					    cout << "\t\t  1. Chocolate Cake (Price: $25)" << endl;
					    cout << "\t\t  2. Vanilla Cake (Price: $20)" << endl;
					    cout << "\t\t  3. Strawberry Cake (Price: $30)" << endl;
					    cout << "\t\t  (Enter cake number to choose)" << endl;
					    do {
					        cout << "\t\tEnter your cake choice: "; cin >> cakeChoice;
					    } while (cakeChoice < 1 || cakeChoice > 3);
					    cout << "\t\tEnter the qty: ";cin >> qty;
					    cout << "\t\tYou have chosen " << qty << " "
					         << (cakeChoice == 1 ? "Chocolate" : (cakeChoice == 2 ? "Vanilla" : "Strawberry"))
					         << " Cake(s)." << endl;
					    cout << "\t\tConfirm booking (y/n): ";cin >> confirm;
					
					    if (confirm == 'y' || confirm == 'N') {
					    	 struct CakeBooking {
				            int cakeId;
				            int qty;
				            string deliveryDate;
				        };
				        CakeBooking booking;
				        booking.cakeId = cakeChoice;
				        booking.qty = qty;
				        cout << "\t\tEnter delivery date (YYYY-MM-DD): ";cin >> booking.deliveryDate;
					    cout << "\t\tCake booking successful!" << endl;
					    } else {
					        cout << "\t\tBooking cancelled." << endl;
					    }
					}break;
					case 3: {
				    ifstream file("ShopcakeFile.bin", ios::binary); if (!file.is_open()) {
				        cout << "\t\tError opening file for reading!" << endl;
				    } else {
				        Customer cus;
				        while (file.read((char*)&cus, sizeof(cus))) {
				            cout << "\t\tCustomer Information:" << endl;
				            cout << "\t\t  Name: " << cus.name << endl;
				            cout << "\t\t  Phone Number: " << cus.phoneNumber << endl;
				            cout << "\t\t  Email: " << cus.email << endl;
				            cout << "\t\t  Address: " << cus.address << endl;
				            cout << endl;
				        }
				        cout << "\t\tEnd of Customer List and Cake Booking Information." << endl;
				    }
				    file.close();
				} break;
				case 4: {
				  // Update List Information
				  fstream file("ShopcakeFile.bin", ios::binary | ios::in | ios::out);
				  if (!file.is_open()) {
				    cout << "\t\tError opening file!" << endl;
				  } else {
				    int customerToUpdate, found = 0;
				    Customer cus, newCus;
				    cout << "\t\tCustomer List:" << endl;
				    int customerIndex = 0;
				    while (file.read((char*)&cus, sizeof(cus))) {
				      customerIndex++;
				      cout << "\t\t  " << customerIndex << ". " << cus.name << endl;
				    }
				    file.clear();
				    file.seekg(0);
				
				    cout << "\t\tEnter the customer number to update: ";cin >> customerToUpdate;
				    while (file.read((char*)&cus, sizeof(cus))) {
				      if (customerToUpdate == customerIndex) {
				        found = 1;
				        cout << "\t\tCurrent Information:" << endl;
				        cout << "\t\t  Name: " << cus.name << endl;
				        cout << "\t\t  Phone Number: " << cus.phoneNumber << endl;
				        cout << "\t\t  Email: " << cus.email << endl;
				        cout << "\t\t  Address: " << cus.address << endl;
				        cout << "\t\tEnter new information (leave blank to keep unchanged):" << endl;
				        cout << "\t\t  Name: ";
				        getline(cin, newCus.name);
				        if (newCus.name.empty()) {
				          newCus.name = cus.name;
				        }
				        cout << "\t\t  Phone Number: ";    getline(cin, newCus.phoneNumber);
				        if (newCus.phoneNumber.empty()) {
				          newCus.phoneNumber = cus.phoneNumber;
				        }
				        cout << "\t\t  Email: ";  getline(cin, newCus.email);
				        if (newCus.email.empty()) {
				          newCus.email = cus.email;
				        }
				        cout << "\t\t  Address: ";  getline(cin, newCus.address);
				        if (newCus.address.empty()) {
				          newCus.address = cus.address;
				        }
				        if (!file.seekp((customerIndex - 1) * sizeof(cus), ios::beg)) {
				          cerr << "\t\tError seeking customer position for update!" << endl;
				          break; 
				        }
				        if (!file.write((char*)&newCus, sizeof(newCus))) {
				          cerr << "\t\tError writing updated customer information!" << endl;
				          break;
				        }
				        cout << "\t\tCustomer information updated successfully!" << endl;
				        break;
				      }
				      customerIndex++;
				    }
				    if (!found) {
				      cout << "\t\tCustomer not found!" << endl;
				    }
				  }
				  file.close();
				}break;
				case 5: {
			    fstream file("ShopcakeFile.bin", ios::binary | ios::in | ios::out);
			    if (!file.is_open()) {
			        cout << "\t\tError opening file!" << endl;
			    } else {
			        int customerToUpdate, foundBooking = 0;
			        Customer cus;
			        struct CakeBooking {
			            int cakeId;
			            int qty;
			            string deliveryDate;
			        };  cout << "\t\tCustomer List:" << endl;
			        int customerIndex = 0;
			        while (file.read((char*)&cus, sizeof(cus))) {
			            customerIndex++;
			            cout << "\t\t  " << customerIndex << ". " << cus.name << endl;
			        }
			        file.clear();
			        file.seekg(0);
			        cout << "\t\tEnter the customer number to update booking: "; cin >> customerToUpdate;
			        while (file.read((char*)&cus, sizeof(cus))) {
			            CakeBooking booking;
			            if (file.peek() != EOF) { 
			                file.read((char*)&booking, sizeof(booking));
			            }
			            if (customerToUpdate == customerIndex) {
			                if (file.peek() != EOF) {
			                    foundBooking = 1;
			                    cout << "\t\tCurrent Booking Information:" << endl;
			                    cout << "\t\t  Cake: " << (booking.cakeId == 1 ? "Chocolate" : (booking.cakeId == 2 ? "Vanilla" : "Strawberry")) << endl;
			                    cout << "\t\t  Qty: " << booking.qty << endl;
			                    cout << "\t\t  Delivery Date: " << booking.deliveryDate << endl;
			                    cout << "\t\tEnter new information (leave blank to keep unchanged):" << endl;
			                    int newCakeChoice, newQty;
			                    string newDeliveryDate;
			                    cout << "\t\t  Cake (enter number or leave blank): ";cin >> newCakeChoice;
			                    cout << "\t\t  Delivery Date (YYYY-MM-DD, leave blank to keep unchanged): ";
			                    getline(cin, newDeliveryDate);
			                    if (newCakeChoice > 0 || newQty > 0 || !newDeliveryDate.empty()) {
			                        booking.cakeId = newCakeChoice > 0 ? newCakeChoice : booking.cakeId;
			                        booking.qty = newQty > 0? newQty : booking.qty;
			                        booking.deliveryDate = newDeliveryDate.empty() ? booking.deliveryDate : newDeliveryDate;
			                        file.seekp(-sizeof(booking), ios::cur);
			                        file.write((char*)&booking, sizeof(booking));
			                        cout << "\t\tCake booking information updated successfully!" << endl;
			                    }
			                } else {
			                    cout << "\t\tCustomer does not have a cake booking." << endl;
			                }
			                break;
			            }
			            customerIndex++;
			        }
			        if (!foundBooking) {
			            cout << "\t\tCustomer not found!" << endl;
			       		}
			  	  	}
			    	file.close();
				}break;
				case 6: {
				  fstream file("ShopcakeFile.bin", ios::binary | ios::in | ios::out);
				  if (!file.is_open()) {
				    cout << "\t\tError opening file!" << endl;
				    break;
				  }
				  fstream tempFile("ShopcakeTempFile.bin", ios::binary | ios::out);
				  if (!tempFile.is_open()) {
				    cout << "\t\tError creating temporary file!" << endl;
				    file.close(); 
				    break;
				  }
				  int customerToDelete, foundCustomer = 0;
				  Customer cus;
				  cout << "\t\tCustomer List:" << endl;
				  int customerIndex = 0;
				  while (file.read((char*)&cus, sizeof(cus))) {
				    customerIndex++;
				    cout << "\t\t  " << customerIndex << ". " << cus.name << endl;
				  }
				  file.clear();
				  file.seekg(0);
				  cout << "\t\tEnter the customer number to delete: ";cin >> customerToDelete;
				  while (file.read((char*)&cus, sizeof(cus))) {
				    if (customerToDelete == customerIndex) {
				      foundCustomer = 1;
				      cout << "\t\tCustomer information to be deleted:" << endl;
				      cout << "\t\t  Name: " << cus.name << endl;
				      cout << "\t\t  Phone Number: " << cus.phoneNumber << endl;
				      cout << "\t\t  Email: " << cus.email << endl;
				      cout << "\t\t  Address: " << cus.address << endl;
				      char confirmDelete;
				      cout << "\t\tAre you sure you want to delete this customer (y/n)? ";cin >> confirmDelete;
				      if (confirmDelete == 'y' || confirmDelete == 'N') {
				        continue;
				      } else {
				        tempFile.write((char*)&cus, sizeof(cus));
				      }
				    } else {
				      tempFile.write((char*)&cus, sizeof(cus));
				    }
				    customerIndex++;
				  }
				  if (!foundCustomer) {
				    cout << "\t\tCustomer not found!" << endl;
				  } else {
				    file.close();
				    tempFile.close();
				    if (remove("ShopcakeFile.bin") != 0) {
				      cerr << "\t\tError deleting original file!" << endl;
				    } else if (rename("ShopcakeTempFile.bin", "ShopcakeFile.bin") != 0) {
				      cerr << "\t\tError renaming temporary file!" << endl;
				    } else {
				      cout << "\t\tCustomer information deleted successfully!" << endl;
				    }
				  }
				} break;
				case 7: {
				  fstream file("ShopcakeFile.bin", ios::binary | ios::in | ios::out);
				  if (!file.is_open()) {
				    cout << "\t\tError opening file!" << endl;
				    break;
				  }
				  int customerToUpdate, foundBooking = 0;
				  Customer cus;
				  struct CakeBooking {
				    int cakeId;
				    int qty;
				    string deliveryDate;
				  };
				   cout << "\t\tCustomer List:" << endl;
					  int customerIndex = 0;
					  while (file.read((char*)&cus, sizeof(cus))) {
					    customerIndex++;
					    cout << "\t\t  " << customerIndex << ". " << cus.name << endl;
					  }
					  file.clear();
					  file.seekg(0);
					  cout << "\t\tEnter the customer number to cancel booking: ";
					  cin >> customerToUpdate;
					  while (file.read((char*)&cus, sizeof(cus))) {
					    CakeBooking booking;
					    if (file.peek() != EOF) { 
					      file.read((char*)&booking, sizeof(booking));
					    }
					    if (customerToUpdate == customerIndex) {
					      if (file.peek() != EOF) {  
					        foundBooking = 1;
					        cout << "\t\tCurrent Booking Information:" << endl;
					        cout << "\t\t  Cake: " << (booking.cakeId == 1 ? "Chocolate" : (booking.cakeId == 2 ? "Vanilla" : "Strawberry")) << endl;
					        cout << "\t\t  Qty: " << booking.qty << endl;
					        cout << "\t\t  Delivery Date: " << booking.deliveryDate << endl;
					
					        char confirmCancel;
					        cout << "\t\tAre you sure you want to cancel this booking (y/n)? ";
					        cin >> confirmCancel;
					
					        if (confirmCancel == 'y' || confirmCancel == 'N') {
					          booking.cakeId = 0;
					          booking.qty = 0;
					          booking.deliveryDate = "";
					          file.seekp(-sizeof(booking), ios::cur);
					          file.write((char*)&booking, sizeof(booking));
					          cout << "\t\tBooking cancelled successfully!" << endl;
					        }
					      } else {
					        cout << "\t\tCustomer does not have a cake booking." << endl;
					      }
					      break;
					    }
					    customerIndex++;
					  }
					  if (!foundBooking) {
					    cout << "\t\tCustomer not found!" << endl;
					  }
					  file.close();
					} break;
            		case 8: {
					  // Add functionality for currency conversion between Khmer Riel (KHR) and US Dollar (USD)
					  fstream file("ShopcakeFile.bin", ios::binary | ios::in | ios::out);
					  if (!file.is_open()) {
					    cout << "\t\tError opening file for reading!" << endl;
					    break;
					  }
					  int conversionChoice;
					  cout << "\t\tCurrency Conversion:" << endl;
					  cout << "\t\t  1. Khmer Riel (KHR) to US Dollar (USD)" << endl;
					  cout << "\t\t  2. US Dollar (USD) to Khmer Riel (KHR)" << endl;
					  cout << "\t\tEnter your choice: ";
					  cin >> conversionChoice;
					
					  if (conversionChoice == 1) {
					    // Convert Khmer Riel (KHR) to US Dollar (USD)
					    double khrAmount;
					    cout << "\t\tEnter the amount in Khmer Riel (KHR): ";cin >> khrAmount;
					    // change rate of 4000 KHR = 1 USD 
					    double usdAmount = khrAmount / 4000.0;
					    cout << "\t\tThe equivalent amount in US Dollar (USD) is: $" << fixed << setprecision(2) << usdAmount << endl;
					  } else if (conversionChoice == 2) {
					    // Convert US Dollar (USD) to Khmer Riel (KHR)
					    double usdAmount;
					    cout << "\t\tEnter the amount in US Dollar (USD): ";cin >> usdAmount;
					    double khrAmount = usdAmount * 4000.0;
					    cout << "\t\tThe equivalent amount in Khmer Riel (KHR) is: ?" << fixed << setprecision(2) << khrAmount << endl;
					  } else {
					    cout << "\t\tInvalid conversion choice." << endl;
					  }
					  file.close();
					} break;
					case 9: {
					  fstream file("ShopcakeFile.bin", ios::binary);
					  if (!file.is_open()) {
					    cout << "\t\tError opening file!" << endl;
					    break;
					  }
					  int emptyCustomer;	
					  char confirmClear;
					  cout << "\t\tWARNING: This will clear all customer and booking data!" << endl;
					  cout << "\t\tAre you sure you want to continue (y/n)? ";
					  cin >> confirmClear;
					
					  if (confirmClear == 'y' || confirmClear == 'N') {
					    file.write((char*)&emptyCustomer, sizeof(emptyCustomer));
					    cout << "\t\tData cleared successfully!" << endl;
					  } else {
					    cout << "\t\tData clearing cancelled." << endl;
					  }
					
					  file.close();
					  break;
					}
                    case 10:
                    {
                         cout << "Thank you for support my company." << endl;
                         exit(0);
                    }
                    break;
                    }
               } while (op != 10);

               // Store
          }
          else if (op == 4)
          {
               do
               {
                    cout << "\t\t\t\t\t________________Stock__________________________" << endl
                         << "\t\t\t\t\t|                                    		 |" << endl
                         << "\t\t\t\t\t|   ---------> 1.Input		    <---------   |" << endl
                         << "\t\t\t\t\t|   ---------> 2.View and Search <---------   |" << endl
                         << "\t\t\t\t\t|   ---------> 3.Delete			<---------   |" << endl
                         << "\t\t\t\t\t|   ---------> 4.Exits 			<---------   |" << endl
                         << "\t\t\t\t\t|_____________________________________________|" << endl;
                    cout << "\t\tEnter option :";
                    cin >> op2;
                    switch (op2)
                    {
				    case 1:
				    {
				        // input
				        file.open("Shopcake1File.bin", ios::app | ios::binary);  // Same file name
				        if (!file)
				        {
				            cout << "\t\tError opening file..!!" << endl;
				        }
				        cout << "\t\tHow many cake you want to Enter in stock: ";
				        cin >> n;
				        for (i = 0; i < n; i++)
				        {
				            cout << "\t\tStock[" << (i + 1) << "]:" << endl;
				            s.input();
				            file.write((char *)&s, sizeof(s));
				        }
				        cout << "\t\tData saved successfully " << endl;
				        file.close();
				    }
				    break;
					case 2: {
					  // View stock
					  file.open("Shopcake1File.bin", ios::binary);
					  if (!file) {
					    cout << "\t\tError opening file..!!" << endl;
					    break;
					  }
					  int totalCakes = 0, soldOutCakes = 0;
					  while (!file.eof()) {
					    file.read((char*)&s, sizeof(s));
					    if (!file.eof()) {
					      totalCakes++;
					      if (s.getQty() == 0) {
					        soldOutCakes++;
					      }
					
					      cout << "\t\tCake Name: " << s.getname() << endl;
					      cout << "\t\tPrice: " << s.getPrice() << endl;
					      cout << "\t\tQty: " << s.getQty() << endl;
					      cout << "----------------------------------" << endl;
					    }
					  }
					
					  cout << "\t\tTotal Cakes: " << totalCakes << endl;
					  cout << "\t\tSold Out Cakes: " << soldOutCakes << endl;
					  cout << "\t\tAvailable Cakes: " << totalCakes - soldOutCakes << endl;
					
					  file.close();
					  }break;
					  case 3: {
					  // Delete stock
					  file.open("Shopcake1File.bin", ios::binary | ios::in);
					  if (!file) {
					    cout << "\t\tError opening file for reading!!" << endl;
					    }break;
					  fstream tempFile("tempShopcake.bin", ios::out | ios::binary);
					  if (!tempFile) {
					    cout << "\t\tError creating temporary file!!" << endl;
					    file.close();
					    }break;
					  int cakeCodeToDelete;
					  bool found = false;
					  cout << "\t\tEnter Cake Code to Delete: ";cin >> cakeCodeToDelete;
					  Cake tempCake;
					  while (!file.eof()) {
					    file.read((char*)&tempCake, sizeof(tempCake));
					    if (!file.eof()) {
					      if (tempCake.getCakeId() != cakeCodeToDelete) {
					        tempFile.write((char*)&tempCake, sizeof(tempCake));
					      } else {
					        found = true;
					        cout << "\t\tCake with code " << cakeCodeToDelete << " deleted successfully." << endl;
					      }
					    }
					  }
					  file.close();
					  tempFile.close(); 
					  if (found) {
					    remove("Shopcake1File.bin");
					    rename("tempShopcake.bin", "Shopcake1File.bin");
					  } else {
					    cout << "\t\tCake with code " << cakeCodeToDelete << " not found." << endl;
					    remove("tempShopcake.bin");  
					  }
					}break;
						case 4: {
						  cout << "\t\tExiting Stock Management..." << endl;
						}break;
									
										
                         while (op2 != 4);
                    }
                    if (op == 3)
                    {
                         cout << "Good bye." << endl;
                         exit(0);
                    }
               } while (op != 5);
          }
     } while (op != 3);
}

