#include<iostream>
#include<conio.h>
#include<math.h>      //floor function
#include<fstream>
#include<string.h>
#include<stdlib.h>     //exit

using namespace std;

void matrix(void);
void exit(void);
int menu(void);
void credits(void);


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++ CLASS +++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class ELEMENT
{
    public:
    char e_name[12],e_symbol[4],e_fact[1000],e_block[2],e_nature[40];
    float at_mass;
    int at_no,e_group,e_period;

    ELEMENT()   //constructor
    {
        strcpy(e_name,"No Info Available");
        strcpy(e_symbol,"No Info Available");
        strcpy(e_fact,"No Info Available");
        strcpy(e_block,"No Info Available");
        strcpy(e_nature,"No Info Available");
        e_group=0;
        e_period=0;
        at_no=0;
        at_mass=0;
    }

    void assign_values();
    void classtofile();
    void show_data();
    void search_e_details(int);

}a1;




void ELEMENT::assign_values()
{
    cout<<"\n\n\t\t\tEnter Values...\n";
    cout<<"\nEnter Element Name : ";
    cin.getline(e_name,11);
    cout<<"\nEnter Element Symbol : ";
    cin.getline(e_symbol,3);
    cout<<"\nEnter Atomic Number : ";
    cin>>at_no;
    cout<<"\nEnter Atomic Mass : ";
    cin>>at_mass;
    cout<<"\nEnter Nature : ";
    cin.ignore();
    cin.getline(e_nature,30);
    cout<<"\nEnter Period Number : ";
    cin>>e_period;
    cout<<"\nEnter Group Number : ";
    cin>>e_group;
    cout<<"\nEnter Block : ";
    cin>>e_block;
    cout<<"\nEnter Element Facts : ";
    cin.ignore();
    cin.getline(e_fact,999);
    cout<<"\nPress Any Key To Continue...";
    getch();
}



void ELEMENT::classtofile()
{
    ofstream datafile;
    datafile.open("P_data.dat",ios::app);
    datafile.write((char*)this,sizeof(*this));
    datafile.close();
}

void ELEMENT::show_data()
{
    cout<<"\n\n\t\t\t\t\t...ELEMENT DATA...\n";
    cout<<"\n\n\t\t\tElement Name : ";
    cout<<e_name;
    cout<<"\n\n\t\t\tElement Symbol : ";
    cout<<e_symbol;
    cout<<"\n\n\t\t\tAtomic Number : ";
    cout<<at_no;
    cout<<"\n\n\t\t\tAtomic Mass : ";
    cout<<at_mass;
    cout<<"\n\n\t\t\tNature : ";
    cout<<e_nature;
    cout<<"\n\n\t\t\tPeriod Number : ";
    cout<<e_period;
    cout<<"\n\n\t\t\tGroup Number : ";
    cout<<e_group;
    cout<<"\n\n\t\t\tBlock : ";
    cout<<e_block;
    cout<<"\n\n\t\t\tElement fact : ";
    cout<<e_fact<<endl<<endl;
    cout<<"Press Any Key To Continue...";
    getch();
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++ SEARCH FUNCTION +++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


void ELEMENT::search_e_details(int choice=0)
{
    int data_flag=0,atno=0;
    ifstream datafile;
    datafile.open("P_data.dat");

    if(choice==2) //ATOMIC NUMBER
    {
        cout<<"\n\nEnter Atomic Number : ";
        cin>>atno;
        datafile.read((char*)this,sizeof(*this));
        while(!datafile.eof())
            {
                if(at_no==atno)
                    {
                        data_flag=1;
                        show_data();
                        break;
                    }
                else
                datafile.read((char*)this,sizeof(*this));
            }
    }


        if(choice==3) //ELEMENT NAME
    {
        char name[21];
        strcpy(name,"No Data Available");
        cin.ignore();
        cout<<"\n\nEnter Element Name : ";
        cin.getline(name,20);
        datafile.read((char*)this,sizeof(*this));
        while(!datafile.eof())
            {
                if(strcmpi(e_name,name)==0)
                    {
                        data_flag=1;
                        show_data();
                        break;
                    }

 else
                datafile.read((char*)this,sizeof(*this));
            }
    }


        if(choice==4) //ELEMENT SYMBOL
    {
        char symbol[4];
        strcpy(symbol,"No Data Available");
        cin.ignore();
        cout<<"\n\nEnter Element Symbol : ";
        cin.getline(symbol,3);
        datafile.read((char*)this,sizeof(*this));
        while(!datafile.eof())
            {
                if(strcmpi(e_symbol,symbol)==0)
                    {
                        data_flag=1;
                        show_data();
                        break;
                    }
                else
                datafile.read((char*)this,sizeof(*this));
            }
    }


        if(choice==5) //ATOMIC MASS
    {
        float mass;
        cout<<"\n\nEnter Atomic Mass : ";
        cin>>mass;
        datafile.read((char*)this,sizeof(*this));
        while(!datafile.eof())
            {
                if(floor(at_mass)==mass||at_mass==mass)
                    {
                        data_flag=1;
                        show_data();
                        break;
                    }
                else
                datafile.read((char*)this,sizeof(*this));
            }
    }

        if(choice==6) //GROUP AND PERIOD NUMBER
    {
        int group=0,period=0;
        cout<<"\n\nEnter Group Number : ";
        cin>>group;
        cout<<"\n\nEnter Period Number : ";
        cin>>period;
        datafile.read((char*)this,sizeof(*this));
        while(!datafile.eof())
            {
                if(e_group==group&&e_period==period)
                    {
                        data_flag=1;
                        show_data();
                        break;
                    }
                else
                datafile.read((char*)this,sizeof(*this));
            }
    }

    if(data_flag!=1)
    {
        cout<<"\n\n\n\t\t\t\t\tNo Data Available...\n\n\nPress Any Key To Continue...";
        getch();
    }


    datafile.close();
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++ GRAPHIC FUNCTIONS +++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void exit_now()
{
    cout<<"\n\n\nExiting...";
    matrix();
    exit(0);
}

void p_table()
{
    char c;
    ifstream in("p.txt");
    cout << "\n\n";
    while (in.eof() == 0)
        {
            in.get(c);
            cout << c;
        }
    cout<<"\n\nPress Any key To Continue...";
    getch();
}

void matrix()
{
    for(int a;a<9999;a++)
        cout<<a;
}

void credits()
{
    cout<<"\n\n\n\t\t\t\t\t----CREDITS----";
    cout<<"\n\n\t\t\t Made by: Akshit Sharma";
    cout<<"\n\n\t\t\t Class : XII - B ";
    cout<<"\n\n\t\t\t Roll number : 12231 ";
    cout<<"\n\n\n\t\t\tSubmitted To : Mrs. Meenu Katal\n\n";
    cout<<"\nPress Any Key To Continue...";
    getch();
}

int menu()
{
    int choice=0;
    a:
    matrix();
    cout<<"\n\n\t\t\t\t\t******************************";
    cout<<"\n\t\t\t\t\t****** Periodic Table++ ******";
    cout<<"\n\t\t\t\t\t******************************";
    cout<<"\n\n\n\n\t\t1) Periodic Table";
    cout<<"\n\n\n\t\t2) Search With Atomic Number";
    cout<<"\n\n\n\t\t3) Search With Element Name";
    cout<<"\n\n\n\t\t4) Search With Element Symbol";
    cout<<"\n\n\n\t\t5) Search With Atomic Mass";
    cout<<"\n\n\n\t\t6) Search With Group And Period";
    cout<<"\n\n\n\t\t7) Credits ";
    cout<<"\n\n\n\t\t8) Exit";
    cout<<"\n\n\n\t\t9) Insert New Elements";
    cout<<"\n\n\n\t\tEnter Choice : ";
    cin>>choice;
    if(choice<=9&&choice>=1)
    {
        if(choice==1)
            p_table();

        if(choice==2)
            a1.search_e_details(2);

        if(choice==3)
            a1.search_e_details(3);

        if(choice==4)
            a1.search_e_details(4);


 if(choice==5)
            a1.search_e_details(5);

        if(choice==6)
            a1.search_e_details(6);

        if(choice==7)
            credits();

        if(choice==8)
            exit_now();

        if(choice==9)
        {
            cin.ignore();
            a1.assign_values();
            a1.classtofile();
        }

    }

    goto a;//loop to show menu
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++ MAIN FUNCTION +++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


int main()
{
    menu();
    return 0;
}
