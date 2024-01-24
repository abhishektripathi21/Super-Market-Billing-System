#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include <unistd.h>
using namespace std;

COORD coord = {0, 0};
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class customer{
	public:
		//int bill_no;
		string name[10];
		long long contact[10];
	
		void Register(int a)
		{
			cout<<"Enter Customer Name :";
			cin>>name[a];
			cout<<"Enter Customer Phone Number :";
			cin>>contact[a];
			cout<<"\npress any key to proceed";
			getch();
		}
		void display(int a)
		{
			cout<<"\n\n\tCustomer Name : "<<name[a]<<endl;
			cout<<"\tCustomer Phone no. : "<<contact[a]<<endl;
		}
};


class item
{
	string item_name[10][10];
	int quantity[10][10], price[10][10],subtotal,total,discount;

	public:
		void in_detail(int a,int b);
		void sub_total(int a,int b);
		void cal_discount();
		void cal_total();
		void print_bill(int a , int b);
		void remove_item(int a, int b);
};
void item :: in_detail(int a,int b)
{
		system("cls");
		cout<<"Enter name of Item : ";
		cin>>item_name[a][b];
		cout<<"Enter price of Item : ";
		cin>>quantity[a][b];
		cout<<"Enter Quantity of Item : ";
		cin>>price[a][b];
}
void item :: sub_total(int a,int b)
{
	subtotal=0;
	for(int i =0;i<=b;i++)
	{
		subtotal = subtotal + (quantity[a][i] * price[a][i]);
	}
}
void item :: cal_discount()
{
	
	if (1000 <= subtotal && subtotal < 2500)
	{
		discount = 3; 
	}
	else if (2500 <= subtotal)
	{
		discount = 5;
	}
	else
	{
		discount = 0;
	}
}
void item :: cal_total()
{
	total = subtotal - (subtotal * discount / 100);
}

void item :: print_bill(int a , int b)
{
	gotoxy(0,0);
	cout<<"\t\t\tBill Number "<<a+1;
	gotoxy(5,10);
	cout<<"Item No";
	gotoxy(20,10);
	cout<<"Item Name";
	gotoxy(35,10);
	cout<<"Price";
	gotoxy(50,10);
	cout<<"Quantity";
	gotoxy(65,10);
	cout<<"Net Amount";
	int c=0;
	for(int i=0;i<=b;i++)
	{
		gotoxy(5,12+c);
		cout<<i+1;
		gotoxy(20,12+c);
		cout<<item_name[a][i];
		gotoxy(35,12+c);
		cout<<quantity[a][i];
		gotoxy(50,12+c);
		cout<<price[a][i];
		gotoxy(65,12+c);
		cout<<quantity[a][i] * price[a][i];
		c += 2;
	}
	gotoxy(30,12+c);
	cout<<"Subtotal is         : "<<subtotal;
	gotoxy(30,13+c);
	cout<<"Discount percent is : "<<discount;
	gotoxy(30,14+c);
	cout<<"Total is : "<<total;
	getch();
}
void item :: remove_item(int a, int b)
{
	item_name[a][b]="-----";
	price[a][b]=0;
	quantity[a][b]=0;
	cout<<"\nItem Deleted Sucessfully ";
}

int main()
{
	string username="";
	string password="";
	bool loginsuccess = false;	
	do
	{
		system("cls");
		cout<<"\n\n\n\t\t\tWelcome! Please Login Below";
		cout<<"\n\t\t\t---------------------------";
		gotoxy(25,8);
		cout<<"Enter Username  : ";
		cin>>username;
		gotoxy(25,10);
		cout<<"Enter Password  : ";
		cin>>password;
		if( username == "admin" && password == "password" )
		{
			cout<<"\n\n\n\t\t\t\t\tLogin Successful...";
			loginsuccess = true ;
			sleep(2);
		}
		else
		{
			cout<<"\n\n\n\t\t\t\t\tAccess Denied.....Try Again...";
			sleep(2);
		}
	}while(!loginsuccess);
	
	int m[10];
	int bill_no=0;
	int count1 = 0;
	int count2 = 0;
	customer cust;
	item itm;
	int choice;
menu:
	system("cls");
    cout<<"\n\t\t\tSuper Market Billing "<<endl;
    cout<<"\t\t     ===========================\n\n";
    cout<<"\n\t\t\t1.Create new bill\n\n";
    cout<<"\t\t\t2.Display bill\n\n";
    cout<<"\t\t\t3.Edit bill\n\n";
    cout<<"\t\t\t4.Exit\n\n";
    cout<<"\n\t\t\tEnter choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1 :
				system("cls");
				cout<<"\t\tadd new bill (Bill no."<<count1+1<<" )"<<endl;
				cout<<"\t     ===========================\n\n";
				cust.Register(count1);
				count2 = 0;
				m[count1]=0;
			a:	
				system("cls");
				cout<<"\n1.Add Items\n";
    			cout<<"2.Genrate bill\n";
    			cout<<"3.Return to main menu"<<endl;
    			cout<<"Enter choice : ";
    			cin>>choice;
    			
				if(choice == 1)
    			{
    				m[count1]++;
    				itm.in_detail(count1,count2);
    				count2++;
				}
				else if(choice == 2)
				{
					system("cls");
					cust.display(count1);
					//cout<<"\n\n\n";
					itm.sub_total(count1,count2-1);
					itm.cal_discount();
					itm.cal_total();
					itm.print_bill(count1 , m[count1]-1);
					
				}
				else if(choice==3)
				{
					m[count1]--;
					count1++;
					goto menu;
				}
				else
				{
					cout<<"\n\nWrong Input.....Try Again.....";
					sleep(2);
				}
				goto a;
			break;
		case 2 : 
			system("cls");
			for(int i =0;i < count1 ; i++)
   			{
				cout<<"\nBill Number : "<<i+1<<endl;
    			cust.display(i);
				cout<<endl;
			}
			cout<<"Enter the bill number to print : ";
			cin>>bill_no;
			//count2=0;
			if((bill_no-1)>=0 && (bill_no-1)<count1)
			{
				system("cls");
				cust.display(bill_no-1);
				cout<<"\n\n\n";
				itm.sub_total(bill_no-1,m[bill_no-1]);
				itm.cal_discount();
				itm.cal_total();
				itm.print_bill(bill_no-1,m[bill_no-1]);
			}
			else
			{
				cout<<"\nBill Does Not exists Try Again";
				cout<<"\nRedircting to the main menu .......";
				sleep(3);
				goto menu;
			}
			
			break;
			
			
		case 3 :
			b:
				system("cls");
				cout<<"\t\tEDIT Bill"<<endl;
				cout<<"\t     ===========================\n\n";
				for(int i =0;i < count1 ; i++)
    			{
    				cout<<"\nBill Number : "<<i+1<<endl;
    				cust.display(i);
    				cout<<endl;
				}
				cout<<"\nEnter Bill number to edit : ";
				cin>>bill_no;

				if((bill_no-1)>=0 && (bill_no-1)<count1)
				{
					system("cls");
					count2 = 0;
					cust.display(bill_no-1);
					cout<<"\n\n1.Edit Customer Details"<<endl;
					cout<<"2.Edit Items"<<endl;
					cout<<"3.Add Items"<<endl;
					cout<<"4.Remove Items"<<endl;
					cout<<"5.Return to main menu  "<<endl;
					cout<<"\n\nEnter Your Choice : ";
					cin>>choice;
					if(choice == 1)
    				{
    					cust.Register(bill_no-1);
					}
					else if(choice == 2 || choice == 3 || choice == 4)
					{
					  e:
						system("cls");
						itm.sub_total(bill_no-1,m[bill_no-1]);
						itm.cal_discount();
						itm.cal_total();
						itm.print_bill(bill_no-1,m[bill_no-1]);
				
						if(choice==2)
						{
							cout<<"\nEnter Item Number to edit : ";
							cin>>count2;
							if(count2-1>=0 && count2-1 <= m[bill_no-1])
							{
								itm.in_detail(bill_no-1,count2-1);
								cout<<"\nItem Updated Successfully \n";
								cout<<"\n1.Edit more items  ";
								cout<<"\n2.Return to main menu ";
								cout<<"\nEnter choice : ";
								cin>>choice;
								if(choice==1)
								{
									goto e;
								}
								else if(choice == 2)
								{
									goto menu;
								}
								else
								{
									cout<<"Wrong Input";
									cout<<"\nRedircting to the Edit Items menu .......";
									sleep(3);
									goto b;
								}
							}
							else
							{
								cout<<"Item Number Does not exists";
								cout<<"\nRedircting to the main menu .......";
								sleep(3);
								goto menu;
							}
						}
						else if( choice == 3)
						{
						  f:
							m[bill_no-1]++;
							itm.in_detail(bill_no-1,m[bill_no-1]);
							cout<<"\nItem Added Sucesfully...";
							cout<<"\n\n1.Add more items  ";
							cout<<"\n2.Return to main menu ";
							cout<<"\n\nEnter choice : ";
							cin>>choice;
							if(choice==1)
							{
								goto f;
							}
							else if(choice==2)
							{
								goto menu;
							}							
							else
							{
								cout<<"Wrong Input";
								cout<<"\nRedircting to the Edit Items menu .......";
								sleep(3);
								goto b;
							}
						}
						else if(choice == 4)
						{
							cout<<"\n\nEnter Item Number to Remove : ";
							cin>>count2;
							if(count2-1>=0 && count2-1 <= m[bill_no-1])
							{
								itm.remove_item(bill_no-1,count2-1);
								cout<<"\nRedirecting to main menu......";
								sleep(3);
								goto menu;
							}
							else
							{
								cout<<"\nItem Not Found";
								cout<<"\nRedirecting to main menu";
								sleep(2);
								goto menu;
							}
						
						}
						break;
					}
					else if(choice==5)
					{
						goto menu;
					}
					else
					{
						cout<<"Wrong Input.....Try Again.....";
						goto b;
					}
				}
				else
				{
					cout<<"\nBill Does Not exists Try Again";
					cout<<"\nRedircting to the main menu .......";
					sleep(3);
					goto menu;
				}
			break;
		case 4 :
			char x;
		c:
			cout<<"\nAre you sure you want to exit (y/n) : ";
			cin>>x;
			if(x == 'y')
			{
				exit(0);
			}
			else if(x== 'n')
			{
				goto menu;
			}
			else
			{
				cout<<"Wrong Input.....Try Again.....";
				goto c;
			}
	}
	goto menu;
	return 0;
}
