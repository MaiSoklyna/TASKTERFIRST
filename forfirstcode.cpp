#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string textfeedback[200];
char y[3];

class Shop
{
private:
    // Personal information for List
    string nameP;
    string numberPhone;
    int IDPeople;
    int day, mm, yy;
    int age;

    // Cake information
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
    // Set attributes for personal information (List)
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

    // Set attributes for cake information
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

    // Input personal information
    void inputlist()
    {
        cout << "  \n\n\n\t========********************=====";

        cout << " \n\n\tEnter name: ";
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
        cout << "\n\n\tIF YOU WANT TO SHOW INFORMATION, PLEASE WRITE Y OR y";

        cin >> y;
        if (cin.get() == 'y' || cin.get() == 'Y')
        {
            showlist();
        }
        else
        {
            return;
        }
    }

    // Show personal information
    void showlist() const
    {
        cout << "\n\n\tYOUR INFORMATION HERE :::::::::::: ";
        cout << "\n\n\t1. ID: " << IDPeople;
        cout << "\n\n\t2. NAME: " << nameP;
        cout << "\n\n\t3. AGE: " << age;
        cout << "\n\n\t4. Birthday (DD/MM/YYYY): " << day << "/" << mm << "/" << yy;
        cout << "\n\n\t5. Phone number: " << numberPhone;
        cout << "\n\n\t==============================";
    }

    // Input cake boxing information
    void inputboxing()
    {
        cout << "\n\n\tEnter cake ID: ";
        cin >> IDCake;
        cout << "\n\n\tEnter cake color: ";
        cin.ignore();
        getline(cin, colorcake);
        cout << "\n\n\tEnter order time: ";
        getline(cin, timeOrder);
        cout << "\n\n\tEnter pickup time: ";
        getline(cin, timeGet);
        cout << "\n\n\tEnter cake type: ";
        getline(cin, typeCake);
        cout << "\n\n\tEnter cake size (S/M/L): ";
        cin >> sizeCake;
        cout << "\n\n\tEnter quantity: ";
        cin >> qualityCake;
        cout << "\n\n\tEnter price: ";
        cin >> price;
        total = price * qualityCake;
        cout << "\n\n\tTotal cost: " << total;
    }

    // Show cake boxing information
    void showboxing() const
    {
        cout << "\n\n\tCAKE INFORMATION HERE :::::::::::: ";
        cout << "\n\n\t1. Cake ID: " << IDCake;
        cout << "\n\n\t2. Cake Color: " << colorcake;
        cout << "\n\n\t3. Order Time: " << timeOrder;
        cout << "\n\n\t4. Pickup Time: " << timeGet;
        cout << "\n\n\t5. Cake Type: " << typeCake;
        cout << "\n\n\t6. Cake Size: " << sizeCake;
        cout << "\n\n\t7. Quantity: " << qualityCake;
        cout << "\n\n\t8. Price per Cake: " << price;
        cout << "\n\n\t9. Total Cost: " << total;
        cout << "\n\n\t==============================";
    }

    // Write personal information to file
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

    // Write cake information to file
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

    // Read personal information from file
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

    // Read cake information from file
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

// Write personal and cake information to file
void writeListIToFile(const string &filename, Shop shop[], int listcount)
{
    ofstream myfile("ShopInformation.txt");
    if (!myfile)
    {
        cout << "ERROR OPENING FILE!" << endl;
        return;
    }
    for (int i = 0; i < listcount; i++)
    {
        shop[i].writeToFile(myfile);
        shop[i].writecakeToFile(myfile);
        myfile << endl;
    }
    myfile.close();
}

// Read personal and cake information from file
void readListFromFile(const string &filename, Shop shop[], int &listcount)
{
    ifstream myfile("ShopInformation.txt");
    if (!myfile)
    {
        cout << "ERROR OPENING FILE!" << endl;
        return;
    }
    listcount = 0;
    while (myfile && listcount < 15)
    {
        shop[listcount].readFromFile(myfile);
        shop[listcount].readcakeboxingToFile(myfile);
        listcount++;
        myfile.ignore();
    }
    myfile.close();
}

int main()
{
    Shop shop[100];
    int listcount = 1;
    int choice, ch;

    // Set initial values
    shop[0].SetAttributeValueTolistI(0, "LyLy", 18, 11, 3, 2006, "0889487788");
    shop[0].SetAttributeValueToCakeBoxing(0, "Pink", "12:30 AM", "6:35 PM", "CHOCOLATE", 'M', 2, 15.00);

    // Write initial data to files
    writeListIToFile("ShopInformation.txt", shop, listcount);

    // Read data from files
    readListFromFile("ShopInformation.txt", shop, listcount);

    do
    {
        cout << "\n\n\t===WELCOME TO MY SHOP CAKE===";
        cout << "\n\n\t1. WRITE YOUR INFORMATION";
        cout << "\n\n\t2. BOXING CAKE BIRTHDAYS";
        cout << "\n\n\t3. SHOW LIST AND CAKE BOXING";
        cout << "\n\n\t4. EXIT";
        cout << "\n\n\tPLEASE INPUT YOUR CHOICE: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            shop[listcount].inputlist();
            listcount++;
            writeListIToFile("ShopInformation.txt", shop, listcount);
            break;

        case 2:
            shop[listcount - 1].inputboxing();
            writeListIToFile("ShopInformation.txt", shop, listcount);
            break;
            
        case 3:

                    for (int i = 0; i < listcount; i++)
            {
                shop[i].showlist();
                shop[i].showboxing();
            }
            break;

        case 4:
            cout << "\n\n\tTHANK YOU FOR USING OUR SHOP SERVICE!";
            exit(0);
            break;

        default:
            cout << "\n\n\tINVALID CHOICE! PLEASE TRY AGAIN.";
        }
        cout << "\n\n\tDo you want to continue? (1 for Yes / 0 for No): ";
        cin >> ch;
    } while (ch == 1);

    return 0;
}

     
