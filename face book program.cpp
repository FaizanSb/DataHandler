#include<iostream>
using namespace std;
void celcioustoforeign(double c);	// function prototype
void foreigntocelcious(double f);	// function prototype
void displaymenu()					// declare function
{
	double choice;
	cout<<"press 1 for convert celcious to foreign height and press 2 to convert foreignheight to celcious:"<<endl;
	cin>>choice;
	if(choice==1){
		double cTOf;
	 cout<<"Enter temprature in celcious"<<endl;
	cin>>cTOf;
		celcioustoforeign(cTOf);		
	}
	else if(choice==2){
		int fTOc;
		cout<<"Enter temprature in foreign height"<<endl;
		cin>>fTOc;
		foreigntocelcious(fTOc);
	}
	else
	cout<<"\a invalid choice"<<endl;
}
void celcioustoforeign(double c)
{
	double f;
	f=c*9/5+32;
	cout<<"Temprature in foreign height is "<<f<<endl;
}
void foreigntocelcious(double f)
{
	double c;
	c=(f-32)*5/9;
	cout<<"Temprature in celcious is "<<c<<endl;
}
int main()
{
	cout<<"Welcome to c++ after passsing PF"<<endl;
	displaymenu();
	return 0;
}


