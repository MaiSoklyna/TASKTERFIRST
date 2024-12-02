#include <iostream>  
#include <fstream>  //error
#include <string>  
using namespace std;  
  
class cloth {  
private:  
   string size;  
   string type;  
   float price;  
   int quantity;  
   float total_price;  
   string time_order;  
   string color;  
  
public:  
   void SetAttributesValueCLOTH(const string& s, const string& t, float p, int q, const string& to, const string& c) {  
      size = s;  
      type = t;  
      price = p;  
      quantity = q;  
      time_order = to;  
      color = c;  
      total_price = price * quantity;  
   }  
  
   void PrintAttributesValueCT() {  
      cout << "Size: " << size << endl;  
      cout << "Type: " << type << endl;  
      cout << "Price: " << price << endl;  
      cout << "Quantity: " << quantity << endl;  
      cout << "Time_order: " << time_order << endl;  
      cout << "Color: " << color << endl;  
      cout << "Total_price: " << total_price << endl;  
      cout << "===============================" << endl;  
   }  
   string getType() { return type; } 
   string getSize() { return size; }  
    
   float getPrice() { return price; }  
   int getQuantity() { return quantity; }  
   string getTime_order() { return time_order; }  
   string getColor() { return color; }  
   float getTotal_price() { return total_price; }  
};  
  
class customer {  
private:  
   int no_customer;  
   string name_customer;  
   string gender;  
   string height;  
   string numberP;  
   cloth cloths[10];  
   int clothCount;  
  
public:  
   void SetAttributesValueC(int no, const string& nc, const string& gd, const string& h, const string& np) {  
      no_customer = no;  
      name_customer = nc;  
      gender = gd;  
      height = h;  
      numberP = np;  
      clothCount = 0;  
   }  
  
   void AddCloth(const string& s, const string& t, float p, int q, const string& to, const string& c) {  
      if (clothCount < 10) {  
        cloths[clothCount].SetAttributesValueCLOTH(s, t, p, q, to, c);  
        clothCount++;  
      } else {  
        cout << "Maximum number of cloths reached!" << endl;  
      }  
   }  
  
   void PrintAttributesValueCT() {  
      cout << "No_customer: " << no_customer << endl;  
      cout << "Name_customer: " << name_customer << endl;  
      cout << "Gender: " << gender << endl;  
      cout << "Height: " << height << endl;  
      cout << "NumberP: " << numberP << endl;  
      cout << "===============================" << endl;  
      cout << "Cloths:" << endl;  
      for (int i = 0; i < clothCount; i++) {  
        cloths[i].PrintAttributesValueCT();  
      }  
   }  
  
   void writeToFile(const string& fileName) {  
      ofstream file("customer_data.txt", ios::app);  
      file << no_customer << endl;  
      file << name_customer << endl;  
      file << gender << endl;  
      file << height << endl;  
      file << numberP << endl;  
      file << clothCount << endl;  
      for (int i = 0; i < clothCount; i++) {  
        file << cloths[i].getSize() << endl;  
        file << cloths[i].getType() << endl;  
        file << cloths[i].getPrice() << endl;  
        file << cloths[i].getQuantity() << endl;  
        file << cloths[i].getTime_order() << endl;  
        file << cloths[i].getColor() << endl;  
        file << cloths[i].getTotal_price() << endl;  
      }  
      file.close();  
      cout << "File write successfully!" << endl;  
   }  
  
   void readFromFile(const string& fileName) {  
      ifstream file("customer_data.txt");  
      if (file.is_open()) {  
        file >> no_customer;  
        file >> name_customer;  
        file >> gender;  
        file >> height;  
        file >> numberP;  
        file >> clothCount;  
        for (int i = 0; i < clothCount; i++) {  
           string s, t, to, c;  
           float p;  
           int q;  
           file >> s;  
           file >> t;  
           file >> p;  
           file >> q;  
           file >> to;  
           file >> c;  
           cloths[i].SetAttributesValueCLOTH(s, t, p, q, to, c);  
        }  
        file.close();  
        cout << "File read successfully!" << endl;  
      } else {  
        cout << "File not found!" << endl;  
      }  
   }  
};  
  
int main() {  
   customer aboutcustomer[30];  
   int customerCount = 0;  
  
   for (int i = 0; i < 30; i++) {  
      int no;  
      string nc, gd, h, np;   
      cout << "Enter customer information:" << endl;  
      cout << "No: ";  
      cin >> no;  
      cout << "Name: ";  
      cin >> nc;  
      cout << "Gender: ";  
      cin >> gd;  
      cout << "Height: ";  
      cin >> h;  
      cout << "NumberP: ";  
      cin >> np;  
  
      aboutcustomer[i].SetAttributesValueC(no, nc, gd, h, np);  
       
      int clothCount;  
      cout << "Enter number of cloths: ";  
      cin >> clothCount;  
  
      for (int j = 0; j < clothCount; j++) {  
        string s, t, to, c;  
        float p;  
        int q;  
        cout << "Enter cloth information:" << endl;  
        cout << "Size: ";  
        cin >> s;  
        cout << "Type: ";  
        cin >> t;  
        cout << "Price: ";  
        cin >> p;  
        cout << "Quantity: ";  
        cin >> q;  
        cout << "Time_order: ";  
        cin >> to;  
        cout << "Color: ";  
         cin >> t;  
        cout << "Price: ";  
        cin >> p;  
        cout << "Quantity: ";  
        cin >> q;  
        cout << "Time_order: ";  
        cin >> to;  
        cout << "Color: ";  
        cin >> c;  
  
        aboutcustomer[i].AddCloth(s, t, p, q, to, c);  
      }  
   }  
  
   // Write data to file  
   aboutcustomer[0].writeToFile("customer_data.txt");  
  
   // Read data from file  
   aboutcustomer[0].readFromFile("customer_data.txt");  
  
   // Print customer information  
   aboutcustomer[0].PrintAttributesValueCT();  
  
   return 0;  
}
        









