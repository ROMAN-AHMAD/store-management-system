#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<fstream>
using namespace std;
int i,n;
ifstream fin;
ofstream fout;
fstream fio;
void disp();
class stock
{
		char name[20],pass[10];
	float pr; int quant;

public:
	void get();
	void get2();
	void show();
    int stchk(char nm[30]);    
    void withd(int qty);
    void refil(int qty);
}st;
void stock::withd(int qty)
{
	if(quant>=qty)
	{
		quant-=qty;
		cout<<"\n\nStock updated.\n";
		cout<<"\n\nTotal price to be paid:"<<pr*qty;
    }
	else 
	   cout<<"\n\nInsufficient stock";
	    getch();
		
	
}

void stock::refil(int qty)
{
	
		quant+=qty;
		cout<<"\n\nStock updated.";
	    getch();
		
	
}
int stock::stchk(char nm[30])
{
	if(strcmp(nm,name)==0)
	 return 0;
	else 
	return 1;
}
void stock::get()
{
	cin>>name>>pr>>quant;
	/*cout<<"\n\nEnter the password letter by letter\n";
	
	for(int z=0;z<5;z++)
	{
		
		cin>>pass[z];
		system("cls");
		cout<<"\n\nEnter the password letter by letter\n";
		for(i=1;i<=(z+1);i++)
		{
			cout<<"*";
		}
	}
	if(strcmp(pass,"hello")==0)
	{
    cout<<"\nCongrats!!Access Granted!!\n\n";
	cout<<"\nEnter the Name followed By the price and then by the quantity\n"; 	
	cin>>name>>pr>>quant;
}
	else
	cout<<"Access Denied!!";*/
}
void stock::get2()
{
	cin>>name>>quant;
}

void stock::show()
{
	
	cout<<"\n"<<name<<"\t\t\t"<<quant<<"\t\t\t"<<pr;
}
void addnew()
{
 //   cout<<"\n\n\nCongrats!!Access Granted!!\n\n";

    system("cls");
	//cout<<"\nEnter the Name followed By the price and then by the quantity\n"; 	
	disp();
	getch();
	system("cls");
	
	cout<<"\nEnter the No. of Products that you wish to add: ";
    cin>>n;
	
    
    if (n!=0)
    {
	
	int j,l,sum=0;
	fout.open("shop.dat",ios::binary|ios::app);
	for(i=0;i<n;i++)
	
	{
	    /*if(i==0)	
		{
		system("cls");
	}*/
		cout<<"\n\nInput the name, price and the quantity of item respectively\n\n";
	    st.get();
	    fout.write((char*)&st,sizeof(st));
        cout<<"\n\nitem updated";
		cin.get();


    }
    cout<<"\n\nStock Updated!!";
    

    fout.close();
    cin.get();
    system("cls");
    disp();
}

	else
{

	fout.close();
	cin.get();
	system("cls");
	cout<<"\n\nNo items to be added";

}
}




void withdraw()
{
	system("cls");
	char temp[100];int qty;
	int i=0;
	long pos=0;
	disp();
	cout<<"\n\nEnter the product's name \n"<<endl;
	cin>>temp;
	cout<<"\n\nEnter quantity: \n"<<endl;
	cin>>qty;
	fio.open("shop.dat",ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&st,sizeof(st));
	    if(st.stchk(temp)==0)
	    {
		  
		  st.withd(qty);
		  fio.seekp(pos);
		  fio.write((char*)&st,sizeof(st));
		  i++;break;
	    }
     }
     
    
     if(i!=1)
       cout<<"\n\n!!Record not found!!";
     fio.close();
    cin.get();
    system("cls");
	 disp(); 
	getch();
}
void disp()
{
	int i=1;
	cout<<"\n==================================================================";
	cout<<"\n\n=================\tTHE STOCK ITEMS ARE\t==================";
	cout<<"\n\n==================================================================\n";
	cout<<"\n\nPARTICULARS\tSTOCK AVAILABLE\t\t\t PRICE";
	cout<<"\n\n============================================================\n";	
	 fin.open("shop.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&st,sizeof(st));
	  if(!fin.eof())
	  {
	     if(fin.tellg()<0)
	     {	i=0; break;}
	     st.show();
	  }
     }
     if(i==0)
     {	cout<<"\n\n\t\t\t!!Empty record room!!";
	getch();
     }
     fin.close();
    
}
void refill()
{
	system("cls");
	char temp[100];int qty;
	int i=0;
	long pos=0;
	disp();
	cout<<"\n\nEnter the products name \n"<<endl;
	cin>>temp;
	cout<<"\n\nEnter quantity: \n"<<endl;
	cin>>qty;
	fio.open("shop.dat",ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&st,sizeof(st));
	    if(st.stchk(temp)==0)
	    {
		  
		  st.refil(qty);
		  fio.seekp(pos);
		  fio.write((char*)&st,sizeof(st));
		  i++;break;
	    }
     }
     if(i!=1)
       cout<<"\n\n!!Record not found!!";
     fio.close();
    system("cls");
    cin.get();
	 disp(); cin.get();
    
	
}
void remove()
{
	system("cls");	
	 int i=0;
     char temp[30];
     cout<<"\n\t\t\t\tDelete Record";
     cout<<"\n\nEnter the name of the product:";
     cin>>temp;
     fout.open("temp.dat",ios::binary);
     fin.open("shop.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&st,sizeof(st));
	  if(!fin.eof())
	    if(st.stchk(temp)==0)
	    {
		  st.show();
		  cout<<"\n\n\t\tRecord deleted";
		  i++;
	    }
	    else
		  fout.write((char*)&st,sizeof(st));
     }
     if(i==0)
       cout<<"\n\n!!Record not found!!";
     fin.close();
     fout.close();
     remove("shop.dat");
     rename("temp.dat","shop.dat");
}
int main()
{
	char pass[10],pass2[10];
	int i,j;
	cout<<"\n\n\n\n\n\n\n\n\n\n\n \t\t\t|============ WELCOME TO STORE MANAGEMENT ============|";
	getch();
	system("cls");
	cout<<"\n\t\t   STORE MANAGEMENT SYSTEM\n";	
	cout<<"=============================================================";
	cout<<"\n\n\t\t   1. Dealer Menu\n\n\t\t   2. Customer Menu\n\n\t\t   3. Employee Menu";
	cout<<"\n\n=============================================================\n";
	cout<<"\n\nEnter Your Choice:";
	cin>>j;
	if(j==1)
	{
	
	system("cls");
	/*disp();
	
	cout<<"\n\n\n\nEnter the No. of Products that you wish to add: ";
    cin>>n;*/
    system("cls");
    cout<<"\n\n\n\n\n\n\n\t\t\t\t\tEnter the password letter by letter: ";
	
	for(int z=0;z<6;z++)
	{
		pass[z]=getch();
		system("cls");
		cout<<"\n\n\n\n\n\n\n\t\t\t\t\tEnter the password letter by letter: ";
		for(i=1;i<=(z+1);i++)
		{
			cout<<"*";
		}
	}
	if(strcmp(pass,"dealer")==0)
	{
    /*cout<<"\n\n\nCongrats!!Access Granted!!\n\n";
    getch();*/
    system("cls");
	dealermenu:
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\t    DEALER MENU\n1. Add new product\n2. Display stock\n3. Refill\n4. Remove an item\n5. Exit:";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
	cin>>i;
	if(i==1)
	{
		addnew();getch();
	goto dealermenu;
	}

	else if(i==2)
	{
		system("cls");
	disp();getch();goto dealermenu;
	}
	else if(i==3)
	{
		refill();goto dealermenu;
	}
	else if(i==4)
	{
		remove();getch();goto dealermenu;
	}
	else 
	{
		system("cls");
	cout<<"\n\n\n\t\t\tBrought To You By code-projects.org";
	getch();
	exit(0);
}
}
else
{
	cout<<"\n\n\nAuthorised Personnel Only\n\n";
	getch();
	getch();
	getch();
	getch();
	getch();
	getch();
	exit(0);
}
	}
	if(j==2)
	{
		custmenu:
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\t    CUSTOMER MENU\n1. Purchase\n2. Display stock\n3. Exit:";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
	cin>>i;
	
	
	
	if (i==1)
	{
	withdraw();getch();goto custmenu;
	}
	else if(i==2)
	{
		system("cls");
	disp();getch();goto custmenu;
	}
	
	else 
	{
		system("cls");
	cout<<"\n\n\n\t\t\tBrought To You By code-projects.org";
	getch();
	exit(0);
}
	
}
if(j==3)

{
	system("cls");
	cout<<"\n\n\n\n\n\n\n\t\t\t\t\tEnter the password letter by letter: ";
	
	for(int z=0;z<3;z++)
	{
		pass2[z]=getch();
		system("cls");
		cout<<"\n\n\n\n\n\n\n\t\t\t\t\tEnter the password letter by letter: ";
		for(i=1;i<=(z+1);i++)
		{
			cout<<"*";
		}
	}
	if(strcmp(pass2,"emp")==0)
	{
	empmenu:
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\tEMPLOYEE MENU\n1. Display stock\n2. Refill\n3. Exit";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
	cin>>i;
	if(i==1)
	{
		system("cls");
	disp();getch();goto empmenu;
	}
	else if(i==2)
	{
		refill();goto empmenu;
	}
	else 
	{
		system("cls");
	cout<<"\n\n\n\t\t\tThank You!!";
	getch();
	exit(0);
}
}
else
{
	cout<<"\n\nSorry!! Access Denied..\n\n";
	getch();
	getch();
	getch();
	getch();
	getch();
	
	exit(0);
}

	}	
	
	getch();
	
}
