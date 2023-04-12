
class Hotel_Dolphin : public My_Hotel_Management{
    public:
        Hotel_Dolphin(){}
            Hotel_Dolphin( int room ){
                room_no = room;
                fflush(stdin);
			    cout<<" Name: ";
		        gets(name);
		        cout<<" Address: ";
		        gets(address);
		        cout<<" Phone No: ";
		        gets(phone);
                cout<<" No of Days to Checkout: ";
		        cin>>days;
		        cout<<"Do you want to special room (y/n):";
		        cin>>speciality_level;
        }
            friend void display_object(Hotel_Dolphin); //to display obj_dolect data
            friend int fare_per_day(Hotel_Dolphin  );
			friend int fare_per_day(Hotel_Dolphin , int);
            void main_menu();		//to display the main menu
			void add();				//to book a room
			void display(); 		//to display the customer record
			void rooms();			//to display allotted rooms
			void edit();			//to edit the customer record
			int check(int);	     	//to check room status
			void modify(int);		//to modify the record
			void delete_rec(int);   //to delete the record
			Hotel_Dolphin operator +(Hotel_Dolphin);  //to add total fare
};
void display_object( Hotel_Dolphin obj_dol){
			cout<<"\n \t\t******************\n";
			if(obj_dol.speciality_level == 'y'){
                setcolor(6);
			    cout<<"\n \tType: special room"<<endl;
			}
			else
                cout<<"\n \tType:Normal room"<<endl;
			cout<<"\n \t\tRoom no: "<<obj_dol.room_no;
			cout<<"\n \t\tName: "<<obj_dol.name;
			cout<<"\n \t\tAddress: "<<obj_dol.address;
			cout<<"\n \t\tPhone no: "<<obj_dol.phone;
			cout<<"\n \t\tDays: "<<obj_dol.days;
			cout<<"\n \t\tTotal Fare: "<<obj_dol.fare;
			setcolor(15);
}
int fare_per_day(Hotel_Dolphin obj_dol){
    int y = obj_dol.days * 900;
    return y;
}
int fare_per_day(Hotel_Dolphin obj_dol, int num){
    int y = obj_dol.days * 1200;
    return y;
}
void Hotel_Dolphin::main_menu(){
    int choice;
	while(1) {
    system("cls");
    head_dolphin();
		cout<<"\n\t\t\t\t\t\t   *************";
		cout<<"\n\t\t\t\t\t\t   * MAIN MENU *";
		cout<<"\n\t\t\t\t\t\t   *************";
		cout<<"\n\n\n\t\t\t1.Customer Record";
		cout<<"\n\t\t\t2.Rooms Allotted";
		cout<<"\n\t\t\t3.Edit Record";
		cout<<"\n\t\t\t4.Exit";
		cout<<"\n\n\t\t\tEnter Your Choice: ";
		cin>>choice;
		switch(choice) {
			case 1: display();
					break;
			case 2: rooms();
					break;
			case 3:	edit();
					break;
			case 4: return ;
			        break;
			default: {
				cout<<"\n\n\t\t\tWrong choice.....!!!";
				cout<<"\n\t\t\tPress any key to continue....!!";
				getch();
			}
		}
	}
}
Hotel_Dolphin obj_dol;
void Hotel_Dolphin::add(){
    system("cls");
    head_dolphin();
	int r,flag;
	ofstream fout("Record of Dolphin.bin",ios::binary|ios::app);
	cout<<"\n Enter Customer Details";
	cout<<"\n ----------------------";
	cout<<"\n\n Room no: ";
	cin>>r;
	flag=check(r);
	if(flag)
		cout<<"\n Sorry..!!!Room is already booked";
	else {
		 Hotel_Dolphin obj_dol(r);
		if(obj_dol.speciality_level =='y')
		obj_dol.fare = fare_per_day(obj_dol,1);
		else
            obj_dol.fare = fare_per_day(obj_dol);
		fout.write((char*)&obj_dol,sizeof(Hotel_Dolphin));
		cout<<"\n Room is booked...!!!";
	}

	cout<<"\n Press any key to continue.....!!";
	getch();
	fout.close();
}
void Hotel_Dolphin::display(){
    system("cls");
	ifstream fin("Record of Dolphin.bin",ios::in|ios::binary);
	int r,flag;
	cout<<"\n Enter room no: ";
	cin>>r;
        system("cls");
	while(!fin.eof()) {
		fin.read((char*)&obj_dol,sizeof(Hotel_Dolphin));
		if(obj_dol.room_no == r) {
			 display_object(obj_dol);
			flag=1;
		}
	}
	fin.close();
	if(flag==0)
		cout<<"\n Sorry Room no. not found or vacant....!!";
	cout<<"\n\n Press any key to continue....!!";
	getch();
}
void Hotel_Dolphin::rooms(){
    system("cls");
	head_dolphin();
	ifstream fin("Record of Dolphin.bin",ios::in|ios::binary);
	cout<<"\n\t\t\t    List Of Rooms Allotted";
	cout<<"\n\t\t\t    ----------------------";
	while(!fin.eof()) {
		fin.read((char*)&obj_dol,sizeof(Hotel_Dolphin));
        display_object(obj_dol);
	}
	cout<<"\n\n\n\t\t\tPress any key to continue.....!!";
	getch();
	fin.close();
}
void Hotel_Dolphin::edit()
{
    system("cls");
    head_dolphin();
	int choice,r;
	setcolor(4);
	cout<<"\n\t\t\t\t\t\t ***************";
	cout<<"\n\t\t\t\t\t\t *  EDIT MENU  *";
	cout<<"\n\t\t\t\t\t\t ***************";
	cout<<"\n\n\t\t\t\t 1.Modify Customer Record";
	cout<<"\n\t\t\t\t 2.Delete Customer Record";
	cout<<"\n\t\t\t\t Enter your choice: ";
	cin>>choice;
    switch(choice) {
		case 1:	{cout<<"\n Enter room no: " ;
	            cin>>r;
	            modify(r);
            }
				break;
		case 2:	{cout<<"\n Enter room no: " ;
	            cin>>r;
		        delete_rec(r);
            }
				break;
		default: cout<<"\n Wrong Choice.....!!";
	}	cout<<"\n Press any key to continue....!!!";
	 setcolor(15);
	getch();
}
int Hotel_Dolphin::check(int r){
    int flag=0;
	ifstream fin("Record of Dolphin.bin",ios::in|ios::binary);
	while(!fin.eof()) {
		fin.read((char*)&obj_dol,sizeof(Hotel_Dolphin));
		if(obj_dol.room_no==r) {
			flag=1;
			break;
		}
	}
	fin.close();
	return(flag);
}
Hotel_Dolphin Hotel_Dolphin :: operator +(Hotel_Dolphin obj_dol) {
    Hotel_Dolphin temp;
    temp.room_no = room_no + obj_dol.room_no;
    temp.fare = fare + obj_dol.fare;
    return temp;
}
void Hotel_Dolphin::modify(int r) {
    system("cls");
	head_dolphin();
	long pos,flag=0;
	fstream file("Record of Dolphin.bin",ios::in|ios::out|ios::binary);
	while(!file.eof()) {
		pos=file.tellg();
		file.read((char*)&obj_dol,sizeof(Hotel_Dolphin));
		if(obj_dol.room_no==r) {
			cout<<"\n\n\t\t Enter New Details";
			cout<<"\n \t\t-----------------";
			cout<<"\n \t\tName: ";
			fflush(stdin);
			gets(obj_dol.name);
			cout<<" \t\tAddress: ";
			gets(obj_dol.address);
			cout<<" \t\tPhone no: ";
			gets(obj_dol.phone);
			cout<<" \t\tDays: ";
			cin>>obj_dol.days;
			cout<<"\t\tDo you want to special room(y/n):";
			cin>>obj_dol.speciality_level;
			if(obj_dol.speciality_level == 'y'){
			obj_dol.fare = fare_per_day(obj_dol,1);
			}
			else{
			obj_dol.fare = fare_per_day(obj_dol);}
			file.seekg(pos);
			file.write((char*)&obj_dol,sizeof(Hotel_Dolphin));
			cout<<"\n Record is modified....!!";
			flag=1;
			break;
		}
	}

	if(flag==0)
		cout<<"\n Sorry Room no. not found or vacant...!!";
	file.close();
}

void Hotel_Dolphin::delete_rec(int r) {
	system("cls");
	head_dolphin();
	int flag=0;
	char ch;
	ifstream fin("Record of Dolphin.bin",ios::in);
	ofstream fout("temp of Dolphin.bin",ios::out);
	while(!fin.eof()) {
		fin.read((char*)&obj_dol,sizeof(Hotel_Dolphin));
		if(obj_dol.room_no==r) {
		    display_object(obj_dol);
			cout<<"\n\t\t\n Do you want to delete this record(y/n): ";
			cin>>ch;
			if(ch=='n')
				fout.write((char*)&obj_dol,sizeof(Hotel_Dolphin));
			flag=1;
		}
		else
			fout.write((char*)&obj_dol,sizeof(Hotel_Dolphin));
	}

	fin.close();
	fout.close();
	if(flag==0)
		cout<<"\n Sorry room no. not found or vacant...!!";
	else {
		remove("Record of Dolphin.bin");
		rename("temp of Dolphin.bin","Record of Dolphin.bin");
	}
}
