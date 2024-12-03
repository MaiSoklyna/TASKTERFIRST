#include <iostream>
#include <iomanip>
#include <fstream>
#include <unistd.h>
#include <string>
using namespace std;
class Cake
{
private:
     int cakeId;
     string name;
     int quantity;
     float price;

public:
     Cake() {}

     int getCakeId() const { return cakeId; }
     void setCakeId(int id) { cakeId = id; }
     string getName() const { return name; }
     void setName(const string &name) { this->name = name; }
     int getQuantity() const { return quantity; }
     void setQuantity(int qty) { quantity = qty; }
     float getPrice() const { return price; }
     void setPrice(float price) { this->price = price; }

     // for example
     // additinal methods  as needed
     // this coe write out class to declear
     void input()
     {
     }
};
// class for add information people
class Person
{
private:
     string name;
     int age, id;
     char gender;

public:
     Person() {}

     void input()
     {
          cout << "\n\n\t========================+++++=========================";
          cout << "\n\n\t===============ADD YOUR PERSONAL INFORMATION =========";
          cout << "\n\n\t======================================================";
          cout << "\n\tENTER YOUR ID :::";
          cin >> id;
          cout << "\n\tENTER YOUR NAME :::";
          cin.ignore();
          getline(cin, name);
          cout << "\n\tENTER YOUR GENDER (F OR M) :::";

          cin >> gender;
          cout << "\n\t ENTER YOUR AGE :::";
          cin >> age;
     }
     void setId(int num)
     {
          this->id = num;
     }
     void setName(string str)
     {
          this->name = str;
     }
     void setGender(char str)
     {
          this->gender = str;
     }
     void setAge(int num)
     {
          this->age = num;
     }
     int getId()
     {
          return id;
     }
     string getName()
     {
          return name;
     }
     char getGender()
     {
          return gender;
     }
     int getAge()
     {
          return age;
     }

     static void header()
     {
          cout << setw(30) << "ID" << setw(12) << "NAME" << setw(12) << "GENDER" << setw(13) << "AGE" << setw(12);
     }
     void output()
     {
          cout << setw(30) << id << setw(12) << name << setw(12) << gender << setw(12) << age << "Y" << setw(13);
     }
};
class Store{
     protected:
     int code,qty;
     string name;
     float price;
     public:
     Store(){
     
     }
     void setCode(int num){
          code=num;
     }
     int getCode(){
          return code;
     }
     void setQty(int qty){
          this->qty=qty;
     }
     int getQty(){
          return qty;
     }
     string getname(){
          return name;
     }
     void setPrice(float price){
          this->price=price;
     }
     float getprice(){
          return price;
     }
     void input(){
          cout<<"\t\t\t ENTER YOUR CODE    ::";
          cin>>code;
          cout<<"\t\t\tENTER YOUR NAME     ::";
          cin.ignore();
          getline(cin,name);
          cout<<"\t\t\tENTER QTY            ::";
          cin>>qty;
          cout<<"ENETR PRICE               ::";
          cin>>price;
     }
    void output() {
        cout << setw(35) << code << setw(15) << name << setw(15) << qty << setw(15) << price << "$" << setw(15) << endl;
    }

    static void header() {
        cout << setw(35) << "CODE" << setw(15) << "NAME" << setw(15) << "QTY" << setw(16) << "PRICE" << endl;
    }


};
class Customer: public Store{
     public:
     string name;
     string phoneNumber;
     string email;
     string address;
     Customer(): Store(){ }
      void input(){
          Store::input();
     }
     float total(){
          return (qty * price);
     }
     int discount(){
          return (total()>=0&&total()<10) ? 0 
           :(total()>=10&&total()<20)? 5
           :(total()>=20&&total()<40)? 10
           :(total()>=60&&total()<70)? 15
           :(total()>=70&&total()<100)? 20
                                        :25;  
     }
     float payment(){
          return total()-(total()*discount())/100;
     }
     void output(){
          cout<< setw(20) << code << setw(12) << name << setw(12) << qty << setw(12) << price << "$" << setw(12)
             << total() << setw(12) << discount() << "%" << setw(12) << payment() << "$" << endl;
     }
     static void header() {
        cout << setw(20) << "CODE" << setw(12) << "NAME" << setw(12) << "QTY" << setw(13) << "PRICE" << setw(12)
             << "TOTAL" << setw(13) << "DISCOUNT" << setw(13) << "PAYMENT" << endl;
    }

};
class Staff:public Person{
     private:
     string position;
     float salary;
     public:
     Staff():Person(){

     }
     void setPosition(string str){
          this-> position=str;
     }
     void setSalary(float num){
          this->salary=num;
     }
     string getPosition(){
          return position;
     }
     float getSalary(){
          return salary;
     }
     void input(){
          Person::input();
          cout<<"\t\t\tENTER POSITION ::";
          cin>>position;
          cout<<"ENTER SALARY   ::";
          cin>>salary;
     }
     void output(){
          Person::output();
          cout<<position<<setw(11)<<salary<<"$"<<setw(12)<<endl;

     }
      static void header() {
        Person::header();
        cout << "POSITION" << setw(12) << "SALARY" << setw(12) << endl;
    }
};
void styleHeader()
{
     cout<<"\t\t_______________________VIEW DATA________________________________________";

}
void style(){
     cout<<"\t\t_________________________________________________________________________";

}
void loading(){
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
int main(){
     Staff st,st2;
     Customer cus,cus2;
     Store s,s2;
     int op,op1,op2,op3;
     int choice;
     fstream file;
     int n,i,count=0;
     Hello();
     do{
           cout << "\t\t\t\t\t________________OPTION__________________" << endl
             << "\t\t\t\t\t|                                      |" << endl
             << "\t\t\t\t\t|   ---------> 1. Customer<---------   |" << endl
             << "\t\t\t\t\t|   ---------> 2. Stock   <---------   |" << endl
             << "\t\t\t\t\t|   ---------> 3. Exits   <---------   |" << endl
             << "\t\t\t\t\t|______________________________________|" << endl;
          cout<<"\t\tENTER OPTION ::";
          cin>>op;
          system("cls");
          
          if (op==1){
               do{
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
                    switch (op)
                    {
                    case 1/* constant-expression */:{
                    file.open("ShopcakeFile.bin",ios::app|ios::binary);
                    if(!file){
                         cout<<"ERROR OPEN FILE....!!";
                    }
                    cout<<"\t\tHOW MANY CUSTOMERS DO YOU WANT TO ADD:::";
                    cin>>n;
                    for(i=i;i<n;i++){
                         cout<<"\t\tCUSTOMER ["<<(i+1)<<"]::"<<endl;
                         cout<<"\n\tENTER YOUR NAME::";
                         cin.ignore();
                         getline(cin,cus.name);
                         cout<<"ENTER YOUR PHONE NUMBERS::";
                        
                         getline(cin,cus.phoneNumber);
                         cout<<"YOUR EMAIL::";
                          getline(cin,cus.email);
                          cout<<"YOUR ADRESS::";
                           getline(cin,cus.address);
                           file.write((char*)&cus,sizeof(cus));
                           cout << "\n\t\t\tCustomer Information Saved" << endl;
					        cout << "NAME: " << cus.name << endl;
					        cout << "PHONE NUMBER: " << cus.phoneNumber << endl;
					        cout << "EMAIL: " << cus.email << endl;
					        cout << "ADDRESS: " << cus.address << endl;

                    }
                    cout<<"\n\t\tDATA SAVE SUCCESSFULLY><><><>"<<endl;
                    file.close();

                         /* code */
                         break;
                    }
                    case 2:{
                    int cakeChioce,qty;
                    char confirm;
                    cout<<"\t\tAVAILABLE CKAE OPTION HERE 3"<<endl;
                    cout<<"\t\t==1. CHOCOLATE CAKE (price $25) "<<endl;
                    cout<<"\t\t==2. VANILLA  CAKE (price $20) "<<endl;
                    cout<<"\t\t==1. STRAWBERRY CAKE (price $30) "<<endl;
                    cout<<"\t\t==(ENTER YOUR CAKE NUMBER U WANT ::)"<<endl;
                    do{
                         cout<<"ENTER  HERE:: ";
                         cin>>cakeChioce;
                    }while()


                    }
                    }


               }while(op!=5);
          }
     }while(op!=3);
}




