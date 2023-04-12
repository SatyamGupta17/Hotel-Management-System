#include<fstream>
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
#include<dos.h>
#include<windows.h>
using namespace std;

class My_Hotel_Management{
   protected:
            int room_no;
			char name[30];
			char address[50];
			char phone[15];
			int days;
			float fare;
			char speciality_level;
   public:
            void hotel_name();
            virtual void main_menu()=0;		//to display the main menu
			virtual void add()=0;			//to book a room
			virtual void display()=0; 		//to display the customer record
			virtual void rooms()=0;			//to display allotted rooms
			virtual void edit()=0;			//to edit the customer record
			virtual int check(int)=0;	    //to check room status
			virtual void modify(int)=0;		//to modify the record
			virtual void delete_rec(int)=0; //to delete the record
};

My_Hotel_Management *h;
#include"design.h"
#include"hotel sunrise.h"
#include"best Western.h"
#include"hotel dolphin.h"
    Hotel_Sunrise sun;
    Best_Western west;
    Hotel_Dolphin dol;
void My_Hotel_Management::hotel_name(){
    int choice;
	while(choice!=4) {
    system("cls");
        setcolor(14);
		cout<<"\n\t\t\t\t---------------";;
		cout<<"\n\t\t\t\t|  HOTEL NAME  |";
		cout<<"\n\t\t\t\t---------------";
		cout<<"\n\n\n\t\t\t1.Hotel Sunrise";
		cout<<"\n\t\t\t2.Best Western";
		cout<<"\n\t\t\t3.Hotel Dolphin";
		cout<<"\n\t\t\t4.Exit";
		cout<<"\n\n\t\t\tEnter Your Choice: ";
		setcolor(15);
		cin>>choice;
		switch(choice) {

			case 1:{
					 h = &sun;
					 h->main_menu();
			       }
					 break;
			case 2:{
			         h = &west;
			         h->main_menu();
                   }
					break;
			case 3:{
                     h = &dol;
                     h->main_menu();
                   }
					break;
			case 4: break;
			default: {
				cout<<"\n\n\t\t\tWrong choice.....!!!";
				cout<<"\n\t\t\tPress any key to continue....!!";
				getch();
			}
		}
	}
}
int main(){
    int location_number;
    system("cls");
    intro();
    int identity;
    do {
            system("cls");
    cout<<endl<<"\t\t\t1. Hotel Administrator 2. User/Consumer 3. Exit"<<endl;
    cout<<"\t\tEnter the choice:";
    cin>>identity;
    if(identity == 1)
    {
        system("cls");
        string id;
        char password[15];
        cout<<"\n\n\t\t\t\tUsername => ";
	    cin>>id;
	    if(id == "Satyam"){
	         cout<<"\n\t\t\t\tPassword => ";
	         int i=0;
	         for(i=0;i<5;i++){
                password[i] = getch();
                cout<<'*';
	         }
	         cout<<"\n\n\t";
            time();
	        if(strcmp(password, "gupta")!= 0){
                cout<<"Incorrect Password\n";
          }
	        else{
                cout<<"\t\tLogin Successfully....."<<endl;
            h -> hotel_name();
	        }
	    }
	    else {
                cout<<"\t\tINVALID CREDENTIALS!!";
        getch();
	    }
	    setcolor(15);
    }
    if(identity == 2){
            system("cls");
    head();
    cout<<"Choose the nearest location to you:";
    cin>>location_number;
       if(location_number == 2 ||location_number == 4 ||location_number == 5 ||
          location_number == 9 ||location_number == 10) {
           Hotel_Sunrise sunrise;
           h = &sunrise;
            h -> add();
       }
        else if(location_number == 1||location_number == 3 ||location_number == 6 ||
          location_number == 11 ||location_number == 12){
           Best_Western best;
           h = &best;
           h -> add();
       }
       else if(location_number == 7||location_number == 8 ||location_number == 13 ||
          location_number == 14 ||location_number == 15){
           Hotel_Dolphin dolphin;
           h = &dolphin;
           h -> add();
       }
       else
         cout<<"Sorry Sir, There is no hotel in your nearest location choose other location...  "<<endl;
     }
  }while(identity!=3);
     return 0;
}
