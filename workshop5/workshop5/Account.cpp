#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }

    std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }
   
   // Conversion to bool
   Account::operator bool() const {
       return m_number >= 10000 && m_number <= 99999 && m_balance >= 0;
   }

   // Conversion to int (account number)
   Account::operator int() const {
       return m_number;
   }

   // Conversion to double (balance)
   Account::operator double() const {
       return m_balance;
   }

   // Unary operator ~ to check if account is new
   bool Account::operator~() const {
       return m_number == 0;
   }

   // Assignment operator for assigning account number
   Account& Account::operator=(int number) {
       if (m_number == 0) { // Only if account is new
           if (number >= 10000 && number <= 99999) {
               m_number = number;
           }
           else {
               setEmpty(); // Invalid account number
           }
       }
       return *this;
   }

   // Assignment operator for transferring account properties
   Account& Account::operator=(Account& other) {
       if (m_number == 0 && bool(other)) { // Only if current account is new and other is valid
           m_number = other.m_number;
           m_balance = other.m_balance;
           other.m_number = 0; // Set other to new state
           other.m_balance = 0;
       }
       return *this;
   }

   // += operator to deposit money
   Account& Account::operator+=(double amount) {
       if (*this && amount > 0) {
           m_balance += amount;
       }
       return *this;
   }

   // -= operator to withdraw money
   Account& Account::operator-=(double amount) {
       if (*this && amount > 0 && m_balance >= amount) {
           m_balance -= amount;
       }
       return *this;
   }

   // << operator to transfer funds from other account to this account
   Account& Account::operator<<(Account& other) {
       if (this != &other && *this && bool(other)) {
           m_balance += other.m_balance;
           other.m_balance = 0;  // Set other account's balance to zero
       }
       return *this;
   }

   // >> operator to transfer funds from this account to other account
   Account& Account::operator>>(Account& other) {
       if (this != &other && *this && bool(other)) {
           other.m_balance += m_balance;
           m_balance = 0; // Set this account's balance to zero
       }
       return *this;
   }

    // Binary helper + operator to add balances of two accounts
    double operator+(const Account& left, const Account& right) {
        if (left && right) {
            return (double)left + (double)right;
        }
        return 0.0;
    }

    // Binary helper += operator to add account balance to double
    double& operator+=(double& left, const Account& right) {
        if (right) {
            left += (double)right;
        }
        return left;
    }

 
}