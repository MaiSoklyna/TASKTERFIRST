#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string textfeedback[200];

class Shop
{
private:
    string nameP;
    string numberPhone;
    int IDPeople;
    int day, mm, yy;
    int age;
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
    // Set personal information
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

    // Set cake boxing information
    void SetAttributeValueToCakeBoxing(int IDC, const string &colorc, const string &timeO, const string &timeG, const string &typeC, char size, int qualC, double Price)
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
        cout << "\n\n\tEnter name: ";
        cin.ignore();
        getline(cin, nameP);
        cout << "\n\n\tEnter ID: ";
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
    }

    // Input cake boxing information
    void inputboxing()
    {
        cout << "\n\n\tEnter Cake ID: ";
        cin >> IDCake;
        cin.ignore();
        cout << "\n\n\tEnter cake color: ";
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
        cout << "\n\n\tEnter price per cake: ";
        cin >> price;
        total = qualityCake * price;
    }

    // Display personal information
    void showlist() const
    {
        cout << "\n\n\t===**********************************===";
        cout << "\n\n\t=========WELCOME TO MY SHOP CAKE=======";
        cout << "\n\n\tYOUR INFORMATION:";
        cout << "\n\n\t1. ID: " << IDPeople;
        cout << "\n\n\t2. Name: " << nameP;
        cout << "\n\n\t3. Age: " << age;
        cout << "\n\n\t4. Birthday (dd/mm/yyyy): " << day << "/" << mm << "/" << yy;
        cout << "\n\n\t5. Phone number: " << numberPhone << endl;
    }

    // Display cake boxing information
    void showboxing() const
    {
        cout << "\n\n\t===**********************************===";
        cout << "\n\n\t=========WELCOME TO MY SHOP CAKE=======";
        cout << "\n\n\tCAKE INFORMATION:";
        cout << "\n\n\t1. Cake ID: " << IDCake;
        cout << "\n\n\t2. Cake Color: " << colorcake;
        cout << "\n\n\t3. Order Time: " << timeOrder;
        cout << "\n\n\t4. Pickup Time: " << timeGet;
        cout << "\n\n\t5. Cake Type: " << typeCake;
        cout << "\n\n\t6. Size: " << sizeCake;
        cout << "\n\n\t7. Quantity: " << qualityCake;
        cout << "\n\n\t8. Total Price: $" << total << endl;
    }

    // Update personal information
    void updatelist()
    {
        cout << "\n\n\tEnter new name: ";
        cin.ignore();
        getline(cin, nameP);
        cout << "\n\n\tEnter new age: ";
        cin >> age;
        cout << "\n\n\tEnter new phone number: ";
        cin.ignore();
        getline(cin, numberPhone);
    }

    // Update cake boxing information
    void updateboxing()
    {
        cout << "\n\n\tEnter new cake color: ";
        cin.ignore();
        getline(cin, colorcake);
        cout << "\n\n\tEnter new order time: ";
        getline(cin, timeOrder);
        cout << "\n\n\tEnter new pickup time: ";
        getline(cin, timeGet);
        cout << "\n\n\tEnter new cake type: ";
        getline(cin, typeCake);
        cout << "\n\n\tEnter new size (S/M/L): ";
        cin >> sizeCake;
        cout << "\n\n\tEnter new quantity: ";
        cin >> qualityCake;
        cout << "\n\n\tEnter new price per cake: ";
        cin >> price;
        total = qualityCake * price;
    }

    // Delete personal information
    void deletelist()
    {
        nameP = "";
        numberPhone = "";
        IDPeople = 0;
        day = 0;
        mm = 0;
        yy = 0;
        age = 0;
        cout << "\n\n\tPersonal information deleted successfully!";
    }

    // Delete cake boxing information
    void deleteboxing()
    {
        IDCake = 0;
        colorcake = "";
        timeOrder = "";
        timeGet = "";
        typeCake = "";
        sizeCake = '\0';
        qualityCake = 0;
        price = 0.0;
        total = 0.0;
        cout << "\n\n\tCake information deleted successfully!";
    }
    void feedback(){
       

    }
};

// Main program
int main()
{
    Shop shop[100];
    int listcount = 0, cakecount = 0;
    int choice, ch;

    do
    {
        cout << "\n\n\t===**********************************===";
        cout << "\n\n\t=========WELCOME TO MY SHOP CAKE=======";
        cout << "\n\n\t===1. WRITE YOUR INFORMATION TO LIST === ";
        cout << "\n\n\t===2. BOXING CAKE BIRTHDAYS ============ ";
        cout << "\n\n\t===3. SHOW LIST AND CAKE BOXING ========= ";
        cout << "\n\n\t===4. UPDATE LIST INFORMATION =======";
        cout << "\n\n\t===5. UPDATE  BOXING CAKE ======="; 
        cout << "\n\n\t===6. DELETE INFOEMATION ==============";
        cout << "\n\n\t===7. DELETE BOXING CAKE ==============";
        cout << "\n\n\t===8. EXIT.............!================";
        cout<<"\n\n\t====9. FEEDBACK TO MY SHOP===============";
        

        cout << "\n\n\t===**********************************===";

        cout << "\n\n\t PLEASE INPUT YOUR CHOICE HERE ++++++++++\n";

        cin >> choice;

        switch (choice)
        {
        case 1:
            // Add personal information
            shop[listcount].inputlist();
            listcount++;
            break;

        case 2:
            // Add cake boxing information
            shop[cakecount].inputboxing();
            cakecount++;
            break;

        case 3:
            // Show personal and cake boxing information
            for (int i = 0; i < listcount; i++)
            {
                shop[i].showlist();
                shop[i].showboxing();
            }

            break;

        case 4:
            // Update personal information
            if (listcount > 0)
            {
                shop[listcount - 1].updatelist(); // Update the last entry
            }
            else
            {
                cout << "\n\n\tNo personal information to update!";
            }
            break;

        case 5:
            // Update cake boxing information
            if (cakecount > 0)
            {
                shop[cakecount - 1].updateboxing(); // Update the last entry
            }
            else
            {
                cout << "\n\n\tNo cake information to update!";
            }
            break;

        case 6:
            // Delete personal information
            if (listcount > 0)
            {
                shop[listcount - 1].deletelist(); // Delete the last entry
                listcount--;
            }
            else
            {
                cout << "\n\n\tNo personal information to delete!";
            }
            break;

        case 7:
            // Delete cake boxing information
            if (cakecount > 0)
            {
                shop[cakecount - 1].deleteboxing(); // Delete the last entry
                cakecount--;
            }
            else
            {
                cout << "\n\n\tNo cake information to delete!";
            }
            break;

        case 8:
            // Exit the program
            cout << "\n\n\tThank you for using the Cake Shop system!";
            exit(0);
            break;
            case 9:
             cout << "\n\n\t==================================";
               cout << "\n\n\t PROVIDE FEEDBACK ON THE SYSTEM";
               cin.ignore(); // Clear input buffer before taking feedback
               cout << "\nEnter your feedback: ";
               getline(cin, textfeedback[listcount]); // Capture the feedback
                shop[listcount - 1].feedback();
           
            break;

        default:
            cout << "\n\n\tInvalid choice! Please try again.";
        }

        cout << "\n\n\tDo you want to continue? (1 for Yes / 0 for No): ";
        cin >> ch;
    } while (ch == 1);

    return 0;
}
