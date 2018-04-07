#include "Node.h"
#include <iostream>
template <class T>
class Queue {
    private:
        Node<T> *back, *front;
    public:
        Queue():back(NULL), front(NULL){}
        bool isEmpty() {return front == NULL;}
        bool isFull() {return false;}
        void enqueue(const T &itm) {
            Node<T> *newNode = new Node<T>(itm);
            if(isEmpty()) {
                back = front = newNode;
            }
            else {
                back -> next = newNode;
                back = back -> next;
            }
        }
        void dequeue(T &itm) {
            Node<T> *del;
            del = front;
            itm = front -> data;
            if(front == back) {
                front = back = NULL;
                delete del;
            }
            else {
                front = front -> next;
                delete del;
            }
        }
        void itemAtFront(T &itm) const {
            if(isEmpty()) return;
            itm = front -> data;
        }
        void printQueue() const {
            Node<T> *walk;
            walk = front;
            while(walk != NULL) {
                std::cout << walk -> data << "->";
                walk = walk -> next;
            }
            std::cout << "NULL\n";
        }
};
