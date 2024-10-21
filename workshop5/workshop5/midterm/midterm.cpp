#include<iostream>
#include <cstring>
#include "midterm.h"

using namespace std;
namespace seneca {
    StringHandler::StringHandler(): m_string{}
    {}
    StringHandler::~StringHandler() {
        delete[] m_string;
    }

    void StringHandler::copyString(const char* Value1) {
        m_string = new char[strlen(Value1) + 1];
        strcpy(m_string, Value1);
    }

    void StringHandler::display() {
        cout << "Value1 is copied from Value 2" << endl;
    }
}

int main () {

}