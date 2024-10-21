#pragma once
#ifndef SENECA_MYSTR_H
#define SENECA_MYSTR_H

namespace seneca
{
	class Mystr
	{
		//private: no need to write private because class is private by default

		char* m_data;

	public:
		Mystr();
		Mystr(const char* str);
		~Mystr();

		void print() const;

	};
}

#endif