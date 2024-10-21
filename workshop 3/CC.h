#ifndef SENECA_CC_H_
#define SENECA_CC_H_
#include <iostream>
namespace seneca {
   class CC {

   private:
      char* cardholderName{};
      short expiryMonth, expiryYear, cvv;
      unsigned long long number;


      void display(const char* cardholderName, unsigned long long number, short expiryYear, short expiryMonth, short cvv) const;
      bool validate(const char* cardholderName, unsigned long long cardNo, short cvv, short expiryMonth, short expiryYear)const;
      void prnNumber(unsigned long long CCnum)const;

      public: 
      void set();
      void cleanUp();
      bool isEmpty() const;
      void set(const char* cc_name,
          unsigned long long cc_no,
          short cvv,
          short expMon = 12,
          short expYear = 24);
      void display() const;
   };

}
#endif // !SENECA_CC_H_


