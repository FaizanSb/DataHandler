#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	const int row_num=3;
	const int col_num=4;
	int i,j;
	int cube[row_num][col_num];
		int matrix[row_num][col_num];
	cout<<"Enter number of element off matrix"<<endl;
	for(i=0;i<row_num;i++)
	{
		for(j=0;j<col_num;j++)
		
		
		cin>>matrix[i][j];
		
	}
	cout<<"Number of elements of matrix are"<<endl;
	for(i=0;i<row_num;i++)
	{
		for(j=0;j<col_num;j++)
		cout<<setw(3)<<matrix[i][j];
		cout<<endl;
}
cout<<"Cube of matrix is"<<endl;
	for (int i=0;i<row_num;i++){
		for(int j=0;j<col_num;j++){
			
			cube[i][j]=matrix[i][j]*matrix[i][j]*matrix[i][j];
			cout<<cube[i][j]<<" ";
		}
		cout<<endl;
	}
	
cout<<endl;
		


}
