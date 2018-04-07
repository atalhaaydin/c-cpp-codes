#include "Node.h"
const int MAXSIZE = 1000;
template <class T>
class Stack{
    private:
        Node<T> *top;
        T items[MAXSIZE];
    public:
        Stack():top(NULL){}
        bool isEmpty() const {return top == NULL;}
        bool isFull() const {return false;}
        void push(const T &itm) {
            Node<T> *newNode = new Node<T>(itm);
            newNode -> next = top;
            top = newNode;
        }
        void pop(T &popped) {
            Node<T> del;
            del = top;
            top = top -> next;
            popped = top -> data;
            delete del;
        }
        void peak(T &peak) {
            peak = items[top];
        }
};
