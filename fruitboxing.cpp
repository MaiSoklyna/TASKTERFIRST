#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class fruite
{
private:
    string namefruit;
    float price;
    int quantity;
    float totalPrice;
    string timegetting;

public:
    // Function to print fruit attributes
    void printFruitAttribute() const
    {
        cout << "Name of Fruit: " << namefruit << endl;
        cout << "Price of Fruit: " << price << endl;
        cout << "Quantity of Fruit: " << quantity << endl;
        cout << "Total Price of Fruit: " << totalPrice << endl;
        cout << "Time Getting Fruit: " << timegetting << endl;
    } 

    // Function to set the fruit attributes
    void SetAttributesValue(int QUA, const string &N, const string &T, float P)
    {
        namefruit = N;
        price = P;
        quantity = QUA;
        totalPrice = price * quantity;
        timegetting = T;
    }

    // Function to save fruit data to file
    void writeToFile(ofstream &myfile) const
    {
        myfile << namefruit << endl;
        myfile << price << endl;
        myfile << quantity << endl;
        myfile << totalPrice << endl;
        myfile << timegetting << endl;
    }

    // Function to read fruit data from file
    void readFromFile(ifstream &myfile)
    {
        getline(myfile, namefruit);
        myfile >> price;
        myfile >> quantity;
        myfile >> totalPrice;
        myfile.ignore(); // Ignore the newline after totalPrice
        getline(myfile, timegetting);
    }
};

// Function to write fruits to a file
void writeFruitBoxingToFile(const string &filename, const fruite typeFruite[], int fruiteCount)
{
    ofstream myfile("BoxingFruit.txt");
    if (!myfile)
    {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    for (int i = 0; i < fruiteCount; i++)
    {
        typeFruite[i].writeToFile(myfile);
        myfile << endl; // Add a blank line to separate records
    }
    myfile.close();
}

// Function to read fruits from a file
void readFruitBoxingFromFile(const string &filename, fruite typeFruite[], int &fruiteCount)
{
    ifstream myfile("BoxingFruit.txt");
    if (!myfile)
    {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    fruiteCount = 0; // Reset the fruit count

    while (myfile && fruiteCount < 15)
    {
        typeFruite[fruiteCount].readFromFile(myfile);
        fruiteCount++;
        myfile.ignore(); // Ignore the blank line between records
    }

    myfile.close();
}

int main()
{
    fruite typeFruite[15]; // Array to store up to 15 fruits
    int fruiteCount = 0;

    // Set the fruit attributes
    typeFruite[0].SetAttributesValue(2, "Strawberry", "11:30 PM", 15.2);
    typeFruite[1].SetAttributesValue(3, "Apple", "12:00 PM", 5.8);
    typeFruite[2].SetAttributesValue(4, "Mango", "12:30 PM", 3.5);
    typeFruite[3].SetAttributesValue(5, "Grapes", "1:00 PM", 7.5);
    typeFruite[4].SetAttributesValue(6, "Banana", "1:30 PM", 2.5);
    typeFruite[5].SetAttributesValue(7, "Orange", "2:00 PM", 4.2);
    typeFruite[6].SetAttributesValue(8, "Pineapple", "2:30 PM", 6.8);
    typeFruite[7].SetAttributesValue(9, "Pear", "3:00 PM", 4.5);
    typeFruite[8].SetAttributesValue(10, "Blueberry", "3:30 PM", 15.2);
    typeFruite[9].SetAttributesValue(11, "Apple", "4:00 PM", 5.8);
    typeFruite[10].SetAttributesValue(12, "Mango", "4:30 PM", 3.5);
    typeFruite[11].SetAttributesValue(13, "Grapes", "5:00 PM", 7.5);
    typeFruite[12].SetAttributesValue(14, "Banana", "5:30 PM", 2.5);
    typeFruite[13].SetAttributesValue(15, "Orange", "6:00 PM", 4.2);
    typeFruite[14].SetAttributesValue(16, "Pineapple", "6:30 PM", 6.8);

    fruiteCount = 15; // We have set attributes for 15 fruits

    // Write fruit data to file
    writeFruitBoxingToFile("BoxingFruit.txt", typeFruite, fruiteCount);

    // Clear the fruit data
    for (int i = 0; i < 15; i++)
    {
        typeFruite[i] = fruite(); // Reset each object
    }

    // Read fruit data back from file
    readFruitBoxingFromFile("BoxingFruit.txt", typeFruite, fruiteCount);

    // Print the fruit data
    cout << "Fruits in Boxing Fruit:" << endl;
    for (int i = 0; i < fruiteCount; i++)
    {
        typeFruite[i].printFruitAttribute();
        cout << "-------------------" << endl;
    }

    return 0;
}
