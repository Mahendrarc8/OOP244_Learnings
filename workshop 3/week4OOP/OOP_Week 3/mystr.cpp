#include <iostream>
#include "mystr.h"
using namespace std;
using namespace seneca;
namespace seneca
{
	Mystr::Mystr()
	{
		m_data = nullptr;
	}

	Mystr::~Mystr()
	{
		delete[];
		cout << "dest called" << endl;
	}
	Mystr(const char* str)
	{

	}
	void Mystr::print() const
	{
		
	}
}


int main()
{
	Mystr s;
}
