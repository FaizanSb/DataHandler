#include<fstream>
#include<iostream>
#include<string>

using namespace std;

void writeOnFile();
void readOnFile();
void updateOnFile();
void deleteOnFile();

int main(){
	system("cls");
	system("color 1f");
	int choice;
	P:
	cout<<"\n\t\t\t=============================================================="<<endl;	
	cout<<"				National Data Base and Registration Authority			"<<endl;
	cout<<"\t\t\t=============================================================="<<endl;
	cout<<"\n\t\t\t\t1.For write on file: "<<endl;
	cout<<"\n\t\t\t\t2.For Read on File: "<<endl;
	cout<<"\n\t\t\t\t3.For Update on FIle: "<<endl;
	cout<<"\n\t\t\t\t4.For Delete on File: "<<endl;
	cout<<"\n\t\t\t\t5.Exit: "<<endl;
	cin>>choice;
	cin.ignore();
	switch(choice){
		case 1:{
			writeOnFile();
			break;
		}
		case 2:{
			readOnFile();
			break;
		}
		case 3:{
			updateOnFile();
			break;
		}
		case 4:{
			deleteOnFile();
			break;
		}
		case 5:{
			exit(0);
			break;	
		}
		default:
		cout<<"\aInvalid Choice....."<<endl;
	}
	goto P;

}
void writeOnFile(){
		string Name,address,age,father_name;
	ofstream myFile("faizan.txt",ios::app);
	if(!myFile.is_open()){
		cout<<"Error in creating file: "<<endl;
	}
	else
	{
		system("cls");
	cout<<"\n\t\t\t=============================================================="<<endl;
	cout<<"					For Register Data in Computer					"<<endl;
	cout<<"\t\t\t=============================================================="<<endl;
	cout<<"\t\t\tEnter Name "<<endl;
	getline(cin,Name);
	cout<<"\t\t\tEnter Fathers name: "<<endl;
	getline(cin,father_name);
	cout<<"\t\t\tEnter address: "<<endl;
	getline(cin,address);
	cout<<"\t\t\tEnter age: ";
	getline(cin,age);
	myFile<<Name<<endl;
	myFile<<father_name<<endl;
	myFile<<address<<endl;
	myFile<<age<<endl;
	myFile<<"-------------------------"<<endl;
	cout<<"Data added Successfully...."<<endl;
	}
	myFile.close();
}
void readOnFile(){
	string name,fatherName,address,age,l;
	ifstream myFile("faizan.txt");
	if(!myFile){
		cout<<"Error in opening the file: "<<endl;
	}
	else
	system("cls");
	cout<<"\n\t\t\t=============================================================="<<endl;
	cout<<"						For View All Data in Computer					"<<endl;
	cout<<"\t\t\t=============================================================="<<endl;
	while(getline(myFile,name)){
		cout<<"\t\t\tName:"<<name<<endl;
		getline(myFile,fatherName);
		cout<<"\t\t\tFathers Name: "<<fatherName<<endl;
		getline(myFile,address);
		cout<<"\t\t\tAddress: "<<address<<endl;
		getline(myFile,age);
		cout<<"\t\t\tAge: "<<age<<endl;
		getline(myFile,l);
		cout<<"\t\t\t"<<l<<endl;
	}
	myFile.close();	
}
void updateOnFile(){
	ifstream myFile("faizan.txt");
	ofstream tempFile("Temp.txt",ios::app);
	string Name,u_name,u_fatherName,u_address,u_age;
	string name,father_Name,address,age,Line;
	char choice;
	bool flag=false;
	if(!tempFile){
		cout<<"Error in writing file"<<endl;
	}
	system("cls");
	cout<<"\n\t\t\t=============================================================="<<endl;
	cout<<"						For Update Data in Computer							"<<endl;
	cout<<"\t\t\t=============================================================="<<endl;	
	cout<<"\t\t\tEnter Name for update: "<<endl;
	getline(cin,Name);
	//cin.ignore()
	while(getline(myFile,name)){
		getline(myFile,father_Name);
		getline(myFile,address);
		getline(myFile,age);
		getline(myFile,Line);
		if(name==Name){
			flag=true;
			cout<<"\t\t\tName: "<<name<<endl;
			getline(myFile,father_Name);
			cout<<"\t\t\tFather Name: "<<father_Name<<endl;
			getline(myFile,address);
			cout<<"\t\t\tAddress: "<<address<<endl;
			getline(myFile,age);
			cout<<"\t\t\tAge : "<<age<<endl;
			cout<<Line<<endl;
			cout<<"\t\t\tIs this information you want to update: (Y,N)"<<endl;
			cin>>choice;
			cin.ignore();
			if(choice=='y'||choice=='Y'){
				cout<<"\t\t\tEnter Updated Name: "<<endl;
				getline(cin,u_name);
				cout<<"\t\t\tEnter Updated Father Name: "<<endl;
				getline(cin,u_fatherName);
				cout<<"\t\t\tEnter Updated address: "<<endl;
				getline(cin,u_address);
				cout<<"\t\t\tEnter Updated Age: "<<endl;
				getline(cin,u_age);
				tempFile<<u_name<<endl;
				tempFile<<u_fatherName<<endl;
				tempFile<<u_address<<endl;
				tempFile<<u_age<<endl;
				tempFile<<"---------------------------"<<endl;
				cout<<"\t\t\tData Updated Successfully....."<<endl;
			}
			else
			{				
				tempFile<<name<<endl;
				tempFile<<father_Name<<endl;
				tempFile<<address<<endl;
				tempFile<<age<<endl;
				tempFile<<Line<<endl;
			}
		}
		else
		{
			tempFile<<name<<endl;
			tempFile<<father_Name<<endl;
			tempFile<<address<<endl;
			tempFile<<age<<endl;
			tempFile<<Line<<endl;
		}
		
	}
	if(!flag){
		cout<<"This Name not Exist...."<<endl;
	}
	myFile.close();
	tempFile.close();
	remove("faizan.txt");
	rename("Temp.txt","faizan.txt");		
}
void deleteOnFile(){
	ifstream myFile("faizan.txt");
	ofstream tempFile("Temp.txt",ios::app);
	string name_of_person,father_name,address_of_person,age_of_person,liNe;
	if(!myFile){
		cout<<"Error in opening the file"<<endl;
	}
	if(!tempFile){
		cout<<"Eror in creating the file: "<<endl;
	}
	else{
		bool found=false;
		char choice;
		string N;
		system("cls");
		cout<<"\n\t\t\t=============================================================="<<endl;
		cout<<"						For Delete Data in Computer							"<<endl;
		cout<<"\t\t\t=============================================================="<<endl;
		cout<<"Enter Name to Delete: "<<endl;
		getline(cin,N);
		while(getline(myFile,name_of_person)){
			getline(myFile,father_name);
			getline(myFile,address_of_person);
			getline(myFile,age_of_person);
			getline(myFile,liNe);
			if(name_of_person==N){
				found=true;
				cout<<"Name: "<<name_of_person<<endl;
				cout<<"Father Name: "<<father_name<<endl;
				cout<<"Address: "<<address_of_person<<endl;
				cout<<"Age: "<<age_of_person<<endl;
				cout<<liNe<<endl;
				cout<<"Is this Data you want to delete? (Y/N): "<<endl;
				cin>>choice;
				if(choice=='Y'||choice=='y'){
					cout<<"Data Deleted Successfully...."<<endl;
				}
				else{
					
					tempFile<<name_of_person<<endl;
					tempFile<<father_name<<endl;
					tempFile<<address_of_person<<endl;
					tempFile<<age_of_person<<endl;
					tempFile<<"------------------------------"<<endl;
				}
			}
				else
				{
					tempFile<<name_of_person<<endl;
					tempFile<<father_name<<endl;
					tempFile<<address_of_person<<endl;
					tempFile<<age_of_person<<endl;
					tempFile<<"------------------------------"<<endl;
					
				}
			}
			if(!found){
				cout<<"This Name not Exists...."<<endl;
			}
			
		}
		myFile.close();
		tempFile.close();
		remove("faizan.txt");
		rename("temp.txt","faizan.txt");
}



