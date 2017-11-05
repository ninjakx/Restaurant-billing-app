#include<iomanip.h>
#include<conio.h>
#include<fstream.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<stdlib.h>
#include<stdio.h>
 //********CLASS->RESTAURANT***********///
class rest
{
private:
char item[40];
int cost;
int code;
long int sum;
public:
void get(void);
void put();
void read();
void show();
int search();
int price();
}t;
int rest::search()
{return code;
}
int rest::price()
{return cost;
}
 //**************Fn TO ADD DATA********************//
void rest::put()
{
cout<<"\nENTER ITEM NAME : "<<endl;
gets(item);
cout<<"\nENTER CODE : "<<endl;
cin>>code;
cout<<"\nENTER COST : "<<endl;
cin>>cost;
cout<<endl<<endl;
} //********Fn TO SEARCH DATA************
void rest::show()
{cout<<"\t"<<item<<"\t\t\t"<<code<<"\t\t"<<cost<<endl;
} //**************Fn TO WRITE DATA***************
void rest::get (void)
{char n;
int N;
gotoxy(6,7);
cout<<"1:CHINESE DISHES"<<endl;
gotoxy(6,9);
cout<<"2:MEXICAN DISHES"<<endl;
gotoxy(6,11);
cout<<"3:INDIAN DISHES"<<endl;
gotoxy(6,13);
cout<<"4:ITALIAN DISHES"<<endl;
char ch;
gotoxy(21,15);
cout<<"enter your choice (1-4)"<<" : ";
ch=getche();
int p=0;
switch(ch)
{case '1':
ofstream foutc;
foutc.open("chinese",ios::binary|ios::app) ;
cout<<"\n\nHow many items do you want to enter"<<"\n";
cin>>N;
do
{t.put();
foutc.write((char*)&t,sizeof(t));
 p++;
 }
 while(N!=p);
foutc.close();
clrscr();
break;
case '2':
ofstream foutm;
foutm.open("mexican",ios::binary|ios::app) ;
cout<<"\n\nHow many items do you want to enter"<<"\n";
cin>>N;
do
{t.put();
foutm.write((char*)&t,sizeof(t));
 p++;
 }
 while(N!=p);
 foutm.close();
clrscr();
break;
case '3':
ofstream fouti;
fouti.open("indian",ios::binary|ios::app) ;
cout<<"\n\nHow many items do you want to enter"<<"\n";
cin>>N;
do
{t.put();
fouti.write((char*)&t,sizeof(t));
 p++;
 }
 while(N!=p);
fouti.close();
clrscr();
break;
case '4':
ofstream foutt;
foutt.open("italian",ios::binary|ios::app) ;
cout<<"\n\nHow many items do you want to enter"<<"\n";
cin>>N;
do
{t.put();
foutt.write((char*)&t,sizeof(t));
 p++;
 }
 while(N!=p);
 foutt.close();
clrscr();
break;
 default:
 cout<<"RECORD NOT FOUND!"<<"\n \n";
 break;
 }
 clrscr();
} //***********CLASS->CUSTOMER************//
class cust
{int v;
char name[30];
char sex[2];
char country[20];
char city[20];
char address[30];
int age;
long int contactno;
public:
int custcode();
void customerg();
void customerp();
void customers();
void customerr();
void modify();
void csearch();
void del();
void cname();
}a;
void cust::customerp()
{randomize();
for(int i=0;i<1;i++)
{v=rand() % 10 + rand() % 100 + rand() % 1000;
}
gotoxy(20,5);
cout<<"ENTER YOUR DETAILS:"<<endl;
cout<<"\nNAME:"<<endl;
gets(name);
cout<<"\nAGE:"<<endl;
cin>>age;
cout<<"\nSEX:"<<endl;
gets(sex);
cout<<"\nADDRESS:"<<endl;
gets(address);
cout<<"\nCITY:"<<endl;
gets(city);
cout<<"\nCOUNTRY:"<<endl;
gets(country);
cout<<"\nCONTACT NO:"<<endl;
cin>>contactno;
}
void cust::customerg()
{ofstream fc;
fc.open("customer",ios::binary|ios::app) ;
{
a.customerp();
fc.write((char*)&a,sizeof(a));
}
}
void cust::cname()
{cout<<"\n\n DEAR CUSTOMER\n"<<setw(15)<<name;
}
 //*************Fn TO SHOW THE DATA****************//
void cust::customers()
{
cout<<setw(10)<<name<<setw(4)<<age<<setw(4)<<sex<<setw(20)
<<address<<setw(11)<<city<<setw(10)<<country<<setw(13)<<contactno
<<setw(7)<<v<<endl;
}
int cust::custcode()
{return v;
} //****TO SEARCH FOR CUSTOMER*****//
void cust::csearch()
{int y;
fstream f;
f.open("customer",ios::binary|ios::in|ios::out);
cout<<"\n\n\t\tENTER THE CODE YOU WANT TO SERACH : ";
cin>>y;
int found =0;
cout<<"\n\n"<<setw(8)<<"NAME"<<setw(6)<<"AGE"<<setw(5)<<"SEX"<<setw(14)
<<"ADDRESS"<<setw(14)<<"CITY"<<setw(11)<<"COUNTRY"<<setw(14)<<"CONTACT NO"
<<setw(7)<<"CCODE"<<endl<<endl;
while(f.read((char*)&a,sizeof(a)) && found ==0)
{if(y==a.custcode())
{a.customers();
getch();
}
}
} //**********Fn TO MODIFY THE DATA***************//
void cust::modify()
{int x;
fstream file;
file.open("customer",ios::binary|ios::in|ios::out);
cout<<"\n\n\tENTER THE CODE YOU WANT TO MODIFY : ";
cin>>x;
cout<<"\n\n"<<setw(8)<<"NAME"<<setw(6)<<"AGE"<<setw(5)<<"SEX"<<setw(14)
<<"ADDRESS"<<setw(14)<<"CITY"<<setw(11)<<"COUNTRY"<<setw(14)<<"CONTACT NO"
<<setw(7)<<"CCODE"<<endl<<endl;
int found =0;
while(file.read((char*)&a,sizeof(a)) && found ==0)
{if(x==a.custcode())
{a.customers();
getch();
clrscr();
cout<<"\n\n\tENTER THE NEW RECORD:";
a.customerp();
int pos=-1*(sizeof(a));
file.seekp(pos,ios::cur);
file.write((char*)&a,sizeof(a));
cout<<"\n\n\tRECORD UPDATED";
found=1;
}}
cout<<"\n\nNOW THE RECORD IS:";
cout<<"\n\n"<<setw(8)<<"NAME"<<setw(6)<<"AGE"<<setw(5)<<"SEX"<<setw(14)
<<"ADDRESS"<<setw(14)<<"CITY"<<setw(11)<<"COUNTRY"<<setw(14)<<"CONTACT NO"
<<setw(7)<<"CCODE"<<endl<<endl;
ifstream ifile;
ifile.open("customer",ios::binary);
while(ifile.read((char*)&a,sizeof(a)))
{a.customers();
}
ifile.close();
} //**********Fn TO REMOVE THE DATA*********//
void cust::del()
{int n;
gotoxy(10,5);
cout<<"\nENTER THE CCODE,FOR WHICH DATA HAS TO BE REMOVED->";
cin>>n;
ifstream c;
c.open("customer",ios::binary) ;
cout<<"\n\tTHIS DATA IS REMOVED\n\n";
cout<<"\n\n"<<setw(8)<<"NAME"<<setw(6)<<"AGE"<<setw(5)<<"SEX"<<setw(14)
<<"ADDRESS"<<setw(14)<<"CITY"<<setw(11)<<"COUNTRY"<<setw(14)<<"CONTACT NO"
<<setw(7)<<"CCODE"<<endl<<endl;
while(c.read((char*)&a,sizeof(a)))
{
if(a.custcode()==n)
a.customers();
}
ofstream f;
f.open("ncustomer",ios::binary);
ifstream cc;
cc.open("customer",ios::binary);
while(cc.read((char*)&a,sizeof(a)))
{if(a.custcode()!=n)
f.write((char*)&a,sizeof(a));
}
cc.close();
f.close();
remove("customer");
rename("ncustomer","customer");
ifstream ic;
ic.open("customer",ios::binary);
cout<<"\n\n\n\tNEW RECORD\n";
cout<<"\n\n"<<setw(8)<<"NAME"<<setw(6)<<"AGE"<<setw(5)<<"SEX"<<setw(14)
<<"ADDRESS"<<setw(14)<<"CITY"<<setw(11)<<"COUNTRY"<<setw(14)<<"CONTACT NO"
<<setw(7)<<"CCODE"<<endl<<endl;
while(ic.read((char*)&a,sizeof(a)))
{a.customers();
}
getch();
}
void cust::customerr()
{
ifstream fcc;
fcc.open("customer",ios::binary);
 while(fcc.read((char*)&a,sizeof(a)))
{
a.customers();
}
fcc.close();
}
//*************TO CREATE BOX**************//
void box(void)
{ textcolor(4);
 textbackground(15);
char c1=178, c2=177, c3=176 ;
int k=1 ;
gotoxy(1,2) ;
for (int i=1; i<=1840; i++)
{
if (k == 1)
cout <<c1 ;
else
if (k == 2)
cout <<c2 ;
else
if (k == 3)
cout <<c3 ;
k++ ;
if (k == 4)
k = 1 ;
}
for (i=5; i<=21; i++)
{
gotoxy(21,i) ;
cout <<" " ;
}
}
void rest::read()
{char cho;
 {
 box();
gotoxy(30,7);
{ //*****************MENU PAGE************************//
 cprintf("WELCOME TO FOOD PLAZA");
 }
gotoxy(37,9);
cout<<"MENU"<<"\n";
gotoxy(22,11);
cout<<"1:CHINESE DISHES"<<"\n";
gotoxy(22,13);
cout<<"2:MEXICAN DISHES"<<"\n";
gotoxy(22,15);
cout<<"3:INDIAN DISHES"<<"\n";
gotoxy(22,17);
cout<<"4:ITALIAN DISHES"<<"\n";
char c;
gotoxy(30,20);
cout<<"enter your choice"<<" :";
//******************LIST*********************//
c=getche();
clrscr();
if(c==9)
return ;
//********************CHINESE************************//
if(c=='1')
{
ifstream finc;
finc.open("chinese",ios::binary) ;
gotoxy(19,5);
cout<<"LIST OF CHINESE DISHES"<<"\n";
gotoxy(19,6);
cout<<"======================";
 cout<<"\n\n";
cout<<"\t"<<"ITEMS"<<"\t\t\t\t"<<"CODE"<<"\t\t"<<"COST"<<"\n";
 cout<<"\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<"\n";
 while(finc.read((char*)&t,sizeof(t)))
{t.show();
}
finc.close();
}
else
//**************************MEXICAN******************************//
if(c=='2')
{
ifstream finm;
finm.open("mexican",ios::binary);
gotoxy(19,5);
cout<<"LIST OF MEXICAN DISHES"<<"\n";
gotoxy(19,6);
cout<<"======================";
 cout<<"\n\n";
 cout<<"\t"<<"ITEMS"<<"\t\t\t\t"<<"CODE"<<"\t\t"<<"COST"<<"\n";
 cout<<"\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<"\n";
 while(finm.read((char*)&t,sizeof(t)))
{t.show();
}
finm.close();
}
else
//***************************INDIAN*******************************//
if(c=='3')
{
ifstream fini;
fini.open("indian",ios::binary);
gotoxy(19,5);
cout<<"LIST OF INDIAN DISHES"<<"\n";
gotoxy(19,6);
cout<<"======================";
cout<<"\n\n";
cout<<"\t"<<"ITEMS"<<"\t\t\t\t"<<"CODE"<<"\t\t"<<"COST"<<"\n";
 cout<<"\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<"\n";
 while(fini.read((char*)&t,sizeof(t)))
{t.show();
}
fini.close();
}
//****************************ITALIAN********************//
if(c=='4')
{
ifstream fint;
fint.open("italian",ios::binary);
gotoxy(19,5);
cout<<"LIST OF ITALIAN DISHES"<<"\n";
gotoxy(19,6);
cout<<"======================";
cout<<"\n\n";
cout<<"\t"<<"ITEMS"<<"\t\t\t\t"<<"CODE"<<"\t\t"<<"COST"<<"\n";
 cout<<"\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<"\n";
 while(fint.read((char*)&t,sizeof(t)))
{t.show();
}
fint.close();
}
}
getch();
}
void main()
{
clrscr();
rest obj;
cust cus;
char o;
char p;
lb:
l:
clrscr();
/**********************HOMEPAGE*****************************************/
U:
gotoxy(27,4) ;
{
cprintf("HOME");
}
gotoxy(6,7);
cout<<"PRESS 1 TO PURCHASE"<<"\n";
gotoxy(6,9) ;
cout<<"PRESS 2 TO SEE THE MENU"<<"\n";
gotoxy(6,11);
cout<<"PRESS 3 TO EDIT"<<"\n";
gotoxy(6,13);
cout<<"PRESS 4 TO SEE THE CUSTOMERS RECORD"<<"\n";
gotoxy(6,15);
cout<<"PRESS 5 TO EXIT"<<"\n";
gotoxy(6,17);
cout<<"ENTER YOUR CHOICE : ";
p=getche();
clrscr();
switch(p) //*******TO PURCHASE**********//
{
case '1':
clrscr();
char a;
gotoxy(20,15);
cout<<"PRESS m TO SEE THE MENU\n";
a=getche();
if(a=='m')
{w: clrscr();
t.read();
clrscr();
gotoxy(10,10);
cout<<"PRESS b TO GO BACK TO MENU OR PRESS ANY KEY TO CONTINUE\n";
char q;
q=getche();
if(q=='b')
goto w;
}
int se;
clrscr();
gotoxy(31,7);
cout<<"PLACE YOUR ORDER"<<"\n";
gotoxy(27,10);
cout<<"PRESS 1 FOR CHINESE DISHES"<<"\n";
gotoxy(27,12);
cout<<"PRESS 2 FOR MEXICAN DISHES"<<"\n";
gotoxy(27,14);
cout<<"PRESS 3 FOR INDIAN DISHES"<<"\n";
gotoxy(27,16);
cout<<"PRESS 4 FOR ITALIAN DISHES"<<"\n\n";
gotoxy(27,18);
cout<<"ENTER YOUR CHOICE : ";
gotoxy(48,18);
 int amt;
 char g;
int s[30],total=0,c=0;
se=getche();
clrscr();
if(se==9)
return;
if(se=='1')
{int co,u;
char q;
clrscr();
gotoxy(10,5);
cout<<"ARE YOU MEMBER OF OUR RESTAURANT(Y/N)\n ";
cin>>q;
clrscr();
if(q=='y'||q=='Y')
{gotoxy(10,5);
cout<<"ENTER YOUR CCODE : ";
cin>>co;
ifstream fg;
fg.open("customer",ios::binary);
while(fg.read((char*)&cus,sizeof(cus)))
{
if(co==cus.custcode())
{ u=1;
cus.cname();
gotoxy(12,12);
{cout<<"\n\tCUSTOMER DETAIL:";
cout<<"\n\n"<<setw(8)<<"NAME"<<setw(6)<<"AGE"<<setw(5)<<"SEX"<<setw(14)
<<"ADDRESS"<<setw(14)<<"CITY"<<setw(11)<<"COUNTRY"<<setw(14)<<"CONTACT NO"
<<setw(7)<<"CCODE"<<endl<<endl;
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~\n";
cus.customers();
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~\n";
cout<<"\n\n\tWE ARE HAVING SPECIAL DISCOUNT FOR OUR MEMBER!\n";
cout<<"\tYOU ARE GETTING 10 % DISCOUNT IN ORDERING THE DISHES";
getch();
}}
}
}
clrscr();
char r='Y';
do
{
gotoxy(10,10);
clreol();
cout<<"ENTER THE CODE OF THE ITEM ,YOU WANT TO PURCHASE : ";
cin>>s[c];
c++;
gotoxy(10,12);
clreol();
cout<<"\DO YOU WANT TO PLACE YOUR ORDER AGAIN ? (Y/N)";
cin>>r;
 }
 while(r=='y'||r=='Y') ;
 cout<<"\n\n\t"<<"ITEMS"<<"\t\t\t\t"<<"CODE"<<"\t\t"<<"COST"<<"\n\n";
 for(int x=0;x<=c;x++)
 { ifstream finch;
finch.open("chinese",ios::binary) ;
finch.read((char*)&t,sizeof(t));
while(!finch.eof())
{
if(t.search()==s[x])
{t.show();
amt=t.price();
if(u==1)
{total=total+amt-(amt*0.2);
}
else
total+=amt;
}
finch.read((char*)&t,sizeof(t)) ;
}
}
cout<<"\n\n\t\tamount to be paid is :"<<total;
getch();
clrscr();
goto U;
 }
if(se=='2')
{ int u,co;
char q;
clrscr();
gotoxy(10,5);
cout<<"ARE YOU MEMBER OF OUR RESTAURANT(Y/N)\n ";
cin>>q;
clrscr();
if(q=='y'||q=='Y')
{gotoxy(10,5);
cout<<"ENTER YOUR CCODE : ";
cin>>co;
ifstream fg;
fg.open("customer",ios::binary);
while(fg.read((char*)&cus,sizeof(cus)))
{if(co==cus.custcode())
{ u=1;
cus.cname();
gotoxy(12,12);
{cout<<"\n\tCUSTOMER DETAIL:";
cout<<"\n\n"<<setw(8)<<"NAME"<<setw(6)<<"AGE"<<setw(5)<<"SEX"<<setw(14)
<<"ADDRESS"<<setw(14)<<"CITY"<<setw(11)<<"COUNTRY"<<setw(14)<<"CONTACT NO"
<<setw(7)<<"CCODE"<<endl<<endl;
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~\n";
cus.customers();
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~\n";
cout<<"\n\n\tWE ARE HAVING SPECIAL DISCOUNT FOR OUR MEMBER!\n";
cout<<"\tYOU ARE GETTING 10 % DISCOUNT IN ORDERING THE DISHES";
getch();
}}
}
}
clrscr();
char r='Y';
do
{
gotoxy(10,10);
clreol();
cout<<"ENTER THE CODE OF THE ITEM ,YOU WANT TO PURCHASE : ";
cin>>s[c];
c++;
gotoxy(10,12);
clreol();
cout<<"\DO YOU WANT TO PLACE YOUR ORDER AGAIN ? (Y/N)";
cin>>r;
 }
 while(r=='y'||r=='Y') ;
 cout<<"\n\n\t"<<"ITEMS"<<"\t\t\t\t"<<"CODE"<<"\t\t"<<"COST"<<"\n\n";
 for(int x=0;x<=c;x++)
 { ifstream fim;
fim.open("mexican",ios::binary) ;
fim.read((char*)&t,sizeof(t));
while(!fim.eof())
{
if(t.search()==s[x])
{t.show();
amt=t.price();
if(u==1)
{total=total+amt-(amt*0.2);
}
else
total+=amt;
}
fim.read((char*)&t,sizeof(t)) ;
}
}
cout<<"\n\n\t\t\tamount to be paid is :"<<total;
getch();
clrscr();
goto U;
 }
 if(se=='3')
{int u,co;
char q;
clrscr();
gotoxy(10,5);
cout<<"ARE YOU MEMBER OF OUR RESTAURANT(Y/N)\n ";
cin>>q;
clrscr();
if(q=='y'||q=='Y')
{gotoxy(10,5);
cout<<"ENTER YOUR CCODE : ";
cin>>co;
ifstream fg;
fg.open("customer",ios::binary);
while(fg.read((char*)&cus,sizeof(cus)))
{if(co==cus.custcode())
{u=1;
cus.cname();
gotoxy(12,12);
{cout<<"\n\tCUSTOMER DETAIL:";
cout<<"\n\n"<<setw(8)<<"NAME"<<setw(6)<<"AGE"<<setw(5)<<"SEX"<<setw(14)
<<"ADDRESS"<<setw(14)<<"CITY"<<setw(11)<<"COUNTRY"<<setw(14)<<"CONTACT NO"
<<setw(7)<<"CCODE"<<endl<<endl;
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~\n";
cus.customers();
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~\n";
cout<<"\n\n\tWE ARE HAVING SPECIAL DISCOUNT FOR OUR MEMBER!\n";
cout<<"\tYOU ARE GETTING 10 % DISCOUNT IN ORDERING THE DISHES";
getch();
}}
}
}
clrscr();
char r='Y';
do
{
gotoxy(10,10);
clreol();
cout<<"ENTER THE CODE OF THE ITEM ,YOU WANT TO PURCHASE : ";
cin>>s[c];
c++;
gotoxy(10,12);
clreol();
cout<<"\DO YOU WANT TO PLACE YOUR ORDER AGAIN ? (Y/N)";
cin>>r;
 }
 while(r=='y'||r=='Y') ;
 cout<<"\n\n\t"<<"ITEMS"<<"\t\t\t\t"<<"CODE"<<"\t\t"<<"COST"<<"\n\n";
 for(int x=0;x<=c;x++)
 { ifstream fii;
fii.open("indian",ios::binary) ;
fii.read((char*)&t,sizeof(t));
while(!fii.eof())
{
if(t.search()==s[x])
{t.show();
amt=t.price();
if(u==1)
{total=total+amt-(amt*0.2);
}
else
total+=amt;
}
fii.read((char*)&t,sizeof(t)) ;
}
}
cout<<"\n\n\t\t\tamount to be paid is :"<<total;
getch();
clrscr();
goto U;
 }
 if(se=='4')
{int u,co;
char q;
clrscr();
gotoxy(10,5);
cout<<"ARE YOU MEMBER OF OUR RESTAURANT(Y/N)\n ";
cin>>q;
clrscr();
if(q=='y'||q=='Y')
{gotoxy(10,5);
cout<<"ENTER YOUR CCODE : ";
cin>>co;
ifstream fg;
fg.open("customer",ios::binary);
while(fg.read((char*)&cus,sizeof(cus)))
{if(co==cus.custcode())
{ u=1;
cus.cname();
gotoxy(12,12);
{cout<<"\n\tCUSTOMER DETAIL:";
cout<<"\n\n"<<setw(8)<<"NAME"<<setw(6)<<"AGE"<<setw(5)<<"SEX"<<setw(14)
<<"ADDRESS"<<setw(14)<<"CITY"<<setw(11)<<"COUNTRY"<<setw(14)<<"CONTACT NO"
<<setw(7)<<"CCODE"<<endl<<endl;
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~\n";
cus.customers();
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~\n";
cout<<"\n\n\tWE ARE HAVING SPECIAL DISCOUNT FOR OUR MEMBER!\n";
cout<<"\tYOU ARE GETTING 10 % DISCOUNT IN ORDERING THE DISHES";
getch();
}}
}
}
clrscr();
char r='Y';
do
{
gotoxy(10,10);
clreol();
cout<<"ENTER THE CODE OF THE ITEM ,YOU WANT TO PURCHASE : ";
cin>>s[c];
c++;
gotoxy(10,12);
clreol();
cout<<"\DO YOU WANT TO PLACE YOUR ORDER AGAIN ? (Y/N)";
cin>>r;
 }
 while(r=='y'||r=='Y') ;
 cout<<"\n\n\t"<<"ITEMS"<<"\t\t\t\t"<<"CODE"<<"\t\t"<<"COST"<<"\n\n";
 for(int x=0;x<=c;x++)
 { ifstream fit;
fit.open("C:\\italian",ios::binary) ;
fit.read((char*)&t,sizeof(t));
while(!fit.eof())
{
if(t.search()==s[x])
{t.show();
amt=t.price();
if(u==1)
{total=total+amt-(amt*0.2);
}
else
total+=amt;
}
fit.read((char*)&t,sizeof(t)) ;
}
}
cout<<"\n\n\t\t\tamount to be paid is :"<<total;
getch();
clrscr();
goto U;
 }
break;
case '2': //*******TO SEE THE MENU******//
obj.read();
clrscr();
goto l;
break;
case '3': //********EDIT***************//
{gotoxy(10,7);
cout<<"PRESS 1 TO ADD DATA"<<"\n";
gotoxy(10,9);
cout<<"PRESS 2 TO REMOVE DATA"<<"\n";
gotoxy(10,11);
cout<<"PRESS 3 TO SEARCH DATA"<<"\n";
gotoxy(10,13);
cout<<"PRESS 4 TO MODIFY DATA"<<"\n";
gotoxy(10,20);
cout<<"\n\n\tENTER YOUR CHOICE"<<" : ";
o=getche();
clrscr();
switch(o)
{case '1': //*************TO ADD DATA******************//
gotoxy(21,4);
cout<<"ADDING OF DATA"<<"\n";
obj.get();
getch();
clrscr();
goto l;
break;
case '2': //*********TO REMOVE DATA**************//
{int che;
gotoxy(31,7);
cout<<"REMOVING THE DATA"<<"\n";
gotoxy(27,10);
cout<<"PRESS 1 FOR CHINESE DISHES"<<"\n";
gotoxy(27,12);
cout<<"PRESS 2 FOR MEXICAN DISHES"<<"\n";
gotoxy(27,14);
cout<<"PRESS 3 FOR INDIAN DISHES"<<"\n";
gotoxy(27,16);
cout<<"PRESS 4 FOR ITALIAN DISHES"<<"\n\n";
gotoxy(27,18);
cout<<"ENTER YOUR CHOICE : ";
gotoxy(48,18);
che=getche();
clrscr();
if(che==9)
return;
if(che=='1') //******TO REMOVE CHINESE DISHES*********//
{
gotoxy(20,6);
int n;
cout<<"ENTER THE CODE,FOR WHICH DATA HAS TO BE REMOVED->";
cin>>n;
cout<<"\n\n\t"<<"ITEMS"<<"\t\t\t\t"<<"CODE"<<"\t\t"<<"COST"<<"\n\n";
ifstream rfinch;
rfinch.open("chinese",ios::binary) ;
while(rfinch.read((char*)&t,sizeof(t)))
{
if(t.search()==n)
t.show();
}
ofstream oc;
oc.open("nchinese",ios::binary);
ifstream ic;
ic.open("chinese",ios::binary);
while(ic.read((char*)&t,sizeof(t)))
{if(t.search()!=n)
oc.write((char*)&t,sizeof(t));
}
ic.close();
oc.close();
remove("chinese");
rename("nchinese","chinese");
ifstream ifch;
ifch.open("chinese",ios::binary);
while(ifch.read((char*)&t,sizeof(t)))
{t.show();
}
getch();
goto l;
}
if(che=='2')
{
gotoxy(20,6);
int n;
cout<<"ENTER THE CODE,FOR WHICH DATA HAS TO BE REMOVED->";
cin>>n;
cout<<"\n\n\t"<<"ITEMS"<<"\t\t\t\t"<<"CODE"<<"\t\t"<<"COST"<<"\n\n";
ifstream rfinm;
rfinm.open("mexican",ios::binary) ;
while(rfinm.read((char*)&t,sizeof(t)))
{
if(t.search()==n)
t.show();
}
ofstream om;
om.open("nmexican",ios::binary);
ifstream im;
im.open("mexican",ios::binary);
while(im.read((char*)&t,sizeof(t)))
{if(t.search()!=n)
om.write((char*)&t,sizeof(t));
}
im.close();
om.close();
remove("mexican");
rename("nmexican","mexican");
ifstream ifm;
ifm.open("mexican",ios::binary);
while(ifm.read((char*)&t,sizeof(t)))
{t.show();
}
getch();
goto l;
}
if(che=='3')
{
gotoxy(20,6);
int n;
cout<<"ENTER THE CODE,FOR WHICH DATA HAS TO BE REMOVED->";
cin>>n;
cout<<"\n\n\t"<<"ITEMS"<<"\t\t\t\t"<<"CODE"<<"\t\t"<<"COST"<<"\n\n";
ifstream rfini;
rfini.open("indian",ios::binary) ;
while(rfini.read((char*)&t,sizeof(t)))
{
if(t.search()==n)
t.show();
}
ofstream oi;
oi.open("nindian",ios::binary);
ifstream ii;
ii.open("indian",ios::binary);
while(ii.read((char*)&t,sizeof(t)))
{if(t.search()!=n)
oi.write((char*)&t,sizeof(t));
}
ii.close();
oi.close();
remove("indian");
rename("nindian","indian");
ifstream ifi;
ifi.open("indian",ios::binary);
while(ifi.read((char*)&t,sizeof(t)))
{t.show();
}
getch();
goto l;
}
if(che=='4')
{
gotoxy(20,6);
int n;
cout<<"ENTER THE CODE,FOR WHICH DATA HAS TO BE REMOVED->";
cin>>n;
cout<<"\n\n\t"<<"ITEMS"<<"\t\t\t\t"<<"CODE"<<"\t\t"<<"COST"<<"\n\n";
ifstream rfini;
rfini.open("italian",ios::binary) ;
while(rfini.read((char*)&t,sizeof(t)))
{
if(t.search()==n)
t.show();
}
ofstream oi;
oi.open("nitalian",ios::binary);
ifstream ii;
ii.open("italian",ios::binary);
while(ii.read((char*)&t,sizeof(t)))
{if(t.search()!=n)
oi.write((char*)&t,sizeof(t));
}
ii.close();
oi.close();
remove("italian");
rename("nitalian","italian");
ifstream ifi;
ifi.open("italian",ios::binary);
while(ifi.read((char*)&t,sizeof(t)))
{t.show();
}
goto l;
}
break;
}
case '3': //********TO SEARCH THE DATA*****************//
box();
int choice,a;
char opt;
gotoxy(31,7);
cout<<"SEARCHING THE DATA"<<"\n";
gotoxy(27,10);
cout<<"PRESS 1 FOR CHINESE DISHES"<<"\n";
gotoxy(27,12);
cout<<"PRESS 2 FOR MEXICAN DISHES"<<"\n";
gotoxy(27,14);
cout<<"PRESS 3 FOR INDIAN DISHES"<<"\n";
gotoxy(27,16);
cout<<"PRESS 4 FOR ITALIAN DISHES"<<"\n\n";
gotoxy(27,18);
cout<<"ENTER YOUR CHOICE : ";
gotoxy(48,18);
choice=getche();
clrscr();
if(choice==9)
return;
if(choice=='1') //********TO SEARCH CHINESE DISHES***********//
{k:
clrscr();
gotoxy(7,5);
cout<<"ENTER THE CODE ,YOU WANT TO SEARCH FOR : ";
cin>>a;
cout<<"\n\n\t"<<"ITEMS"<<"\t\t\t\t"<<"CODE"<<"\t\t"<<"COST"<<"\n\n";
ifstream finch;
finch.open("chinese",ios::binary) ;
while(finch.read((char*)&t,sizeof(t)))
{
if(t.search()==a)
t.show();
}gotoxy(7,14);
cout<<"PRESS y TO ENTER AGAIN ELSE ENTER n "<<"-->";
opt=getche();
if(opt=='y')
goto k;
else
{clrscr();
goto l;
}
}
else if(choice=='2') //************TO SEARCH MEXICAN DISHES********///
{t:
clrscr();
gotoxy(7,5);
cout<<"ENTER THE CODE ,YOU WANT TO SEARCH FOR : ";
cin>>a;
cout<<"\n\n\t"<<"ITEMS"<<"\t\t\t\t"<<"CODE"<<"\t\t"<<"COST"<<"\n\n";
ifstream finmh;
finmh.open("mexican",ios::binary) ;
while(finmh.read((char*)&t,sizeof(t)))
{
if(t.search()==a)
t.show();
}gotoxy(7,14);
cout<<"PRESS y TO ENTER AGAIN ELSE ENTER n "<<"-->";
opt=getche();
if(opt=='y')
goto t;
else
{clrscr();
goto l;
}
}
else if(choice=='3') //**************TO SEARCH INDIAN DISHES**************//
{m:
clrscr();
gotoxy(7,5);
cout<<"ENTER THE CODE ,YOU WANT TO SEARCH FOR : ";
cin>>a;
cout<<"\n\n\t"<<"ITEMS"<<"\t\t\t\t"<<"CODE"<<"\t\t"<<"COST"<<"\n\n";
ifstream finih;
finih.open("indian",ios::binary) ;
while(finih.read((char*)&t,sizeof(t)))
{
if(t.search()==a)
t.show();
}gotoxy(7,14);
cout<<"PRESS y TO ENTER AGAIN ELSE ENTER n "<<"-->";
opt=getche();
if(opt=='y')
goto m;
else
{clrscr();
goto l;
}
}
else if(choice=='4') //************TO SEARCH ITALIAN DISHES**************//
{h:
clrscr();
gotoxy(7,5);
cout<<"ENTER THE CODE ,YOU WANT TO SEARCH FOR : ";
cin>>a;
cout<<"\n\n\t"<<"ITEMS"<<"\t\t\t\t"<<"CODE"<<"\t\t"<<"COST"<<"\n\n";
ifstream finth;
finth.open("italian",ios::binary) ;
while(finth.read((char*)&t,sizeof(t)))
{
if(t.search()==a)
t.show();
}gotoxy(7,14);
cout<<"PRESS y TO ENTER AGAIN ELSE ENTER n "<<"-->";
opt=getche();
if(opt=='y')
goto h;
 else
{clrscr();
goto l;
}
}
break;
case '4': //*********TO MODIFY THE DATA*************//
{ int choice,a;
char opt;
gotoxy(31,7);
cout<<"MODIFYING THE DATA"<<"\n";
gotoxy(27,10);
cout<<"PRESS 1 FOR CHINESE DISHES"<<"\n";
gotoxy(27,12);
cout<<"PRESS 2 FOR MEXICAN DISHES"<<"\n";
gotoxy(27,14);
cout<<"PRESS 3 FOR INDIAN DISHES"<<"\n";
gotoxy(27,16);
cout<<"PRESS 4 FOR ITALIAN DISHES"<<"\n\n";
gotoxy(27,18);
cout<<"ENTER YOUR CHOICE : ";
gotoxy(48,18);
choice=getche();
clrscr();
if(choice=='1') //******TO MODIFY CHINESE DISHES********///
{
clrscr();
gotoxy(7,5);
int d;
cout<<"ENTER THE CODE ,YOU WANT TO MODIFY : ";
cin>>d;
fstream mfinch;
mfinch.open("chinese",ios::binary|ios::in|ios::out) ;
int found=0;
cout<<"\n\n\t"<<"ITEMS"<<"\t\t\t\t"<<"CODE"<<"\t\t"<<"COST"<<"\n\n";
while(mfinch.read((char*)&t,sizeof(t)) && found==0)
{
if(t.search()==d)
{t.show();
 cout<<"\nEnter The New Details";
 t.put();
 int pos=-1*(sizeof(t));
 mfinch.seekp(pos,ios::cur);
 mfinch.write((char*)&t,sizeof(t));
 found=1;
 }
 }
ifstream modc;
modc.open("chinese",ios::binary);
while(mfinch.read((char*)&t,sizeof(t)))
{t.show();
}
goto l;
}if(choice=='2') //******TO MODIFY MEXICAN DISHES********///
{
clrscr();
gotoxy(7,5);
int d;
cout<<"ENTER THE CODE ,YOU WANT TO MODIFY : ";
cin>>d;
fstream mfinm;
mfinm.open("mexican",ios::binary|ios::in|ios::out) ;
int found=0;
cout<<"\n\n\t"<<"ITEMS"<<"\t\t\t\t"<<"CODE"<<"\t\t"<<"COST"<<"\n\n";
while(mfinm.read((char*)&t,sizeof(t)) && found==0)
{
if(t.search()==d)
{t.show();
 cout<<"\nEnter The New Details";
 t.put();
 int pos=-1*(sizeof(t));
 mfinm.seekp(pos,ios::cur);
 mfinm.write((char*)&t,sizeof(t));
 found=1;
 }
 }
ifstream modm;
modm.open("mexican",ios::binary);
while(mfinm.read((char*)&t,sizeof(t)))
{t.show();
} goto l;
}
if(choice=='3') //******TO MODIFY INDIAN DISHES********///
{
clrscr();
gotoxy(7,5);
int d;
cout<<"ENTER THE CODE ,YOU WANT TO MODIFY : ";
cin>>d;
fstream mfini;
mfini.open("indian",ios::binary|ios::in|ios::out) ;
int found=0;
cout<<"\n\n\t"<<"ITEMS"<<"\t\t\t\t"<<"CODE"<<"\t\t"<<"COST"<<"\n\n";
while(mfini.read((char*)&t,sizeof(t)) && found==0)
{
if(t.search()==d)
{t.show();
 cout<<"\nEnter The New Details";
 t.put();
 int pos=-1*(sizeof(t));
 mfini.seekp(pos,ios::cur);
 mfini.write((char*)&t,sizeof(t));
 found=1;
 }
 }
ifstream modi;
modi.open("indian",ios::binary);
while(mfini.read((char*)&t,sizeof(t)))
{t.show();
}
goto l;
}
if(choice=='4') //******TO MODIFY ITALIAN DISHES********///
{
clrscr();
gotoxy(7,5);
int d;
cout<<"ENTER THE CODE ,YOU WANT TO MODIFY : ";
cin>>d;
fstream mfint;
mfint.open("italian",ios::binary|ios::in|ios::out) ;
int found=0;
cout<<"\n\n\t"<<"ITEMS"<<"\t\t\t\t"<<"CODE"<<"\t\t"<<"COST"<<"\n\n";
while(mfint.read((char*)&t,sizeof(t)) && found==0)
{
if(t.search()==d)
{t.show();
 cout<<"\nEnter The New Details";
 t.put();
 int pos=-1*(sizeof(t));
 mfint.seekp(pos,ios::cur);
 mfint.write((char*)&t,sizeof(t));
 found=1;
 }
 }
ifstream modt;
modt.open("italian",ios::binary);
while(mfint.read((char*)&t,sizeof(t)))
{t.show();
}
goto l;
}
else if(choice!=1||choice!=2|choice!=3|choice!=4)
{cout<<"INVALID OPTION";
goto l;
}
}
}
default:
goto l;
}
case '4': //**********CUSTOMER RECORDS***************//
{ char pr;
gotoxy(20,5);
cout<<"CUSTOMER RECORDS\n\n";
gotoxy(10,7);
cout<<"1)CREATE\n";
gotoxy(10,9);
cout<<"2)DISPLAY\n";
gotoxy(10,11);
cout<<"3)QUERY\n";
gotoxy(10,13);
cout<<"4)MODIFY\n";
gotoxy(10,15);
cout<<"5)DELETE\n";
gotoxy(10,17);
cout<<"6)BACK TO MENU\n";
pr=getche();
clrscr();
if(pr=='1')
{
cus.customerg();
getch();
goto l;
}
else if(pr=='2')
{cout<<"\n\n"<<setw(8)<<"NAME"<<setw(6)<<"AGE"<<setw(5)<<"SEX"<<setw(14)
<<"ADDRESS"<<setw(14)<<"CITY"<<setw(11)<<"COUNTRY"<<setw(14)<<"CONTACT NO"
<<setw(7)<<"CCODE"<<endl<<endl;
cus.customerr();
getch();
goto l;
}
else if(pr=='3')
{ cus.csearch();
getch();
goto l;
}
else if(pr=='4')
{
cus.modify();
getch();
goto l;
}
else if(pr=='5')
{
cus.del();
getch();
goto l;
}
else if(pr=='6')
{goto l;
}
getch();
}
break;
case '5': //***********EXIT******************//
exit(0);
}
getch();
}
