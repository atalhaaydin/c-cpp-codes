const int MAX = 1000;
template <class T>
class Stack{
    private:
        int top;
        T items[MAX];
    public:
        Stack():top(-1) {}
        bool isEmpty() const {return top == -1;}
        bool isFull() const {return top == MAX - 1;}
        void pop(T &popped) {
            if (isEmpty()) return;
            popped = items[top];
            top--;
        }
        void push(const T &itm) {
            if(isFull()) return;
            top++;
            items[top] = itm;
        }
        void peak(T &pitem) {
            pitem = items[top];
        }
};
