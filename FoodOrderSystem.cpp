/*INTRODUCTION
Food Order System is a platform which will help restaurant to optimize and control over their restaurants. For the waiters, it is making life easier because they don’t have to go to the kitchen and give the orders to chef easily. For management point of view, the manager will be able to control the restaurant by having all the records of each orders.

The system helps the restaurants to do all functionalities accurately and in a faster way. It reduces the manual work and improves the efficiency of restaurant. It helps to maintain the stock and cash flow and there are many functionalities like.
To store records.
Control orders and services.
Billings.
Control multiple neighborhood restaurant.
Easy communication between customers and restaurant staff
Providing a secure platform  

The main goal is to maintain the restaurant’s functions in an effective and accurate manner and also it is reducing the use of manual entries. The system helps to maintain day to day records. It keeps a proper record of the database.


Objective of this Project
The main objective of the Project on Food Ordering System is to manage the details of Food, Item Category, Shopping Cart, Customer and Order. The project is totally built at administrative end and thus only the administrator is guaranteed the access.

The objectives of developing Food Ordering System are: 
To computerize the food ordering system process. 
To display details of sales history. 
To calculate price of order.


Language and Backend
The language used to code this is OOPS with C++. Files has been implemented to store data of customers.

CLASS DATA MEMBERS AND MEMBER FUNCTIONS*/

#include<iostream>
#include<string.h>		// used for employee and customer names 
#include<fstream>		// used to implement concept of files 
#include<conio.h>		// for system clear and other inbuilt functions 
#include<ctime>		// to get date and time for food order
#include<windows.h>		// used for declaring Sleep function
#include<iomanip>		// for set width function
using namespace std;
fstream fil; 			// file global declaration || fstream fil as global
int xD=0,j=1;			// flag variables used at certain instances || global variables
char l=186, d=205, tl=201, tr=187, bl=200, br=188, x=204, y=185, s=196;		// ascii characters
class foodorder
{
	private:
		// adminsec variables
		int i, id, yj;
		char name[30],place[20], dob[15];
		char department[50], position[50];
		double salary;
		
		// customersec variables
		char ch1[50];
		float price;
		int k, total, qty[10], ch, tbill, result, ono;
		int bill[10], bil[10], bilor[10];
		string item[10], itemor[10];
		char pno[20], modpmt[10], dtime[50];

	public:
	// MAIN SECTION FUNCTION
	void mainsec();
	
		// ADMIN SECTION
		void adminsec();
			void add_record(); 		// add employee record *using concept of files
			void view_record(); 	// view employee record *using concept of files
			void search_record(); 	// search employee record *using concept of files
			void delete_record(); 	// delete employee record *using concept of files
			void order_record();	// view customer orders *using concept of files
			

		// CUSTOMER SECTION
		void customersec();		// main customer section menu		
		void food_orderinp(); 		// displays food menu || accepts food order	
		void food_order();		// passes information on order, customer details and payment to file
		void search_order();		// searches a specific order
		void getorderid();		// auto generates order id
			void foodinfodetails(); // accepts customer details and payment information
			void details(); 		// customer details *storing data using concept of files
	
		// UTILITY FUNCTIONS
		int getempid();				// gets emplpoyee ID and checks if it already exists
		int getempdata();			// gets the remaining employee data to add
		void adminlogin();			// admin authentication || password required
		void loading();				// load animation in the initial screen
		void delay();				// delay function
		void aboutus(); 			// project development credits 
		void exitprogram();			// exit oad animation to come out of the program	
		void empheader();			// header for displaying all employee records
		void showempdetails();		// displays all employee details
		void custheader();			// header for customer
		void custorderdetails();		// displays customer information	
};
foodorder f; 		// global object declaration for file handling

//LOADING SCREEN 
//void foodorder::loading()
//{
//	system("Color F0");
//	char a = 176 , b = 219;
//    	cout<<"\n\n\n\n\n\n\n\n\n\n"<<endl;
//	cout<<"\t\t\t\t\t\t\t\t\t\t\t";
//    	cout<<"Loading...\n\n";
//   	cout<<"\t\t\t\t\t\t\t\t\t\t\t";    
//   	 for (int i=0; i<30; i++)
//   	 cout<<(char)a;
//   	 cout<<"\r";
//   	 cout<<"\t\t\t\t\t\t\t\t\t\t\t";  
//   	 for (int i=0; i<30; i++) 
//	{
//		cout<<(char)b;
//       		Sleep(60);
//   	}
//	mainsec();
//}





//MAIN SECTION
void foodorder::mainsec() // aligned and tested
{
	system("Color F0");
	char wel[100]="WELCOME TO OUR FOOD ORDERING SYSTEM";
	system("cls");
	cout<<"\n\n\n\n\n\n\n"<<endl;
	cout<<"\t\t\t\t\t\t\t\t "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t";
	for(int j=0;j<50;j++)
	{
		Sleep(30);
		cout<<wel[j];
	}
	cout<<"\n\t\t\t\t\t\t\t\t "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"\n\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t    1. Administrator Section "<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t    2. Customer Section "<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t    3. About Us"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t    4. Exit Program"<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t\t "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"\n\n";
	cout<<"\t\t\t\t\t\t\t\t\t Enter your choice by pressing the option number from the list:\t";
	switch(getch())
	{
		case '1': adminlogin();
		break;
		case '2': customersec();
		break;
		case '3': aboutus();
		break;
		case '4': exitprogram();
		break;	
		default:
			system("Color 0C");
			cout<<"\n\n\t\t\t\t\t\t\t\t\t Wrong input! Please re-enter the correct option in 3 seconds..";
			Sleep(3000);
			system("Color 07");
			mainsec();
	}
}


//ADMIN LOGIN
void foodorder::adminlogin() // aligned and tested
{
	system("Color 07");
	int i=0;
	char ch, pass[10];
	char password[30]="FOS"; // password to login into admin section
	system("cls");
	cout<<"\n\n\n\n\n\n\n"<<endl;
	cout<<"\t\t\t\t\t\t\t\t "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t ADMIN AUTHENTICATION REQUIRED\n";
	cout<<"\t\t\t\t\t\t\t\t "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<endl;
	cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t    ENTER ADMIN PASSWORD: ";
	while(ch!=13)
	{
		ch=getch();
		if(ch!=13 && ch!=8)
		{
			putch('*');
			pass[i]=ch;
			i++;
		}
	}
	pass[i]='\0';
	if(strcmp(pass,password)==0)
	{
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t      ACCESS GRANTED! LOGGING YOU IN NOW... \n\n";
		for (i=0;i<10;i++)
		{
			if(i%3==0)
			{
				system("Color 27");
				Sleep(180);
			}
			else
			{
				system("Color 70");
				Sleep(180);	
			}
		}
		system("Color 07");
		adminsec();
	}
	else
	{
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t     INCORRECT PASSWORD... PLEASE TRY AGAIN!";
		for (i=0;i<10;i++)
		{
			if(i%3==0)
			{
				system("Color 47");
				Sleep(180);
			}
			else
			{
				system("Color 74");
				Sleep(180);	
			}
		}
		adminlogin();
	}
}


//ADMIN SECTION
void foodorder::adminsec() // aligned and tested
{
	fil.close();
	system("Color 07");
	system("cls");
	cout<<"\n\n\n\n\n\n\n"<<endl;
	cout<<"\t\t\t\t\t\t\t\t "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\t ADMINISTRATION SECTION\n";
	cout<<"\t\t\t\t\t\t\t\t "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"\n\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t  1. Add New Employee Record"<<endl;          
	cout<<"\t\t\t\t\t\t\t\t\t\t\t  2. View Employee Record"<<endl;          
	cout<<"\t\t\t\t\t\t\t\t\t\t\t  3. Search Employee Record"<<endl;          
	cout<<"\t\t\t\t\t\t\t\t\t\t\t  4. Delete Employee Records"<<endl;                 
	cout<<"\t\t\t\t\t\t\t\t\t\t\t  5. Back To Main Menu"<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t\t "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"\n\n";             
	cout<<"\t\t\t\t\t\t\t\t\t Enter your choice by pressing the option number from the list:\t";
	switch(getch())
	{	
		case '1': add_record();	
		break;
		case '2': view_record();
		break;
		case '3': search_record();
		break;
		case '4': delete_record();
		break;
		case '5':
			cout<<"\n\n\t\t\t\t\t\t\t\t\t\t Taking you back to Main Section, please wait...";
			Sleep(2000);
			system("cls");
			mainsec();
			break;
		default:
			system("Color 0C");
			cout<<"\n\n\t\t\t\t\t\t\t\t\t Wrong input! Please re-enter the correct option in 3 seconds..";
			Sleep(3000);
			system("Color 07");
			adminsec();
	}
}


//ADD RECORD
void foodorder::add_record() // aligned and tested
{
	char ch;
	system("cls");
	f.getempdata();
	fil.open("ADMINRECORD.txt",ios::app | ios::binary);
	fil.write((char*)&f, sizeof(f)); 
	fil.close();
	cout<<"\n\t  The Record Is Successfully Saved !!\n\n";
	cout<<"\t  Do you want to save another record? (Y / N): \t";
	ch=getch();
	ch=toupper(ch);
	switch(ch)
	{
		case 'Y':
			cout<<"\n\t  Please enter another record in 2 seconds...";
			Sleep(1800);
			add_record();
			break;
		case 'N':
			cout<<"\n\t  Taking you to admin section, please wait...";
			Sleep(1500);
			adminsec();
			break;
		default:
			cout<<"\n\t  Incorrect input, please try again";
			Sleep(1800);
			adminsec();
	}
}

//VIEW RECORD
void foodorder::view_record() // aligned and tested
{
	system("cls");
	cout<<"\n\n";
	cout<<"\t\t\t\t\t\t\t    "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t   ALL EMPLOYEE DETAILS \n";
	cout<<"\t\t\t\t\t\t\t    "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<"\n\n";
   	f.empheader();
	fil.open("ADMINRECORD.txt", ios::in | ios::binary);
	if(!fil)
	{
		cout<<"\n\t  File not Found or No record exists";
		fil.close();
		Sleep(1500);
		cout<<"\n\n\t  Press any key to return to Admin Section";	
		getch();	
		f.adminsec();
	}
	else
	{
		while(!fil.eof())
		{
			fil.read((char*)&f, sizeof(f));
			if(fil.eof())
			break;
			f.showempdetails();
			cout<<"\n";
		}
	}
	fil.close();
	if(xD==0)
	{
		cout<<"\n\n\t  Press any key to return to Admin Section...";
    	getch();
    	adminsec();
	}
}


//SEARCH RECORD
void foodorder::search_record() // aligned and tested
{
	char empname[30], namefound=0;
	int idfound=0, code,count=0;
	system("cls");
	cout<<"\n\n";
	cout<<"\t  "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<endl;
	cout<<"\t\t\t SEARCH EMPLOYEE DETAILS \n";
	cout<<"\t  "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<"\n\n";
	cout<<"\t  Press 1 to Search by EMPLOYEE ID"<<endl;
	cout<<"\t  Press 2 to Search by EMPLOYEE NAME"<<endl;
	cout<<"\t  Enter your choice: \t";
	switch(getch())
	{
		case '1':
		{
			cout<<"\n\n\t  Enter the EMPLOYEE ID to be Searched: ";
			cin>>code;
			cout<<"\n\t  Searching for Employee "<<code<<".\n\t  Please wait.... \n\n";
			Sleep(1500);
			fil.open("ADMINRECORD.txt", ios::binary | ios::in);
			if(!fil)
			{
				cout<<"\n\t  File not Found or No record exists";
				fil.close();
				Sleep(800);
				cout<<"\n\t  Press any key to return to Admin Section\t";
				getch();
				f.adminsec();
    		}
    		while(fil)
			{
    			if(fil.read((char*)&f,sizeof(f)))
				{
        			if(f.id==code)
					{
            			cout<<"\n\t\t\t\t\t\t\t\t\t\t   RECORD FOUND\n";
            			f.empheader();
            			f.showempdetails();
						idfound=1;
            			break;
        			}
				}
			}
    		if(idfound==0)
			{
				cout<<"\t  No such Record could be found!!!\n";
			}
    		fil.close();
			break;
		}


		
		case '2':
		{
			cout<<"\n\n\t  Enter the EMPLOYEE NAME to be Searched: ";
			cin>>empname;
			cout<<"\n\t  Searching for Employee "<<empname<<".\n\t  Please wait.... \n\n";
			Sleep(1200);
			fil.open("ADMINRECORD.txt",ios::binary|ios::in);
  			if(!fil)
			{
				cout<<"\n\t  File not Found or No record exists";
				fil.close();
				Sleep(1000);
				cout<<"\n\t  Press any key to return to Admin Section\t";
				getch();
				f.adminsec();
    		}
			while(fil)
			{
    			if(fil.read((char*)&f,sizeof(f)))
				{
	        		if(strcasecmp(empname, name)==0)
					{
						count++;
						cout<<"\n\t\t\t\t\t\t\t\t\t\t RECORD FOUND ( "<<count<<" )\n";
                		f.empheader();
						f.showempdetails();
                		namefound=1;
            		}
				}
			}
    		if(namefound==0)
			{
				cout<<"\t  No such Record could be found!!!\n";
			}
			fil.close();
    		break;
    	default:
    		cout<<"\n\n\t  Invalid input, please try again";
		}
	}
	cout<<"\n\n\n\t  Press 1 to search another record"<<endl;
	cout<<"\t  OR Press any key to return to Admin Section";
	switch(getch())
	{
		case '1':
			cout<<"\n\t  Please wait...";
			Sleep(1200);
			f.search_record();
			break;
		default:
			cout<<"\n\t  Please wait...";
			Sleep(1200);
			adminsec();
	}
}


//DELETE RECORD
void foodorder::delete_record()
{
	int idfound=0;
	xD=2;
	system("cls");
	cout<<"\n\n";
	cout<<"\t  "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<endl;
	cout<<"\t\t\t DELETE EMPLOYEE DETAILS \n";
	cout<<"\t  "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<"\n\n";
	int del_id;
	f.view_record();
	xD=0;
	cout<<"\n\n\t\t\t\t\t\t\t    "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
	cout<<"\n\t\t\t\t\t\t\t    |\t   ABOVE is the list of all employees "<<(char)24<<"\t     |";
	cout<<"\n\t\t\t\t\t\t\t    "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
	cout<<"\n\n\t  Enter the EMPLOYEE ID to be deleted: \t";
	cin>>del_id;
	fil.open("ADMINRECORD.txt", ios::binary | ios::in);
	if(!fil)
	{
		cout<<"\n\t  File not Found or No record exists";
		fil.close();
		Sleep(1200);
		cout<<"\n\t  Press any key to return to Admin Section\t";	
		getch(); 	
		f.adminsec();
    }
    while(fil)
	{
    	if(fil.read((char*)&f,sizeof(f)))
		{
    		if(f.id==del_id)
			{
				cout<<"\n \t\t\t\t\t\t\t\t\t RECORD DETAILS\n";
				f.empheader();
				f.showempdetails();
				idfound++;
				break;
        	}
		}
	}
	if(idfound==0)
	{
		cout<<"\n\t\t\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
		cout<<"\n\t\t\t |\t  No such Record could be found\t\t|\n\t\t\t |\t     Unable to delete data!!!\t\t|";
		cout<<"\n\t\t\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
	}
    fil.close();
    if(idfound==0)
    {
    	cout<<"\n\n\n\t  Press 1 to delete another record \n\t  OR Press any key to return to Admin Section";
    	switch(getch())
    	{
    		case '1':
    			cout<<"\n\n\t  Please wait...\n";	
				Sleep(1200);
    			f.delete_record();
    			break;
    		default:
    			cout<<"\n\n\t  Please wait...\n";	
				Sleep(1200);
    			adminsec();
		}
	}
	else
	{
		cout<<"\n\n\t  Are you sure you want to delete above record with ID -> "<<del_id<<" ? \n\t  Press Y to confirm or ANY OTHER KEY to cancel\n";
		switch(getch())
		{
			default:
				cout<<"\n\t  "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
				cout<<"\n\t  \t  Record with ID "<<del_id<<" was NOT deleted  \t    ";
				cout<<"\n\t  "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
				cout<<"\n\n\n\t  Press 1 to delete another record"<<endl;
				cout<<"\t  OR Press any key to return to Admin Section";
			switch(getch())
    		{
    			case '1':
    				cout<<"\n\n\t  Please wait...\n";
					Sleep(1200);
    				f.delete_record();
    				break;
    			default:
    				cout<<"\n\n\t  Please wait...\n";
					Sleep(1200);
    				adminsec();
    		}
			break;
			case 'y':
			case 'Y':
				ifstream infile;
				infile.open("ADMINRECORD.txt", ios::binary);
				ofstream outfile;
				outfile.open("temp.txt", ios::out|ios::binary);
				while(infile.read((char*)&f, sizeof(f)))
				{
					if(del_id!=f.id)
					{			
						outfile.write((char*)&f, sizeof(f));
					}
				}
				cout<<"\n\t  "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
				cout<<"\n\t  |\t Record with ID "<<del_id<<" was deleted SUCCESSFULLY\t  |";
				cout<<"\n\t  "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
				infile.close();
				outfile.close();
				remove("ADMINRECORD.txt");
				rename("temp.txt","ADMINRECORD.txt");	
				cout<<"\n\n\n\t  Press 1 to delete another record"<<endl;
				cout<<"\t  OR Press any key to return to Admin Section";
    			switch(getch())
    			{
    				case '1':
    					cout<<"\n\n\t  Please wait...\n";
						Sleep(1200);
    					f.delete_record();
    					break;
    				default:
    					cout<<"\n\n\t  Please wait...\n";
						Sleep(1200);
    					adminsec();
				}
    			break;
		}
	}
}

//CUSTOMER SECTION
void foodorder::customersec()
{
	system("Color 07");
	system("cls");
	cout<<"\n\n\n\n\n\n\n"<<endl;
	cout<<"\t\t\t\t\t\t\t\t "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\t CUSTOMER SECTION";
	cout<<"\n\t\t\t\t\t\t\t\t "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"\n\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t    1. Order Food"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t    2. Customer Order Records"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t    3. Search Specific Record"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t    4. Back to Main Menu"<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t\t "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"\n\n";            
	cout<<"\t\t\t\t\t\t\t\t\t Enter your choice by pressing the option number from the list:\t";
	switch(getch())
	{	
		case '1': food_order();
		break;
		case '2': details();
		break;
		case '3': search_order();
		break;
		case '4':
			cout<<"\n\n\t\t\t\t\t\t\t\t\t\t Taking you back to Main Section, please wait...";
			Sleep(1800);
			system("cls");
			mainsec();
			break;
		default:
			system("Color 0C");
			cout<<"\n\n\t\t\t\t\t\t\t\t\t Wrong input! Please re-enter the correct option in 3 seconds..";
			Sleep(3000);
			system("Color 07");
			f.customersec();
	}
}


//FOOD ORDER
void foodorder::food_order()
{
	f.food_orderinp();
	fil.open("foodorderdetails.txt",ios::app| ios::binary);
	fil.write((char*)&f, sizeof(f)); 
	fil.close();
	cout<<"\t Press ANY KEY to go back to Customer Section";
	getch();
	f.customersec();	
}

void foodorder:: food_orderinp()
{
	price=0;
	system("cls");
	cout<<"\n\t "<<tl<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<tr<<"\n";
	cout<<"\t "<<l<<"\t\tMOOD FOR FOOD MENU\t\t"<<l<<endl;
	cout<<"\t "<<x<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<y<<"\n";
	cout<<"\t "<<l<<"   "<<tl<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<tr<<"\t\t\t\t"<<l<<endl;
	cout<<"\t "<<l<<"   "<<l<<" STARTERS "<<l<<"\t\t\t\t"<<l<<endl;
	cout<<"\t "<<l<<"   "<<bl<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<br<<"\t\t\t\t"<<l<<endl;
	cout<<"\t "<<l<<"    1. French Fries \t\t 90/-"<<"\t\t"<<l<<endl;
	cout<<"\t "<<l<<"    2. Honey Chilli Potato \t 100/-"<<"\t\t"<<l<<endl;
	cout<<"\t "<<l<<"    3. Cheesy Nachos \t\t 110/-"<<"\t\t"<<l<<endl;
	cout<<"\t "<<l<<"    4. Paneer Tikka \t\t 120/-"<<"\t\t"<<l<<endl;
	cout<<"\t "<<l<<"    5. Gobi Manchurian \t 110/-"<<"\t\t"<<l<<endl;
	cout<<"\t "<<l<<"    6. Paneer Manchurian \t 140/-"<<"\t\t"<<l<<endl<<"\t "<<l<<"\t\t\t\t\t\t"<<l<<"\n";
	cout<<"\t "<<l<<"   "<<tl<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<tr<<"\t\t\t\t"<<l<<endl;
	cout<<"\t "<<l<<"   "<<l<<" MAIN COURSE "<<l<<"\t\t\t\t"<<l<<endl;
	cout<<"\t "<<l<<"   "<<bl<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<br<<"\t\t\t\t"<<l<<endl;
	cout<<"\t "<<l<<"    7. Veg Fried Rice \t 110/-"<<"\t\t"<<l<<endl;
	cout<<"\t "<<l<<"    8. Paneer Tikka Wrap \t 120/-"<<"\t\t"<<l<<endl;
	cout<<"\t "<<l<<"    9. Hakka Noodles \t\t 100/-"<<"\t\t"<<l<<endl;
	cout<<"\t "<<l<<"    10. Chilli Garlic Noodles  120/-"<<"\t\t"<<l<<endl;
	cout<<"\t "<<l<<"    11. Aalu Tikki Burger \t 90/-"<<"\t\t"<<l<<endl;
	cout<<"\t "<<l<<"    12. Cheese Corn Sandwich \t 70/-"<<"\t\t"<<l<<endl<<"\t "<<l<<"\t\t\t\t\t\t"<<l<<"\n";
	cout<<"\t "<<l<<"   "<<tl<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<tr<<"\t\t\t"<<l<<endl;
	cout<<"\t "<<l<<"   "<<l<<" DRINKS AND BEVERAGES "<<l<<"\t\t\t"<<l<<endl;
	cout<<"\t "<<l<<"   "<<bl<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<br<<"\t\t\t"<<l<<endl;
	cout<<"\t "<<l<<"    13. Tea \t\t\t 30/-"<<"\t\t"<<l<<endl;
	cout<<"\t "<<l<<"    14. Coffee \t\t 40/-"<<"\t\t"<<l<<endl;
	cout<<"\t "<<l<<"    15. Lime Juice \t\t 50/-"<<"\t\t"<<l<<endl;
	cout<<"\t "<<l<<"    16. Masala Jeera \t\t 50/-"<<"\t\t"<<l<<endl;
	cout<<"\t "<<l<<"    17. Vanilla Milkshake \t 80/-"<<"\t\t"<<l<<endl;
	cout<<"\t "<<l<<"    18. Chocolate Milkshake \t 90/-"<<"\t\t"<<l<<endl<<"\t "<<l<<"\t\t\t\t\t\t"<<l<<endl;
	cout<<"\t "<<bl<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<br<<"\n";
	cout<<"\n\t Enter your choice by inputing the item number: \t";
	cin>>ch;
	if(ch>18)
	{
		cout<<"\n\t Invalid input, please try again...\n";
		Sleep(1800);
		f.food_order();
	}	
	else
	{
		switch (ch)
		{
			case 1:
				strcpy(ch1,"French Fries");
				price=90;
				break;
			case 2:
				strcpy(ch1,"Honey Chilli Potato");
				price=100;
				break;
			case 3:
				strcpy(ch1,"Cheesy Nachos");
				price=110;
				break;
			case 4:
				strcpy(ch1,"Paneer Tikka");
				price=120;
				break;
			case 5:
				strcpy(ch1,"Gobi Manchurian");
				price=110;
				break;
			case 6:
				strcpy(ch1,"Paneer Manchurian");
				price=140;
				break;
			case 7:
				strcpy(ch1,"Veg Fried Rice");
				price=110;
				break;
			case 8:
				strcpy(ch1,"Paneer Tikka wrap");
				price=120;
				break;
			case 9:
				strcpy(ch1,"Hakka Noodles");
				price=100;
				break;
			case 10:
				strcpy(ch1,"Chilli Garlic Noodles");
				price=120;
				break;
			case 11:
				strcpy(ch1,"Aalu tikki burger");
				price=90;
				break;
			case 12:
				strcpy(ch1,"Cheese Grilled Sandwich");
				price=170;
				break;
			case 13:
				strcpy(ch1,"Tea");
				price=30;
				break;
			case 14:
				strcpy(ch1,"Coffee");
				price=40;
				break;
			case 15:
				strcpy(ch1,"Lime Juice");
				price=50;
				break;
			case 16:
				strcpy(ch1,"Masala Jeera");
				price=50;
				break;
			case 17:
				strcpy(ch1,"Vanilla Milkshake");
				price=80;
				break;
			case 18:
				strcpy(ch1,"Chocolate Milkshake");
				price=90;
				break;	
		}
	cout<<"\n\t You have chosen the below item\n";
	cout<<internal;
	cout<<"\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
	cout<<"\n\t "<<"|"<<setw(15)<<"Item number"<<setw(5)<<"|"<<setw(20)<<"ITEM NAME"<<setw(13)<<"|"<<setw(11)<<"    PRICE (RS)\t    "<<"|";
	cout<<"\n\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<"\n";
	cout<<left;
	cout<<"\t "<<setw(7)<<"|"<<setw(13)<<ch<<setw(5)<<"|"<<setw(28)<<ch1<<setw(7)<<"|"<<setw(13)<<price<<"  |\n";
	cout<<"\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;		
	cout<<"\n\n\t Enter the quantity: \t";
	cin>>qty[j];
	bill[j]=(price*qty[j]);
	cout<<"\n\t The following item added to the cart\n";	
	cout<<"\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;	
	cout<<"\n\n\t\tItem name ==> "<<ch1<<" (Rs "<<price<<")"<<"\n\n\t\tQuantity ==> "<<qty[j]<<"\n\n\t\tTotal Amount ==> Rs "<<price<<" X "<<qty[j]<<" = Rs "<<bill[j]<<"";
	cout<<"\n\n\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
	total=total+bill[j];
	}
	fil.open("temporder.txt",ios::app| ios::binary);
	fil.write((char*)&f, sizeof(f)); 
	fil.close();
	cout<<"\n\t Want to order more items? Just Press Y ";
	cout<<"\n\t Press any other key to proceed to CHECKOUT";
	switch(getch())
	{
		case 'y':
		case 'Y':
			j=j+1;
			f.food_order();
			break;
		default:
			system("cls");
			cout<<"\n\t\t\t\t\t  "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
			cout<<"\n\t\t\t\t\t\t\tORDER SUMMARY";
			cout<<"\n\t\t\t\t\t  "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<"\n";
			cout<<internal; 
			cout<<"\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
			cout<<"\n\t "<<"|"<<setw(11)<<"Sl. NO"<<setw(7)<<"|"<<setw(20)<<"ITEM NAME"<<setw(10)<<"|"<<setw(14)<<"QUANTITY"<<setw(8)<<"|"<<setw(10)<<"PRICE"<<setw(6)<<"|"<<setw(15)<<"AMOUNT\t  "<<"|";
			cout<<"\n\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<"\n";
			fil.open("temporder.txt",ios::in| ios::binary);
			if(!fil)
			{
				cout<<"\t File not Found";
			}
			else
			{
				int slno=1;j=1;
				while(!fil.eof()) 
				{
					fil.read((char*)&f, sizeof(f));
					if(fil.eof())
					break;			
					cout<<left;
					cout<<"\t "<<setw(7)<<"|"<<setw(11)<<slno<<setw(5)<<"|"<<setw(25)<<f.ch1<<setw(10)<<"|"<<setw(12)<<qty[j]<<setw(7)<<"|"<<setw(9)<<f.price<<setw(8)<<"|"<<setw(11)<<f.price*qty[j]<<"|\n";
					cout<<"\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
					j++;
					cout<<"\n";
					slno++;
				}
				fil.close();
			cout<<internal;
			cout<<"\t |"<<setw(106)<<"|\n";
			cout<<"\t |"<<setw(61)<<"TOTAL BILL ==> INR "<<total<<setw(41)<<"|\n";
			cout<<"\t |"<<setw(106)<<"|\n";
			cout<<"\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;	
			remove("temporder.txt");
			cout<<"\n\n\t Press ANY KEY to proceed to PAYMENT";
			getch();			
			f.foodinfodetails();
}
}
}


//PAYMENT
void foodorder::getorderid()
{
	srand((unsigned) time(0));
	cout<<"\n\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
    printf("\n\t  Your ORDER ID is\t");
    result = 1 + (rand() % 600);
    printf("%d \n", result);
    cout<<"\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
}

void foodorder::foodinfodetails()
{
	j=1;
	system("cls");
	system("color 0B");
	cout<<"\n\n\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
	cout<<"\n\t\t\tPAYMENT INFO";
	cout<<"\n\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<"\n";
	cout<<"\n\n\t Total Amount to be PAID ==> RS "<<total;
	cout<<"\n\n\n\t Enter Customer's FIRST NAME:\t";
	cin>>name;
	cout<<"\n\t Enter Customer's PHONE NUMBER:\t";
	cin>>pno;
	getorderid();
	cout<<"\n\n\t Select Mode of PAYMENT";
	cout<<"\n\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
	cout<<"\n\t  Press 1 for Cash\n\t  Press 2 for Card/UPI";
	cout<<"\n\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
	switch(getch())
	{
	case '1':
		strcpy(modpmt,"CASH");
		system("color 0A");
		cout<<"\n\n\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
		cout<<"\n\t\t\t   Please Accept CASH...";
		cout<<"\n\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<"\n";
		Sleep(2000);
		system("color 0F");
		break;
	case '2':
		strcpy(modpmt,"CARD");
		system("color 0D");
		cout<<"\n\n\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
		cout<<"\n\t\tPlease Accept PAYMENT via Card/UPI...";
		cout<<"\n\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<"\n";
		Sleep(2000);
		system("color 0F");
		break;
	default:
		system("Color 0C");
		cout<<"\n\t Wrong input! Please Try again...";
		Sleep(3000);
		system("Color 07");		
		f.foodinfodetails();
	}
	time_t now = time(0);
	char* date_time = ctime(&now);
	cout<<"\n\t The order was placed on: " << date_time << endl;
	strcpy(dtime,date_time);
	ono=result;
	tbill=total;
	total=0;
	
}


//VIEW ORDER RECORDS
void foodorder::details()
{
	system("cls");
	system("color 0B");
	cout<<"\n\t\t\t\t\t\t\t"<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
	cout<<"\n\t\t\t\t\t\t\t\t\tDISPLAYING ORDER HISTORY";
	cout<<"\n\t\t\t\t\t\t\t"<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<"\n\n";
	fil.open("foodorderdetails.txt", ios::in | ios::binary);
	if(!fil)
	{
		cout<<"\t File not Found or No record exists";
	}
	else
	{
		f.custheader();
		while(!fil.eof()) 
		{
			fil.read((char*)&f, sizeof(f));
			if(fil.eof())
			break;
			f.custorderdetails();
		}
	}	
	fil.close();
	cout<<"\n\n\t Press ANY KEY to return to Customer Section\t";
	getch();
	system("color 0F");
	f.customersec();
}


//SEARCH CUSTOMER ORDER
void foodorder::search_order()
{
	int idfound=0, code;
	system("cls");
	cout<<"\n\n";
	cout<<"\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<endl;
	cout<<"\t\t\tSEARCH ORDER DETAILS \n";
	cout<<"\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<"\n"<<endl;
	cout<<"\n\n\t Enter the ORDER ID to be Searched: ";
	cin>>code;
	cout<<"\n\t Searching for ORDER ID "<<code<<".\n\n\t Please wait... ";
	Sleep(1200);
	fil.open("foodorderdetails.txt",ios::binary | ios::in);
	if(!fil)
	{
		cout<<"\t\t File not found, or no order was placed previously. \n";
	}
    while(fil)
	{
    	if(fil.read((char*)&f,sizeof(f)))
		{
        	if(f.ono==code)
			{
				system("color 0B");
            	cout<<"\n\n\t\t\t\t\t\t\t\t\t RECORD FOUND\n";
            	f.custheader();
            	f.custorderdetails();
           		idfound=1;
           		Sleep(1800);
           		system("color 07");
            	break;
        	}
		}
	}
    		if(idfound==0)
			{
				system("color 0C");
				cout<<"\n\n\t RECORD WITH ID "<<code<<" DOES NOT EXIST";
				Sleep(1800);
				system("color 07");
			}
    		fil.close();
    		cout<<"\n\n\t PRESS 1 to Search Another Record\n\t OR Press ANY OTHER KEY to return to Customer Section";
    		switch(getch())
    		{
    			case '1':
    				cout<<"\n\t Please wait...";
    				Sleep(1500);
    				f.search_order();
    				break;
    			default:
    				cout<<"\n\t Please wait...";
    				Sleep(1500);
    				f.customersec();
    		}
}


//PROJECT DEVELOPED BY
void foodorder::aboutus() // project developed by 
{
	system("cls");
	cout<<"\n\n\n\n\n\n"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t  "<<tl<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<tr<<"\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t  "<<l<<"                                                "<<l<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t  "<<l<<"\t"<<tl<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<tr<<"     "<<l<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t  "<<l<<"\t"<<l<<"\t PROJECT DEVELOPED BY        "<<l<<"     "<<l<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t  "<<l<<"\t"<<x<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<char(203)<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<y<<"     "<<l<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t  "<<l<<"\t"<<l<<"   Member Names   "<<l<<"   USN Number    "<<l<<"     "<<l<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t  "<<l<<"\t"<<x<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<char(206)<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<y<<"     "<<l<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t  "<<l<<"\t"<<l<<"                  "<<l<<"                 "<<l<<"     "<<l<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t  "<<l<<"\t"<<l<<"    BISWATOSH     "<<l<<"   20BCAR0177    "<<l<<"     "<<l<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t  "<<l<<"\t"<<l<<"    RAVLEEN       "<<l<<"   20BCAR0196    "<<l<<"     "<<l<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t  "<<l<<"\t"<<l<<"    KANAK RAJ     "<<l<<"   20BCAR0201    "<<l<<"     "<<l<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t  "<<l<<"\t"<<l<<"                  "<<l<<"                 "<<l<<"     "<<l<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t  "<<l<<"\t"<<bl<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<char(202)<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<br<<"     "<<l<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t  "<<l<<"                                                "<<l<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t  "<<l<<"                                                "<<l<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t  "<<l<<"   "<<tl<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<char(203)<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<tr<<"   "<<l<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t  "<<l<<"   "<<l<<"   PROJECT MENTOR   "<<l<<"  JAYASHREE MA'AM  "<<l<<"   "<<l<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t  "<<l<<"   "<<x<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<char(206)<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<y<<"   "<<l<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t  "<<l<<"   "<<l<<"   JAIN UNIVERSITY  "<<l<<" SCHOOL OF CS & IT "<<l<<"   "<<l<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t  "<<l<<"   "<<bl<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<char(202)<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<br<<"   "<<l<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t  "<<l<<"                                                "<<l<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t  "<<bl<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<br<<"\n";
	for (i=1;i<=10;i++)
	{
		if(i%2==0)
		{
			system("Color 07");
			Sleep(400);
		}
		else
		{
			system("Color 17");
			Sleep(400);
		}
	}
    system("Color 07");
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Press any key to return to Main Menu \t";
	getch();
	mainsec();	
}

//OTHER FUNCTIONS
void foodorder::loading()
{
	system("Color F0");
	char a = 176 , b = 219;
    cout<<"\n\n\n\n\n\n\n\n\n\n"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t";
    cout<<"Loading...\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t\t";    
    for (int i=0; i<30; i++)
    cout<<(char)a;
    cout<<"\r";
    cout<<"\t\t\t\t\t\t\t\t\t\t\t";  
    for (int i=0; i<30; i++) 
	{
		cout<<(char)b;
        Sleep(60);
    }
	mainsec();
}
void foodorder::custorderdetails()
{
	cout<<left;
	cout<<"\n\t "<<setw(7)<<""<<setw(10)<<f.ono<<setw(5)<<"|"<<setw(17)<<f.modpmt<<setw(4)<<"|"<<setw(18)<<f.name<<setw(5)<<"|"<<setw(16)<<f.pno<<setw(9)<<"|"<<setw(12)<<f.tbill<<setw(5)<<"|"<<setw(30)<<f.dtime;
	cout<<"\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
	cout<<"";
}
void foodorder::custheader()
{
	cout<<internal; 
	cout<<"\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
	cout<<"\n\t "<<" "<<setw(12)<<"ORDER ID"<<setw(5)<<"|"<<setw(16)<<"PAYMENT METHOD"<<setw(6)<<"|"<<setw(16)<<"CUSTOMER NAME"<<setw(6)<<"|"<<setw(14)<<"PHONE NO"<<setw(7)<<"|"<<setw(15)<<"TOTAL BILL"<<setw(6)<<"|"<<setw(23)<<"ORDER PLACED ON"<<setw(9)<<" ";
	cout<<"\n\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
}
void foodorder::empheader()
{
	cout<<internal;
	cout<<"\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
	cout<<"\n\t "<<"|"<<setw(15)<<"EMPLOYEE ID"<<setw(6)<<"|"<<setw(18)<<"EMPLOYEE NAME"<<setw(7)<<"|"<<setw(12)<<"D.O.B"<<setw(10)<<"|"<<setw(16)<<"YEAR JOINED"<<setw(6)<<"|"<<setw(15)<<"DEPARTMENT"<<setw(6)<<"|"<<setw(16)<<"POSITION"<<setw(9)<<"|"<<setw(10)<<"SALARY"<<setw(5)<<"|";
	cout<<"\n\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<endl;
}

void foodorder::showempdetails()
{
	cout<<left;
	cout<<"\t "<<setw(8)<<"|"<<setw(13)<<f.id<<setw(5)<<"|"<<setw(20)<<f.name<<setw(7)<<"|"<<setw(15)<<f.dob<<setw(10)<<"|"<<setw(12)<<f.yj<<setw(6)<<"|"<<setw(15)<<f.department<<setw(5)<<"|"<<setw(20)<<f.position<<setw(5)<<"|"<<setw(10)<<f.salary<<"|\n";
	cout<<"\t "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s;
}

int foodorder:: getempid()
{
	int newid, idfound=0;
	char l=186, d=205;
	cout<<"\n\t  Enter the EMPLOYEE ID : \t";
	cin>>newid;
	fil.open("ADMINRECORD.txt",ios::binary | ios::in);
	if(!fil)
	{
		ofstream ("ADMINRECORD.txt");
    }
    while(fil)
	{
    	if(fil.read((char*)&f,sizeof(f)))
		{
        	if(f.id==newid)
			{
				system("Color 0C");
            	cout<<"\n\n\t  "<<char(201)<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<char(187);
				cout<<"\n\t  "<<l<<"  EMPLOYEE ID ALREADY EXISTS  "<<l<<endl;
				cout<<"\t  "<<char(200)<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<char(188);
				cout<<"\n\n\n\t  Please INPUT a different EMPLOYEE ID";
            	Sleep(3500);
            	idfound=1;
            	system("Color 0F");
            	fil.close();
            	adminsec();            	
        	}
		}
	}
	fil.close();
    if(idfound==0)
	{
		f.id=newid;
	}    
}

int foodorder::getempdata() 
{	
	int ch_dept;
	char ch_pos;
	cout<<"\n\n";
	cout<<"\t  "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<endl;
	cout<<"\t\t\t INPUT EMPLOYEE DETAILS \n";
	cout<<"\t  "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<"\n"<<endl;
	f.getempid();
	cout<<"\n\t  Enter EMPLOYEE NAME : \t";
	cin>>name;
	cout<<"\n\t  Enter the Date of Birth in\n\t  DD-MM-YYYY format(including dash) : \t";
	cin>>dob;
	cout<<"\n\t  Enter the YEAR OF JOINING :  \t";
	cin>>yj;
	cout<<"\n\t  Select DEPARTMENT"<<endl;
	cout<<"\t  "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<"\n";
	cout<<"\t  1. Kitchen Staff"<<endl;
	cout<<"\t  2. Management Staff"<<endl;
	cout<<"\t  3. Floor Staff"<<endl;
	cout<<"\t  4. Delivery Staff"<<endl;
	cout<<"\t  "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<endl;
	cout<<"\t  Enter your choice: ";
	cin>>ch_dept;	
	switch(ch_dept)
	{
		case 1:
			strcpy(department, "Kitchen");
			cout<<"\n\t  Select POSITION"<<endl;
			cout<<"\t  "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<endl;
			cout<<"\t  a.Executive Chef"<<endl;
			cout<<"\t  b.Assistant Chef"<<endl;
			cout<<"\t  c.Kitchen Helper"<<endl;
			cout<<"\t  "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<endl;
			cout<<"\t  Enter your choice: ";
			cin>>ch_pos;
			ch_pos=toupper(ch_pos);
			switch(ch_pos)
			{
			case 'A':
			case '1':
				strcpy(position, "Executive Chef");
				salary=40000;
				break;
			case 'B':
			case '2':
				strcpy(position, "Assistant Chef");
				salary=30000;
				break;
			case 'C':
			case '3':
				strcpy(position, "Kitchen Helper");
				salary=10000;
				break;
			default:
				cout<<"\t  Entered input is incorrect, please try again\n\n";
				Sleep(4000);
				f.add_record();
			}
			break;
			
		case 2:
			strcpy(department, "Management");
			cout<<"\n\t  Select POSITION"<<endl;
			cout<<"\t  "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<endl;
			cout<<"\t  a.Manager"<<endl;
			cout<<"\t  b.Cashier"<<endl;
			cout<<"\t  c.Store Keeper"<<endl;
			cout<<"\t  "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<endl;
			cout<<"\t  Enter your choice: ";
			cin>>ch_pos;
			ch_pos=toupper(ch_pos);
			switch(ch_pos)
			{
			case 'A':
			case '1':
				strcpy(position, "Manager");
				salary=35000;
				break;
			case 'B':
			case '2':
				strcpy(position, "Cashier");
				salary=12000;
				break;
			case 'C':
			case '3':
				strcpy(position, "Store Keeper");
				salary=8000;
				break;
			default:
				cout<<"\t  Entered input is incorrect, please try again\n\n";
				Sleep(4000);
				f.add_record();
				break;
			}
			break;
			
		
		case 3:
			strcpy(department, "Floor");
			cout<<"\n\t  Select POSITION"<<endl;
			cout<<"\t  "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<endl;
			cout<<"\t  a. Waiter"<<endl;
			cout<<"\t  b. House Keeper"<<endl;
			cout<<"\t  c. Security"<<endl;
			cout<<"\t  "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<endl;
			cout<<"\t  Enter your choice: ";
			cin>>ch_pos;
			ch_pos=toupper(ch_pos);
			switch(ch_pos)
			{
			case 'A':
			case '1':
				strcpy(position, "Waiter");
				salary=15000;
				break;
			case 'B':
			case '2':
				strcpy(position, "House Keeper");
				salary=8000;
				break;
			case 'C':
			case '3':
				strcpy(position, "Security");
				salary=8000;
				break;
			default:
				cout<<"\t  Entered input is incorrect, please try again\n\n";
				Sleep(4000);
				f.add_record();
				break;
			}
			break;				
		
		case 4:
			strcpy(department, "Delivery");
			cout<<"\n\t  Select POSITION"<<endl;
			cout<<"\t  "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<endl;
			cout<<"\t  a.Delivery boy"<<endl;
			cout<<"\t  "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<endl;
			cout<<"\t  Enter your choice: ";
			cin>>ch_pos;
			ch_pos=toupper(ch_pos);
			switch(ch_pos)
			{
			case 'A':
			case '1':
				strcpy(position, "Delivery Boy");
				salary=15000;
				break;
			default:
				cout<<"\t  Entered input is incorrect\n Please try again";
				Sleep(2500);
				f.add_record();
			}
			break;
		default:
			cout<<"\t  Entered input is incorrect\n Please try again";
			Sleep(2500);
			f.add_record();
	}	
}

//EXIT PROGRAM
void foodorder::exitprogram()
{
	system("Color F0");
	char a = 176, b = 219;
	system("cls");
	cout<<"\n\n\n\n\n\n\n"<<endl;
	cout<<"\t\t\t\t\t\t\t\t "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t    ";
	cout<<"Thank you for visiting. Hope to see you again with a smile :)";
	cout<<"\n\t\t\t\t\t\t\t\t "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"\n\n";
	cout<<"\n\t\t\t\t\t\t\t\t\t\t      Please wait while the program exits";	
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t";
    cout<<"Exiting...\n\n";
    cout<<"  \t\t\t\t\t\t\t\t\t\t\t";    
    for (int i=0; i<30; i++)
    cout<<(char)a;
    cout<<"\r";
    cout<<"  \t\t\t\t\t\t\t\t\t\t\t";  
    for (int i=0; i<30; i++) 
	{
		cout<<(char)b;
        Sleep(60);
    }
	cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t         YOU CAN CLOSE THE WINDOW NOW\n\n\n\n\n\n";
	system("Color 07");
	exit(0);
}

//MAIN FUNCTON THAT TRIGGERS THE PROGRAM TO START
int main() 
{
	remove("temporder.txt"); // removes older temporary files if it failed to be removed earlier || makes sure no error is caused because of old redundant files.
	system("Color 07");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t HELLO! WELCOME TO MOOD FOR FOOD\n";
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\t    PRESS ANY KEY TO BEGIN...   ";
	getch();
	system("cls");
	f.loading(); // triggers the program to actually begin
}




// Conclusion
// It helps customer in making order easily; it gives information needed in making order to customer. The Food Order System can help restaurant and receiving orders and modifying its data and it is also made for admin so that it helps admin in controlling all the Food system.
// We have made this project very user friendly. We were able to use what we have learned in class and were able to implement the knowledge into this project. This project wouldn’t be possible with the help our own OOPS with C++ ma’am Jayashree ma’am. 
