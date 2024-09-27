#ifndef NODE
#define NODE
using namespace std;

template<typename T>
class Node{

protected:
    T* _Node;

public:
    Node();
    Node(unsigned int);
    ~Node();

    T* reCreate(unsigned int);

};

template<typename T>
Node<T>::Node(){

    _Node = nullptr;

}

template<typename T>
Node<T>::Node(unsigned int _length){

    if(_length == 0) _Node = nullptr;
    else _Node = new T[_length];
}

template<typename T>
Node<T>::~Node(){

    if(_Node != nullptr){
        delete [] _Node;
        _Node = nullptr;
    }
}

template<typename T>
T* Node<T>::reCreate(unsigned int _length){

    if(_length == 0) _Node = nullptr;
    else _Node = new T[_length];

    return _Node;
}

#endif
