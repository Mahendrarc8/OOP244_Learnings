#include<iostream>
#include "Utils.h"
using namespace std;
namespace seneca 
{
    Utils ut;
    int Utils::getInt()
    {
        int val{};
        cin >> val;
        while (cin.fail())
        {
            cout << "Invalid int";
            cin.clear();
            cin.ignore(12000, '\n');
            cin >> val;
        }
        //cin.ignore();// only one character
        cin.ignore(12000, '\n');
        return val;
    }
    void Utils::getCstr(char* str, size_t len)
    {
       
        cin .getline( str, len+ 1);
        while (cin.fail())
        {
            cout << "max " << len << "char!  , Retry \n";
            cin.clear();
            cin.ignore(12000, '\n');
            cin.getline(str, len+ 1);
        }
        //cin.ignore();// only one character
        //cin.ignore(12000, '\n'); not required because getine will do that
       // return str;

    }

    bool Utils::yes(const char* prompt)
    {
        char resp{};
        char newline{};
        bool done = false;
        if (prompt) cout << prompt;

        do {
            resp = cin.get();
            newline = cin.get();

            if (newline != '\n')
            {
                cin.ignore(10000, '\n');
            }
            else if (resp == 'Y' || resp == 'y' || resp == 'N' || resp == 'n') {
                done = true;
          
        } while (!done && cout << "(Y)es or (N)o... Please try again");
        return false;
    }
}
