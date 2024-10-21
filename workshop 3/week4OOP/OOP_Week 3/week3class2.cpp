#include<iostream>
#include "Utils.h"
using namespace std;
using namespace seneca;
int main()
{
	//Utils ut;
	/*int num;
	cout << "Enter an int: ";
	num = ut.getInt();
	cout << num <<  endl;*/
	char name[81];
	cout << " please enter a name: ";
	//cin >> name; // it will print until space
	//cin.getline(name, 81); // it will include the space in it, eat the \n
	ut.getCstr(name, 5);
	cout << "name is: " << name << endl;



	//int num;
	//char str[81];
	//cout << "int: ";
	//cin >> num;
	////if (!cin)
	//if(cin.fail())
	//{
	//	cin.clear();// means sorry cin, lets start again
	//	cin.ignore(1000, '\n');
	//}
	//cout << "String: ";
	//cin >> str;
	//cout << endl;
	//cout << "Int: " << num << "\nString: " << str << endl;

	// full proof reading




	//int val = 1234, val2 = 67;// no fix format for double
	// char value[20] = "hello";
	//cout << 1234 << endl;
	//cout.width(20); // is will effect ONLY the next print out; its temporary
	//cout <<"*" << val << endl;
	//cout << val2 << endl;
	//cout << "**************************************" << endl;
	//cout << "*";
	//cout.width(30);
	//cout.setf(ios::left); // set the flag of the printout to be left justified until changed
	//cout << val << "*"<< endl;
	//cout.unsetf(ios::left); // bcz set is permanent
	//cout << "**************************************" << endl;
	//cout << "*";
	//cout.width(30);
	//cout.setf(ios::left); // set the flag of the printout to be left justified until changed
	//cout.fill('~');
	//cout << val << "*" << endl;
	//cout.unsetf(ios::left); // bcz set is permanent

	//// DOUBLE---------

	//double val3 = 123.45678;
	//cout.setf(ios::fixed);
	//cout.precision(3);
	//cout << val3 << endl;

	


	return 0;
}