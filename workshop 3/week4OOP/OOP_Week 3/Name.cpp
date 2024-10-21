//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<cstring>
//#include "Name.h"
//using namespace std;
//namespace seneca
//{
//    int counter{};
//    void Name::set(const char* name, const char* surname) // scope(::) shows that set belongs to Name, so no n. required
//    {
//        m_givenname = new char[strlen(name) + 1];
//        //this->m_givenname = new char[strlen(m_givenname) + 1];
//        m_surname = new char[strlen(surname) + 1];
//        if (m_givenname && m_surname) // if both successful means within memory
//        {
//            strcpy(m_givenname, name);
//            strcpy(m_surname, surname);
//        }
//        else  // so no memory leak
//        {
//            deallocate();
//            //delete[] n.m_givenname;
//            //delete[] n.m_surname;
//            //n.m_givenname = n.m_surname = nullptr; // Rule: not to keep that uninitialized
//        }
//    }
//        void Name::deallocate()
//        {
//            delete[] m_givenname;
//            delete[] m_surname;
//            m_givenname = m_surname = nullptr;
//        }
//      /*  void Name::init()
//        {
//            m_givenname = m_surname = nullptr;
//        }*/
//        Name::Name()
//        {
//            //init();
//            m_givenname = m_surname = nullptr;
//            cout << "Name: " << ++counter << "is created" << endl;
//        }
//        Name::~Name()
//        {
//            deallocate();
//            cout << "Name: " << counter-- << "is destroyed" << endl;
//        }
//        void Name::read()
//        {
//            char name[61];
//            char surname[81];
//            cout << "Name: ";
//            cin >> name;
//            cout << "Surname: ";
//            cin >> surname;
//            set(name, surname);
//        }
//
//        void Name::print()const//void print(const Name& n) --put constant so name will not be changed
//        {
//            if (m_givenname && m_surname && m_givenname[0] && m_surname[0]) // adding [0] means thats its a string even if its an empty string
//            {
//                cout << m_givenname << " " << m_surname << endl;
//            }
//            else
//            {
//                cout << "No name!" << endl;
//            }
//            //  m_givenname = nullptr; cannot because print is const
//        }
//        /*void Name::finalize()
//        {
//            deallocate();
//        }*/
//}
