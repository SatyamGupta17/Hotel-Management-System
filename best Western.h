class Best_Western :public My_Hotel_Management{
    public:
        Best_Western(){}
        Best_Western( int room ){
                room_no = room ;
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
		        //try to enter data in text form
        }
            friend void display_object(Best_Western);
            friend int fare_per_day(Best_Western  );
			friend int fare_per_day(Best_Western , int);
            void main_menu();		//to display the main menu
			void add();				//to book a room
			void display(); 		//to display the customer record
			void rooms();			//to display allotted rooms
			void edit();			//to edit the customer record
//			void booked();
			int check(int);	     	//to check room status
			void modify(int);		//to modify the record
			void delete_rec(int);   //to delete the record
            Best_Western operator +(Best_Western);  //to add total fare
};
void display_object(Best_Western obj_best){
			cout<<"\n \t\t*******************";
			if(obj_best.speciality_level == 'y'){
                setcolor(6);
			    cout<<"\n \tType: special room"<<endl;
			}
			else
                cout<<"\n \tType:Normal room"<<endl;
			cout<<"\n \t\tRoom no: "<<obj_best.room_no;
			cout<<"\n \t\tName: "<<obj_best.name;
			cout<<"\n \t\tAddress: "<<obj_best.address;
			cout<<"\n \t\tPhone no: "<<obj_best.phone;
			cout<<"\n \t\tDays: "<<obj_best.days;
			cout<<"\n \t\tTotal Fare: "<<obj_best.fare;
			setcolor(15);
}
int fare_per_day(Best_Western obj_best){
    int y = obj_best.days * 900;
    return y;
}
int fare_per_day(Best_Western obj_best, int num){
    int y = obj_best.days*1200;
    return y;
}
void Best_Western ::main_menu(){
    int choice;
	while(1) {
    system("cls");
		head_western();
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
Best_Western obj_best;
void Best_Western::add(){
    system("cls");
    head_western();
	int r,flag ;
	ofstream fout("Record of Western.bin",ios::binary|ios::app);
	cout<<"\n Enter Customer Details";
	cout<<"\n ----------------------";
	cout<<"\n\n Room no: ";
	cin>>r;
	flag=check(r);
	if(flag)
		cout<<"\n Sorry..!!!Room is already booked";
	else {
		 Best_Western obj_best(r);
		if(obj_best.speciality_level =='y')
		obj_best.fare = fare_per_day(obj_best,1);
		else
            obj_best.fare = fare_per_day(obj_best);
		fout.write((char*)&obj_best,sizeof(Best_Western));
		cout<<"\n Room is booked...!!!";
	}

	cout<<"\n Press any key to continue.....!!";
	getch();
	fout.close();
}
void Best_Western::display(){
    system("cls");
	ifstream fin("Record of Western.bin",ios::in|ios::binary);
	int r,flag;
	cout<<"\n Enter room no: ";
	cin>>r;
          system("cls");
	while(!fin.eof()) {
		fin.read((char*)&obj_best,sizeof(Best_Western));
		if(obj_best.room_no==r) {
			display_object(obj_best);
			flag=1;
		}
	}
	fin.close();
	if(flag==0)
		cout<<"\n Sorry Room no. not found or vacant....!!";
	cout<<"\n\n Press any key to continue....!!";
	getch();
}
void Best_Western::rooms(){
    system("cls");
	head_western();
	ifstream fin("Record of Western.bin",ios::in|ios::binary);
	cout<<"\n\t\t\t    List Of Rooms Allotted";
	cout<<"\n\t\t\t    ----------------------";
	while(!fin.eof()) {
		fin.read((char*)&obj_best,sizeof(Best_Western));
		   display_object(obj_best);
	}
	cout<<"\n\n\n\t\t\tPress any key to continue.....!!";
	getch();
	fin.close();
}
void Best_Western::edit(){
    system("cls");
    head_western();
	int choice,r;
	setcolor(5);
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
	}
	cout<<"\n Press any key to continue....!!!";
	getch();
	setcolor(15);
}
int Best_Western::check(int r){
    int flag=0;
	ifstream fin("Record of Western.bin",ios::in|ios::binary);
	while(!fin.eof()) {
		fin.read((char*)&obj_best,sizeof(Best_Western));
		if(obj_best.room_no==r) {
			flag=1;
			break;
		}
	}
	fin.close();
	return(flag);
}
Best_Western Best_Western :: operator +(Best_Western obj_best) {
    Best_Western temp;
    temp.room_no = room_no + obj_best.room_no;
    temp.fare = fare + obj_best.fare;
    return temp;
}
void Best_Western::modify(int r) {
	system("cls");
	head_western();
	long pos,flag=0;
	fstream file("Record of Western.bin",ios::in|ios::out|ios::binary);
	while(!file.eof()) {
		pos = file.tellg();
		file.read((char*)&obj_best,sizeof(Best_Western));
		if(obj_best.room_no==r) {
			cout<<"\n \t\tName: ";
			fflush(stdin);
			gets(obj_best.name);
			cout<<" \t\tAddress: ";
			gets(obj_best.address);
			cout<<" \t\tPhone no: ";
			gets(obj_best.phone);
			cout<<" \t\tDays: ";
			cin>>obj_best.days;
			cout<<"\t\tDo you want to special room(y/n):";
			cin>>obj_best.speciality_level;
			if(obj_best.speciality_level == 'y'){
			obj_best.fare = fare_per_day(obj_best,1);
			}
			else{
			obj_best.fare = fare_per_day(obj_best);}
			file.seekg(pos);
			file.write((char*)&obj_best,sizeof(Best_Western));
			cout<<"\n Record is modified....!!";
			flag=1;
			break;
		}
	}

	if(flag==0)
		cout<<"\n Sorry Room no. not found or vacant...!!";
	file.close();
}

void Best_Western::delete_rec(int r) {
    system("cls");
	head_western();
	int flag=0;
	char ch;
	ifstream fin("Record of Western.bin",ios::in);
	ofstream fout("temp of Western.bin",ios::out);
	while(!fin.eof()) {
		fin.read((char*)&obj_best,sizeof(Best_Western));
		if(obj_best.room_no==r) {
		     display_object(obj_best);
			cout<<"\n\t\t\n Do you want to delete this record(y/n): ";
			cin>>ch;
			if(ch=='n')
				fout.write((char*)&obj_best,sizeof(Best_Western));
			flag=1;
		}
		else
			fout.write((char*)&obj_best,sizeof(Best_Western));
	}

	fin.close();
	fout.close();
	if(flag==0)
		cout<<"\n Sorry room no. not found or vacant...!!";
	else {
		remove("Record of Western.bin");
		rename("temp of Western.bin","Record of Western.bin");
	}
}
