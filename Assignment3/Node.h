#ifndef NODE
#define NODE

class Node{

protected:
    long* _Node;

public:
    Node();
    Node(unsigned int);
    Node(const Node&);
    ~Node();

    long* reCreate(unsigned int);

};


#endif

