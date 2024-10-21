#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_

#include <iostream>

namespace seneca {
    class Account {
        int m_number;
        double m_balance;
        void setEmpty();

    public:
        Account();
        Account(int number, double balance);
        
        // Display function
        std::ostream& display() const;

        // Type conversion operators
        operator bool() const;  // Conversion to bool
        operator int() const;   // Conversion to int (account number)
        operator double() const; // Conversion to double (balance)

        // Unary member operator
        bool operator~() const; // Check if the account is new

        // Assignment operators
        Account& operator=(int number); // Assigning account number
        Account& operator=(Account& other); // Assigning one account to another

        // Binary member operators
        Account& operator+=(double amount); // Deposit money
        Account& operator-=(double amount); // Withdraw money

        // Transfer funds between accounts
        Account& operator<<(Account& other); // Transfer from other to this
        Account& operator>>(Account& other); // Transfer from this to other


         // Binary helper operators
        friend double operator+(const Account& left, const Account& right);
        friend double& operator+=(double& left, const Account& right);
    };

}

#endif // SENECA_ACCOUNT_H_

