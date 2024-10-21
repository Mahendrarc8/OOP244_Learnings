#include <iostream>
#include <cstring>
#include "dma.h"
using namespace std;
namespace seneca {

	//Function to receive an unknown number of double numbers from the console and prints them in reverse order.
	void reverse() {
		int num;

		cout << "Enter the number of double values:\n> ";
		cin >> num;

		//Positive doubles validation
		if (num <= 0) {
			cout << "Invalid size. Number of doubles must be positive." << endl;
			return;
		}

		double* values = new double[num];

		for (int i = 0; i < num; ++i) {
			cout << (i + 1) << "> ";
			cin >> values[i];
		}

		for (int i = num - 1; i >= 0; --i) {
			cout << values[i] << endl;
		}

		//Free the allocated memmory
		delete[] values;
	}

	//Function to create a Contact compound type dynamically and gets its content from the console, then returns its address.
	Contact* getContact() {

		Contact* newContact = new Contact;

		cout << "Name: ";
		cin >> newContact->m_name;                                               

		cout << "Last Name: ";
		cin >> newContact->m_lastname;

		cout << "Phone number: ";
		cin >> newContact->m_phoneNumber;

		// Return the address of the dynamically allocated Contact structure
		return newContact;
	}

	//Function to print a Contact in a line
	void display(const Contact& contact) {
		cout << contact.m_name << " " << contact.m_lastname << ", +" << contact.m_phoneNumber << endl;
	}

	//Function that receives the address of a dynamically allocated Contact and removes it from memory.
	void deallocate(Contact* contact) {
		delete contact;
	}

	//Function to  empty the content of the Contact received by reference by setting the name and last name to empty strings and the phone number to zero.
	void setEmpty(Contact& contact) {
		strcpy_s(contact.m_name, sizeof(contact.m_name), "");
		strcpy_s(contact.m_lastname, sizeof(contact.m_lastname), "");
		contact.m_phoneNumber = 0;
	}
}
