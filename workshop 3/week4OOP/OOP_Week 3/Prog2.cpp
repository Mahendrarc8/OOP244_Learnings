//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include "Name.h"
//using namespace std;
//using namespace seneca;
//
//int main()
//{
//    Name* names = nullptr;
//    size_t num{};
//    cout << "how many names?\n> ";
//    cin >> num;
//    names = new Name[num];
//    /*for (size_t i = 0; i < num; i++)
//    {
//        names[i].init();
//    }*/ // not required because we will use constructor
//    names[0].print();
//    for (size_t i = 0; i < num; i++)
//    {
//        names[i].read();
//    }
//   // names[0].m_givenname = nullptr; // memory leak; the attributes that you dnt want others to use, make them private
//
//    for (size_t i = 0; i < num; i++)
//    {
//        names[i].print();
//    }
//
//
//    //for (size_t i = 0; i < num; i++) {
//    //    names[i].finalize(); // hey names deallocate itself
//    //} // not use bcz use deconstructor
//
//    delete[] names;
//    return 0;
//}
//
//
//
//
//
//
