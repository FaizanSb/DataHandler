#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int i,j;
	for(i=2;i<=14;i+=3)
	{
		for(j=i;j<=i+8;j+=2)
		// use condition for spaces in output
		if((i==5 && j==7)||(i==5 && j==9)||(i==5 && j==11)||(i==8 && j==10)||(i==8 && j==12)
		||(i==8 && j==14)||(i==11 && j==13)||(i==11 && j==15)||(i==11 && j==17))
		{
			
		cout<<setw(5)<<" ";
		
		}
		else		
		cout<<setw(5)<<j;
		cout<<endl;
}
	return 0;
}
