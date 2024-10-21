    #include <iostream>

    using namespace std;

    void print()
    {
        cout << "This is cout function" << endl;
    }

    namespace first {


    int print () 
    {
        //int sum = a + b;
        cout << "The sum is: ";
    }
    }


    int main()
    {
        print();
        first::print();
    }