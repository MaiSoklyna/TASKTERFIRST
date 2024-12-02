// this functon use parameter to set attribute don't use array
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
 string textfeedback[200];
class List
{
private:
string nameP;
 string numberPhone;
 int IDPeople;
 int day,mm,yy;
 int age;

     //===============
public:
     void SetAttributeValueTolistI(int id, const string& N,int Age,int Day,int M,int Year,const string& NUMBERP ){
          IDPeople = id;
          nameP = N;
          age = Age;
          day = Day;
          mm = M;
          yy = Year;
          numberPhone = NUMBERP;

     }
     //input list people
     void inputlist(){

     }
     void showlist();
     void updatelist();
     void deletelist();
     void feedback();
     void writeToFile(ofstream &myfile) const{
          myfile << nameP<<endl;
          myfile<<IDPeople<<endl;
          myfile << age<<endl;
          myfile << day<<endl;
          myfile << mm<<endl;
          myfile << yy<<endl;
        
          myfile << numberPhone<<endl;
     }
     void readFromFile(ifstream &myfile){
         getline( myfile , nameP);
          myfile >> IDPeople;
          myfile >> age;
          myfile >> day;
          myfile >> mm;
          myfile >> yy;
          myfile.ignore();
          myfile >> numberPhone;
     }


};
void writeListIToFile(const string &filename,const List  listI[],int listcount){
     ofstream myfile("ListInformation.txt");
     if(!myfile){
          cout<<"ERROE OPEN FILE>>>>>>>";
          return ;
     }
     for(int i=0;i< listcount;i++)
     {
          listI[i].writeToFile(myfile);
          myfile<<endl;
     }
     myfile.close();
}
void readListFromFile(const string &filename,const List listI[],int listcount){
     ifstream myfile("ListInformation.txt");
     if(!myfile){
          cout<<"ERROE OPEN FILE>>>>>>>";
          return ;
     }
     listcount=0;
    while(myfile&& listcount<15){
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
int qualtyCake;
double price;
double total;





     //==============
public:
     void SetAttributeValueToCakeBoxing( int IDC,const string&colorc,const string&timeO,const string&timeG,const string&typsC,const char*size,int qualC,double Price,double Total){
          IDCake = IDC;
          colorcake = colorc;
          timeOrder = timeO;
          timeGet = timeG;
          typeCake = typsC;
          sizeCake = *size;
          qualtyCake = qualC;
          price = Price;
          total = Total;
          Total=Price*qualC;

     }
     //input list people
    void  inputboxing(){

    }
    void showboxing(){

    }
    void updateboxing(); /* code */
               
    void deleteboxing();
    
     void writecakeToFile(ofstream&myfile){

     }
     void readcakeboxingToFile();
};
void writecakeToFile(const string& &filename,const Cake cake[],int cakecount ){
     

}
void readcakeboxingToFile();
int main()
{
     List listI[100]; // list for inforamtion of people
     Cake cake[100];  // boxing cake nd make a new file is different from class list
     int listcount = 0;
     int cakecount = 0;
     int choice;
     int ch;
     // set the first value of list people information
     listI[0].SetAttributeValueTolistI(0,"LyLy",18,11,3,2006,"0889487788");
     cake[0].SetAttributeValueToCakeBoxing(0,"Pink","12:30 AM","6:35 PM","CHOCOLATE","M",2,15.00,30);

     // write list and cake  data to file
     writeListIToFile("ListInformation.txt", listI, listcount);

     for (int i = 0; i < 100; i++)
     {
          listI[i] = List();
     }
     writecakeToFile("CakeBoxingInformation.txt", cake, cakecount);
     for (int i = 0; i < 100; i++)
     {
          cake[i] = Cake();
     } 
     // read fruit data back fron=m file
     readListFromFile("ListInformation.txt", listI, listcount);
     for (int i = 0; i < listcount; i++)
     {
          listI[i] = List();
     } 
     readcakeboxingToFile("CakeBoxingInformation.txt", cake, cakecount);
     for (int i = 0; i < cakecount; i++)
     {
          cake[i] = Cake();
     } 

     do
     {
          menu:
          cout << "\n\n\t===**********************************===";
          cout << "\n\n\t=========WELCOME TO MY SHOPE CAKE=======";
          cout << "\n\n\t===1. WRITE YOUR INFORMATION TO LIST === ";
          cout << "\n\n\t===2. BOXING CAKE BIRTHDAYS ============ ";
          cout << "\n\n\t===3.SHOW LIST AND CAKE BOXING ========= ";
          cout << "\n\n\t===4.UPDATE LIST AND BOXING CAKE =======";
          cout << "\n\n\t===5.DELETE LIST AND BOXING CAKE =======";
          cout << "\n\n\t===6.FEEDBACK TO MY SHOP  ==============";
          cout << "\n\n\t===7. EXIT.............!================";

          cout << "\n\n\t===**********************************===";
          cout << "\n\n\t PLEASE INPUT YOUR CHOICE HERE ++++++++++";
          cin >> choice;
          switch (choice)
          {
          case 1 /* constant-expression */:
               /* code */ listI[100].inputlist();
               break;
          case 2:
               cake[100].inputboxing();
               break;
          case 3:
               do
               {
                    int ch=0;
                    cout << "\n\n\t ==================================";
                    cout << "\n\n\t ===THERE ARE HAVE TWO FUCNTION ===";
                    cout << "\n\n\t ===1. SHOW LIST INFORMATION=======";
                    cout << "\n\n\t ===2. SHOW BOXING CAKE  =========";
                    cout << "\n\n\t (((PLEASE SELECT YOU WANT HERE)))";
                    cin >> ch;
                    if (ch == 1)
                    {
                         cout << "\n\n\t==================++++++++++";
                         cout << "\n\n\t YOU WILL SEE LIST INFORMATION ";
                         listI[100].showlist();
                    }
                    else
                    {
                         cout << "\n\n\t==================++++++++++";
                         cout << "\n\n\t YOU WILL SEE BOXING CAKE INFORMATION ";
                         cake[100].showboxing();
                    }
               } while(ch!=10);
               break;
          case 4: 
          cout<<"\n\n\t==================================";
          cout<<"\n\n\t YOU GO TO UPDATE LIST AND BOXING CAKE";
          do
          {
               cout<<"\n\n\tWE HAVE TWO FUCNTION FOR U WANT ";
               cout<<"\n\n\n=====1.FOR LIST UPDATE===========";
               cout<<"\n\n\n=====2.FOR BOXING UPDATE===========";
               cout<<"\n\n\t PLEASE SELECT HERE >>>>>>>>>>";
               cin>> ch;
               if(ch=1){
                    cout<<"\n\n\t YOU WILL UPDATE LIST";
                    listI[100].updatelist();
               }
               else
               {
                   cout<<"\n\n\t YOU WILL UPDATE BOXING CAKE";
                   cake[100].updateboxing(); /* code */
               }
               
               /* code */
          } while (ch!=0);
          
          break;
          case 5:
           cout<<"\n\n\t==================================";
           cout<<"\n\n\t YOU GO TO DELTED LIST AND BOXING CAKE";
            do
          {
               cout<<"\n\n\tWE HAVE TWO FUCNTION FOR U WANT ";
               cout<<"\n\n\n=====1.FOR LIST DELETE===========";
               cout<<"\n\n\n=====2.FOR BOXING DELETE===========";
               cout<<"\n\n\t PLEASE SELECT HERE >>>>>>>>>>";
               cin>> ch;
               if(ch=1){
                    cout<<"\n\n\t YOU WILL DELETE LIST";
                    listI[100].deletelist();
               }
               else
               {
                   cout<<"\n\n\t YOU WILL DELETE BOXING CAKE";
                   cake[100].deleteboxing(); /* code */
               }
               
               /* code */
          } while (ch!=0);


          break;
          case 6:
          cout<<"\n\n\t==================================";
           cout<<"\n\n\t YOU CAN TEXT SOME ERROR ABOUT MY SYSTEM TO SOPVE AGAIN";
           getline(cin,textfeedback[200] );
           listI[100].feedback();

          break;
          case 7:
          cout<<"\n\n\t==================================";
           cout<<"\n\n\t YOU EIXT  MY SYSTEM TO LOCGIN AGAIN";
           exit(0);
           goto menu;



          default:
               cout << "\nplease choice again ((error system!!!!!!))";
          }

     } while (choice != 0);

     return 0;
}
