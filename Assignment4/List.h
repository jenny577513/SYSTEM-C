#ifndef LIST
#define LIST
#include <iostream>
#include "Node.h"
using namespace std;

template<typename T>
class List: public Node<T>{

    friend istream& operator>>(istream &in, List<T> &list){
    for(unsigned int i=0; i<list.getLength(); i++)
        in >> list._Node[i];
    return in;
    }
    
    friend ostream& operator<<(ostream &out, List<T> list){
    for(unsigned int i=0; i<list.getLength(); i++)
        out << list._Node[i] << " ";
    out << endl;

    return out;
    }

private:
    unsigned int length;

public:
    List();
    List(unsigned int);
    List(const List&);
    ~List();

    List& operator=(const List&);
    int setLength(unsigned int);
    unsigned int getLength();
    int setElement(unsigned int, T);
    T getElement(unsigned int);

    inline bool operator==(const List&);

};

template<typename T>
List<T>::List(): Node<T>(){

    length = 0;
}

template<typename T>
List<T>::List(unsigned int _length): Node<T>(_length){

    length = _length;
}

template<typename T>
List<T>::List(const List &other): Node<T>(other.length){

    length = other.length;
    if(other.length>0){
        for(unsigned int i=0; i<length; i++){
            this->_Node[i] = other._Node[i];
        }
    }

    else{
        this->_Node = NULL;
        length = 0;
    }
}

template<typename T>
List<T>::~List(){

    length = 0;
}

template<typename T>
List<T>& List<T>::operator=(const List<T> &other){

    this->reCreate(0);
    if(this != &other){

        length = other.length;
        this->reCreate(other.length);

        for(unsigned int i=0; i<length; i++)
            this->_Node[i] = other._Node[i];
    }

    return *this;
}

template<typename T>
int List<T>::setLength(unsigned int _length){
    if(length == 0){
        length = _length;
        this->reCreate(length);
        return 1;
    }
    else{
        cerr << "setLength error" <<endl;
        return 0;
    }
}

template<typename T>
unsigned int List<T>::getLength(){

    return length;
}

template<typename T>
int List<T>::setElement(unsigned int pos, T val){

    if(pos < length){
        this->_Node[pos] = val;
        return 1; 
    }
    else{
        cerr << "setElement error" << endl;
        return 0;
    }
}

template<typename T>
T List<T>::getElement(unsigned int pos){

    if(pos < length) return this->_Node[pos];
    else{
        cerr << "getElement error" << endl;
        return -99999;
    }
}

template<typename T>
inline bool List<T>::operator==(const List &other){

    if(this == &other) return 1;
    if(length != other.length) return 0;
    for(unsigned int i=0; i<other.length; i++){
        if(this->_Node[i] != other._Node[i]) return 0;
    }
    return 1;
}

#endif
