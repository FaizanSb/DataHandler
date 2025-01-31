#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	system("color 1f");
	int a =5;
	int b = 10;
	// using nested loops 
	for (int x = 0; x<a ; x++)
	{
		for (int y = 0;  y<(a-x); y++)
		{
			cout << setw(6)<<" ";
		}
		for (int y = 0; y <= x; y++)
		{
			cout << setw(6) << b;
			b=b-1;
		}

		cout << endl;
		b=10;
        
	}
    return 0;
}
