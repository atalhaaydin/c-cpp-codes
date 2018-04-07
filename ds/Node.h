#include <iostream>
template <class T>
class Node{
    public:    
        Node *next;
        T data;
        Node():next(NULL) {}
        Node(const T &d):next(NULL), data(d) {}
};
