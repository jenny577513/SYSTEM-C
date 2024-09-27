#include <iostream>
#include "List.h"

using namespace std;

List::List(): Node(){

    length = 0;
}

List::List(unsigned int _length): Node(_length){

    length = _length;

}

List::List(const List &other): Node(other.length){

    length = other.length;
    if(other.length>0){
        for(unsigned int i=0; i<length; i++){
            _Node[i] = other._Node[i];
        }
    }

    else{
        _Node = NULL;
        length = 0;
    }
}

List::~List(){

    length = 0;
}

List List::operator=(const List &other){

    if(this != &other){

        length = other.length;
        reCreate(length);

        for(unsigned int i=0; i<length; i++)
            _Node[i] = other._Node[i];
    }

    return *this;
}

int List::setLength(unsigned int _length){
    if(length == 0){
        length = _length;
        reCreate(length);
        return 1;
    }
    else{
        cerr << "setLength error" <<endl;
        return 0;
    }
}

unsigned int List::getLength(){

    return length;
}

int List::setElement(unsigned int pos, long val){

    if(pos < length){
        _Node[pos] = val;
        return 1; 
    }
    else{
        cerr << "setElement error" << endl;
        return 0;
    }
}

long List::getElement(unsigned int pos){

    if(pos < length) return _Node[pos];
    else{
        cerr << "getElement error" << endl;
        return -99999;
    }
}


List List::operator+(const List &other){

    unsigned int loop = 
        length < other.length ? length : other.length;
    List obj(loop);
    for(unsigned int i=0; i<loop; i++)
        obj._Node[i] = _Node[i] + other._Node[i];
    
    return obj;
}

List List::operator+=(const List &other){
    unsigned int loop = 
        length < other.length ? length : other.length;
    
    for(unsigned int i=0; i<loop; i++)
        _Node[i] += other._Node[i];

    return *this;

}

List List::operator++(){

    for(unsigned int i=0; i<length; i++)
        ++_Node[i]; //prefix++

    return *this;
}

List List::operator++(int){

    List tmp(*this); //Retain a copy

    for(unsigned int i=0; i<length; i++)
        _Node[i]++; //postfix++

    return tmp;
}

List List::operator--(){

    for(unsigned int i=0; i<length; i++)
        --_Node[i]; //prefix--

    return *this;
}

List List::operator--(int){

    List tmp(*this); //Retain a copy

    for(unsigned int i=0; i<length; i++)
        _Node[i]--; //postfix--

    return tmp;
}

ostream& operator<<(ostream &out, List list){
    for(unsigned int i=0; i<list.getLength(); i++)
        out << list._Node[i] << " ";
    out << endl;

    return out;
}

istream& operator>>(istream &in, List &list){
    for(unsigned int i=0; i<list.getLength(); i++)
        in >> list._Node[i];

    return in;
}

