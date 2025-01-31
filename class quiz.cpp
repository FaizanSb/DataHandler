#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int rows,cols,max;
	int a[rows][cols];
	cout<<"Enter number of rows"<<endl;
	cin>>rows;
	cout<<"Enter number of columns"<<endl;
	cin>>cols;
	cout<<"Enter values in matrix";
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		cin>>a[i][j];
	}
	cout<<"Elements of matrix are"<<endl;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		cout<<setw(5)<<a[i][j];
		cout<<endl;
	}
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
			max=a[i][j];
			for(int k=0;k<rows;k++)
			{
				for(int l=0;l<cols;l++)
				if(k==l)
				if(max<a[k][l])
				max=a[k][l];
			}
	}
	cout<<"maximum is"<<max<<endl;	
	return 0;
		
}

