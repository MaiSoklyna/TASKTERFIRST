#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class food
{
private:
     string name;
     float price;
     int quantity;
     string customerName;
     string timedilevery;
     float totalCost;

public:
void addOrder(){
     cout << "Enter the name of the food: ";
     cin >> name;
     cout << "Enter the price of the food: $";
     cin >> price;
     cout << "Enter the quantity of the food: ";
     cin >> quantity;
     cout << "Enter the customer's name: ";
     cin >> customerName;
     cout << "Enter the time of delivery (morning/afternoon): ";
     cin >> timedilevery;
     totalCost = price * quantity;
 
}
     void displayOrderDetails()
     {
          cout << "Name: " << name << endl;
          cout << "Price: $" << price << endl;
          cout << "Quantity: " << quantity << endl;
          cout << "Customer Name: " << customerName << endl;
          cout << "Time of Delivery: " << timedilevery << endl;
          cout << "Total Cost: $" << totalCost << endl;
     }

     void writeOrderDetailsToFile(ofstream &fo)
     {
          fo << "Name: " << name << endl;
          fo << "Price: $" << price << endl;
          fo << "Quantity: " << quantity << endl;
          fo << "Customer Name: " << customerName << endl;
          fo << "Time of Delivery: " << timedilevery << endl;
          fo << "Total Cost: $" << totalCost << endl;
          fo << endl;
     }
};

int main()
{ int choice;
     cout<<"choice";
     cin>>choice;
     ofstream fo;
     fo.open("order.txt"); 

     // Write order details to the file for each food object
     food apple;
     apple.addOrder();
     apple.writeOrderDetailsToFile(fo);
     food tell;
     tell.writeOrderDetailsToFile(fo);
     tell.displayOrderDetails();
     

     // Close the file
     fo.close();

     return 0;
}
