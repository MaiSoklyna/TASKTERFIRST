#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

class account_query
{
private:
    char account_number[20];
    char firstName[10];
    char lastName[10];
    double total_Balance;
    

public:
    void read_data();
    void show_data();
    void write_rec();
    void read_rec();
    void search_rec();
    void edit_rec();
    void delete_rec();
    void update_balance(bool isDeposit); // Function to add or subtract balance
};

void account_query::read_data()
{
    cout << "Enter Account Number: ";
    cin >> account_number;
    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Last Name: ";
    cin >> lastName;
    cout << "Enter Initial Balance: ";
    cin >> total_Balance;
    cout << endl;
}

void account_query::show_data()
{
    cout << "\n---------------------------------------" << endl;
    cout << "Account Number: " << account_number << endl;
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Current Balance: Rs. " << fixed << setprecision(2) << total_Balance << endl;
    cout << "---------------------------------------" << endl;
}

void account_query::write_rec()
{
    ofstream outfile;
    outfile.open("record.bank", ios::binary | ios::app);
    if (!outfile)
    {
        cout << "Error opening file!" << endl;
        return;
    }
    read_data();
    outfile.write(reinterpret_cast<char *>(this), sizeof(*this));
    outfile.close();
    cout << "Record added successfully." << endl;
}

void account_query::read_rec()
{
    ifstream infile;
    infile.open("record.bank", ios::binary);
    if (!infile)
    {
        cout << "Error opening file!" << endl;
        return;
    }
    cout << "Displaying all records from the file:\n";
    while (infile.read(reinterpret_cast<char *>(this), sizeof(*this)))
    {
        show_data();
    }
    infile.close();
}

void account_query::search_rec()
{
    ifstream infile;
    infile.open("record.bank", ios::binary);
    if (!infile)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    infile.seekg(0, ios::end);
    int count = infile.tellg() / sizeof(*this);
    infile.seekg(0);

    int n;
    cout << "There are " << count << " records in the file." << endl;
    cout << "Enter record number to search: ";
    cin >> n;

    if (n < 1 || n > count)
    {
        cout << "Invalid record number!" << endl;
        infile.close();
        return;
    }

    infile.seekg((n - 1) * sizeof(*this));
    infile.read(reinterpret_cast<char *>(this), sizeof(*this));
    show_data();
    infile.close();
}

void account_query::edit_rec()
{
    fstream iofile;
    iofile.open("record.bank", ios::in | ios::out | ios::binary);
    if (!iofile)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    iofile.seekg(0, ios::end);
    int count = iofile.tellg() / sizeof(*this);
    iofile.seekg(0);

    int n;
    cout << "There are " << count << " records in the file." << endl;
    cout << "Enter record number to edit: ";
    cin >> n;

    if (n < 1 || n > count)
    {
        cout << "Invalid record number!" << endl;
        iofile.close();
        return;
    }

    iofile.seekg((n - 1) * sizeof(*this));
    iofile.read(reinterpret_cast<char *>(this), sizeof(*this));
    cout << "Record " << n << " has the following data:" << endl;
    show_data();

    cout << "\nEnter new data: " << endl;
    read_data();

    iofile.seekp((n - 1) * sizeof(*this));
    iofile.write(reinterpret_cast<char *>(this), sizeof(*this));
    iofile.close();
    cout << "Record updated successfully." << endl;
}

void account_query::delete_rec()
{
    ifstream infile;
    infile.open("record.bank", ios::binary);
    if (!infile)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    infile.seekg(0, ios::end);
    int count = infile.tellg() / sizeof(*this);
    infile.seekg(0);

    int n;
    cout << "There are " << count << " records in the file." << endl;
    cout << "Enter record number to delete: ";
    cin >> n;

    if (n < 1 || n > count)
    {
        cout << "Invalid record number!" << endl;
        infile.close();
        return;
    }

    ofstream tmpfile;
    tmpfile.open("tmpfile.bank", ios::out | ios::binary);

    infile.seekg(0);
    for (int i = 0; i < count; i++)
    {
        infile.read(reinterpret_cast<char *>(this), sizeof(*this));
        if (i == (n - 1))
            continue;
        tmpfile.write(reinterpret_cast<char *>(this), sizeof(*this));
    }

    infile.close();
    tmpfile.close();

    remove("record.bank");
    rename("tmpfile.bank", "record.bank");

    cout << "Record deleted successfully." << endl;
}

// Function to update balance (deposit or withdraw)
void account_query::update_balance(bool isDeposit)
{
    double amount;
    if (isDeposit)
    {
        cout << "Enter amount to deposit: ";
        cin >> amount;
        total_Balance += amount;
        cout << "Amount deposited successfully. New balance: Rs. " << total_Balance << endl;
    }
    else
    {
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount > total_Balance)
        {
            cout << "Insufficient balance!" << endl;
        }
        else
        {
            total_Balance -= amount;
            cout << "Amount withdrawn successfully. New balance: Rs. " << total_Balance << endl;
        }
    }
}

int main()
{
    account_query A;
    int choice;
    cout << "*****Account Information System******" << endl;

    while (true)
    {
        cout << "\nSelect an option below:";
        cout << "\n1 ==> Add record to file" << endl;
        cout << "2 ==> Show records from file" << endl;
        cout << "3 ==> Search record from file" << endl;
        cout << "4 ==> Update record" << endl;
        cout << "5 ==> Delete record" << endl;
        cout << "6 ==> Deposit to account" << endl;
        cout << "7 ==> Withdraw from account" << endl;
        cout << "8 ==> Quit" << endl;
        cout << "Please input your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            A.write_rec();
            break;
        case 2:
            A.read_rec();
            break;
        case 3:
            A.search_rec();
            break;
        case 4:
            A.edit_rec();
            break;
        case 5:
            A.delete_rec();
            break;
        case 6:
            A.search_rec();
            A.update_balance(true);  // Deposit
            break;
        case 7:
            A.search_rec();
            A.update_balance(false); // Withdraw
            break;
        case 8:
            exit(0);
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}

