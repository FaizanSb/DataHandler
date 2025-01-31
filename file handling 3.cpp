
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Account{
	private:
	static int accountNumber;
	string accountHolder;
	double balance;
	public:
		Account(const string &accHol,double initial_balance):accountHolder(accHol),balance(initial_balance)
		{	accountNumber++;			}
		void deposit(double amount)
		{
			if(amount>0)
			{
				balance+=amount;
				cout<<"\nDeposited $"<<amount<<"Successfully"<<endl;
			}
			else
			cerr<<"\aError! invalid amount"<<endl;
			
		}
		void withdraw(double amount)
		{
			if(amount>0 && balance>=amount )
			{
				balance-=amount;
				cout<<"\nWith draw "<<amount<<" successfully"<<endl;
			}
			else
			cout<<"Invalid amount / insufficuent amount"<<endl;
		}
		void dispaly()
		{
			cout<<"\nAccount number: "<<accountNumber<<endl;
			cout<<"\nBalance : "<<balance<<endl;
			cout<<"\nAccount Holder: "<<accountHolder<<endl;
		}
		void Tbalance()
		{
			cout<<"\nYour total balance after deposit or withdraw is: "<<balance<<endl;
		}
		string accountholder()const
		{
			return accountHolder;
		}
		int accountnumber()const
		{
			return accountNumber;
		}
		double Balance() const
		{
			return balance;
		}
		
};
int Account::accountNumber=100;
class Bank
{
	public:
		void addAccount(const Account &account)
		{
			ofstream accountAdd("ACCOUNT.txt",ios::app);
			if(accountAdd.is_open())
			{
				accountAdd<<"Account Info\n";
				accountAdd<<"Account Holder :"<<account.accountholder()<<endl;
				accountAdd<<"Account Number: "<<account.accountnumber()<<endl;
				accountAdd<<"Total Balance:"<<account.Balance()<<endl;
				accountAdd<<"-------------------------------"<<endl;
				accountAdd.close();
			}
			else 
			cerr<<"\aError in writing file"<<endl;
			
		}
	void displayAllAccounts()
	{
		ifstream accountAdd("ACCOUNT.txt",ios::app);
		string s;
		if(accountAdd.is_open())
		{
			while(getline(accountAdd,s))
			cout<<s<<endl;
			accountAdd.close();
		}
		else
		cerr<<"\aError in opening file"<<endl;
	}
	void deleteAccount(){
		string name;
		int accountNumber;
		int amount;
		ofstream myFile("tempFile.txt",ios::app);
	ifstream addAccount("ACCOUNT.txt");
	if(addAccount.is_open()){
		cout<<"Enter name for delete account: "<<endl;
		getline(cin,n);
		getline(addAccount,name);
		if(name==n){
			cout<<"Name: "<<n<<endl;
			cout<<""
		}
	}	
	}
	
	
	
		
};
int main()
{
	system("color 5f");
	p:
	int choise;
	cout<<"\n\t\t\t****BANK MANAGEMENT SYSTEM****"<<endl;
	cout<<"Press 1 to dispaly deposited and with draw amount of account: "<<endl;
	cout<<"Press 2 to dispaly all account records of file: "<<endl;
	cout<<"Press 3 to remove the account: "<<endl;
	cout<<"Press 4 for exit: "<<endl;
	cin>>choise;
	if(choise==1)
	{system("cls");
	cout<<"\n\t\tAll Deposited And Withdraw Anount"<<endl;
		Bank b1;
	Account a1("Abid",12000);
	a1.dispaly();
	a1.deposit(500);
	a1.withdraw(200);
	a1.Tbalance();
	b1.addAccount(a1);
///////////////////////////////////////////////////////////////////	
	Account a2("Bilal",15000);
	a2.dispaly();
	a2.deposit(300);
	a2.withdraw(600);
	a2.Tbalance();
	b1.addAccount(a2);
////////////////////////////////////////////////////////////////////////
	Account a3("Moon",20000);
	a3.dispaly();
	a3.deposit(4500);
	a3.withdraw(3500);
	a3.Tbalance();
	b1.addAccount(a3);
/////////////////////////////////////////////////////////////////////
	Account a4("Zubair",56000);
	a4.dispaly();
	a4.deposit(800);
	a4.withdraw(10000);
	a4.Tbalance();
	b1.addAccount(a4);
/////////////////////////////////////////////////////////////////////////
	}
	else if(choise==2)
	{
		system("cls");
		Bank b1;
		b1.displayAllAccounts();
	}
	else if(choise==3)
	{
		system("cls");
		Bank b1;
		b1.removeAccount(103);
	}
	else if(choise==4)
	{
		exit(0);
	}
	else 
	cout<<"\aInvalid Choise"<<endl;
	goto p;
	return 0;

}
