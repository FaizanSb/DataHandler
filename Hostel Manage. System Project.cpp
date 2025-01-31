#include <iostream>

#include <string>
#include <fstream>

using namespace std;

class Hostel 
{
 private:
    string hostelName;
    string location;
    string contactNo;

 public:
//    void setData(const string& name, const string& loc, const string& contact) 
//	{
//        hostelName = name;
//        location = loc;
//        contactNo = contact;
//    }

    void getData() const 
	{
        cout<<"\t\t------------------------------\t\t"<<endl;
        cout<<"\t\t------------------------------\t\t"<<endl;
		cout<<"\t\t  Hostel Name: * Jamia Hostel *\t\t"<<endl ;          //<<hostelName<<endl;
        cout<<"\t\t  Location:        Jhang Road Chinio\t\t"<<endl;              //<<location<<endl;
        cout<<"\t\t  Contact Number:  0315-7249304\t\t"<<endl;        //<< contactNo<<endl;
        cout<<"\t\t------------------------------\t\t"<<endl;
        cout<<"\t\t------------------------------\t\t"<<endl;
    }
};

class Person
{
 protected:
    string ID;
    string name;
    string fatherName;
    string age;
    string email;
    string cnic;
    string phoneNumber;
    string address;
    string comingDate;

 public:


};

class Admin : public Person 
{
	private:
		char ch;
public:
	
	
    void addHostile() 
	{
		
       // string comingDate;
        ad:
        cout << "\nEnter ID: ";
        cin >> ID;
        cout << "\nEnter Name: ";
        cin.ignore(); // Add this line to clear the input buffer
        getline(cin, name);
        cout << "\nEnter Father Name: ";
        getline(cin, fatherName);
        cout << "\nEnter Age: ";
        cin >> age;
        cout << "\nEnter Email: ";
        cin.ignore();
        getline(cin, email);
        cout << "\nEnter CNIC: ";
        getline(cin, cnic);
        cout << "\nEnter Phone Number: ";
        getline(cin, phoneNumber);
        cout << "\nEnter Address: ";
        getline(cin, address);
        cout << "\nEnter Coming Date: ";
        getline(cin, comingDate);
        cout << "Data has been added Successfully." << endl;
        
       
		

		
        ofstream file("Hostel Record.txt", ios::app);
        if (!file)
            cerr << "Error opening File" << endl;

        file << ID << endl;
        file << name << endl;
        file << fatherName << endl;
        file << age << endl;
        file << email << endl;
        file << cnic << endl;
        file << phoneNumber << endl;
        file << address << endl;
        file << comingDate << endl;
        file.close();
        
    }

    void displayHostile() 
	{
        ifstream file("Hostel Record.txt");
        string fileId;
		//string comingDate;
		
        cout << "\t\t**********************" << endl;
        cout << "\t\t                        Hostile Data                          " << endl;
        cout << "\t\t**********************" << endl;

        while (getline(file,fileId)) 
		{
			
          	cout << "ID: " << fileId << endl;
	    	getline(file,name);
	        cout << "Name: " << name << endl;
	        getline(file,fatherName);
	        cout << "Father Name: " << fatherName << endl;
	        getline(file,age);
	        cout << "Age: " << age << endl;
	        getline(file,email);
	        cout << "Email: " << email << endl;
	        getline(file,cnic);
	        cout << "CNIC: " << cnic << endl;
	        getline(file,phoneNumber);
	        cout << "Phone Number: " << phoneNumber << endl;
	        getline(file,address);
	        cout << "Address: " << address << endl;
	        getline(file,comingDate);
	
	        cout << "Coming Date: " << comingDate << endl;        
	        cout<<"\n-----------------------------------------"<<endl;
        }
        file.close();
    }

    void searchHostile() 
	{
	       	bool found=false;
    		string fileId;
    		//string comingDate;
    		ifstream file("Hostel Record.txt");
    		
    		cout<< "Enter Hostile ID: ";
    		cin>>ID;
    		
    		while(getline(file,fileId))
			{
    		
				if (ID==fileId){
    				
	    			cout << "ID: " << fileId << endl;
	    			getline(file,name);
	                cout << "Name: " << name << endl;
	                getline(file,fatherName);
	                cout << "Father Name: " << fatherName << endl;
	                getline(file,age);
	                cout << "Age: " << age << endl;
	                getline(file,email);
	                cout << "Email: " << email << endl;
	                getline(file,cnic);
	                cout << "CNIC: " << cnic << endl;
	                getline(file,phoneNumber);
	                cout << "Phone Number: " << phoneNumber << endl;
	                getline(file,address);
	                cout << "Address: " << address << endl;
	                getline(file,comingDate);
	
	                cout << "Coming Date: " << comingDate << endl;
	                found=true;
	                break;
    			
				}
    				
			}
			if (!found){
    				cout<<"Incorrect ID "<<endl;
				}
    		
    }
    

    void removeHostile()
{
    string removeid;
	string id;
    cout << "Enter ID of the Hostile to remove: ";
    cin >> id;
    
    ifstream file("Hostel Record.txt");
    ofstream outFile("temp.txt", ios::app);
        file >> ID;
        file >> name;
        file >> fatherName;
        file >> age;
        file >> email;
        file >> cnic;
        file >> phoneNumber;
        file >> address;
        file >> comingDate;
       // file.close();

    while(getline(file, removeid ))
    {
    	if(id!= removeid)
    	{
    	outFile << ID << endl;
        outFile << name << endl;
        outFile << fatherName << endl;
        outFile << age << endl;
        outFile << email << endl;
        outFile << cnic << endl;
        outFile << phoneNumber << endl;
        outFile << address<<endl;
        outFile << comingDate << endl;
        outFile.close();
		}
	}

    file.close();
    outFile.close();

    remove("Hostel Record.txt");
    rename("temp.txt", "Hostel Record.txt");

    cout << "Hostile with ID " <<id<< " removed successfully." << endl;
}

void updateHostile()
{
	bool found=false;
    string fileId;
    string updateID;
    string updatename;
    string updatefatherName;
    string updateage;
    string updateemail;
    string updatecnic;
    string updatephoneNumber;
    string updateaddress;
    string updatecomingDate;
    
    cout << "Enter ID of the Hostile to update: ";
    cin >> ID;

    ifstream inFile("Hostel Record.txt");
    ofstream outFile("temp.txt");
    
    
    while(getline(inFile, fileId))
	{
	    	getline(inFile,name);
	        getline(inFile,fatherName);
	        getline(inFile,age);
	        getline(inFile,email);
	        getline(inFile,cnic);
	        getline(inFile,phoneNumber);
	        getline(inFile,address);
	        getline(inFile,comingDate);
	
			
	if (ID==fileId)
	{
	    cout << "\nEnter ID: ";
		cin >> updateID;
		cout << "\nEnter Name: ";
		cin.ignore(); // Add this line to clear the input buffer
		getline(cin, updatename);
		cout << "\nEnter Father Name: ";
		getline(cin, updatefatherName);
		cout << "\nEnter Age: ";
		cin >> updateage;
		cout << "\nEnter Email: ";
		cin.ignore();
		getline(cin, updateemail);
		cout << "\nEnter CNIC: ";
		getline(cin, updatecnic);
		cout << "\nEnter Phone Number: ";
		getline(cin, updatephoneNumber);
		cout << "\nEnter Address: ";
		getline(cin, updateaddress);
		cout << "\nEnter Coming Date: ";
		getline(cin, updatecomingDate);
		outFile << updateID << endl;
        outFile << updatename << endl;
        outFile << updatefatherName << endl;
        outFile << updateage << endl;
        outFile << updateemail << endl;
        outFile << updatecnic << endl;
        outFile << updatephoneNumber << endl;
        outFile << updateaddress<<endl;
        outFile << updatecomingDate << endl;
	    found=true;
    			
		}
		else{
		
		outFile << ID << endl;
        outFile << name << endl;
        outFile << fatherName << endl;
        outFile << age << endl;
        outFile << email << endl;
        outFile << cnic << endl;
        outFile << phoneNumber << endl;
        outFile << address<<endl;
        outFile << comingDate << endl;
    }
	}
				if (!found){
    				cout<<"Incorrect ID "<<endl;
				}
    			

        	
			
    
    inFile.close();
    outFile.close();
    cout<<"*****************************"<<endl;
    remove("Hostel Record.txt");
    rename("temp.txt", "Hostel Record.txt");

    cout << "Hostile with ID " << fileId << " updated successfully." << endl;
}

    void menu() 
	{
        int choice=6;
        
        for(;;)
		{
        	
        	while (choice==6)
			{
			system("cls");
        	cout << "1. Add Hostile" << endl;
            cout << "2. Search Hostile" << endl;
            cout << "3. Update Hostile Information" << endl;
            cout << "4. Remove Hostile Information" << endl;
            cout << "5. Display Hostile Information" << endl;
            cout << " --> Press(0) to Exit!" << endl;
            cout << "Enter Your Choice: ";
            cin >> choice;
			
			while(choice == 1)
			{
				addHostile();
				cout<<"Press(1) to Add Hostile: "<<"\nPress(0) to Exit: "<<"\nPress(6) to Restart: ";
				cin>>choice;
			}
			while(choice == 2)
			{
				searchHostile();
				cout<<"Press(2) to Search Hostile: "<<"\nPress(0) to Exit: "<<"\nPress(6) to Restart: ";
				cin>>choice;
			}
			while(choice == 3)
			{
				updateHostile();
				cout<<"Press(3) to Update Hostile: "<<"\nPress(0) to Exit: "<<"\nPress(6) to Restart: ";
				cin>>choice;
			}
			while(choice == 4)
			{
				removeHostile();
				cout<<"Press(4) to Remove Hostile: "<<"\nPress(0) to Exit: "<<"\nPress(6) to Restart: ";
				cin>>choice;
			}
			while(choice == 5)
			{
				displayHostile();
				cout<<"Press(5) to Display Hostile: "<<"\nPress(0) to Exit: "<<"\nPress(6) to Restart: ";
				cin>>choice;	
			}
	    }	
         
		} 


//        switch (choice) {
//            case 1:
//                addHostile();
//                 cout<<"Do you want to add another Hostile (Y/N): "<<endl;
//        cin>>ch;
//        
//        if( ch== 'Y' || ch== 'y')
//        {
//              addHostile();    
//		}
//		else if( ch== 'N' || ch== 'n')
//		{
//		goto ah;
//		}
//		else
//		{
//			cout<<"Ivalid Input!"<<endl;
//		}
                //break;
//            case 2:
//                searchHostile();
//                break;
//            case 3:
//                updateHostile();
//                break;
//            case 4:
//                removeHostile();
//                break;
//            case 5:
//                displayHostile();
//                break;
//            default:
//                cout << "Invalid Choice!" << endl;
//                goto c;
//        }
}

};


class Hostile : public Person 
{
	private:
		
		string comingDate;
        
    public:
    	
    	void displayHostileData(){
    		bool found=false;
    		string fileId;
    		
    		ifstream file("Hostel Record.txt");
    		
    		cout<< "Enter Hostile ID: ";
    		cin>>ID;
    		
    		while(getline(file,fileId)){
    			
				if (ID==fileId){
    				
	    			cout << "ID: " << fileId << endl;
	    			getline(file,name);
	                cout << "Name: " << name << endl;
	                getline(file,fatherName);
	                cout << "Father Name: " << fatherName << endl;
	                getline(file,age);
	                cout << "Age: " << age << endl;
	                getline(file,email);
	                cout << "Email: " << email << endl;
	                getline(file,cnic);
	                cout << "CNIC: " << cnic << endl;
	                getline(file,phoneNumber);
	                cout << "Phone Number: " << phoneNumber << endl;
	                getline(file,address);
	                cout << "Address: " << address << endl;
	                getline(file,comingDate);
	
	                cout << "Coming Date: " << comingDate << endl;
	                found=true;
	                break;
    			
				}
    				
			}
			if (!found){
    				cout<<"Incorrect ID "<<endl;
				}
    		
		}
    	
	
 
};

class Login
{ 
    public:
      static bool loginAdmin(const string& username,const string& password )
	  {
      	return (username=="Shahid" && password=="123");
	  }

      static bool loginWarden(const string& username,const string& password )
	  {
      	return (username=="Ali" && password=="123");
	  }
	  
	  static bool loginHostile(const string& username,const string& password )
	  {
      	return (username=="Usman" && password=="123");
	  }

};

class Room
{
	
	int totalRooms;
	int roomnumber;
	int floorNumber;
	int capacity;
	
	public:
		void checkAvailability();
		void displayRoomInfo();
};

class Warden:public Person{
	
	
	public:
		
		void allocateRoom();
		void verifyRoomID();
		void setMessMenu();
		void setRules();
		void wMenu();
		
};
void Warden::setMessMenu()
{
	
	ofstream messFile("Mess Menu");
	    
	if (!messFile)	
		cout <<"Error writing on file" <<endl;
  		/// input and write in file then read when needed to display
  		
	
}

void Warden::setRules()
{
	cout<<"Rules should be followed."<<endl;
}

void Warden::allocateRoom() 
{
    char choice;
    int roomId;

    string fileID;
    cout << "Enter Student ID: ";
    cin >> fileID;

    if (fileID.empty()) {
        cout << "Invalid ID!" << endl;
        return;
    }

    ifstream file("Hostel Record.txt");
    ofstream temp("temp.txt");

    if (!file.is_open() || !temp.is_open()) {
    	
        std::cout << "Error opening files!" << std::endl;
        return;
    }

        while(getline(file, ID)){
        	
        	getline(file, name);
        	getline(file, fatherName);
            getline(file, age);
            getline(file, email);
            getline(file, cnic);
            getline(file, phoneNumber);
            getline(file, address);
            getline(file, comingDate);
		
        if (fileID == ID) {
            std::cout << "ID: " << fileID << std::endl;
            std::cout << "Name: " << name << std::endl;
           

            cout << "Is this Student you want to Allocate room(Y/N) ";
            cin >> choice;
            choice = toupper(choice);
            if (choice == 'Y') {
            	temp << ID << std::endl;
            	temp << name << std::endl;
            	temp << fatherName << std::endl;
            	temp << age << std::endl;
            	temp << email << std::endl;
            	temp << cnic << std::endl;
           	 	temp << phoneNumber << std::endl;
            	temp << address << std::endl;
            	temp << comingDate << std::endl;
                std::cout << "Enter Room ID: ";
                std::cin >> roomId;
                temp << roomId << std::endl;
            } else {
                std::cout << "Error" << std::endl;
            }
        } else {
        	
            temp << ID << std::endl;
            temp << name << std::endl;
            temp << fatherName << std::endl;
            temp << age << std::endl;
            temp << email << std::endl;
            temp << cnic << std::endl;
            temp << phoneNumber << std::endl;
            temp << address << std::endl;
            temp << comingDate << std::endl;
        }
    } 

    file.close();
    temp.close();

    remove("Hostel Record.txt");
    rename("temp.txt", "Hostel Record.txt");
}
//void verifyRoomID(string roomId){
//	
//	ifstream file("Hostel Record.txt")
//	
//		bool found=false;
//		while(getline,file){
//			if (roomID==file){
//				
//				found=true;
//				break;
//			}
//		}
//		if (!found)
//			cerr<<"This room is occuiped "<<endl;
//
//		
//}

   void Warden::wMenu() 
	{
        int choice=4;
        
        for(;;)
		{
        	
        	while (choice==4)
			{
        	cout << "1.Allocate Room" << endl;
            cout << "2. Set Mess Menu" << endl;
            cout << "3. Set Rules" << endl;
            cout << " --> Press(0) to Exit!" << endl;
            cout << "Enter Your Choice: ";
            cin >> choice;
			
			while(choice == 1)
			{
			 allocateRoom();
				cout<<"Press(1) to Allocate Room: "<<"\nPress(0) to Exit: "<<"\nPress(4) to Restart: ";
				cin>>choice;
			}
			while(choice == 2)
			{
				setMessMenu();
				cout<<"Press(2) to Set Mess Menu: "<<"\nPress(0) to Exit: "<<"\nPress(4) to Restart: ";
				cin>>choice;
			}
			while(choice == 3)
			{
				setRules();
				cout<<"Press(3) to Set Rules: "<<"\nPress(0) to Exit: "<<"\nPress(4) to Restart: ";
				cin>>choice;
			}
			
	    }	
         
		} 
	}

class Mess
{
	private:
		string dish;
		int no_of_dishes;
		
	public:
		breakfast()
		{
			cout<<"Set Menu for Monday"<<endl;
			
			cin>>dish;
			
		}
		
};

class Payment : public Hostile
{
	public:
		calculateFee();
};

int main() 
{
	int choice;  
	string username, password;
//	
	cout<<"\t\t\t\t\tWELCOME TO HOSTEL MANAGEMENT SYSTEM\t\t\t\t\t"<<endl;
//	
	p:
	
	cout<<"1. Admin"<<endl;
	cout<<"2. Warden"<<endl;
	cout<<"3. Hostile"<<endl;
	cout<<"Enter Your Choice: "<<endl;
	cin>>choice;
	
	switch (choice)
	{
		case 1:
			if(choice = 1)
			{
				a:
				cout<<"Enter Username: "<<endl;
				cin>>username;
				cout<<"Enter Password: "<<endl;
				cin>>password;
				if(Login::loginAdmin(username, password))
				{
					system("cls");
					cout<<"\nAdmin Logged in succesfully."<<endl;
					Admin admin;
					admin.menu();
					

				}
				else
				{
					cout<<"Invalid Data"<<endl;
					goto a;
				}	
				
			}
			break;	
			
		case 2:
		    if(choice = 2)
			{
			    w:
				cout<<"Enter Username: "<<endl;
				cin>>username;
				cout<<"Enter Password: "<<endl;
				cin>>password;
				if(Login::loginWarden(username, password))
				{
					system("cls");
					cout<<"Warden Logged in succesfully."<<endl;
					Warden warden;
				    warden.wMenu() ;
				}
				else
				{
					cout<<"Wrong Username/Password!"<<endl;
					goto w;
				}
			}
			
			case 3:
		    if(choice = 3)
			{
	            h:
				cout<<"Enter Username: "<<endl;
				cin>>username;
				cout<<"Enter Password: "<<endl;
				cin>>password;
				if(Login::loginHostile(username, password))
				{
					system("cls");
					cout<<"Hostile Logged in succesfully."<<endl;
				}
				else
				{
					cout<<"Wrong Username/Password!"<<endl;
					goto h;
				}
			}
			
			default:
				{
					cout<<"Wring Input!"<<endl;
			goto a;
				}
		}
		
		
		
//		Admin admin;
//		admin.addHostile();
		
//		Hostile ho;
//		ho.displayHostileData();
//	Warden a;
//	a.allocateRoom();
    
    return 0;

}
