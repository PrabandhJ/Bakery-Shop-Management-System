#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>


using namespace std;
//**********************
//function declare
//*********************
void insertt();
void display();
void serch();
void update();
void deletee();
void order();
void displayc();
void feedback();
void readfeedback();

//******************
//Stock class
//******************
class stock{
public:
    char iname[30];
    char iid[30];
    int iquantity;
    int iprice;

public:
    void input(){
    cout<<"\nEnter name of item: ";
    getchar();
    cin.getline(iname,30);
    cout<<"\nEnter item id: ";
    cin.getline(iid,30);
    cout<<"\nEnter Item price: ";
    cin>>iprice;
    cout<<"\nEnter item quantity: ";
    cin>>iquantity;
    }
    void show(){
    cout<<iid<<"\t"<<iname<<"\t"<<iprice<<"\t"<<iquantity<<endl;
    }
}s;
//class ends

//******************
//feedback class
//******************
class feedback{
public:
    char feedback[50];

public:
    void feed(){
    cout<<"Enter your Feedback here\n\n";
    getchar();
    cin.getline(feedback,50);
    }

}f;


//************************
//main function starts
//************************
int main(){
char username[20]="jainbakery";
char id[10];
char user[10];
int option,choice,pass,password=1234;

system("cls");
    COORD c;
    c.X = 40;
    c.Y = 16;

SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
cout<<"\n\t\t\t\t\t\t\t\t______________________\n";
cout<<"\n\t\t\t\t\t\t\t\t| JAIN BAKERY SHOP   | ";
cout<<"\n\t\t\t\t\t\t\t\t______________________";
cout<<"\n\n\t\t\t\t\t\t\t\tpress enter";
getch();
system("cls");
cout<<"\n\t\t\t\t\t\tLogin Page";
cout<<"\n\t\t\t\t\t\t_____________\n\n\n";

cout<<"\n\n\n\t\t\tWelcome to Jain Bakery Shop\n\n"<<endl;
cout<<"\n\t\t\tPress 1 if you are Costumer\n\t\t\tPress 2 if you are ADMIN\n";
cout<<"\t\t\t";
cin>>choice;
//****************************
//costumer functionalities
//****************************
if (choice == 1 ){
    system("cls");
    cout<<"\n\t\t\t\t\tWe will happy to serve you\n\n\n";
    do{
    system("cls");
    main:
    cout<<"\nHello Sir/Ma'am how may we help you ?? :\n\nEnter your choice\n\n";
    cout<<"1.Order \n";
    cout<<"2.Menu\n";
    cout<<"3.Other query\n";
    cout<<"4.Compliment or Suggestion\n";
    cout<<"5.Main menu\n";
    cout<<"0.Exit\n";

    cin>>option;
    switch(option){
    case 1:
        system("cls");
        order();
        break;
    case 2:
        system("cls");
        displayc();
        getch();
        break;
    case 3:
        system("cls");
        cout<<"\n\t\tFor your queries call on 1800-200-522\n";
        cout<<"\n\t\tYou can go to reception window\n";
        getch();
        break;
    case 4:
        int c;
        system("cls");
        cout<<"\n\t1. To complaint"<<endl;
        cout<<"\n\t2. For Suggestion"<<endl;
        cout<<"\n\t";
        cin>>c;
        feedback();
        if(c==1)
            cout<<"\n\t\tWe have received your complaint\n\t\tWe are assuring that the mistake will not be repeated again";
        else
            cout<<"\n\t\tThanks for suggestion we will work accordingly";
            getch();
        break;
    case 5:
        system("cls");
        goto main;
        break;
    case 0:
        system("cls");
        cout<<"EXIT";
        exit(0);
        break;
    default:
        cout<<"\nPress valid key[1/2/3/4/5/0]";
        break;

    }//switch ends
    }while(option!=0);

}
//***************************
//Admin functionalaties
//***************************
else if(choice==2){
    system("cls");
    cout<<"\n\t\t\tAdmin login page \n\n";
    cout<<"\n\tEnter Username: ";
    getchar();
    cin.getline(user,20);
    cout<<"\n\tEnter password: ";
    cin>>pass;
    getch();
    if(password==pass)
{

system("cls");
cout<<"\t\t\tADMIN ";
cout<<"\n\nChoose the option: "<<endl;
do{
    system("cls");
    cout<<"\t\t\t\tAdmin Page";
    cout<<"\n1.Insert\n2.Display\n3.Search\n4.Update\n5.Delete\n6.Read Feedback\n0.Exit\n";
    cin>>option;
    switch(option){
case 1:
    system("cls");
    insertt();
    getch();
    break;
case 2:
    system("cls");
    display();
    getch();
    break;
case 3:
    system("cls");
    serch();
    getch();
    break;
case 4:
    system("cls");
    display();
    update();
    getch();
    break;
case 5:
    system("cls");
    display();
    deletee();
    getch();
    break;
case 6:
    readfeedback();
    getch();
    break;

case 0:
    exit(1);
    break;
default:
    cout<<"\n Enter valid option";
    }//switch ends

}while(option!=0);//do while ends
}//login if ends
else
{
    cout<<"incorect password";
}
}//admin if ends

return 0;
}

//*********************
//insert function start
////********************
void insertt(){
fstream fp;

int ch=1;
cout<<"\t\tDo the stock entry\n\n"<<endl;
fp.open("stock.dat",ios::binary | ios::app);
if(!fp){
    cout<<"Can't open the file";
    return;
    }
while(ch){

    s.input();
    fp.write((char *)&s,sizeof(s));
    //cin.ignore();
    cout<<"\nPress 1 to enter more data else Press 0"<<endl;
    cin>>ch;

}
fp.close();
}
////**********************
//display function starts
//*************************
void display(){
fstream fp;

cout<<"\t\tItem in stock\n\n"<<endl;
fp.open("stock.dat",ios::binary | ios::in);
if(!fp){
    cout<<"Can't open the file";
    return;
    }
cout<<"\t\tId \t Name\t Price \t Quantity "<<endl;

cout<<"\t\t________________________________\n\n"<<endl;

while(fp.read((char *)&s,sizeof(s))){
cout<<"\t\t"<<s.iid<<"\t"<<s.iname<<"\t"<<s.iprice<<"\t"<<s.iquantity<<endl;
}
cout<<"\t\t________________________________"<<endl;

fp.close();
}

//************************
//search function starts
//************************
void serch(){
fstream fp;
fp.open("stock.dat",ios::binary | ios::in);
if(!fp){
    cout<<"Can't open the file";
    return;
    }
char name[30],code[30];
int cho,flag=0,srno;

cout<<"Press 1 to search using ITEM NAME \nPress 2 to search using ITEM CODE\n"<<endl;
cin>>cho;
if(cho==1){
   cout<<"enter item name :";
   getchar();
cin.getline(name,30);
}
else if (cho == 2 ){
   cout<<"enter item id :";
    getchar();
cin.getline(code,30);

}
else {
    cout<<"Press Valid key : ";
    exit(0);
}
    while(fp.read((char *)&s,sizeof(s)))
    {


        if((strcmp(s.iname,name)==0)||(strcmp(s.iid,code)==0))
        {
                flag=1;
    cout<<"\t\tId \t Name\t Price \t Quantity "<<endl;
    cout<<"\t\t_______________________________"<<endl;
    cout<<"\t\t"<<s.iid<<"\t"<<s.iname<<"\t"<<s.iprice<<"\t"<<s.iquantity<<endl;
    cout<<"\t\t_______________________________"<<endl;
    }
  }

if(flag!=0){
    cout<<"\nSearch successful: ";
}
else{
    cout<<"Item is not in stock";
}

fp.close();
}
//************************
//update function starts
//************************
void update(){
char name[30],code[30];
int cho,countt=0,flag=0,up=0;
fstream fp;
fp.open("stock.dat",ios::binary | ios::in | ios::out);
fp.seekg(0);

if(!fp){
    cout<<"Can't open the file";
    exit(0);
    }

cout<<"Press 1 to search using ITEM NAME \nPress 2 to search using ITEM CODE\n"<<endl;
cin>>cho;

if(cho==1){
   cout<<"\nEnter item name :";
   getchar();
cin.getline(name,30);
}
else if (cho == 2 ){
cout<<"\nEnter item id :";
getchar();
cin.getline(code,30);
}
else {
    cout<<"Press Valid key : ";
    exit(0);
}
   while(fp.read((char *)&s,sizeof(s)))
    {
     if((strcmp(s.iname,name)==0)||(strcmp(s.iid,code)==0))
    {
    flag=1;
    cout<<"\t\tId \t Name\t Price \t Quantity "<<endl;
    cout<<"\t\t_______________________________"<<endl;
    cout<<"\t\t"<<s.iid<<"\t"<<s.iname<<"\t"<<s.iprice<<"\t"<<s.iquantity<<endl;
    cout<<"\t\t_______________________________"<<endl;
    cout<<"Enter Updated price and quantity of the item \n"<<endl;
    cout<<"Enter the quantity: ";
    cin>>s.iquantity;
    cout<<"\nEnter the updated price of"<<s.iname<<" :";
    cin>>s.iprice;
    fp.seekp(-sizeof(s),ios::cur);
    fp.write((char *)&s,sizeof(s));

    }
   }//while ends
    if(flag == 0){
        cout<<"No Such Item is found in Stock ";
    return;
    }
}

//************************
//delete function start
//************************
void deletee(){
    char id[30];
    fstream fb("stock.dat",ios::binary | ios::in);
    fstream fb1("temp.dat",ios::binary | ios::out);
    fb.seekg(0);
    if(!fb || ! fb1){
        cout<<"Error in opening the file"<<endl;
        return;
    }
    else{
        cout<<"Enter item Id to delete: ";
            getchar();
            cin.getline(id,30);
        while(fb.read((char *)&s,sizeof(s))){
            if(strcmp(s.iid,id)!=0){
             fb1.write((char *)&s,sizeof(s));
            }
        }
        fb.close();
        fb1.close();
    }
    remove("stock.dat");
    rename("temp.dat","stock.dat");

}
//***********************************
//Costumer functionalities starts
//************************
//Order function
//************************
//************************************
void order(){
fstream fp;
int flag=0;
int total=0,quantity,i=1;
char pay,idd[10];
fp.open("stock.dat",ios::binary | ios::in);
if(!fp){
    cout<<"Can't open the file";
    return;
    }

label1:
displayc();
getchar();

    cout<<"Enter the order Id from the list: ";
        cin.getline(idd,10);
    fp.seekg(0,ios::beg);
    while(fp.read((char *)&s,sizeof(s)))
    {

    if((strcmp(s.iid,idd)==0))
    {
    flag=1;
    cout<<"\t\tId \t Name\t Price \t "<<endl;
    cout<<"\t\t_______________________________"<<endl;
    cout<<"\t\t"<<s.iid<<"\t"<<s.iname<<"\t"<<s.iprice<<"\t"<<endl;
    cout<<"\t\t_______________________________"<<endl;
    cout<<"How many "<<s.iname <<" you want to order";
    cin>>quantity;
    total=total+(s.iprice*quantity);
    }
}
if(flag!=0){
    cout<<"\nWe've received your order: "<<endl;
    cout<<"Your order amount is "<<total<<"\nPress [y/Y] to pay the bill: ";
    cin>>pay;
    if(pay=='y'||pay=='Y'){
        cout<<"\nYour order is forwarded wait for 10 minutes:  "<<endl;
       getch();
    }
    else{
        cout<<"Something went wrong please try again: "<<endl;
        getch();
        return;
    }
}
else{
    cout<<"\n\nSorry we don't have this item: ";
    cout<<"\nyou can order another thing: ";
    cout<<"\nPress 0 to get Main Menu or 1 to Order other item\n";
    cin>>i;
    if(i==0) return;
    else goto label1;
}
fp.close();
getch();
}

//************************
//Display C function
//************************
void displayc(){
    fstream fp;

cout<<"\t\tItem in stock\n\n"<<endl;
fp.open("stock.dat",ios::binary | ios::in);
if(!fp){
    cout<<"Can't open the file";
    return;
    }
cout<<"\t\tId \t Name\t Price \t "<<endl;

cout<<"\t\t________________________________\n\n"<<endl;

while(fp.read((char *)&s,sizeof(s))){
cout<<"\t\t"<<s.iid<<"\t"<<s.iname<<"\t"<<s.iprice<<"\t"<<endl;
}
cout<<"\t\t________________________________"<<endl;
fp.close();
}

//************************
//feedback function
//************************
void feedback(){
fstream ffp;
ffp.open("feedback.dat",ios::binary | ios::app);
if(!ffp){
    cout<<"Can't open the file";
    return;
    }
    f.feed();
    ffp.write((char *)&f,sizeof(f));
cin.ignore();
ffp.close();
getch();
}

//************************
//read feedback
//************************
void readfeedback(){
int go;
fstream fp;

fp.open("feedback.dat",ios::binary | ios::in);
if(!fp){
    cout<<"Can't open the file";
    return;
    }
do{
fp.read((char *)&f,sizeof(f));
cout<<"____________________________________________________________________\n"<<endl;
cout<<f.feedback;
cout<<"\n____________________________________________________________________"<<endl;
cout<<"1.For next feedback else 0\n";
cin>>go;
}while(go!=0);
fp.close();
}
