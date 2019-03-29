#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#define total_seats 140
using namespace std;

// node declaration for the linked list of seats
// each node stores security code of the seat
struct node
{
    int info;
    struct node *next;
};


//Class Declaration
class single_llist
{
    public:
        node* create_node(int);
        void insert_begin(int);
        void delete_pos(int,int);
        void display(int);

};

void admin(void);
void customer(void);
void cancel(void);
int search_sec(int);

single_llist sl;            // class object for the linked list declared


/*parameters for the seating arrangement defined */

#define rows 10
#define columns 14
int row2,col2,z,i,j;
int menu ();
void chart ();
const char FULL = 'B',EMPTY = '.';
char arran[rows][columns];
char now_showing[]="yet to be added",show_time[]="yet to be added ",*housefull []={"filling fast "};
int total = 0,rem = 140,bkd = 0,sta=1;
int price[rows];
int cost,ans;
struct node *master[10];            // IMP: an array of structure pointers declared - meaning an array is declared where
                                    //each element is a head node of a single linked list representing that row


// search function: for finding the security code (linear search)
int search_sec(int sec)
{
    int array_security[total_seats];
    int state=0,i;
    for(i=0;i<140;i++)
    {
        if(array_security[i]==sec)
            state=1;
    }

    if(state==1)
        return 1;
    else
        return 0;
}



int main()
{
int i1,j1;
//head node of each linked list initialised to NULL
for(z=0;z<10;z++)
{
    master[z]=NULL;
}

//initialising the security codes
int array_security[total_seats],p=0;

for(i1=1;i1<=10;i1++)
{
    for(j1=1;j1<=14;j1++)
    {
        array_security[p]=(i1*100)+(j1);
        p++;
    }

}

// for setting the '.' symbol to empty seats

for (i = 0; i < rows; i++)
    {
    for (j = 0; j < columns; j++)
    arran[i][j] = EMPTY;
    }
int choose1;
do
{
cout<<"\t*********************************************************\n";
cout<<"\t*      MOVIE SEAT BOOKING SYSTEM     *\n";
cout<<"\t*      a data structure project      *\n";
cout<<"\t*      using linked list and array   *\n";
cout<<"\t*    welcome to our small theatre    *\n";
cout<<"\t*                                    *\n";
cout<<"\t*********************************************************\n\n\n";


cout<<"\n\t MAIN MENU ";
cout<<"\nselect from the following ";
cout<<"\n1.ADMIN";
cout<<"\n2.CUSTOMER ";
cout<<"\n3.exit"<<endl;
cin>>choose1;

switch(choose1)
{
case 1:
    admin();
    break;

case 2:
    customer();
    break;

case 3:
    cout<<endl<<"..exiting the program ..";
    exit(0);
    break;

default:
    cout<<"\nerror:wrong input"<<endl<<"\tenter correct value ";
}
}while(choose1!=3);

return 0;
}



//********************function definitions ************************************************************



void admin()
{
int cho_admin;
do
{

cout<<"\n---------------------------------------------------------";
cout<<"\n---------------------------------------------------------";
cout<<"\n\tWELCOME ADMINSTRATOR";
cout<<"\n\twarning:be careful with the admin settings";
cout<<"\nchoose the correct option "<<endl<<endl;
cout<<endl<<"1. adding/modifying the prices of the seats ";
cout<<endl<<"2. display the security codes of the seats ";
cout<<endl<<"3. change the movie details displayed to the customer ";
cout<<endl<<"4. declaring HOUSEFULL";
cout<<endl<<"5. display the number of tickets sold";
cout<<endl<<"6. return to the main menu"<<endl;
cin>>cho_admin;
switch(cho_admin)
{
case 1:
    cout<<endl;
    cout<<"\nSET THE PRICES FOR THE TICKETS ";
for (i = 0; i < rows; i++)
    {

    cout<<"Please enter the price for row "<<(i + 1);
    if(i<4)
        cout<<"\nGOLD CLASS ROW  ";
    else
        cout<<"\nREGULAR CLASS ROW ";
    cin>>price [i];
    }
    break;

case 2:
    cout<<endl;
    cout<<"\nadministrator priviledge:\n";
    for(row2=0;row2<10;row2++)
    {
        sl.display(row2);
    }
    break;

case 3:
    cout<<"\nenter the movie details";
    cout<<endl<<"designate the movie NOW SHOWING"<<endl;
    cin>>now_showing;
    cout<<endl<<"enter the show time "<<endl;
    cin>>show_time;
    break;

case 4:
    char yes;
    cout<<"\ndo you want to declare house full?(y/n)";
    cin>>yes;
    if(yes=='y')
    {
        *housefull="HOUSEFULL:no more tickets available";
    }

         break;

case 5:
    cout<<"\nTotal ticket sales: "<<bkd;
    break;

case 6:
    cout<<"...returning to main menu ..."<<endl<<endl;
    break;

default:
    cout<<"\nerror:wrong input"<<endl<<"\tenter correct value ";
    break;

}
}while(cho_admin!=6);

}


void customer()
{

int cho_customer;
do
{
cout<<endl<<endl;
cout<<"\n\t----------------------------------------------";
cout<<"\n\t........Esteemed Customer......... ";
cout<<"\nwelcome to KIONISK cinemas: an experience like no other ";
cout<<"\n\tselect the correct option:";
cout<<"\n\t1.show movie details ";
cout<<"\n\t2.show the ticket prices ";
cout<<"\n\t3.show available seats ";
cout<<"\n\t4.book your seat ";
cout<<"\n\t5.cancel your booking ";
cout<<"\n\t6.return to main menu";
cout<<"\n\t-------------------------------------------------"<<endl;
cin>>cho_customer;

switch(cho_customer)
{
case 1:
    cout<<endl<<"Currently showing movie "<<now_showing;
    cout<<endl<<"The show time is "<<show_time;
    break;

case 2:
    cout<<"\nshow seat prices\n\n";

        for (i= 0; i< rows;i++)
       {
        cout<<"\nThe price for row "<<(i+ 1);
        if(i<4)
        cout<<"\nGOLD CLASS ROW";
        else
        cout<<"\nREGULAR CLASS ROW ";

        cout<<"\n"<<price[i];
       }
        break;

case 3:
    cout<<"\nView Available Seats\n\n";
    cout<<"\nseats status "<<*housefull<<endl<<endl;
    chart ();
    break;

case 4:
    cout<<"\n...........................................\n";
    cout<<"\nPURCHASE A TICKET";
    do
    {
       int input_row,input_column;
       cout<<"\nPlease select the row you would like to sit in: ";
       cin>>row2;
       input_row=row2;
       while(input_row<1 || input_row>10)
       {
       	cout<<"Please Enter Valid Row detail !";
	   cout<<"\nPlease select the row you would like to sit in: ";
	   cin>>row2;
	   input_row=row2;
	   }

       cout<<"\nPlease select the column you would like to sit in: ";
       cin>>col2;
       input_column=col2;
       while(input_column<1 || input_column>14)
       {
       	cout<<"Please Enter Valid Column detail !";
	   cout<<"\nPlease select the column you would like to sit in: ";
	   cin>>col2;
	   input_column=col2;
	   }

         row2--;col2--;
                if (arran[row2][col2] == 'B')
                        {
                            cout<<"\nAWWW seat is sold-out, select a new seat."<<endl;
                        }
                else
                    {
                        cost = price [row2] + 0;
                        total = total + cost;
                        cout<<"\nThat ticket costs: "<<cost;
                        cout<<"\nConfirm Purchase? Enter (1 = YES / 0 = NO)"<<endl;
                        cin>>ans;
                        rem=rem-ans;
                        bkd=bkd+ans;



                        if (ans== 1)
                        {
                        cout<<"\nYour ticket purchase has been confirmed."<<endl;
                            arran [row2][col2] = FULL;
                            cout<<endl<<row2;
                            sl.insert_begin(row2);
                        }
                        else if (ans== 0)
                        {
                        cout<<"\nWould you like to look at another seat? (1 = YES / 2 = NO)";
                        cin>>sta;
                        }

                        cout<<"\nWould you like to look at another seat?(1 = YES / 2 = NO)";
                        cin>>sta;
                    }
        }
        while (sta == 1);
    break;

case 5:
    cout<<"\n\n...cancellation of booking selected ...";
    cancel();
    break;

case 6:
    cout<<"\n\n...returning to main menu ...\n\n";
    break;

default:
    cout<<"\nerror:wrong input"<<endl<<"\tenter correct value ";
    break;
}
}while(cho_customer!=6);

}



void cancel()
{
    int can,sec,can2,can3;
    char canc2='n';

    do
    {
    cout<<endl<<"..please enter the row of your seat.. ";
    cin>>can;
    cout<<endl<<"please enter the security code "<<"\n which you received during the booking of your seat ";
    cin>>sec;

    can2=sec-(can*100);

    can--;can2--;

    if(search_sec(sec)==1)
        {
        cout<<endl<<"...security code matched..... "<<endl;
        cout<<endl<<"..... cancellation in progress ...."<<endl;
        arran [can][can2] = EMPTY;

        sl.delete_pos(can,sec);
        }
    else
        cout<<endl<<"no such security code found "<<endl<<"recheck the code entered ";
    cout<<endl;
    cout<<"do you want to cancel another seat ?(y/n)"<<endl;
    cin>>canc2;
    }while(canc2=='y');


}


void chart ()
{

cout<<"\n\tSeats";
cout<<"\n\t    1    2    3    4    5    6    7    8    9    10   11   12   13   14 \n";
int i,j;
    for (i= 0;i< 10;i++)
    {
      printf("\nRow %d\t",i+1);
         for (j= 0;j< 14;j++)
        {
        printf("    %c",arran[i][j]);
        }
    }
    printf("\n\n--------------------------------------------------------------------------------");
    printf("\n\t\t                            screen this way ");
}




//****************************
//linked list function defined
int choice, nodes, element, position;


//Creating Node

node *single_llist::create_node(int value)
{
    struct node *temp, *s;
    temp = new(struct node);
    if (temp == NULL)
    {
        cout<<"Memory not allocated "<<endl;
        return 0;
    }
    else
    {
        temp->info = value;
        temp->next = NULL;
        return temp;
    }
}

/*
 * Inserting element in beginning
 */
void single_llist::insert_begin(int)
{

    int val;
    val=((row2+1)*100+(col2+1));            //generates security code
    struct node *temp, *p;

    temp = create_node(val);
    if (master[row2] == NULL)
    {
        master[row2] = temp;
        master[row2]->next = NULL;
    }
    else
    {
        p = master[row2];
        master[row2] = temp;
        master[row2]->next = p;
    }

    cout<<"\n...ticket booking in process ....\n"<<endl<<endl;
    cout<<"your security code for the booked ticket is "<<endl<<val<<"\nplease remember it for future reference ";

    //sorting the linked list : to allow the row order to be maintained in linked list

    struct node *ptr, *s;
    if (master[row2] == NULL)
    {
        cout<<"NO BOOKINGS MADE YET"<<endl;
        return;
    }

    ptr = master[row2];
    while (ptr != NULL)
    {
        for (s = ptr->next;s !=NULL;s = s->next)
        {
            if (ptr->info > s->info)
            {
                val = ptr->info;
                ptr->info = s->info;
                s->info = val;
            }
        }
        ptr = ptr->next;
    }
}


//deleting a seat code
void single_llist::delete_pos(int can,int can2)
{
    int i, counter = 0;
    if (master[can] == NULL)
    {
        cout<<"NO BOOKINGS MADE YET"<<endl;
        return;
    }

    struct node *s, *ptr,*del;

    s = master[can];
    /*if (can2 == 1)
    {
        master[can] = s->next;
    }
    else
    {*/
        do
        {

            counter++;
            if(s->info==can2)
            {
            del=s;
            break;
            }
            s = s->next;


        }while (s != NULL);


            s = master[can];
            if(counter==1)
            {
                master[can]=s->next;
            }
            else
            {
            for (i = 1;i < counter;i++)
            {
                ptr = s;
                s = s->next;
            }
            ptr->next = s->next;

            }
        free(s);
        cout<<"cancellation successful"<<endl;

}

//displaying the security code in each node of linked list

void single_llist::display(int)
{
    struct node *temp;
    if (master[row2] == NULL)
    {
        cout<<"NO BOOKINGS MADE YET"<<endl;
        return;
    }
    temp = master[row2];
    cout<<"GENERATED SECURITY CODES: "<<endl;
    while (temp != NULL)
    {
        cout<<temp->info<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
