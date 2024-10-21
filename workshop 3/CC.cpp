#include <iostream>
#include "cstr.h"
#include "CC.h"
using namespace std;
namespace seneca {

    void CC::prnNumber(unsigned long long no) const {
        cout << no / 1000000000000ull << " ";
        no %= 1000000000000ull;
        cout.fill('0');
        cout.width(4);
        cout.setf(ios::right);
        cout << no / 100000000ull << " ";
        no %= 100000000ull;
        cout.width(4);
        cout << no / 10000ull << " ";
        no %= 10000ull;
        cout.width(4);
        cout << no;
        cout.unsetf(ios::right);
        cout.fill(' ');
    }

    void CC::display(const char* cardholderName, unsigned long long number, short expiryYear, short expiryMon, short cvv) const {
        char lname[31]{};
        strcpy(lname, cardholderName, 30);
        cout << "| ";
        cout.width(30);
        cout.fill(' ');
        cout.setf(ios::left);
        cout << lname << " | ";
        prnNumber(number);
        cout << " | " << cvv << " | ";
        cout.unsetf(ios::left);
        cout.setf(ios::right);
        cout.width(2);
        cout << expiryMon << "/" << expiryYear << " |" << endl;
        cout.unsetf(ios::right);
    }

    bool CC::validate(const char* cardholderName, unsigned long long cardNo, short cvv, short expiryMon, short expiryYear)const {
     
        if (cardholderName == nullptr || strlen(cardholderName) <= 2)
        {
            return false;
        }

        if (cardNo < 4000000000000000ull || cardNo > 4099999999999999ull)
        {
            return false;
        }

        if (cvv < 100 || cvv > 999)
        {
            return false;
        }

      
        if (expiryMon < 1 || expiryMon > 12) {
            return false;
        }

        if (expiryYear < 24 || expiryYear > 32) {
            return false;
        }

        return true; 
    }


    void CC::set()
    {
        cardholderName = nullptr;
        expiryMonth = 0;
        expiryYear = 0;
        cvv = 0;
        number = 0;
    }

    void CC::cleanUp()
    {
        freeMem(cardholderName);
        set();
    }


    bool CC::isEmpty() const
    {
        if (cardholderName != nullptr)
        {
            return false;
        }
        else {
            return true;
        }
    }

    void CC::set(const char* cc_name,
        unsigned long long cc_no,
        short cvv,
        short expMon,
        short expYear)
    {
        if (!validate(cc_name, cc_no, cvv, expMon, expYear)) {
            cleanUp();
        }
        else {
            alocpy(cardholderName, cc_name); 
            number = cc_no;
            this->cvv = cvv;
            expiryMonth = expMon;
            this->expiryYear = expYear;
        }

    }

    void CC::display() const
    {
        if (isEmpty()) {
            cout << "Invalid Credit Card Record" << endl;
        }
        else {
            display(cardholderName, number, expiryYear, expiryMonth, cvv);
        }
    }
}