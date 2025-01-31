#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

int main()
{
    int n1,n;
	srand(time(0));
	n=rand()%50;
	
	while(true)
	{
	cout<<"Enter number to guess"<<endl;
	cin>>n1;
	if(n1>n)
	{
		cout<<"The is greater then guessing number .Try again"<<endl;
	}
	if(n1<n)
	{
		cout<<"The number is less then guessing number.Try again"<<endl;
	}
	if(n1==n)
	{
		cout<<"**** Congrulations ******"<<endl;
		cout<<"You find the guessing number";
		break;
	}
}
	return 0;
}
