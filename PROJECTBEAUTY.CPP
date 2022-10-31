#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<iomanip.h>
#include<graphics.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
#include<stdlib.h>
#include<ctype.h>
#include<process.h>

typedef char option[50];
const int ROW = 10,COL = 10;
// Function used to do screening
class final_menu
{
	int a;
	public:
	void main_menu();
	void client_menu();
	void product_menu();
	void edit_menu();
	void help();

}x,y,z;
// Class contains the initial deposit of customers
class initial
{
	public:
		void add_to_file(int, char t_name[30], int t_age,char t_email[50],char t_contnumber[30], float);	// For initial deposits in customers account
		void display_list(void); // Displaying customers account list
		void delete_account(int); // Deleting customers account
		void update_balance(int, char t_name[30],int age,char t_email[50], char t_contnumber[30], float); // For updating the customer account
		void modify(void);   	// To modify the customer account information
		int last_accno(void); // To know the last account number
		int found_account(int); // To found the account is in "CLIENT.dat" or n
		float give_balance(int); // To print the balance amount of a particular customer
		int recordno(int);
		void display(int); // To display the customer account
	private:
		void modify_account(int, char t_name[30],int age, char t_email[50], char contnumber[30]);	// Function to modify the customer account
		int accno;
		char name[30],contnumber[30],email[50];
		int age;float balance;

}ini;

class initial_product
{
	public:
		void ad_to_file(int , char t_name1[30], char t_rate[10],char t_tax[10],char t_amount[10]);	// For initial deposits in customers account
		void display_product(void); // Displaying customers account list
		void delete_product(int); // Deleting customers account
		void update_product(int, char t_name1[30], char t_rate[10],char t_tax[10],char t_amount[10]); // For updating the customer account
		void modify1(void);   	// To modify the customer account information
		void edit_product(void);
		int last_pno(void); // To know the last account number
		int found_pno(int); // To found the account is in "CLIENT1.dat" or n
		void display1(int);
		int recordno1(int);
	private:
		void modify_product(int , char t_name1[30], char t_rate[10], char t_tax[10],char t_amount[10] );	// Function to modify the customer account
		int pno;
		char name1[30],rate[10],tax[10],amount[10];
}n,ini1;

// Class contains the customers daily transaction entry
class new_product
{
	public:
		void register_product(void);
		void view_product(void);
		void close_product(void);
		void edit_product(void);
		void clear(int, int);
	private:
		int no_of_days(int, int, int, int, int, int); // Function to find the total days
		char type[10],tran;	// Account type as Cheque or Cash
		int dd, mm, yy; // To store the system date/ Enter date
		int accno;			// As the account type is Deposit or Withdraw
		float interest, amount, balance;

}c,ini11;

class account
{
	public:
		void new_account(void);  // Function to create a new account
		void close_account(void);	// Function to close an accoun
		void clear(int, int); // Function to perform a clear screen function

	private:
		int no_of_days(int, int, int, int, int, int); // Function to find the total days
		char type[10],tran;	// Account type as Cheque or Cash
		int dd, mm, yy; // To store the system date/ Enter date
		int accno;			// As the account type is Deposit or Withdraw
		float interest, amount, balance;
}a;


/* The function client_menu() is used to display the client menu of clinic */
void final_menu::main_menu()
{
	char choice1;
	do
	{
	clrscr();
		int gd=DETECT,gm;
		initgraph(&gd,&gm,"c:\\turboc3\\bgi");
		settextstyle(0,0,6);
		setcolor(RED); delay(100);
		outtextxy(165,50,"WELCOME");
		outtextxy(270,100,"TO");
		outtextxy(30,150,"A-One BEAUTY");
		delay(100);
		settextstyle(3,0,5); setcolor(WHITE); outtextxy(65,200,"1. CLIENT"); delay(100);
		settextstyle(3,0,5); setcolor(MAGENTA); outtextxy(65,250,"2. PRODUCT"); delay(100);
		settextstyle(3,0,5); setcolor(LIGHTGRAY); outtextxy(65,300,"3. HELP"); delay(100);
		settextstyle(3,0,5); setcolor(GREEN); outtextxy(65,350,"4. EXIT"); delay(100);
		cout<<"\t\t\t\t\t\t\n\t\t\t\t\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nEnter your choice : ";
		cin>>choice1;
		switch(choice1)
		{
			case '1':
				x.client_menu();
				break;
			case '2':
				y.product_menu();
				break;
			case '3':
				z.help();
				break;
			case '4':
				exit(0);
				break;
		}
	}while(choice1!=4);
}

void final_menu::help(void)
{
	int gd1=DETECT,gm1;
	initgraph(&gd1,&gm1,"c:\\turboc3\\bgi");
	settextstyle(0,0,6);
	setcolor(RED);
	gotoxy(180,125);
	cout<<"t\t\n\n\n\n\nThis program is developed especially for BeautyMantra";
}

void final_menu::client_menu()
{
	clrscr();
	closegraph();
	char choice;
	account a;
	do
	{
		int gd2=DETECT,gm2;
		initgraph(&gd2,&gm2,"c:\\turboc3\\bgi");
		settextstyle(0,0,6);
		setcolor(RED); delay(100);
		outtextxy(165,100,"CLIENT");
		outtextxy(180,150,"MENU"); delay(100);
		settextstyle(3,0,5); setcolor(WHITE); outtextxy(65,200,"1. CLIENT REGISTRATION"); delay(100);
		settextstyle(3,0,5); setcolor(MAGENTA); outtextxy(65,250,"2. LIST OF CLIENT"); delay(100);
		settextstyle(3,0,5); setcolor(LIGHTGRAY); outtextxy(65,300,"3. EDIT  ACCOUNT"); delay(100);
		settextstyle(3,0,5); setcolor(GREEN); outtextxy(65,350,"4. EXIT"); delay(100);
		cout<<"\t\t\t\t\t\t\n\t\t\t\t\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nEnter your choice : ";
		cin>>choice;
		switch (choice)
		{
			case '1':
				a.new_account(); // New account member function
				break;
			case '2':
				initial ini;
				ini.display_list(); // Global list of account function
				break;
			case '3':
				x.edit_menu(); // Sub menu for editing the account
				break;
			case '4':
				return;
		 }
	  } while (choice != 4);
}

void final_menu::product_menu()
{
	closegraph();
	char choice2;
	new_product c;
	do
	{
	int gd3=DETECT,gm3;
	initgraph(&gd3,&gm3,"c:\\turboc3\\bgi");
	settextstyle(0,0,6);
	setcolor(RED);
	outtextxy(165,100,"PRODUCT");
	outtextxy(180,150,"MENU");
	settextstyle(3,0,5);
	setcolor(WHITE); outtextxy(65,200,"1. REGISTER PRODUCT"); delay(100);
	setcolor(MAGENTA); outtextxy(65,250,"2. VIEW PRODUCT"); delay(100);
	setcolor(LIGHTGRAY); outtextxy(65,300,"3. EDIT PRODUCT"); delay(100);
	setcolor(GREEN); outtextxy(65,350,"4. EXIT"); delay(100);
	cout<<"\t\t\t\t\t\t\n\t\t\t\t\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nEnter your choice : ";
	cin>>choice2;
		switch (choice2)
		{
			case '1':
				c.register_product();
				break;
			case '2':
				initial_product n;
				n.display_product();
				break;
			case '3':
				n.edit_product();
				break;
			case '4':
				return;
		}
	} while (choice2 != 4);
}

/* Function for edit menu with account modification and close */
void new_product::register_product()
{
	closegraph();
	int gd4=DETECT,gm4;
	initgraph(&gd4,&gm4,"c:\\turboc3\\bgi");
	int o, valid1;
	initial_product ini1;
	gotoxy(3,3);
	for (o = 1; o<= 76; o++)
		cprintf(" ");
	gotoxy(30, 3);
	cprintf("Register New Product");
	int d1, m1, y1;
	struct date d;		// For extracting system date
	getdate(&d);
	d1 = d.da_day;
	m1 = d.da_mon;
	y1 = d.da_year;
	int t_pno;
	t_pno = ini1.last_pno();
	t_pno++;
	// Appends and deletes a false record to create primary position in data files
	if (t_pno == 1)
	{
		ini1.ad_to_file(t_pno, "abc","def","ghi","jkl");
		ini1.delete_product(t_pno);
		cout << "Press enter";
		getch();
	}
	char name1[30],rate[10],tax[10],amount[10];
	gotoxy(5, 6);
	cout << "Date: " << d1 << '/' << m1 << '/' << y1;
	gotoxy(5, 8);
	cout << "Product No # " << t_pno;
	gotoxy(5, 10);
	cout << "Product Name : ";
	gotoxy(5, 11);
	cout<<"Rate :";
	gotoxy(5,13);
	cout<<"Tax :";
	gotoxy(5,15);
	cout<<"Cost :";
	do
	{
		clear(5, 23);
		gotoxy(10, 23);
		cout << "Enter Name of the product";
		valid1 = 1;
		gotoxy(20, 10);
		gets(name1);
		strupr(name1);
		if (strlen(name1) == 0)
		{
			valid1 = 0;
			gotoxy(5, 23);
			cprintf("\7Name of product should not be blank");
			getch();
		}
	}while (!valid1);
		do
	{
		clear(5, 23);
		gotoxy(5, 23);
		cout << "Enter rate of the product";
		valid1 = 1;
		gotoxy(20, 11);
		gets(rate);
		strupr(rate);
		if (strlen(rate) == 0)
		{
			valid1 = 0;
			gotoxy(5, 23);
			cprintf("\7Rate should not be blank");
			getch();
		}
	}while (!valid1);
		do
	{
		clear(5, 23);
		gotoxy(5, 23);
		cout << "Enter tax of the product";
		valid1 = 1;
		gotoxy(20, 13);
		gets(tax);
		strupr(tax);
		if (strlen(tax) == 0 )
		{
			valid1 = 0;
			gotoxy(5, 23);
			cprintf("\7Tax should not be blank");
			getch();
		}
	}while (!valid1);
	do
	{
		clear(5, 23);
		gotoxy(5, 23);
		cout << "Enter amount ";
		valid1 = 1;
		gotoxy(20, 15);
		gets(amount);
		strupr(amount);
		if (strlen(amount) == 0 )
		{
			valid1 = 0;
			gotoxy(5, 23);
			cprintf("\Cost should not blank");
			getch();
		}
	}while (!valid1);
	char ch1;
	clear(5, 23);
	do
	{
		clear(5, 18);
		valid1 = 1;
		gotoxy(5, 18);
		cout << "Do you want to save the record <Y/N>: ";
		ch1 = getch();
		//return;
		ch1 = toupper(ch1);
	}while (ch1 != 'N' && ch1 != 'Y');
	if (ch1 == 'N')
		return;
   //	float t_amount;
 //	t_amount = t_balance;
	// Appends the records contents into both CLIENT1.dat and BANKING.dat data files
	ini1.ad_to_file( t_pno,name1,rate,tax,amount );
}


void initial_product::edit_product(void)
{

	closegraph();
	char choice4;
	do
	{
	int gd5=DETECT,gm5;
	initgraph(&gd5,&gm5,"c:\\turboc3\\bgi");
	settextstyle(0,0,3);
	setcolor(RED);
	outtextxy(110,100,"PRODUCT MODIFICATION");
	outtextxy(280,150,"MENU");
	settextstyle(3,0,5);
	setcolor(WHITE); outtextxy(65,200,"1. MODIFY PRODUCT"); delay(100);
	setcolor(MAGENTA); outtextxy(65,250,"2. DELETE PRODUCT"); delay(100);
	setcolor(GREEN); outtextxy(65,300,"3. EXIT"); delay(100);
	cout<<"\t\t\t\t\t\t\n\t\t\t\t\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nEnter your choice : ";
	cin>>choice4;
		switch (choice4)
		{
			case '1':
				initial_product ini1;
				ini1.modify1();
				break;
			case '2':
				ini11.close_product();
				break;
			case '3':
				return;
		}
	} while (choice4!= 3);
}



void final_menu::edit_menu()
{
	closegraph();
	char choice;
	do
	{
	int gd6=DETECT,gm6;
	initgraph(&gd6,&gm6,"c:\\turboc3\\bgi");
	settextstyle(0,0,3);
	outtextxy(110,100,"ACCOUNT MODIFICATI0N");
	outtextxy(280,150,"MENU");
	settextstyle(3,0,5);
	setcolor(WHITE); outtextxy(65,200,"1. MODIFY ACCOUNT"); delay(100);
	setcolor(MAGENTA); outtextxy(65,250,"2. DELETE ACCOUNT"); delay(100);
	setcolor(GREEN); outtextxy(65,300,"3. EXIT"); delay(100);
	cout<<"\t\t\t\t\t\t\n\t\t\t\t\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nEnter your choice : ";
	cin>>choice;
		switch (choice)
		{
			case '1':
				initial ini;
				ini.modify();
				break;
			case '2':
				account a;
				a.close_account();
				break;
			case '3':
				return;
		}
	} while (choice != 3);
}

/* Function for modifying the existing accounts */
void initial::modify(void)
{
	closegraph();
	int gd7=DETECT,gm7;
	initgraph(&gd7,&gm7,"c:\\turboc3\\bgi");
	int j;
	char t_acc[10];
	int t, t_accno;
	gotoxy(5,5);
	cout << "Enter the Client no. ";
	gets(t_acc);
	t = atoi(t_acc);
	t_accno = t;
	if (!found_account(t_accno))
	{
		closegraph();
		gotoxy(5, 5);
		cout << "\7Client not found";
		getch();
		return;
	}
	gotoxy(3, 3);
	gotoxy(30, 3);
	cprintf("Modify Account Screen");
	int d1, m1, y1;
	struct date d;		// For extracting system date
	getdate(&d);
	d1 = d.da_day;
	m1 = d.da_mon;
	y1 = d.da_year;
	gotoxy(4, 2);
	cout << "Date: " << d1 << "/" << m1 << "/" << y1;
	char ch;
	display(t_accno);
	account a;
	do
	{
		a.clear(5, 15);
		gotoxy(5, 15);
		cout << "Modify  client account? <y/n>: ";
		ch = getche();
		if (ch == '0')
			return;
		ch = toupper(ch);
	}while (ch != 'N' && ch != 'Y');
	if (ch == 'N')
		return;
	int modified = 0, valid;
	char t_name[30],t_email[50],t_contnumber[30];
	int t_age;
	gotoxy(5, 15);
	cout << "Name : ";
	gotoxy(5,17);
	cout<<"Age : ";
	gotoxy(5,18);
	cout<<"Email : ";
	gotoxy(5,19);
	cout<<"Mobile No :";
	do
	{
		a.clear(15, 15);
		a.clear(5, 23);
		gotoxy(5, 23);
		cout << "Enter Name or Press Enter for No Change";
		valid = 1;
		gotoxy(15, 15);
		gets(t_name);
		strupr(t_name);
		if (t_name[0] == '0')
			return;
		if (strlen(t_name) > 25)
		{
			valid = 0;
			gotoxy(5, 23);
			cprintf("\7Name should not greater than 25");
			getch();
		}
	} while (!valid);

	a.clear(5,23);
	do
	{
		a.clear(15, 17);
		a.clear(5, 23);
		gotoxy(5, 23);
		cout << "Enter Age or press enter for no Change";
		valid = 1;
		gotoxy(15, 17);
		cin>>age;
		if (age>100)
		{
			valid = 0;
			gotoxy(5, 23);
			cprintf("\7Age should not greater than 100");
			getch();
		}
	}while (!valid);
	if (age > 0)
		modified = 1;
	if (!modified)
		return;
	// clears the screen at 23rd row and from 5th column
	a.clear(5,23);
      do
	{
		a.clear(15, 18);
		a.clear(5, 23);
		gotoxy(5, 23);
		cout << "Enter Email Address or press enter for no Change";
		valid = 1;
		gotoxy(15, 18);
		gets(t_email);
		strupr(t_email);
		if (t_email[0] == '0')
			return;
		if (strlen(t_email) >50)
		{
			valid = 0;
			gotoxy(5, 23);
			cprintf("\7Email Address should not greater than 50");
			getch();
		}
	}while (!valid);
	if (strlen(t_email) > 0)
		modified = 1;
	if (!modified)
		return;
	// clears the screen at 23rd row and from 5th column
	a.clear(5,23);
	do
	{
		a.clear(15, 19);
		a.clear(5, 23);
		gotoxy(5, 23);
		cout << "Enter Mobile Number or press enter for no Change";
		valid = 1;
		gotoxy(15, 19);
		gets(t_contnumber);
		strupr(t_contnumber);
		if (t_contnumber[0] == '0')
			return;
		if (strlen(t_contnumber) >10 || strlen(t_contnumber)<10)
		{
			valid = 0;
			gotoxy(5, 23);
			cprintf("\7Mobile Number should not greater than or less then 10");
			getch();
		}
	}while (!valid);
	if (strlen(t_contnumber) > 0)
		modified = 1;
	if (!modified)
		return;
	// clears the screen at 23rd row and from 5th column
	a.clear(5,23);
	do
	{
		a.clear(5, 23);
		gotoxy(5, 20);
		cout << "Do you want to save Changes <Y/N>: ";
		ch = getch();
		if (ch == '0')
			return;
		ch = toupper(ch);
	}while (ch != 'N' && ch != 'Y');
	if (ch == 'N')
		return;
	// Passes the parameter to add in data file
	modify_account(t_accno, t_name,age, t_email, t_contnumber);
	gotoxy(5, 21);
	cout << "\7Record modified";
	gotoxy(5, 23);
	cout << "Press any key to continue...";
	getch();
}
void initial_product::modify1(void)
{
	closegraph();
	int gd8=DETECT,gm8;
	initgraph(&gd8,&gm8,"c:\\turboc3\\bgi");
	int j;
	char t_p[10];
	int t1, t_pno;
	gotoxy(5,5);
	cout << "Enter the Product no. ";
	cin>>t_pno;
	if (!found_pno(t_pno))
	{
		closegraph();
		gotoxy(5, 5);
		cout << "\7Product not found";
		getch();
		return;
	}
	gotoxy(3, 3);
	gotoxy(30, 3);
	cprintf("Modify Product Screen");
	int d1, m1, y1;
	struct date d;		// For extracting system date
	getdate(&d);
	d1 = d.da_day;
	m1 = d.da_mon;
	y1 = d.da_year;
	gotoxy(4, 2);
	cout << "Date: " << d1 << "/" << m1 << "/" << y1;
	char ch1;
	display1(t_pno);
	new_product a1;
	do
	{
		a1.clear(5, 15);
		gotoxy(5, 15);
		cout << "Modify this  Product? <y/n>: ";
		ch1 = getche();
		if (ch1 == '0')
			return;
		ch1 = toupper(ch1);
	}while (ch1 != 'N' && ch1 != 'Y');
	if (ch1 == 'N')
		return;
	int modified = 0, valid1;
	char t_name1[30],t_rate[10],t_tax[10],t_amount[10];
	gotoxy(5, 17);
	cout << "Product Name : ";
	gotoxy(5, 18);
	cout << "Rate of Product : ";
	gotoxy(5,19);
	cout<<"Tax on the Product : ";
	gotoxy(5,20);
	cout<<"Cost of the Product : ";
	do
	{
		a1.clear(45, 17);
		a1.clear(35, 23);
		gotoxy(35, 23);
		cout << "Enter Product name or Press Enter for No Change";
		valid1 = 1;
		gotoxy(45, 17);
		gets(t_name1);
		strupr(t_name1);
		if (t_name1[0] == '0')
			return;

	} while (!valid1);

	do
	{
		a1.clear(45, 18);
		a1.clear(35, 23);
		gotoxy(35, 23);
		cout << "Enter Rate of Product or press enter for no Change";
		valid1 = 1;
		gotoxy(45, 18);
		gets(t_rate);
		strupr(t_rate);

	}while (!valid1);
	if (strlen(t_rate) > 0)
		modified = 1;
	if (!modified)
		return;
	// clears the screen at 23rd row and from 5th column
	a1.clear(5,23);
	do
	{
		a1.clear(45, 19);
		a1.clear(35, 23);
		gotoxy(35, 23);
		cout << "Enter Tax on Product or press enter for no Change";
		valid1 = 1;
		gotoxy(45, 19);
		gets(t_tax);

	}while (!valid1);
	if (t_tax > 0)
		modified = 1;
	if (!modified)
		return;
	// clears the screen at 23rd row and from 5th column
	a1.clear(35,23);
      do
	{
		a1.clear(45, 20);
		a1.clear(35, 23);
		gotoxy(35, 23);
		cout << "Enter Cost of Product or Press Enter for no change";
		valid1 = 1;
		gotoxy(45, 20);
		gets(t_amount);
		strupr(t_amount);
	}while (!valid1);
	if (strlen(t_amount) > 0)
		modified = 1;
	if (!modified)
		return;
	// clears the screen at 23rd row and from 5th column
	a1.clear(35,23);

	do
	{
		a1.clear(45, 23);
		gotoxy(35, 22);
		cout << "Do you want to save Changes <Y/N>: ";
		ch1 = getch();
		if (ch1 == '0')
			return;
		ch1 = toupper(ch1);
	}while (ch1 != 'N' && ch1 != 'Y');
	if (ch1 == 'N')
		return;
	// Passes the parameter to add in data file
	modify_product(t_pno, t_name1, t_rate,t_tax,t_amount);
	gotoxy(5, 21);
	cout << "\7Record of Product modified";
	gotoxy(5, 23);
	cout << "Press any key to continue...";
	getch();
}

/* Function for displaying an account when modified */
void initial::display(int t_accno)
{
	closegraph();
	int gd9=DETECT,gm9;
	initgraph(&gd9,&gm9,"c:\\turboc3\\bgi");
	fstream file;
	file.open("CLIENT1.dat", ios::in);
	file.seekg(0, ios::beg);
	// Displays the record contents matching with t_accno from CLIENT1.dat data file
	while (file.read((char *)this, sizeof(initial)))
	{
		if (t_accno == accno)
		{
			gotoxy(8, 5);
			cout << "Account no. " << accno;
			gotoxy(10, 8);
			cout << "Name : ";
			puts(name);
			gotoxy(10, 10);
			cout<<"Age:";
			cout<<age;
			gotoxy(10,11);
			cout<<"Email:";
			puts(email);
			gotoxy(10,12);
			cout<<"Mobile Number:";
			puts(contnumber);
			gotoxy(10,13);
			cout << "Balance : " << setw(15)    // setwidth
						<< setprecision(2)    // set position of decimal point
						<< setiosflags(ios::left)   // set left justified output
						<< setiosflags(ios::showpoint)  // always show decimal point
						<< setiosflags(ios::fixed)    // set fixed notation for display
						<< balance;
			break;
		}
	}
	file.close();
}
void initial_product::display1(int t_pno)
{
	closegraph();
	int gd10=DETECT,gm10;
	initgraph(&gd10,&gm10,"c:\\turboc3\\bgi");
	fstream file1;
	file1.open("PRODUCT1001.dat", ios::in);
	file1.seekg(0, ios::beg);
	// Displays the record contents matching with t_accno from CLIENT.dat data file
	while (file1.read((char *)this, sizeof(initial)))
	{
		if (t_pno == pno)
		{
			gotoxy(10, 5);
			cout << "Product no. " << pno;
			gotoxy(10, 8);
			cout << "Product Name : ";
			puts(name1);
			gotoxy(10, 11);
			cout << "Product Rate : ";
			puts(rate);
			gotoxy(10, 13);
			cout<<"Product Tax :";
			puts(tax);
			gotoxy(10,15);
			cout<<"Product Cost : ";
			puts(amount);
			break;
		}
	}
	file1.close();
}

/* Function for updating the modified account into CLIENT.dat file */
void initial::modify_account(int t_accno, char t_name[30],int t_age,char t_email[50],char t_contnumber[30])
{
	int recno;
	recno = recordno(t_accno);
	fstream file;
	file.open("CLIENT1.dat", ios::out|ios::ate);
	strcpy(name, t_name);
	age=t_age;
	strcpy(email,t_email);
	strcpy(contnumber,t_contnumber);
	int location;
	// finds the position in data file
	location = (recno-1) * sizeof(initial);
	file.seekp(location);
	// Overwrites the modified record into CLIENT.dat data file
	file.write((char *)this, sizeof(initial));
	file.close();
	return;
}
void initial_product::ad_to_file(int t_pno, char t_name1[30], char t_rate[10],char t_tax[10], char t_amount[10])
{
	pno = t_pno;
	strcpy(name1, t_name1);
	strcpy(rate,t_rate);
	strcpy(tax,t_tax);
	strcpy(amount,t_amount);
	fstream file1;
	// Appends new account record with the balance into CLIENT.dat data file
	file1.open("PRODUCT1001.dat",ios::app);
	file1.write((char *)this, sizeof(initial_product));
	file1.close();
}

void initial_product::modify_product(int t_pno, char t_name1[30], char t_rate[10],char t_tax[10],char t_amount[10])
{
	int recno1;
	recno1 = recordno1(t_pno);
	fstream file1;
	file1.open("PRODUCT1001.dat", ios::out|ios::ate);
	strcpy(name1, t_name1);
	strcpy(rate,t_rate);
	strcpy(tax,t_tax);
	strcpy(amount,t_amount);
	int location1;
	// finds the position in data file
	location1 = (recno1-1) * sizeof(initial_product);
	file1.seekp(location1);
	// Overwrites the modified record into PRODUCT100.dat data file
	file1.write((char *)this, sizeof(initial_product));
	file1.close();
	return;
}

/* Function to find the last account number */
int initial::last_accno(void)
{
	fstream file22;
	file22.open("CLIENT1.dat", ios::in);
	file22.seekg(0, ios::beg);
	int count = 0;
	// Founds the last account no.
	while (file22.read((char *)this, sizeof(initial)))
		count = accno;
	file22.close();
	return count;
}
int initial_product::last_pno(void)
{
	fstream file1;
	file1.open("PRODUCT1001.dat", ios::in);
	file1.seekg(0, ios::beg);
	int count1 = 0;
	// Founds the last account no.
	while (file1.read((char *)this, sizeof(initial_product)))
		count1 = pno;
	file1.close();
	return count1;
}

/* This function add_to_file() is used to create new/fresh record in the data file */
void initial::add_to_file(int t_accno, char t_name[30],int t_age,char t_email[50],char t_contnumber[20], float t_balance)
{
	accno = t_accno;
	strcpy(name, t_name);
	age= t_age;
	strcpy(email,t_email);
	strcpy(contnumber,t_contnumber);
	balance = t_balance;
	fstream file;
	// Appends new account record with the balance into CLIENT.dat data file
	file.open("CLIENT1.dat", ios::app);
	file.write((char *)this, sizeof(initial));
	file.close();
}

// Function for deleting a account from CLIENT.dat file
void initial::delete_account(int t_accno)
{
	fstream file;
	file.open("CLIENT1.dat", ios::in);
	fstream temp;
	temp.open("TEMP501.dat", ios::out);
	file.seekg(0,ios::beg);
	// Uses a copy method to delete the account from INTITAL.dat data file
	while (!file.eof())
	{
		file.read((char *)this, sizeof(initial));
		if (file.eof())
			break;
		if (accno != t_accno)
			temp.write((char *)this, sizeof(initial));
	}
	file.close();
	temp.close();
	file.open("CLIENT1.dat", ios::out);
	temp.open("TEMP501.dat", ios::in);
	temp.seekg(0, ios::beg);

	// Copy the TEMP50.dat contents into INTITAL.dat data file
	while (!temp.eof())
	{
		temp.read((char *)this, sizeof(initial));
		if (temp.eof())
			break;
		if (accno != t_accno)
			file.write((char *)this, sizeof(initial));
	}
	file.close();
	temp.close();
}

void initial_product::delete_product(int t_pno)
{
	fstream file1;
	file1.open("PRODUCT1001.dat", ios::in);
	fstream temp1;
	temp1.open("TEMP1001.dat", ios::out);
	file1.seekg(0,ios::beg);
	// Uses a copy method to delete the account from INTITAL.dat data file
	while (!file1.eof())
	{
		file1.read((char *)this, sizeof(initial_product));
		if (file1.eof())
			break;
		if (pno != t_pno)
			temp1.write((char *)this, sizeof(initial_product));
	}
	file1.close();
	temp1.close();
	file1.open("PRODUCT1001.dat", ios::out);
	temp1.open("TEMP1001.dat", ios::in);
	temp1.seekg(0, ios::beg);

	// Copy the TEMP50.dat contents into INTITAL.dat data file
	while (!temp1.eof())
	{
		temp1.read((char *)this, sizeof(initial_product));
		if (temp1.eof())
			break;
		if (pno != t_pno)
			file1.write((char *)this, sizeof(initial_product));
	}
	file1.close();
	temp1.close();
}


/* Function for displaying an account from "CLIENT.dat". */
void initial::display_list(void)
{
	closegraph();
	int gd11=DETECT,gm11;
	initgraph(&gd11,&gm11,"c:\\turboc3\\bgi");
	int flag;
	float t_bal;
	fstream file;
	gotoxy(25,2);
	cout << "Client Details";
	gotoxy(25, 3);
	cout << "==============";
	int d1, m1, y1;
	struct date d;		// For extracting system date
	getdate(&d);
	d1 = d.da_day;
	m1 = d.da_mon;
	y1 = d.da_year;
	gotoxy(62, 3);
	cout << "Date: " << d1 << "/" << m1 << "/" << y1;
	gotoxy(1, 4);
	for (int j = 1; j <= 79; j++)
		cout << "=";

	gotoxy(1, 5);
	cout << "Accno#";
	gotoxy(10,5);
	cout << "Name";
	gotoxy(30,5);
	cout<<"Age";
	gotoxy(35,5);
	cout<< "Email";
	gotoxy(62,5);
	cout<<"Mobile";
	gotoxy(75,5);
	cout << "Amount paid";
	gotoxy(1, 6);
	for (j = 1; j <= 79; j++)
		cout << "=";
	file.open("CLIENT1.dat", ios::in);
	file.seekg(0,ios::beg);
	int row = 7;
	// Reads all the records to display on the screen
	while (file.read((char *)this, sizeof(initial)));
	{
		flag = 0;
		delay(2);
		gotoxy(2, row);
		cout << accno;
		gotoxy(10, row);
		puts(name);
		gotoxy(30, row);
		cout<<age;
		gotoxy(35,row);
		puts(email);
		gotoxy(62,row);
		puts(contnumber);
		gotoxy(75,row);
		cout <<  setw(10)
			<< setprecision(2)
			<< setiosflags(ios::left)
			<< setiosflags(ios::showpoint)
			<< setiosflags(ios::fixed)
			<< balance;
		t_bal = t_bal + balance;
		row++;
		if (row > 23)
		{
			flag = 1;
			row = 6;
			gotoxy(4, 24);
			cout << "Press any key to continue.... ";
			getch();
			clrscr();
		}
	}
	gotoxy(1, row);
	for (j = 1; j <= 79; j++)
		cout << "=";
	row++;
	gotoxy(65, row);
	file.close();
	if (!flag)
	{
		gotoxy(4, 24);
		cout << "Press any key to continue...";
		getch();
	}
}
void initial_product::display_product(void)
{
	closegraph();
	int gd12=DETECT,gm12;
	initgraph(&gd12,&gm12,"c:\\turboc3\\bgi");
	int flag;
	//float t_bal = 0.0;
	ifstream file;
	gotoxy(25,2);
	cout << "Product Details";
	gotoxy(25, 3);
	cout << "===============";
	int d1, m1, y1;
	struct date d;		// For extracting system date
	getdate(&d);
	d1 = d.da_day;
	m1 = d.da_mon;
	y1 = d.da_year;
	gotoxy(62, 3);
	cout << "Date: " << d1 << "/" << m1 << "/" << y1;
	gotoxy(1, 4);
	for (int j = 1; j <= 79; j++)
		cout << "=";

	gotoxy(1, 5);
	cout << "Productno : ";
	gotoxy(15,5);
	cout << "Name : ";
	gotoxy(55,5);
	cout<<"Rate : ";
	gotoxy(65,5);
	cout<<"Tax : ";
	gotoxy(75,5);
	cout<<"Cost : ";
	gotoxy(1, 6);
	for (j = 1; j <= 79; j++)
		cout << "=";
	file.open("PRODUCT1001.dat", ios::in);
	file.seekg(0,ios::beg);
	int row = 7;
	// Reads all the records to display on the screen
	while (file.read((char *)this, sizeof(initial_product)))
	{
		flag = 0;
		delay(2);
		gotoxy(1, row);
		cout << pno;
		gotoxy(15, row);
		puts(name1);
		gotoxy(55, row);
		puts(rate);
		gotoxy(65, row);
		puts(tax);
		gotoxy(75,row);
		puts(amount);
		row++;
		if (row > 23)
		{
			flag = 1;
			row = 6;
			gotoxy(4, 24);
			cout << "Press any key to continue.... ";
			getch();
			clrscr();
		}
	}

	gotoxy(1, row);
	for (j = 1; j <= 79; j++)
	      {	cout << "=";  }
	row++;
		file.close();
	if (!flag)
	{
		gotoxy(4, 24);
		cout << "Press any key to continue...";
		getch();
	}
}

/* Function for clearing specified row and column. */
void account::clear(int col, int row)
{
	for (int j = col; j <= 79; j++)
	{
		gotoxy(j, row);
		cout << " ";
	}
}
void new_product::clear(int col, int row)
{
	for (int j = col; j <= 79; j++)
	{
		gotoxy(j, row);
		cout << " ";
	}
}

/* Function to found an account for display account function. */
int initial::found_account(int t_accno)
    {
	fstream file;
	file.open("CLIENT1.dat", ios::in);
	file.seekg(0, ios::beg);
	int found = 0;
	// Searches the specified record in CLIENT.dat data file
	while (file.read((char *)this, sizeof(initial)))
	{
		if (accno == t_accno)
		{
			found = 1;
			break;
		}
	}
	file.close();
	return found;
}
/* Function for creating new account for new customer. */
int initial_product::found_pno(int t_pno)
    {
	fstream file1;
	file1.open("PRODUCT1001.dat", ios::in);
	file1.seekg(0, ios::beg);
	int found1 = 0;
	// Searches the specified record in CLIENT.dat data file
	while (file1.read((char *)this, sizeof(initial_product)))
	{
		if (pno == t_pno)
		{
			found1 = 1;
			break;
		}
	}
	file1.close();
	return found1;
}

void account::new_account(void)
{
	closegraph();
	int gd13=DETECT,gm13;
	initgraph(&gd13,&gm13,"c:\\turboc3\\bgi");
	char ch;
	int i, valid;
	initial ini;
	gotoxy(3,3);
	for (i = 1; i<= 76; i++)
		cprintf(" ");
	gotoxy(30, 3);
	cprintf("Register New Client");
	int d1, m1, y1;
	struct date d;		// For extracting system date
	getdate(&d);
	d1 = d.da_day;
	m1 = d.da_mon;
	y1 = d.da_year;
	int t_accno;
	t_accno = ini.last_accno();
	t_accno++;
	// Appends and deletes a false record to create primary position in data files
	if (t_accno == 1)
	{
		ini.add_to_file(t_accno, "abc",0,"xyz","dsa", 1.1);
		ini.delete_account(t_accno);
		cout << "Press enter";
		getch();
	}
	char t_name[30], t[10], t_email[50],t_contnumber[30];
	float t_bal = 0.0, t_balance = 0.0;
	int t_age;
	gotoxy(5, 6);
	cout << "Date: " << d1 << '/' << m1 << '/' << y1;
	gotoxy(5, 8);
	cout << "Account No # " << t_accno;
	gotoxy(5, 10);
	cout << "Name : ";
	gotoxy(5, 12);
	cout<<"Age :";
	gotoxy(5,13);
	cout<<"Email :";
	gotoxy(5,15);
	cout<<"Mobile:";
	gotoxy(5,16);
	cout << "Amount Paid : ";
	do
	{
		clear(5, 23);
		gotoxy(5, 23);
		cout << "Enter Name of the Client";
		valid = 1;
		gotoxy(15, 10);
		gets(t_name);
		if (strlen(t_name) == 0 || strlen(t_name) > 25)
		{
			valid = 0;
			gotoxy(5, 23);
			cprintf("\7Name should not greater than 25");
			getch();
		}
	}while (!valid);

	do
	{
		clear(5, 23);
		gotoxy(5, 23);
		cout << "Enter age of the Client ";
		valid = 1;
		gotoxy(15, 12);
		cin>>t_age;
		if (t_age == 0)
		     {
			valid = 0;
			gotoxy(5, 23);
			cprintf("\7Should not be less than 1 year");
			getch();
		}
	}while (!valid);
       do
	{
		clear(5, 23);
		gotoxy(5, 23);
		cout << "Enter Email of the Client";
		valid = 1;
		gotoxy(15,13);
		gets(t_email);
		if (strlen(t_email) == 0 || strlen(t_email) >30)
		{
			valid = 0;
			gotoxy(5, 23);
			cprintf(" Blank or greater than 30 not allowed");
			getch();
		}
	}while (!valid);
	do
	{
		clear(5, 23);
		gotoxy(5, 23);
		cout << "Enter Mobile of the Client ";
		valid = 1;
		gotoxy(15,15);
		gets(t_contnumber);
		if (strlen(t_contnumber) == 0 || strlen(t_contnumber) > 10)
		{
			valid = 0;
			gotoxy(5, 23);
			cprintf("Should not blank or greater than 10");
			getch();
		}
	}while (!valid);
	do
	{
		clear(5, 23);
		gotoxy(5,23) ;
		cout << "Enter fees for the Beauty treatment: ";
		valid = 1;
		gotoxy(23, 16);
		gets(t);
		t_bal = atof(t);
		t_balance = t_bal;
		if (t[0] == '0')
		{
			valid = 0;
			gotoxy(5, 23);
			cprintf("Should not less than 100");
			getch();
		}
	}while (!valid);
	clear(5, 23);
	do
	{
		clear(5, 18);
		valid = 1;
		gotoxy(5, 18);
		cout << "Do you want to save the record <Y/N>: ";
		ch = getch();
		if (ch == '0')
			return;
		ch = toupper(ch);
	}while (ch != 'N' && ch != 'Y');
	if (ch == 'N')
		return;
	float t_amount;
	t_amount = t_balance;
	// Appends the records contents into both CLIENT.dat and BANKING.dat data files
	ini.add_to_file(t_accno, t_name,t_age,t_email,t_contnumber , t_balance);
}

/* Function for returning balance amount of an account. */
float initial::give_balance(int t_accno)
{
	fstream file;
	file.open("CLIENT1.dat", ios::in);
	file.seekg(0, ios::beg);
	float t_balance;
	// Gives the last balance of an individual account
	while (file.read((char *)this, sizeof(initial)))
	{
		if (accno == t_accno)
		{
			t_balance = balance;
			break;
		}
	}
	file.close();
	return t_balance;
}

/* Function for returning the record no. for updating balance */
int initial::recordno(int t_accno)
{
	fstream file;
	file.open("CLIENT1.dat", ios::in);
	file.seekg(0, ios::beg);
	int count = 0;
	// Finds the record position in CLIENT.dat data file
	while (file.read((char *)this, sizeof(initial)))
	{
		count++;
		if (t_accno == accno)
			break;
	}
	file.close();
	return count;
}
int initial_product::recordno1(int t_pno)
{
	fstream file1;
	file1.open("PRODUCT1001.dat", ios::in);
	file1.seekg(0, ios::beg);
	int count = 0;
	// Finds the record position in CLIENT.dat data file
	while (file1.read((char *)this, sizeof(initial)))
	{
		count++;
		if (t_pno == pno)
			break;
	}
	file1.close();
	return count;
}

/* Function for updating the balance for the given account no. */
void initial::update_balance(int t_accno, char t_name[30],int t_age,char t_email[50],char t_contnumber[30], float t_balance)
{
	int recno;
	recno = recordno(t_accno);
	fstream file;
	file.open("CLIENT1.dat", ios::out|ios::ate);
	strcpy(name, t_name);
	age=t_age;
	strcpy(email,t_email);
	strcpy(contnumber,t_contnumber);
	balance = t_balance;
	int location;
	location = (recno-1) * sizeof(initial); // Find the location in file
	file.seekp(location);	// Searches the insertion position in data file
	// Updates the balance amount in CLIENT.dat data file
	file.write((char *)this, sizeof(initial));
	file.close();
}
void initial_product::update_product(int t_pno, char t_name1[30], char t_rate[10],char t_tax[10],char t_amount[10])
{
	int recno1;
	recno1 = recordno1(t_pno);
	fstream file1;
	file1.open("PRODUCT1001.dat", ios::out|ios::ate);
	strcpy(name1, t_name1);
	strcpy(rate, t_rate);
	strcpy(tax,t_tax);
	strcpy(amount,t_amount);
	int location1;
	location1 = (recno1-1) * sizeof(initial_product); // Find the location in file
	file1.seekp(location1);	// Searches the insertion position in data file
	// Updates the balance amount in CLIENT.dat data file
	file1.write((char *)this, sizeof(initial_product));
	file1.close();
}

/* Function for closing any account after inputing account number. */
void account::close_account(void)
{
	closegraph();
	int gd14=DETECT,gm14;
	initgraph(&gd14,&gm14,"c:\\turboc3\\bgi");
	char t_acc[10];
	int t, t_accno;
	gotoxy(5, 5);
	cout << "Enter the account no. ";
	gets(t_acc);
	t = atoi(t_acc);
	t_accno = t;
	initial ini;
	if (!ini.found_account(t_accno))
	{
		closegraph();
		gotoxy(5, 5);
		cout << "Account not found ";
		getch();
		return;
	}
	gotoxy(3, 3);
	for (int i = 1; i <= 76; i++)
		cprintf(" ");
	gotoxy(30, 3);
	cprintf("Close account screen");
	int d1, m1, y1;
	struct date d;
	getdate(&d);
	d1 = d.da_day;
	m1 = d.da_mon;
	y1 = d.da_year;
	gotoxy(5, 6);
	cout << "Date: " << d1 << "/" << m1 << "/" << y1;
	char ch;
	ini. display(t_accno);
	do
	{
		clear(5, 15);
		gotoxy(5, 15);
		cout << "Close this  Client's account <y/n>? ";
		ch = getche();
		ch = toupper(ch);
	}while (ch != 'N' && ch != 'Y');
	if (ch == 'N')
		return;
	// Function calls to delete the existing account no.
	ini.delete_account(t_accno);
	gotoxy(5, 20);
	cout << "\7Account Deleted";
	gotoxy(5, 23);
	cout << "Press any key to continue...";
	getch();
}
void new_product::close_product(void)
{
	closegraph();
	int gd15=DETECT,gm15;
	initgraph(&gd15,&gm15,"c:\\turboc3\\bgi");
	char t_p[10];
	int t1, t_pno;
	gotoxy(5, 5);
	cout << "Enter the product no. ";
	gets(t_p);
	t1 = atoi(t_p);
	t_pno = t1;
	initial_product ini1;
	if (!ini1.found_pno(t_pno))
	{
		closegraph();
		gotoxy(5, 5);
		cout << "Product not found ";
		getch();
		return;
	}
	gotoxy(3, 3);
	for (int i = 1; i <= 76; i++)
		cprintf(" ");
	gotoxy(30, 3);
	cprintf("Close product screen");
	int d1, m1, y1;
	struct date d;
	getdate(&d);
	d1 = d.da_day;
	m1 = d.da_mon;
	y1 = d.da_year;
	gotoxy(5, 6);
	cout << "Date: " << d1 << "/" << m1 << "/" << y1;
	char ch1;
	ini1. display1(t_pno);
	do
	{
		clear(5, 15);
		gotoxy(5, 15);
		cout << "Delete this  Product <y/n>? ";
		ch1 = getche();
		ch1 = toupper(ch1);
	}while (ch1 != 'N' && ch1 != 'Y');
	if (ch1 == 'N')
		return;
	// Function calls to delete the existing account no.
	ini1.delete_product(t_pno);
	gotoxy(5, 20);
	cout << "\7Account Deleted";
	gotoxy(5, 23);
	cout << "Press any key to continue...";
	getch();
	}

void main()
{
 int gd16=DETECT,gm16;
 initgraph(&gd16,&gm16,"c:\\turboc3\\bgi");
 setbkcolor(0);
 delay(1000);
 setcolor(RED);
 settextstyle(1,0,10);
 outtextxy(65,85,"WELCOME"); delay(1000);
 setcolor(BLUE);
 settextstyle(3,0,8);
 outtextxy(260,195,"TO"); delay(1000);
 setcolor(WHITE);
 settextstyle(10,0,5);
 for(int i=-205;i<71;i++)
 {
  outtextxy(i,260,"A-ONE BEAUTY");
  delay(5); setcolor(BLACK);
  outtextxy(i,260,"A-ONE BEAUTY");
  delay(5); setcolor(WHITE);
 }
 outtextxy(70,260,"A-ONE BEAUTY");
 delay(100);
 i=1;
 setbkcolor(BLACK);
 do
 {
  settextstyle(10,0,5);
  setcolor(i+1);
  outtextxy(70,260,"A-ONE BEAUTY"); delay(100);
  i++;
 } while(i!=15);
 delay(1000); cleardevice();
 settextstyle(0,0,0);
 for(i=400;i>=0;i--) { setcolor(BLUE); circle(320,240,i); delay(1); }
 for(i=0;i<=400;i++) { setcolor(RED); circle(320,240,i); delay(1); }

 closegraph();
 x.main_menu();
 z.help();
 x.client_menu();
 y.product_menu();
 a.new_account();
 ini.display_list();
 x.edit_menu();
 c.register_product();
 n.display_product();
 n.edit_product();
 ini1.modify1();
 ini11.close_product();
 ini.modify();
 a.close_account();
 };




