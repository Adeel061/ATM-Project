#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#include <cstdlib>
#include <sstream>

using namespace std;

int addition (int d, int e)
{
	int f;
	f = d + e;
	return f;
}

int subtraction (int g, int h)
{
	int i;
	i = g - h;
	return i;
}

int main(void)
{
	int a;
	float b = 10000;
	int c,j;
	const int CR = 13;

	std::string s;

	retry:
	j = 0;
	s = "0";
	cout<< "Welcome"<<endl;
	
	 cout<<"Mr Adeel Mushtaq\n";
	
	cout<< "Enter your PIN : ";
    do
	{
		j = _getch();
		if (isdigit(j))
			{
				s += (char)j;
				cout << "*";
			}
	}
	while (j != CR);
  
	stringstream convert(s);
	if ( !(convert >> j) )
		j = 0;
	sleep (1);
	system ("CLS");
	
	if (j == 9877)
	{
		goto proceed;
	}
	else
	{
		system ("CLS");
		cout<< "Invalid pin.";
		sleep (2);
		system ("CLS");
		goto retry;
	}
	proceed:
	cout<< "\nSuccess!\nAccessing your data..........................";
	sleep (3);
	system ("CLS");
	
	repeat:
	cout<< "\n\nPlease select one of three options:\n";
	cout<< "(1) Balance Inquiry"<<endl;
	cout<<"(2) Withdraw"<<endl;
	cout<<"(3) Deposit"<<endl;
	cout<< "Option selected: ";
	cin>> a;
	system ("CLS");
	
	if (a==1)
	{
		cout<< "\nYour current balance is : " << b;
	}
	else if (a==2)
	{
		cout<< "\nPlease enter how much you would like to withdraw : ";
		cin>> c;
		system ("CLS");
		if (c>b)
		{
			cout<< "\nError, insufficient balance.";
		}
		else if (c<=0)
		{
			cout<< "\nError, the amount cannot be less than 1.";
		}
		else
		{
		b = subtraction (b, c);
		cout<< "\nTransaction successful, your current remaining balance is: " << b;
		}
	}
	else if (a==3)
	{
		cout<< "\nPlease enter how much you would like to deposit: ";
		cin>> c;
		system ("CLS");
		if (c<=0)
		{
			cout<< "\nError, the amount cannot be less than 1.";
		}
		else
		{
			b = addition (b, c);
			cout<< "\nTansaction successful, your current balance is now: " << b;
		}
	}
	else
	{
		cout<< "\n\nInvalid choice.";
		goto repeat;
		return 0;
	}
	last:
	cout<< "\n\nWould you like to do something else?\n";
	cout<< "Select an option:\n\n";
	cout<< "[1] Yes\n[2] No\n\n" << "Option selected: ";
	cin>>c;
	system ("CLS");
	if (c==1)
	{
		goto repeat;
	}
	else
	{
		end:
		system ("CLS");
		cout<< "\nThank you for using ATM Machine!";
		return 0;
	}
}

