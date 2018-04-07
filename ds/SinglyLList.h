#include "Node.h"
#include <iostream>
template <class T>
class List{
    private:
        Node<T> *head;
        int sz;
    public:
        List():head(NULL), sz(0) {}
        int getSize() const {return sz;}
        bool isEmpty() const {return sz == 0;}
        bool isFull() const {return false;}
        void insertAtFront(const T &data) {
            Node<T> *newNode = new Node<T>(data);
            newNode -> next = head;
            head = newNode;
            sz++;
        }
        void insertAtEnd(const T &data) {
            Node<T> *newNode = new Node<T>(data);
            if (head == NULL) {
                head = newNode;
                sz++;
            }
            else {
                Node<T> *walk;
                walk = head;
                while(walk -> next != NULL) {
                    walk = walk -> next;
                }
                walk -> next = newNode;
                sz++;
            }
        }
        void insertAt(const T &data, int pos) {
            Node<T> *newNode = new Node<T>(data);
            Node<T> *walk;
            Node<T> *prev;
            if (pos > sz || pos < 0) return;
            else if (pos == 0) {
                newNode -> next = head;
                head = newNode;
                sz++;
                return;
            }
            else if (pos == sz) {
                walk = head;              
                while(walk -> next != NULL) {
                    walk = walk -> next;
                }
                walk -> next = newNode;
                sz++;
                return;
            }
            else {
                int count = 0;
                walk = head;
                prev = NULL;
                while(count != pos) {
                    prev = walk;
                    walk = walk -> next;
                    count++;
                }
                prev -> next = newNode;
                newNode -> next = walk;
                sz++;
                return;
            }
        }
        void traverse() const {
            Node<T> *walk;
            walk = head;
            while(walk != NULL) {
                std::cout << walk -> data << "->";
                walk = walk -> next;
            }
            std::cout << "NULL\n";
        }
};
