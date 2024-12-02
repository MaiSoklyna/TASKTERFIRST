#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string textfeedback[200];
char y[3];

class List
{
private:
     string nameP;
     string numberPhone;
     int IDPeople;
     int day, mm, yy;
     int age;

public:
     // Set attributes to the list
     void SetAttributeValueTolistI(int id, const string &N, int Age, int Day, int M, int Year, const string &NUMBERP)
     {
          IDPeople = id;
          nameP = N;
          age = Age;
          day = Day;
          mm = M;
          yy = Year;
          numberPhone = NUMBERP;
     }


     // Input list (define if needed)
     void inputlist() {
          cout<<"  \n\n\n\t========********************=====";

          cout <<" \n\n\tEnter name: ";
          cin.ignore();
          getline(cin, nameP);
          cout << "\n\n\n\tEnter ID: ";
          cin >> IDPeople;
          cout << "\n\n\tEnter age: ";
          cin >> age;
          cout << "\n\n\tEnter day of birth (DD): ";
          cin >> day;
          cout << "\n\n\tEnter month of birth (MM): ";
          cin >> mm;
          cout << "\n\n\tEnter year of birth (YYYY): ";
          cin >> yy;
          cin.ignore();
          cout << "\n\n\tEnter phone number: ";
          getline(cin, numberPhone);
          cout<<"\n\n\tIF YOUR WANT TO SHOW INFORMATION YOUR PLEASE WRITE Y OR y";
         
          cin>>y;
          if(cin.get() == 'y' || cin.get() == 'Y'){
              cout<<"\n\n\t========You selected showlist==========";
               void showlist();

          }
          else {
             
               return ;
          }
     }

     // Show list (define if needed)
     //print attribute from input list();
    
     void showlist()const  {
         cout<<"\n\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
         cout<<"\n\n\t============**********=========";
         cout<<"\n\n\tYOUR INFORMATION HERE :::::::::::: ";
         cout<<" \n\n\t1. ID (must to remember )::"<<IDPeople<<endl;
         cout<<"\n\n\t2. YOUR NAME:<<<<"<<nameP;
         cout<<"\n\n\t3. AGE ===:"<<age;
         cout<<"\n\n\t4. Birthday of dd/mm/yy==="<<day<<"/"<<mm<<"/"<<yy<<endl;
         cout<<"\n\n\t5. Numberphone's U::\t"<<numberPhone;
         cout<<"\n\n\t==============================";
         cout<<"\n\n\tIF YOU WANT TO FEEDBACK YOUR PLEASE WRITE Y OR y";
         
         cin>>y;
         if(cin.get() == 'y' || cin.get() == 'Y'){
          cout<<"\n\n\t========You selected feedback==========";
             void feedback();
             cout<<"\n\n\tIF YOU WANT TO BACK TO MENU YOUR PLEASE WRITE Y OR y";
             cin>>y;
             if(cin.get() == 'y' || cin.get() == 'Y'){
                cout<<"\n\n\t========You selected menu==========";
                 return ;
             }

         


     }
     }

     // Update list (define if needed)
     void updatelist();

     // Delete list (define if needed)
     void deletelist() ;

     // Feedback (define if needed)
     void feedback() ;

     // Write to file
     void writeToFile(ofstream &myfile) const
     {
          myfile << nameP << endl;
          myfile << IDPeople << endl;
          myfile << age << endl;
          myfile << day << endl;
          myfile << mm << endl;
          myfile << yy << endl;
          myfile << numberPhone << endl;
     }

     // Read from file
     void readFromFile(ifstream &myfile)
     {
          getline(myfile, nameP);
          myfile >> IDPeople;
          myfile >> age;
          myfile >> day;
          myfile >> mm;
          myfile >> yy;
          myfile.ignore();
          getline(myfile, numberPhone);
     }
};

// Write list data to file
void writeListIToFile(const string &filename, List listI[], int listcount)
{
     ofstream myfile("ListInformation.txt");
     if (!myfile)
     {
          cout << "ERROR OPENING FILE!" << endl;
          return;
     }
     for (int i = 0; i < listcount; i++)
     {
          listI[i].writeToFile(myfile);
          myfile << endl;
     }
     myfile.close();
}

// Read list data from file
void readListFromFile(const string &filename, List listI[], int &listcount)
{
     ifstream myfile("ListInformation.txt");
     if (!myfile)
     {
          cout << "ERROR OPENING FILE!" << endl;
          return;
     }
     listcount = 0;
     while (myfile && listcount < 15)
     {
          listI[listcount].readFromFile(myfile);
          listcount++;
          myfile.ignore();
     }
     myfile.close();
};

class Cake
{
private:
     int IDCake;
     string colorcake;
     string timeOrder;
     string timeGet;
     string typeCake;
     char sizeCake;
     int qualityCake;
     double price;
     double total;

public:
     // Set attributes for the cake
     void SetAttributeValueToCakeBoxing(int IDC, const string &colorc, const string &timeO, const string &timeG,
                                        const string &typeC, char size, int qualC, double Price)
     {
          IDCake = IDC;
          colorcake = colorc;
          timeOrder = timeO;
          timeGet = timeG;
          typeCake = typeC;
          sizeCake = size;
          qualityCake = qualC;
          price = Price;
          total = Price * qualC;
     }

     // Input boxing (define if needed)
     void inputboxing() {}

     // Show boxing (define if needed)
     void showboxing() {}

     // Update boxing (define if needed)
     void updateboxing() {}

     // Delete boxing (define if needed)
     void deleteboxing() {}

     // Write cake data to file
     void writecakeToFile(ofstream &myfile) const
     {
          myfile << IDCake << endl;
          myfile << colorcake << endl;
          myfile << timeOrder << endl;
          myfile << timeGet << endl;
          myfile << typeCake << endl;
          myfile << sizeCake << endl;
          myfile << qualityCake << endl;
          myfile << price << endl;
          myfile << total << endl;
     }

     // Read cake data from file
     void readcakeboxingToFile(ifstream &myfile)
     {
          myfile >> IDCake;
          myfile.ignore();
          getline(myfile, colorcake);
          getline(myfile, timeOrder);
          getline(myfile, timeGet);
          getline(myfile, typeCake);
          myfile >> sizeCake;
          myfile >> qualityCake;
          myfile >> price;
          myfile >> total;
     }
};


// Write cake data to file
void writecakeToFile(const string &filename, Cake cake[], int cakecount)
{
     ofstream myfile("CakeBoxingInformation.txt");
     if (!myfile)
     {
          cout << "ERROR OPENING FILE!" << endl;
          return;
     }
     for (int i = 0; i < cakecount; i++)
     {
          cake[i].writecakeToFile(myfile);
          myfile << endl;
     }
     myfile.close();
}

// Read cake data from file
void readcakeboxingToFile(const string &filename, Cake cake[], int &cakecount)
{
     ifstream myfile("CakeBoxingInformation.txt");
     if (!myfile)
     {
          cout << "ERROR OPENING FILE!" << endl;
          return;
     }
     cakecount = 0;
     while (myfile && cakecount < 15)
     {
          cake[cakecount].readcakeboxingToFile(myfile);
          cakecount++;
          myfile.ignore();
     }
     myfile.close();
}

int main()
{
     List listI[100];
     Cake cake[100];
     int listcount = 1;
     int cakecount = 1;
     int choice, ch;

     // Set initial values
     listI[0].SetAttributeValueTolistI(0, "LyLy", 18, 11, 3, 2006, "0889487788");
     cake[0].SetAttributeValueToCakeBoxing(0, "Pink", "12:30 AM", "6:35 PM", "CHOCOLATE", 'M', 2, 15.00);

     // Write list and cake data to files
     writeListIToFile("ListInformation.txt", listI, listcount);
     writecakeToFile("CakeBoxingInformation.txt", cake, cakecount);

     // Read data from files
     readListFromFile("ListInformation.txt", listI, listcount);
     readcakeboxingToFile("CakeBoxingInformation.txt", cake, cakecount);

     do
     {
     menu:
          cout << "\n\n\t===**********************************===";
          cout << "\n\n\t=========WELCOME TO MY SHOP CAKE=======";
          cout << "\n\n\t===1. WRITE YOUR INFORMATION TO LIST === ";
          cout << "\n\n\t===2. BOXING CAKE BIRTHDAYS ============ ";
          cout << "\n\n\t===3. SHOW LIST AND CAKE BOXING ========= ";
          cout << "\n\n\t===4. UPDATE LIST AND BOXING CAKE =======";
          cout << "\n\n\t===5. DELETE LIST AND BOXING CAKE =======";
          cout << "\n\n\t===6. FEEDBACK TO MY SHOP  ==============";
          cout << "\n\n\t===7. EXIT.............!================";
          cout << "\n\n\t===**********************************===";
          cout << "\n\n\t PLEASE INPUT YOUR CHOICE HERE ++++++++++";
          cin >> choice;

          switch (choice)
          {
          case 1:
               // Write new information to the list
               listI[listcount].inputlist();
               listcount++;
               writeListIToFile("ListInformation.txt", listI, listcount);
               break;

          case 2:
               // Boxing cake for birthdays
               cake[cakecount].inputboxing();
               cakecount++;
               writecakeToFile("CakeBoxingInformation.txt", cake, cakecount);
               break;

          case 3:
               // Show list and cake boxing
               do
               {
                    cout << "\n\n\t ==================================";
                    cout << "\n\n\t ===THERE ARE TWO OPTIONS ===";
                    cout << "\n\n\t ===1. SHOW LIST INFORMATION=======";
                    cout << "\n\n\t ===2. SHOW BOXING CAKE  =========";
                    cout << "\n\n\t (((PLEASE SELECT YOUR OPTION)))";
                    cin >> ch;

                    if (ch == 1)
                    {
                         cout << "\n\n\t==================++++++++++";
                         cout << "\n\n\t YOU WILL SEE LIST INFORMATION ";
                         for (int i = 0; i < listcount; i++)
                         {
                              listI[i].showlist();
                         }
                    }
                    else if (ch == 2)
                    {
                         cout << "\n\n\t==================++++++++++";
                         cout << "\n\n\t YOU WILL SEE BOXING CAKE INFORMATION ";
                         for (int i = 0; i < cakecount; i++)
                         {
                              cake[i].showboxing();
                         }
                    }
               } while (ch != 0);
               break;

          case 4:
               // Update list and boxing cake
               cout << "\n\n\t==================================";
               cout << "\n\n\t YOU WILL UPDATE LIST AND BOXING CAKE";
               do
               {
                    cout << "\n\n\tSELECT FUNCTION: ";
                    cout << "\n\n\n=====1. UPDATE LIST===========";
                    cout << "\n\n\n=====2. UPDATE BOXING CAKE===========";
                    cout << "\n\n\t PLEASE SELECT >>>>>>>>>> ";
                    cin >> ch;

                    if (ch == 1)
                    {
                         cout << "\n\n\t YOU WILL UPDATE LIST";
                         listI[listcount - 1].updatelist(); // Updating the last entry
                         writeListIToFile("ListInformation.txt", listI, listcount);
                    }
                    else if (ch == 2)
                    {
                         cout << "\n\n\t YOU WILL UPDATE BOXING CAKE";
                         cake[cakecount - 1].updateboxing(); // Updating the last entry
                         writecakeToFile("CakeBoxingInformation.txt", cake, cakecount);
                    }
               } while (ch != 0);
               break;

          case 5:
               // Delete list and boxing cake
               cout << "\n\n\t==================================";
               cout << "\n\n\t DELETE LIST AND BOXING CAKE";
               do
               {
                    cout << "\n\n\tSELECT FUNCTION: ";
                    cout << "\n\n\n=====1. DELETE LIST===========";
                    cout << "\n\n\n=====2. DELETE BOXING CAKE===========";
                    cout << "\n\n\t PLEASE SELECT >>>>>>>>>> ";
                    cin >> ch;

                    if (ch == 1)
                    {
                         cout << "\n\n\t YOU WILL DELETE LIST";
                         listI[listcount - 1].deletelist(); // Deleting the last entry (you may adjust this logic)
                         listcount--;
                         writeListIToFile("ListInformation.txt", listI, listcount);
                    }
                    else if (ch == 2)
                    {
                         cout << "\n\n\t YOU WILL DELETE BOXING CAKE";
                         cake[cakecount - 1].deleteboxing(); // Deleting the last entry (you may adjust this logic)
                         cakecount--;
                         writecakeToFile("CakeBoxingInformation.txt", cake, cakecount);
                    }
               } while (ch != 0);
               break;

          case 6:
               // Feedback to the shop
               cout << "\n\n\t==================================";
               cout << "\n\n\t PROVIDE FEEDBACK ON THE SYSTEM";
               cin.ignore(); // Clear input buffer before taking feedback
               cout << "\nEnter your feedback: ";
               getline(cin, textfeedback[listcount]); // Capture the feedback
               listI[listcount - 1].feedback();
               break;

          case 7:
               // Exit the system
               cout << "\n\n\t==================================";
               cout << "\n\n\t EXITING THE SYSTEM...";
               exit(0);
               goto menu;

          default:
               cout << "\nInvalid choice! Please select again.";
          }

     } while (choice != 0);

     return 0;
}
