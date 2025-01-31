#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int array1[3][3][3],array2[3][3][3],array3[3][3][3];
	int array_no=3;
	int row_no=3;
	int col_no=3;
	int i,j,k;
	cout<<"Enter first array element:"<<endl;
	for(i=0;i<array_no;i++)
	{
		for(j=0;j<row_no;j++)
		{
			for(k=0;k<col_no;k++)
			cin>>array1[i][j][k];
		}
	}
	cout<<"Enter element of 2nd array:"<<endl;
	for(i=0;i<array_no;i++)
	{
		for(j=0;j<row_no;j++)
		{
			for(k=0;k<col_no;k++)
			cin>>array2[i][j][k];
		}
	}
	for(i=0;i<array_no;i++)
	{
		for(j=0;j<row_no;j++)
		{
			for(k=0;k<col_no;k++)
			if(array1[i][j][k]==array2[i][j][k])
			array3[i][j][k]=pow(array1[i][j][k],2)+pow(array2[i][j][k],2);
		}
	}
	cout<<"\t\t***Elements of third array are****"<<endl;
	for(i=0;i<array_no;i++)
	{
		for(j=0;j<row_no;j++)
		{
			for(k=0;k<col_no;k++)
			{
			cout<<array3[i][j][k]<<" ";
		}
		}
		cout<<endl;
	}
	cout<<"\n\n****Elements of First array****"<<endl;
	for(i=0;i<array_no;i++)
	{
		for(j=0;j<row_no;j++)
		{
			for(k=0;k<col_no;k++)
			{
				cout<<array1[i][j][k]<<" ";
			}
		}
		cout<<endl;
	}
	cout<<"\n\n*****Elements of Second array*****"<<endl;
	for(i=0;i<array_no;i++)
	{
		for(j=0;j<row_no;j++)
		{
			for(k=0;k<col_no;k++)
			{
				cout<<array2[i][j][k]<<" ";
			}
		}
		cout<<endl;
	}
}

