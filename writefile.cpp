#include <iostream>
#include <fstream>
using namespace std;
int main()
{
     fstream myfile;
     myfile.open("tester.txt", ios::out);
     if (myfile.is_open())
     {
          myfile << "Hello World!";
          myfile.close();
          cout << "File created successfully!";
     }
     system("cls");
}