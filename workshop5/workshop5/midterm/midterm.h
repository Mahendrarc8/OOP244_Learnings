#ifndef SENECA_MIDTERM_H
#define SENECA_MIDTERM_H

namespace seneca {
class StringHandler {
    char* m_string;

    public:
    StringHandler();
    ~StringHandler();
    void copyString(const char* Value1);
     void display();
};
}
#endif