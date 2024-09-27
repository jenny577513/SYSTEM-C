#ifndef LIST
#define LIST
#include <iostream>
#include "Node.h"

using namespace std;

class List: public Node{

private:
    unsigned int length;

public:
    List();
    List(unsigned int);
    List(const List&);
    ~List();

    List operator=(const List&);
    int setLength(unsigned int);
    unsigned int getLength();
    int setElement(unsigned int, long);
    long getElement(unsigned int);

    List operator+(const List&);
    List operator+=(const List&);
    List operator++();
    List operator++(int);
    List operator--();
    List operator--(int);

    friend ostream& operator<<(ostream&, List);
    friend istream& operator>>(istream&, List&);

};

#endif
