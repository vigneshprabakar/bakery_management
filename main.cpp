#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
using namespace std;
class sales //class for holding sales data
{
	private:
	 char cus_name[20];
	 char  ph_no[10];
	 char  pur_date[10]; //date -dd/mm/yyyy
	 long int itemno;
	 int quantity;
	 char name[25];
	 float price;
	 float total;
  public:
	 void purchase(); //func to make new sale  item
	 void modify_cart(); //to modify the sale details  item
	 void remove_product(); // to delete any sale item
	 void bill(); // display
	 void cart();
	 void sales_history();
}s;

class inventory // class for holding inventory data
{
  private:
	  long int itemno;
	  int quantity;
	  char mdate[10], edate[10];
	  char item[25];
	  float price;
	  char name[25];
  public:
	  char * get_name()
	  {
		return name;
	  }
	  long int get_itemno()
	  {
		  return itemno;
	  }
	  void change_itemno(long int itno)
	  {
		  itemno = itno;
	  }

	  int get_quantity()
	  {
		  return quantity;
	  }
	  void change_quantity(int qty)
	  {
		  quantity = qty;
	  }
	  float get_price()
	  {
		  return price;
	  }
	  void create_item(); //func to create items
	  void modify_inv(); // make Changes to info regarding items
	  void delete_item(); //delete items
	  void display_inv(); // to view items in inventory
	  void search_foodnum(); //search based on item number
	  void search_foodname(); // based on food name

}inv;

void space(int s) //function to enhance output
{
	 int i;
	 for (i = 0; i <= s; i++)
	 {
		  cout << " ";
	 }
}

void header ()
{      system ("CLS");
cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
cout<<" ................................ LLOYDS BAKERY ............................... ";
cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
cout<<"\n";
}

void delay(	)				//time delay function
{
	for(long  i=0;i<350;i++)
	for(long  j=0;j<350;j++)
	for(long k=0;k<350;k++);
}

void intro()
{   system ("CLS");
 cout<<"/^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\\";
 cout << "|                                  _     _  _        _                         |";
cout << "|                            |  | |_ |  |  | | |\\/| |_                         |";
cout << "|                            |/\\| |_ |_ |_ |_| |  | |_                         |";
cout << "|                                     ___  _                                   |";
cout << "|                                      |  | |                                  |";
cout << "|                                      |  |_|                                  |";
cout << "|                                                                              |";
cout<<"|\t        db      db       .d88b.  db    db d8888b. .d8888.              |";
delay();
cout<<"|\t        88      88      .8P  Y8. `8b  d8' 88  `8D 88'  YP              |";
delay();
cout<<"|\t        88      88      88    88  `8bd8'  88   88 `8bo.                |";
delay();
cout<<"|\t        88      88      88    88    88    88   88   `Y8b.              |";
delay();
cout<<"|\t        88booo. 88booo. `8b  d8'    88    88  .8D db   8D              |";
delay();
cout<<"|\t        Y88888P Y88888P  `Y88P'     YP    Y8888D' `8888Y'              |";
cout << "|                                                                              |";
cout << "|                                                                              |";
cout<<"|                d8888b.  .d8b.  db   dD d88888b d8888b. db    db              |";
delay();
cout<<"|                88  `8D d8' `8b 88 ,8P' 88'     88  `8D `8b  d8'              |";
delay();
cout<<"|                88oooY' 88ooo88 88,8P   88ooooo 88oobY'  `8bd8'               |";
delay();
cout<<"|                88~~~b. 88~~~88 88`8b   88~~~~~ 88`8b      88                 |";
delay();
cout<<"|                88   8D 88   88 88 `88. 88.     88 `88.    88                 |";
delay();
cout<<"|                Y8888P' YP   YP YP   YD Y88888P 88   YD    YP                 |";
cout << "\\                                                                              /";
cout<<" ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ";
 

}

void homescreen();
void adminlogin(); //func for loging in
void adminscreen(); //func to display
void inventorymodule(); //contains inventory
void admin_salesmodule(); //contains sales, for admin
void user_salesmodule(); //for user


void inventory::create_item()
{
	 inventory i;
	 long itno = 0;
	 ifstream t("inventory.dat", ios::binary | ios:: in );
	 if (!t)
	  {
		  itno = 0;
	  }
	  else                                                   //to get current item number
	  {
		while (t.read((char * ) & i, sizeof(i)))
		itno = i.itemno;
	  }
	  t.close();

	 ofstream f;
	 char ans;

	 do
	  {
		  system ("CLS");
		  header();
		  f.open("inventory.dat", ios::binary | ios::out | ios::app);
		  if (!f)
			{
				cerr << "\n CANNOT OPEN";
				exit(1);
			}

		  itno++; //to increment to next item
		  inv.itemno = itno;
		  cout << "\n Item Number : ";
		  cout << inv.itemno;
		  cout << "\n\n";
		  space(20);
		  cout << "Enter the Item Name: ";
		  gets(inv.name);
	 repet:
		  space(30);
		  cout << "  Choose Item Type\n\n";
		  space(20);
		  cout << "1.Snacks\n\n";
		  space(20);
		  cout << "2.Pastry\n\n";
		  space(20);
		  cout << "3.Chocolates and Deserts\n\n";
		  space(20);
		  cout << "4.Cheese and Dairy\n\n";
		  space(30);
		  cout << "Enter Choice: ";
		  int choice = 0;
		  cin >> choice;

		  switch (choice)
		  {
		  case 1:
				strcpy(inv.item, "Snacks\0");
				break;

		  case 2:
				strcpy(inv.item, "Pastry\0");
				break;

		  case 3:
				strcpy(inv.item, "Chocolates and Desert\0");
				break;

   		  case 4:
				strcpy(inv.item, "Cheese and Diary\0");
				break;

		default:
				cout << "\n WRONG CHOICE!\n";
			
				goto repet;

		  }


		  cout << "\n";
		  space(20);
		  cout << "Enter the Price: ";
		  cin >> inv.price;
		  cout << "\n";
		  space(20);
		  cout << "Enter Quantity: ";
		  cin >> inv.quantity;
		  cout << "\n";
		  space(20);
		  cout << "Enter Manufacturing Date: ";
		  gets(inv.mdate);
		  cout << "\n";
		  space(20);
		  cout << "Enter Expiry Date: ";
		  gets(inv.edate);
		  f.write((char * ) & inv, sizeof(inv));
		  f.close();

		  cout << "\n DO YOU WANT TO CONTINUE? Y or N:";
		  cin >> ans;
	  }
		while (ans == 'y' || ans == 'Y');

}


void inventory::modify_inv() // func to modify existing items
{
	ifstream f;
	ofstream t;
	int flag, itno = -1;
	char response;
	do
	 {
		 header();
		 f.open("inventory.dat", ios::binary);
		 t.open("temp.dat", ios::binary);
		 if (!f || !t)
		  {
			  cerr << "\n CANNOT OPEN";
			  exit(1);
		  }
		 flag = 0, itno = -1;
		 inv.display_inv();
		 cout << "\n\t WHAT DO YOU WANT TO MODIFY ?";
		 cout << "\n\t1.Price";
		 cout << "\n\t2.Quantity";
		 cout << "\n\t\t Enter Your Choice:";
		 int c = 0;
		 cin >> c;
		 cout << "\n Enter Item Code To Be Modified ";
		 cin >> itno;

		 switch (c)
			{
			case 1:
				 float nprice;
				 while (f.read((char * ) & inv, sizeof(inv)))
				 {
					  if (itemno == itno)
					{
						cout << "\n\t Enter The New Price:\t";
						cin >> nprice;
						inv.price = nprice;
						t.write((char * ) & inv, sizeof(inv));
						space(20);
						cout << "\n\t\t\t\t Price updated!\n ";
						flag = 1;
					 }
					  else
					{
						t.write((char * ) & inv, sizeof(inv));
					}
				 }
				 if (flag == 0)
				 cout << "\n \t\t\t\tITEM DOES NOT EXIST! \a";
				 break;
			case 2:
				 int nquantity;
				 while (f.read((char * ) & inv, sizeof(inv)))

				  {
					  if (itemno == itno)
					{
						cout << "\n\t Enter The New Quantity:\t";
						cin >> nquantity;
						inv.quantity = nquantity;
						t.write((char * ) & inv, sizeof(inv));
						space(20);
						cout << "\n\t\t\t\t QUANTITY UPDATED!\n ";
						flag = 1;
					 }
					  else
					{
						t.write((char * ) & inv, sizeof(inv));
					}
				  }
				 if (flag == 0)
				  cout << "\n\t\t\t\t ITEM DOES NOT EXIST! \a ";
				 break;

		default:
			  cout << "\n\t\t\t\t INVALID CHOICE!!! \a\a";

		}
		cout << "\n DO YOU WANT TO CONTINUE?";
		cin >> response;
		f.close();
		t.close();
		remove("inventory.dat");
		rename("temp.dat", "inventory.dat");
 }
			while (response == 'y' || response == 'Y');

}



void inventory::delete_item() // delete func for inventory

{    int flag;
	  char ch;
	  int id;
	  ifstream f;
	  ofstream r;

		do
		{
			header();
			inv.display_inv();
			flag = 0;
			cout << "\n\n Enter The Item Number Of The Item You Want To Delete : ";
			cin >> id;
			f.open("inventory.dat", ios:: in | ios::binary);
			r.open("temp.dat", ios::out | ios::binary);
			if (!f || !r)
			 { cerr << "\n CANNOT OPEN FILE";
				exit(1);
			 }

			while (f.read((char * ) & inv, sizeof(inv)))
			 {
				  if (itemno == id)
				  {
					  flag = 1;
				  }
				  else
					 r.write((char * ) & inv, sizeof(inv));
			 }
			 f.close();
			 r.close();
			 remove("inventory.dat");
			 rename("temp.dat", "inventory.dat");
			 if (flag)
			 cout << "\n ITEM REMOVED\n";
			 else
			 cout << "\n \t\tITEM DOES NOT EXIST\n";
			 cout << "\t\tDO YOU WANT TO DELETE ANOTHER ITEM?(Y/N)";
			 cin >> ch;
		}
		  while (ch == 'y' || ch == 'Y');

}


void inventory::display_inv() // to display all items

{
	  header();
	  ifstream f;
	  f.open("inventory.dat", ios::binary);
	  if (!f)
		{
		  cout << "\n\n\n\n\n\n";
		  space(25);
		  cout << " INVENTORY EMPTY !!!\a\a";
		  goto end;
		}

		space(34);
		cout << " Products  " << '\n';
		space(35);
		cout << "========\n";
		while (f.read((char * ) & inv, sizeof(inv)))
		{
		cout << "--------------------------------------------------------------------------------\n";
			cout << "  Item no. " << itemno;
			space(5);
			cout << "Name: " << name;
			space(10);
			cout << "Price: " << price << '\n';
			space(55);
			cout << "Stock Left: " << quantity << '\n';
			space(7);
			cout << "Item Type          : " << item<< '\n';
			space(7);
			cout << "Date Of Manufacture:" << mdate << "\n";
			space(7);
			cout << "Date Of Expiry     :" << edate << "\n\n";
		}

		cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
 end:
		f.close();

}

void inventory::search_foodnum() // search inventory items with item number

{
	 fstream f;
	 char choice = 'n';
	 int flag = 0;
	 int food_num;

	 do
	  
   {  header();
	        cout << "\n Enter The Food Number To Be Searched For:\n";
	       cin >> food_num;
	       f.open("inventory.dat", ios:: in | ios::binary);
	         if (!f)
		{
		cerr << "\n FILE NOT EXISTING !!! \a";
		exit(1);
		}
		else
		{
			while (!f.eof())
			 {
				 f.read((char * ) & inv, sizeof(inv));
				 if (itemno == food_num)
				  {
					  cout << "\n ITEM DETAILS ARE:";
  			cout <<"\n===================================================";
			  space(32);
			  cout << " Item Number: " << itemno << '\n';
			  cout << "====================================================";
			  space(10);
			  cout << "Name Of The Item: " << name << '\n';
			  space(10);
			  cout << "Item: " << item << '\n';
			  space(10);
			  cout << "Price: " << price << '\n';
			  space(10);
			  cout << "Quantity: " << quantity << '\n';
			  space(10);
			 cout << "Date Of Manufacture: " << " " << mdate << '\n';
			  space(10);
			  cout << "Date Of Expiry     : " << " " << edate << '\n';
			  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			  flag = 1;
			  break;
			  }
		      }
		f.close();
		if (flag == 0)
		 cout << "\n\n\n\t\t\a ITEM NOT FOUND.";
		cout << "\n\t Do You Want To Search More Item?(Y:N)or(y:n)";
		cin >> choice;
		}

             }
	while (choice == 'y' || choice == 'Y');

}

void inventory::search_foodname()                           // search inventory with food name
{

	ifstream f;
	int flag;
	char food_name[20], choice = 'n';
	do
		 {  header();
		 cout << "\n Enter The Food Name To Be Searched For:";
		 gets(food_name);
		 f.open("inventory.dat", ios::binary);
		 if (!f)
		  {
			  cerr << "\n File Not Existing !!! \a";
			  exit(1);
		  }


		 else
		  {
			  flag = 0;
			  while (!f.eof())
			{
				 f.read((char * ) & inv, sizeof(inv));
				int res = std::strncmp(food_name, name,4);
				 if (res == 0)
				 {
					 cout << "\n ITEM DETAILS ARE:";
				 cout << "\n=============================================";
					 space(32);
					 cout << " Item Number: " << itemno << '\n';
				 cout << "==============================================";
					 space(10);
					 cout << "Name Of The Item: " << name << '\n';
					 space(10);
					 cout << "Item: " << item << '\n';
					 space(10);
					 cout << "Price: " << price << '\n';
					 space(10);
					 cout << "Quantity: " << quantity << '\n';
					 space(10);
					 cout << "Date Of Manufacture: " << " " << mdate << '\n';
					 space(10);
					 cout << "Date Of Expiry     : " << " " << edate << '\n';
				 cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					 flag = 1;
					 break;
				 }
			}
			f.close();
			if (flag == 0)
			  cout << "\n \n\t\t\tITEM NOT FOUND.";
			cout << "\n \tDo You Want To Search More Item?(Y:N)or(y:n)";
			cin >> choice;
			  }
		}
		  while (choice == 'y' || choice == 'Y');
}


void sales::purchase()
{
	ifstream sale;
	sale.open("sales.dat", ios::binary | ios:: in ); //to check customers first information
	if (!sale)
	 {
		 header();
		 cout << "\n\n\t Enter Your Name: ";
		 gets(s.cus_name);
		 cout << "\n \t Enter Phone Number: ";
		 gets(s.ph_no);
	  }
	  sale.close();
	header();
	ifstream invI;
	ofstream invO, saleO;
	char ch;
	int qty, flag, q;
	long int fitno;  // food item number
	do
	 {
		  qty = 0, flag = 0, q = 0;
		  invI.open("inventory.dat", ios::binary | ios:: in );
		  invO.open("tempinv.dat", ios::binary | ios::out);
		  saleO.open("sales.dat", ios::binary | ios::out | ios::app);
		  if (!invI || !invO || !saleO)
		  {
			  cout << " CANNOT OPEN";
			  exit(1);
		  }
		 menu:
			header();
		  inv.display_inv();
		  cout << "\n Enter The Item Number Of Food Product: ";
		  cin >> fitno;
		  while (invI.read((char * ) & inv, sizeof(inv)))
		  {
			if (fitno == inv.get_itemno())
			{
				cout << "\n Enter The Quantity Of " << inv.get_name() << " : ";
				cin >> qty;
				while(qty>inv.get_quantity())
				{
				cout<<"\n\t SORRY ! ONLY "<<inv.get_quantity()<<" AVAILABLE";
				cout<< "\n  Enter The Quantity again : ";
				cin>>qty;
				}
				q = inv.get_quantity() - qty;
				inv.change_quantity(q);
				itemno = fitno;
				strcpy(name, inv.get_name());
				price = inv.get_price();
				quantity = qty;
				saleO.write((char * ) & s, sizeof(s));
				flag = 1;
			}
			invO.write((char * ) & inv, sizeof(inv));
		 }
		 if (flag == 0)
		 cout << "\n ITEM IS NOT AVAILABLE!";

		 else
		  {
			  cout << "\n ADDED SUCCESSFULLY!\n";
		}

		 invI.close();
		 invO.close();
		 saleO.close();
		 remove("inventory.dat");
		 rename("tempinv.dat", "inventory.dat");
		 cout << "\n DO YOU WANT TO ADD MORE ITEMS?";
		 cin >> ch;
	 }
	  while (ch == 'Y' || ch == 'y');
}


void sales::modify_cart()
{
 system ("CLS");
	 int flag, qty;
	  ifstream f, i2;
	  ofstream t, i1;
	  i1.open("tempory.dat", ios::binary | ios::app | ios::out);
 	  i2.open("inventory.dat", ios::binary | ios:: in );
	  f.open("sales.dat", ios::binary | ios:: in );
	  t.open("temp.dat", ios::binary | ios::app | ios::out);
	  if (!f || !t || !i1 || !i2)
	{
		cerr << "\n CANNOT OPEN";
		exit(1);
	 }
	 flag = 0, qty = 0;
	 s.cart();
	 cout << "\n";
	 long int itno;
	 cout << "\n Enter Item Number Of The Product: ";
	 cin >> itno;
	 int nquantity;
	 while (f.read((char * ) & s, sizeof(s)))
	  {
		  if (s.itemno == itno)
		  {
			  cout << "\n Enter The New Quantity\t  : ";
			  cin >> nquantity;
			  while (i2.read((char * ) & inv, sizeof(inv)))
			{
				if (inv.get_itemno() == itno)
				 {
					qty = inv.get_quantity() + s.quantity;

					while(nquantity>qty)
					{
						cout<<"\n\t SORRY ! ONLY "<<qty<<" AVAILABLE";
						cout<< "\n  Enter The Quantity again : ";
						cin>>nquantity;
					}
					  qty = qty-nquantity;
					  inv.change_quantity(qty);
					i1.write((char * ) & inv, sizeof(inv));
					s.quantity = nquantity;
				 }
				else
				  i1.write((char * ) & inv, sizeof(inv));
			}
			t.write((char * ) & s, sizeof(s));
			cout << "\n QUANTITY CHANGED ! ";
			flag = 1;
		}
		 else
		  {
			  t.write((char * ) & s, sizeof(s));
		  }
	}
	if (flag == 0)
	cout << "\n INCORRECT ITEM NUMBER";
	if(flag==1)
	{
		remove("inventory.dat");
		rename("tempory.dat", "inventory.dat");
	}
	i1.close();
	i2.close();
	f.close();
	t.close();
	
	remove("sales.dat");
	rename("temp.dat", "sales.dat");
}

void sales::remove_product() //to delete sales item
{
	 header();
	 int flag;
	 char ch;
	 int id;
	 int q;
	 ifstream i1, s1;
	 ofstream i2, s2;



	 do
	  {
		  flag = 0;
		  q = 0;
		  i1.open("inventory.dat", ios::binary);
		  s1.open("sales.dat", ios::binary);
		  i2.open("tempinv.dat", ios::binary);
		  s2.open("tempsale.dat", ios::binary);
		  if (!i1 || !i2 || !s1 || !s2)
			{
				 cerr << "\n CANNOT OPEN FILE";
				 exit(1);
			}
			s.cart();
		  cout << "\n enter the item number of the item you want to delete";
		  cin >> id;

		  while (s1.read((char * ) & s, sizeof(s)))
			{
				if (id == itemno)
				{
					flag = 1;
					while (i1.read((char * ) & inv, sizeof(inv)))
					{
						 if (inv.get_itemno() == id)
						  {
							  q = inv.get_quantity() + quantity;
							  inv.change_quantity(q);
							  i2.write((char * ) & inv, sizeof(inv));
						  }
						else
						  i2.write((char * ) & inv, sizeof(inv));
					}
					  remove("inventory.dat");
					  rename("tempinv.dat", "inventory.dat");

				}
				 else

				s2.write((char * ) & s, sizeof(s));
			}

			if (flag == 1)
			{
			  cout << "\n ITEM REMOVED\n";
			  remove("sales.dat");
			  rename("tempsale.dat", "sales.dat");
			}
			else
			 {
				 cout << "\n ITEM DOES NOT EXIST\n";
				 remove("tempsale.dat");
				 remove("tempinv.dat");
			  }
			 i1.close();
			 i2.close();
			 s1.close();
			 s2.close();
			 cout << "DO YOU WANT TO REMOVE ANOTHER ITEM?(Y/N)";
			 cin >> ch;

	  }
		while (ch == 'y' || ch == 'Y');
}



void sales::cart()
{
	 header();
	 int i = 1;
	 ifstream c;
	 c.open("sales.dat", ios::binary | ios:: in );
	 if (!c)
	  {
		 cout << "\n cart empty !!!\a";
		 goto end;
	  }
	 cout << "\n";
	 space(33);
	 cout << "CART DETAILS \n";
	 space(33);
	 cout << "==== ======= \n";
	 while (c.read((char * ) & s, sizeof(s)))
	  {
		  cout << i;
		  cout << "]\n";
		  i++;
		  space(3);
		  cout << "Item Number: " << itemno;
		  space(7);
		  cout << "Item Name         : " << name << '\n';
		  space(25);
		  cout << "Quantity Purchased: " << quantity << "\n\n";
	  }

	end:

	  c.close();

}



void sales::bill()
{
	  header();
	  int i = 1;
	  float tol=0;
	  ifstream f;
	  ofstream s_his;
	  cout<<" Enter Today\'s Date [dd/mm/yyyy] : ";
	  gets (s.pur_date);

	  f.open("sales.dat", ios::binary | ios:: in );
	  s_his.open("sales_history.dat",ios::binary|ios::out|ios::app);
	  if(!s_his)
	  {
			cerr<<"\t CANNOT OPEN";
			exit(1);
		}
	  if (!f)
		{
			cout << "\n NO PRODUCTS ADDED TO CART!\a";
			goto end;
		}


	 header();
 space(30);
	  cout << "BILL DETAILS \n";
	  space(10);
	  cout << "name: " << s.cus_name<<'\n';
	  space(10);
	  cout << "Phone Number: "; puts( s.ph_no);
	  space(10);
	  cout << "Date Of Purchase: " ;puts(s.pur_date); cout<< '\n';
	  while (f.read((char * ) & s, sizeof(s)))
	  {
			space(5);
			cout << i;
			cout << "]";
			i++;
			space(2);
			cout << "Item Name         : " << s.name << '\n';
			space(10);
			cout << "Quantity Purchase : " << s.quantity << '\n';
			space(10);
			cout << "Price Of Each Item: " << s.price << '\n';
			space(45);
			cout << " Subtotal :" << quantity * price << '\n';
			cout << "\n\n\a";
			tol+=(quantity * price );
			s_his.write((char * )&s,sizeof(s));
		}
		cout << "\n\n\a";
		space(50);
		s.total=tol;
		cout << " TOTAL AMOUNT :" << s.total;
		cout << "\n\n\a";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		space(20);
		cout << "THANK YOU FOR SHOPPING WITH US!!!\n";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		remove("sales.dat");
	  end:
	
		f.close();
		s.total = 0;

}

void sales::sales_history()
{  header();
	float grand_tol=0;
	ifstream log("sales_history.dat",ios::binary|ios::in);
	 if(!log)
	 {
		cerr<<"\n File Not Existing !!!\a";
	 }
	 else
	 {   	int flag=0;
		space(30);
		cout<<"   SALES HISTORY\n ";
		space(30);
		cout<<"  ===== ======= ";
		char n[25] = "\0";

		while(log.read((char*)&s,sizeof(s)))
		{
			 if (strcmp(n,s.cus_name) != 0)
			{
				strcpy(n, s.cus_name);
				cout << "\n";
				cout << "-----------------------------------------------------------------------------";
				cout << " Customer Name: " << s.cus_name << "\n\n";
			 }
			cout << '\n';
			space(3);
			cout << "Item Number:" << s.itemno;
			space(10);
			cout << "Product Name : " << s.name;
			cout << '\n';
			space(26);
			cout << " Quantity     : " << s.quantity;
			cout << '\n';
			grand_tol+=s.quantity*s.price;
		}
		cout << "--------------------------------------------------------------------------------";
		cout<<"\n\n \t\t\t\t Total Sales  : "<<grand_tol;
		log.close();
 }
	
}



 int main()																					 //function main
{
		intro();
		homescreen();

}



void homescreen()

 {   home:
		 header();
		 cout << "\n\n\n";
		 space(15);
		 cout << "\t LOGIN AS :";
		 cout << "\n\n";
		 space(20);
		 cout << "1. Admin \n\n";
		 space(20);
		 cout << "2. User \n\n";
		 space(20);
		 cout << "3. Exit\n\n";
		 space(25);
		 cout << " Enter Your Option: ";
		 int op = 0;     //option
		 cin >> op;

		 switch (op)
		 {
		  case 1:
			  adminlogin();
			  goto home;

		  case 2:
			  user_salesmodule();
			  goto home;

		  case 3:   header();
			cout<<"\n\n\n\a\a";
			cout<<"\t\tProject Done By -\n";
			cout<<"\t\t \tChinmay Nambiar \n";
			  exit(0);

		  default:
			  cout << "\n";
			  space(2);
			  cout << "THAT IS AN INVALID OPTION, PLEASE ENTER IT AGAIN";
			  cout << "\n\n";
			  space(15);
			  cout << "(Press Any Key to Continue)";
			 
			  goto home;

		  }

}



void adminlogin() 				// password   ( lloydsbake )

{   int y = 0;

	 for (y = 0; y < 3; y++)
	  {  system ("CLS");
		header();
		space(32);
		cout << "ADMIN LOGIN \n";

		cout << "\n\n\n\n\t Enter Password(10 characters) : ";
		int i = -1;
		char pass[10];

		do
			{
				i++;
				pass[i] = getchar();
				if (i != 10 && pass[i] != '\b' && pass[i] != '\n')
				 {
					cout << '*';
				 }
				else if (pass[i] == '\b')
				 {
					cout << '\b';
					i -= 2;
				 }

				if (i == 10)
					 pass[i] = '\0';
			}
			 while (pass[i] != '\n' && i < 10);
           int res1= strncmp(pass, "lloydsbake",4);
			if ( res1 == 0)
			{
				for (int a = 0; a < 1; a++)
				cout<<"\n\n\n";
				space(25);
				cout << "LOGIN SUCESSFULL !!";
				getchar();
				adminscreen();
			 }
			 else
			 {
				cout << "\n\n\n\t\tINCORRECT PASSWORD!";
				cout << "\n\t\t\t(Enter Any Key to Try Again)\n\n";
				getchar();
			 }

		}
		 header();
		  cout << "\n\n\n\n\n";
		 space(28);
		 cout << "UNSUCESSFULL LOGIN\n\a\a";
		 space(28);
		 cout << "EXITING...";
       exit(0);

}



void adminscreen()

{    admin:
		 header();
		 cout << "\n\n\n";
		 space(20);
		 cout << " WHAT DO YOU WANT TO ACCESS\n\n\n";
		 space(20);
		 cout << "1. Inventory Module\n\n";
		 space(20);
		 cout << "2. Sales Module\n\n";
		 space(20);
		 cout << "3. Exit\n\n";
		 space(20);
		 cout << "   Enter Your Choice: ";
		 int op = 0;
		 cin >> op;

		 switch (op)
			{
			 case 1:
				  inventorymodule();
				  getchar();
				  break;
			 case 2:
				  admin_salesmodule(); //sales module function
				  break;

			 case 3:
				  homescreen();

			 default:
				  cout << "\n";
				  space(2);
				  cout << "THAT IS AN INVALID OPTION, PLEASE ENTER IT AGAIN";
				  cout << "\n\n";
				  space(15);
				  cout << "(Press Any Key to Continue)";
				  getchar();
				  goto admin;
			}

}



void inventorymodule()

 {    inventory: //name for goto
		int op;
		     system ("CLS");

		header();

		space(32);
		cout << "INVENTORY \n\n\n";
		space(25);
		cout << "WHAT DO YOU WANT TO DO?\n\n";
		space(20);
		cout << "1.Create Food Item\n\n";
		space(20);
		cout << "2.Modify Food Item\n\n";
		space(20);
		cout << "3.Delete Food Item\n\n";
		space(20);
		cout << "4.Search Item by Food Number\n\n";
		space(20);
		cout << "5.Search Item by Food Name\n\n";
		space(20);
		cout << "6.View All Items\n\n";
		space(20);
		cout << "7. Exit ";
		cout << "\n\n";
		space(25);
		cout << "Enter Your Option: ";
		cin >> op;

		switch (op)
		 {
			  case 1:
				  inv.create_item();
				  goto inventory;

			  case 2:
				  inv.modify_inv();
				  goto inventory;

			  case 3:
				  inv.delete_item(); //delete food item function
				  goto inventory;

			  case 4:
				  inv.search_foodnum(); //search on food no function
				  goto inventory;

			  case 5:
				  inv.search_foodname(); //search on food name function
				  goto inventory;

			 case 6:
				  inv.display_inv();
				  getchar();
				  goto inventory;

			 case 7:
				  adminscreen();

			 default:
				  cout << "\n";
				  space(2);
				  cout << "THAT IS AN INVALID OPTION, PLEASE ENTER IT AGAIN";
				  cout << "\n\n";
				  space(15);
				  cout << "(Press Any Key to Continue)";
				  getchar();
				  goto inventory;

		 }

}



void admin_salesmodule()

 {
		admin_s: // name for goto
		     system ("CLS");

		header();

		space(30);
		cout << " SALES MODULE\n\n\n";
		space(25);
		cout << " 1. Create Sales \n\n";
		space(25);
		cout << " 2. Modify Sales \n\n";
		space(25);
		cout << " 3. Delete Sales\n\n";
		space(25);
		cout << " 4. View Cart \n\n";
		space(25);
		cout << " 5. Print Bill\n\n";
		space(25);
		cout << " 6. Sales History\n\n";
		space(25);
		cout << " 7. Exit\n\n\n";
		space(20);
		cout << " Enter Your Choice: ";
		int ch = 0;
		cin >> ch;
		 switch (ch)
		 {
			 case 1:
				s.purchase(); //create function
				goto admin_s;

			 case 2:
				s.modify_cart(); //modify function
				goto admin_s;

			 case 3:
				s.remove_product();
				goto admin_s;

			 case 4:
				s.cart();
				getchar();
				goto admin_s;



			 case 5:
				  s.bill();
				  goto admin_s;


			 case 6:
				s.sales_history();
				 goto admin_s;

			 case 7:
				  adminscreen();

			 default:
				  cout << "\n";
				  space(2);
				  cout << "THAT IS AN INVALID OPTION, PLEASE ENTER IT AGAIN";
				  cout << "\n\n";
				  space(15);
				  cout << "(Press Any Key to Continue)";
				  getchar();
				  admin_salesmodule();
				  break;

		  }

}



void user_salesmodule()

{    user_s:                      // goto name
		header();
		cout << "\n\n";
		space(25);
		cout << "1. Buy Products \n\n";
		 space(25);
		 cout << "2. Modify Purchase \n\n";
		 space(25);
		 cout << "3. View Cart \n\n";
		 space(25);
		 cout << "4. Print Bill \n\n\n";
		 space(20);
		 cout << " Enter Your Choice: ";
		 int ch = 0;
		 cin >> ch;
		 switch (ch)
		 {
			case 1:
				 s.purchase(); //create function
				 goto user_s;

			case 2:
				  s.modify_cart(); //modify function
				  goto user_s;

			case 3:
				  s.cart();
				  getchar();
				  goto user_s;

			case 4:
				  s.bill();
				  exit(0);

			 default:
				  cout << "\n";
				  space(2);
				  cout << "THAT IS AN INVALID OPTION, PLEASE ENTER IT AGAIN";
				  cout << "\n\n";
				  space(15);
				  cout << "(Press Any Key to Continue)";
				  getchar();
				  user_salesmodule();
				  break;

		 }

}
