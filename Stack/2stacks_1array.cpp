#include<iostream>
using namespace std;

class Stack {
    private:
        int _top1;
        int _top2;
        int *arr;
        int capacity;

    public:
        Stack(int capacity) {
            this -> capacity = capacity;
            arr = new int[capacity];
            _top1 = -1;
            _top2 = capacity;
        }

        ~Stack() {
            delete []arr;
        }

        bool empty1() {
            if(_top1 == -1) return true;
            else return false;
        }

        bool empty2() {
            if(_top2 == capacity) return true;
            else return false;
        }

        void push1(int data) {
            if(_top2 - _top1 > 1) {
                _top1++;
                arr[_top1] = data;
            }
            else cout << "Stack 1 Overflow" << endl;
        }

        void push2(int data) {
            if(_top2 - _top1 > 1) {
                _top2--;
                arr[_top2] = data;
            }
            else cout << "Stack 2 Overflow" << endl;
        }

        void pop1() {
            if(_top1 >= 0) _top1--;
            else cout << "Stack 1 Underflow" << endl;
        }

        void pop2() {
            if(_top2 < capacity) _top2++;
            else cout << "Stack 2 Underflow" << endl;
        }

        int top1() {
            if(_top1 >= 0) return arr[_top1];
            else {
                cout << "...Stack 1 is empty...";
                return 0;
            }
        }

        int top2() {
            if(_top2 < capacity) return arr[_top2];
            else {
                cout << "...Stack 2 is empty...";
                return 0;
            }
        }

        int size1() {
            return _top1 + 1;
        }

        int size2() {
            return capacity - _top2;
        }
};

void printStack1(Stack &st) {
    //base case
    if(st.empty1()) 
        return;
    
    int num = st.top1();
    st.pop1();

    //recursive call
    printStack1(st);

    cout << num << " ";
    st.push1(num);
}

void printStack2(Stack &st) {
    //base case
    if(st.empty2()) 
        return;
    
    int num = st.top2();
    st.pop2();

    //recursive call
    printStack2(st);

    cout << num << " ";
    st.push2(num);
}

int main() {
    Stack st(5);
    st.push1(5);
    st.push1(8);
    st.push1(10);
    st.push2(15);

    cout << "The stack 1 is: ";
    printStack1(st);
    cout << endl;
    cout << "The top element in stack 1 is: " << st.top1() << endl;
    cout << "The size of stack 1 is: " << st.size1() << endl;
    cout << "stack 1 is empty: " << st.empty1() << endl;

    cout << "The stack 2 is: ";
    printStack2(st);
    cout << endl;
    cout << "The top element in stack 2 is: " << st.top2() << endl;
    cout << "The size of stack 2 is: " << st.size2() << endl;
    cout << "stack 2 is empty: " << st.empty2() << endl;

    st.pop1();
    st.pop2();

    cout << "After popping an element from each stack..." << endl;
    cout << "The stack 1 is: ";
    printStack1(st);
    cout << endl;    
    cout << "The top element in stack 1 is: " << st.top1() << endl;
    cout << "The size of stack 1 is: " << st.size1() << endl;
    cout << "stack 1 is empty: " << st.empty1() << endl;
    
    cout << "The stack 2 is: ";
    printStack2(st);
    cout << endl;
    cout << "The top element in stack 2 is: " << st.top2() << endl;
    cout << "The size of stack 2 is: " << st.size2() << endl;
    cout << "stack 2 is empty: " << st.empty2() << endl;
    return 0;
}