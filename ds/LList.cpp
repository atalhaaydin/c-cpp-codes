#include "SinglyLList.h"
#include <iostream>

using namespace std;

int main(void) {
    List<int> l;
    l.insertAtFront(12);    
    l.insertAt(10, 0);
    l.insertAt(10, 0);
    l.insertAtEnd(51);
    l.traverse();
    l.insertAt(10, 0);
    l.insertAtFront(17);
    l.insertAt(10, 0);
    l.traverse();
    cout << l.getSize() << endl;
    l.insertAt(66, 7);
    l.insertAt(55, 9);
    l.traverse();
    return 0;
}
