#include<iostream>
using namespace std;

class Queue {
    private:
        int *arr;
        int _front;
        int _rear;
        int capacity;
    
    public:
        Queue(int capacity = 10000) {
            this -> capacity = capacity;
            arr = new int[capacity];
            _front = -1;
            _rear = -1;
        }

        ~Queue() {
            delete []arr;
        }

        bool isEmpty() {
            if(_front == -1 && _rear == -1) {
                return true;
            }
            else return false;
        }

        void enqueue(int data) {
            if(_rear == capacity - 1) {
                cout << "Queue is full!!!" << endl;
            }
            else if(isEmpty()) {
                _front++;
                arr[++_rear] = data;
            }
            else {
                arr[++_rear] = data;
            }
            return;
        }

        void dequeue() {
            if(isEmpty()) {
                cout << "Queue is empty!!!" << endl;
            }
            else if(_front == _rear) {
                _front = -1;
                _rear = -1;
            }
            else {
                _front++;
            }
        }

        int front() {
            if(!isEmpty()) {
                return arr[_front];
            }
            else {
                cout << "...Queue is empty!!!...";
                return 0;
            }
        }

        int rear() {
            if(!isEmpty()) {
                return arr[_rear];
            }
            else {
                cout << "...Queue is empty!!!...";
                return 0;
            }
        }

        int size() {
            if(isEmpty()) {
                return 0;
            }
            else 
                return (_rear - _front + 1);
        }

        void printQueue() {
            if(isEmpty()) {
                cout << "Queue is empty!!!" << endl;
                return;
            }

            cout << "The queue is: ";
            for(int i=_front; i<=_rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;  
        }
};

int main() {
    Queue q(4);

    q.enqueue(5);
    q.enqueue(8);
    q.enqueue(22);
    q.enqueue(15);

    q.printQueue();

    q.dequeue();
    q.dequeue();
    
    q.printQueue();
    return 0;
}