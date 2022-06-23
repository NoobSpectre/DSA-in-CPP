#include<iostream>
using namespace std;

class Stack {
    private:
        int _top;
        int *arr;
        int capacity;

    public:
        Stack(int capacity) {
            this -> capacity = capacity;
            arr = new int[capacity];
            _top = -1;
        }

        ~Stack() {
            delete []arr;
        }

        bool empty() {
            if(_top == -1) return true;
            else return false;
        }

        void push(int data) {
            if(capacity - _top > 1) {
                _top++;
                arr[_top] = data;
            }
            else cout << "Stack Overflow" << endl;
        }

        void pop() {
            if(!empty()) _top--;
            else cout << "Stack Underflow" << endl;
        }


        int top() {
            if(_top >= 0)
                return arr[_top];
            else {
                cout << "...Stack  is empty...";
                return 0;
            }
        }

        inline int size() {
            return _top + 1;
        }

};

void printStack(Stack &st) {
    //base case
    if(st.empty()) 
        return;
    
    int num = st.top();
    st.pop();

    //recursive call
    printStack(st);

    cout << num << " ";
    st.push(num);
}


int main() {
    Stack st(5);
    st.push(5);
    st.push(8);
    st.push(10);
    st.push(15);

    cout << "The stack is: ";
    printStack(st);

    st.pop();
    st.pop();

    cout << "\nThe stack is: ";
    printStack(st);
    return 0;
}