#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int x,y;
	for(x=1;x<=10;x++)
	{
		for(y=x;y<=x+8;y+=2)
		cout<<setw(3)<<y;
		cout<<endl;
		if(y>19)
		{ 
		   break;
		}
		
	}
	return 0;
}
