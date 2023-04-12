string setcolor(unsigned short color){
  HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hcon,color);
  return "";
}
void intro() {
    setcolor(10);
        cout<<"\n\n\t\t\t*****************************"<<endl;
            cout<<"\t\t\t||                         ||\n\t\t\t|| ";
	string str ="Hotel Management System ||";
	for(int i=0;i<str[i];i++){
        cout<<str[i];
        Sleep(50);
	}

	cout<<"\n\t\t\t||         ";
	       str ="MADE BY         ||";
	for(int i=0;i<str[i];i++){
        cout<<str[i];
        Sleep(50);
	}
           cout<<"\n\t\t\t||      ";
           str ="Satyam Gupta       ||";
	for(int i=0;i<str[i];i++){
        cout<<str[i];
        Sleep(50);
	}
             cout<<"\n\t\t\t||                         ||";
           cout<<"\n\t\t\t*****************************";
           setcolor(15);
    getch();

}
inline void head(){
    setcolor(12);
    cout<<"\n\n\n\t\t\t\t\t||------------------------------||";
    cout<<"\n\t\t\t\t\t||  Welcome To Groups of Hotel  ||";
    cout<<"\n\t\t\t\t\t||          In JALANDHAR        ||";
    cout<<"\n\t\t\t\t\t||------------------------------||";
    setcolor(11);
    cout<<"\n\n\t-------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\t||       Enter the your nearest location from given below location:                                  ||"<<endl;
    cout<<"\t||1. Atwal House                     2. Bajwa Colony        3. Bus Stand                             ||"<<endl;
    cout<<"\t||4. Central Bank of India           5. Central Town        6. Composite Hospital                    ||"<<endl;
    cout<<"\t||7. Jalandhar City Railway Station  8. Jyoti Market        9. Master Tara Singh Nagar               ||"<<endl;
    cout<<"\t||10. Partab Bagh                    11. Preet Nagar        12. Punjab Institute of Medical Science  ||"<<endl;
    cout<<"\t||13. Royale Touch                   14. Shakti Nagar       15. The Reagent Park                     ||"<<endl;
    cout<<"\t-------------------------------------------------------------------------------------------------------";
    setcolor(15);
    cout<<endl;
}
void time(){
    setcolor(13);
    string str = "Connecting to server\n ";
    for(int i=0;i<str[i];i++){
        cout<<str[i];
        Sleep(10);
    }
    str = "\nSyncing Data";
    for(int i=0;i<str[i];i++){
        cout<<str[i];
        Sleep(10);
    }
    for(int i=0;i<10;i++){
        cout<<".";
        Sleep(50);
    }
}
inline void head_sunrise(){
    setcolor(3);
     cout<<"\n\n\n\t\t\t\t\t||------------------------------||";
    cout<<"\n\t\t\t\t\t||   Welcome To HOTEL SUNRISE   ||";
    cout<<"\n\t\t\t\t\t||          In JALANDHAR        ||";
    cout<<"\n\t\t\t\t\t||------------------------------||";
    setcolor(15);
}
inline void head_western(){
      setcolor(6);
     cout<<"\n\n\n\t\t\t\t\t||------------------------------||";
    cout<<"\n\t\t\t\t\t||   Welcome To BEST WESTERN    ||";
    cout<<"\n\t\t\t\t\t||          In JALANDHAR        ||";
    cout<<"\n\t\t\t\t\t||------------------------------||";
    setcolor(15);
}
inline void head_dolphin(){
    setcolor(10);
     cout<<"\n\n\n\t\t\t\t\t||------------------------------||";
    cout<<"\n\t\t\t\t\t||   Welcome To HOTEL DOLPHIN   ||";
    cout<<"\n\t\t\t\t\t||          In JALANDHAR        ||";
    cout<<"\n\t\t\t\t\t||------------------------------||";
    setcolor(15);
}
