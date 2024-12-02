#include <fstream>
#include <string>
#include <iostream>
#include <iomanip> // Include this for put_time if available
#include <ctime>
#include <sstream>
using namespace std;

class PersonData {
public:
    int day[30], month[30], year[30]; // Store people's birthdays
    int PersonID[30];
    string phoneNumber[30];
    string personName[30];

    void person_info();
    void upcomingbd();
    void EditInfo();
    void searchList();
    void showList();
    void deleteList();
    void readFromFile();
    void writeToFile();

private:
    string formatDate(const tm* date);
};

// Function to format date without put_time
string PersonData::formatDate(const tm* date) {
    ostringstream oss;
    oss << (date->tm_mday < 10 ? "0" : "") << date->tm_mday << "-"
        << ((date->tm_mon + 1) < 10 ? "0" : "") << (date->tm_mon + 1) << "-"
        << (date->tm_year + 1900);
    return oss.str();
}

//===================== File Handling ===================
void PersonData::readFromFile() {
    ifstream file("birthDateAndPeople_Info.txt");
    int i = 0;
    while (file >> PersonID[i] >> personName[i] >> day[i] >> month[i] >> year[i] >> phoneNumber[i]) {
        i++;
    }
    file.close();
    cout << "Data loaded from file successfully!" << endl;
}

void PersonData::writeToFile() {
    ofstream file("birthDateAndPeople_Info.txt");
    for (int i = 0; i < 30; i++) {
        if (!personName[i].empty()) {
            file << PersonID[i] << " " << personName[i] << " " << day[i] << " " << month[i] << " " << year[i]
                 << " " << phoneNumber[i] << "\n";
        }
    }
    file.close();
    cout << "Data saved to file successfully!" << endl;
}

//===================== Adding New Person ===================
void PersonData::person_info() {
    int i = 0;
    while (i < 30 && !personName[i].empty()) {
        i++;
    }
    if (i < 30) {
        cout << "Enter your info:\nID: ";
        cin >> PersonID[i];
        cout << "Name: ";
        cin >> personName[i];
        cout << "Birthday (day month year): ";
        cin >> day[i] >> month[i] >> year[i];
        cout << "Phone Number: ";
        cin >> phoneNumber[i];
        cout << "Data added successfully!\n";
    } else {
        cout << "Sorry, we are fully booked.\n";
    }
    writeToFile();
}

//===================== Editing Person Info ===================
void PersonData::EditInfo() {
    cout << "Enter name you want to edit: ";
    string SearchPersonName;
    cin >> SearchPersonName;

    for (int i = 0; i < 30; i++) {
        if (SearchPersonName == personName[i]) {
            cout << "Update your info (ID, Name, Birthday (day month year), Phone Number): ";
            cin >> PersonID[i] >> personName[i] >> day[i] >> month[i] >> year[i] >> phoneNumber[i];
            writeToFile();
            cout << "Info updated successfully!\n";
            return;
        }
    }
    cout << "Person not found.\n";
}

//===================== Searching Person Info ===================
void PersonData::searchList() {
    cout << "Enter name to search: ";
    string SearchPersonName;
    cin >> SearchPersonName;

    for (int i = 0; i < 30; i++) {
        if (SearchPersonName == personName[i]) {
            cout << "ID: " << PersonID[i] << "\nName: " << personName[i]
                 << "\nBirthday: " << day[i] << "/" << month[i] << "/" << year[i]
                 << "\nPhone Number: " << phoneNumber[i] << "\n\n";
            return;
        }
    }
    cout << "Person not found.\n";
}

//===================== Showing All Persons ===================
void PersonData::showList() {
    cout << "Birthdays and Information:\n-------------------------\n";
    for (int i = 0; i < 30; i++) {
        if (!personName[i].empty() && PersonID[i] != 0 && day[i] != 0 && month[i] != 0 && year[i] != 0) {
            cout << "ID: " << PersonID[i] << "\nName: " << personName[i]
                 << "\nBirthday: " << day[i] << "/" << month[i] << "/" << year[i]
                 << "\nPhone Number: " << phoneNumber[i] << "\n\n";
        }
    }
}

//===================== Deleting a Person ===================
void PersonData::deleteList() {
    cout << "Enter name to delete: ";
    string DeletePersoninfo;
    cin >> DeletePersoninfo;

    for (int i = 0; i < 30; i++) {
        if (personName[i] == DeletePersoninfo) {
            PersonID[i] = 0;
            personName[i].clear();
            day[i] = month[i] = year[i] = 0;
            phoneNumber[i].clear();
            writeToFile();
            cout << "Record deleted successfully.\n";
            return;
        }
    }
    cout << "Person not found.\n";
}

//===================== Upcoming Birthdays ===================
void PersonData::upcomingbd() {
    time_t t = time(NULL);
    tm* localTime = localtime(&t);

    int currentDay = localTime->tm_mday;
    int currentMonth = localTime->tm_mon + 1;
    int currentYear = localTime->tm_year + 1900;

    cout << "Current Date: " << formatDate(localTime) << endl;

    localTime->tm_mon += 1;
    mktime(localTime);

    cout << "Date in a Month: " << formatDate(localTime) << endl;
    cout << "Upcoming birthdays:\n";

    for (int i = 0; i < 30; i++) {
        if (!personName[i].empty() && 
           ((month[i] == currentMonth && day[i] >= currentDay) || 
           (month[i] == localTime->tm_mon + 1 && day[i] <= localTime->tm_mday))) {
            cout << "ID: " << PersonID[i] << "\nName: " << personName[i]
                 << "\nBirthday: " << day[i] << "/" << month[i] << "/" << year[i]
                 << "\nPhone Number: " << phoneNumber[i]
                 << "\n" << personName[i] << " will turn " << (currentYear - year[i] + 1) << " years old.\n\n";
        }
    }
}

//===================== Main Function ===================
int main() {
    PersonData list;
    list.readFromFile();
    int choice;

    do { 
         cout << "\t\t\t\t\t______________________WELCOME_______________________" << endl
             << "\t\t\t\t\t|                                                   |" << endl
             << "\t\t\t\t\t|   ---------> 1.input personal info   <---------   |" << endl
             << "\t\t\t\t\t|   ---------> 2.View all birthday list<---------   |" << endl
             << "\t\t\t\t\t|   ---------> 3.Search info           <---------   |" << endl
             << "\t\t\t\t\t|   ---------> 4.up coming birthday    <---------   |" << endl
             << "\t\t\t\t\t|   ---------> 5.Edit your info        <---------   |" << endl
             << "\t\t\t\t\t|   ---------> 6.delete                <---------   |" << endl
             << "\t\t\t\t\t|   ---------> 7.Exit                  <---------   |" << endl
             << "\t\t\t\t\t|__________________________________________________________|" << endl;
        cout << "\t\tEnter option :";
        cin >> choice;

        switch (choice) {
            case 1: list.person_info(); break;
            case 2: list.showList(); break;
            case 3: list.searchList(); break;
            case 4: list.upcomingbd(); break;
            case 5: list.EditInfo(); break;
            case 6: list.deleteList(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Please enter a valid option.\n";
        }
    } while (choice != 7);

    return 0;
}

