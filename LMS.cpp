#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream.h>


class cus
{
  public:
  char name[20];
  float blnc;
  int ac_no;
  void input();

};


void cus::input()
{

  cout<<"\n\nname:";
 cin>>name;
 cout<<"\n\naccount no:";
 cin>>ac_no;
 cout<<"\n\n balance:";
 cin>>blnc;


};

///////////////////////////////

class acc:public cus
{
public:
float intrst;
int tim;
void add();
void output();
acc();
};

acc::acc()
{
tim=0;
intrst=0;
}

void acc::output()
{
 cout<<"\n\nname:"<<name;
 cout<<"\n\n total balance:"<<blnc;
 cout<<"\n\ninterest:"<<intrst;
}


void acc::add()
{
 int i;
 tim++;
 cout<<"\n\n Amount:";
 cin>>i;
 intrst=intrst+blnc*tim*.07;
 blnc=blnc+intrst+i;

};

class loan:public acc
{
public:
float lon;
loan()
{
lon=0;
}
void payloan();
void getloan();
};


void loan::getloan()
{
  int l;
  if(lon==0)
  {
    cout<<"Enter loan:";
    cin>>l;
    if(l<=(l*1.50))
    {
    cout<<"\n\n\tyou can get loan";
    lon=l+l*0.1;
    }

    else
    {
     cout<<"\n \n\tSorry.";
     lon=0;
    }
    }
    else
     cout<<"\n\n\tYou have previous loan.";
}


void loan::payloan()
{
  int m;
  if(lon==0)
  cout<<"\n\n\t You have no loan.";
  else
  {
    cout<<"\n\n\t You have to pay "<<lon;
    cout<<"\n\nEnter your payment";
    cin>>m;
    lon=lon-m;
    if(lon<=0)
    {
    cout<<"\n\n\tok your loan paid.";
    lon=0;
    }
    else
    cout<<"loan to be paid="<<lon;
}
}

void show()
{
 loan a;
 int i,found=0;
 fstream file;

 file.open("final.text",ios::ate|ios::in|ios::out|ios::binary);
 file.seekg(0);

 cout<<"\n\nInsert account no:";
 cin>>i;
 for(;;)
 {
    file.read((char*)&a,sizeof(a));
    if(!file)
    break;

 if(i==a.ac_no)
 {
  a.output();
  found=1;
  break;
 }
 }
 if(found!=1)
  cout<<"\nNot exist.";
  file.close();

 getch();
};

void add_a()
{
 loan a;
 fstream file;
 int i,k,found=0;
 cout<<"\n\nInsertaccount no:";
 cin>>i;
 file.open("final.text",ios::ate|ios::in|ios::out|ios::binary);
 file.seekg(0);
 for(k=0;;k++)
 {
     file.read((char*)&a,sizeof(a));
     if(!file)
     break;
    if(i==a.ac_no)
    {
     a.add();
     found=1;

     break;
    }

 }
 if(found==1)
 {
 cout<<" K="<<k;
  int d=sizeof(a);
  cout<<"OBject="<<d;
  int n=k*sizeof(a );
    file.seekp(n);
  file.write((char*)&a,sizeof(a));
  cout<<"\n\n\tInformation added to file.";
  file.close();
 }
 else
  cout<<"\n\n\t This account is not exist in file.";

 getch();

};


void dlt()
{
loan a[100];
 fstream file;
  file.open("final.text",ios::ate|ios::in|ios::out|ios::binary);

 int i,l,found=0;
 cout<<"\n\n insert account no:";
 cin>>i;
 file.seekg(0);

 for(int k=0;;k++)
 {
     file.read((char*)&a[k],sizeof(a[k]));
      if(!file)
      break;

  }
 file.close();
 file.open("final.text",ios::out|ios::binary);
  for(l=0;l<k;l++)
 {
    if(i==a[l].ac_no)
    {
     cout<<"\n\n\t Record deleted.";
     found=1;
    }
    else
     file.write((char*)&a[l],sizeof(a[l]));

  }
    if(found==0)
    cout<<"\n\n\t Record is not in file.";
    file.close();
  getch();


};


void loanf()
{
 loan a;
 fstream file;
 file.open("final.text",ios::ate|ios::in|ios::out|ios::binary);
  int i,found=0;
 cout<<"\n\naccount no:";
 cin>> i;
 file.seekg(0);
 for(int k=0;;k++)
 {
        file.read((char*)&a,sizeof(a));
        if(!file)
      break;

    if(i==a.ac_no)
    {
    a.getloan();
    int n=k*sizeof(a);
    file.seekp(n);
    file.write((char*)&a,sizeof(a));
    found=1;
    break;

    }
    }
    file.close();
        if(found==0)
         cout<<"\n\n\t This account is not exist in file.";

 getch();
};

void pay()
{
loan a;
 fstream file;
 file.open("final.text",ios::ate|ios::in|ios::out|ios::binary);

 int i,found=0;
 cout<<"Account no:";
 cin>>i;
 file.seekg(0);

 for(int k=0;;k++)
 {file.read((char*)&a,sizeof(a));
    if(!file)
      break;

 if(i==a.ac_no)
 {
 a.payloan();
 int n=k*sizeof(a);
    file.seekp(n);
    file.write((char*)&a,sizeof(a));
    found=1;
    break;
 }
 }
 if(found==0)
 {
 cout<<"\n\n\t This account is not exist in file.";
 }
 file.close();

 getch();
};


void inputdata(loan a)
{
 fstream file;

 file.open("final.text",ios::ate|ios::in|ios::out|ios::binary);
 file.seekp(0,ios::end);
 file.clear();
 file.write((char*)&a,sizeof(a));
 file.close();

 }



/////////////MAIN PROGRAM//////////////////

int main()
{
     int i;


 for(;;)
 {
  loan a;
  clrscr();
  cout<<"\n\n\t<<<<<<<<<<<<<<<<<<MENU>>>>>>>>>>>>>>>>>>>>>>>>\n";

          cout<<"________________________________________________\n";
          cout<<"________________________________________________\n" ;
          cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
  cout<<"\n\n\n\n\t 1.input. \n\n\t 2.output\n\n\t 3.Add\n\n\t 4.Delete\n\n\t  5.loan\n\n\t 6.pay\n\n\t7.Exit\n\n\t  your choice:";
  cin>>i;
  switch(i)
  {
    case 1:a.input();inputdata(a);
             break;
    case 2:show();
    break;
    case 3:add_a();
    break;
    case 4:dlt();
    break;

    case 5:loanf();
    break;
     case 6:pay();
    break;
     default:exit(0);
  }
 }
// return 0;
}