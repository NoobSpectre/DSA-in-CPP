#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* link;

        Node() {
            link = NULL;
        }
};

class Queue {
    private:
        Node *head, *_front, *_rear;
        int _size;

    public:
        Queue(int capacity) {
            head = NULL;
            _front = NULL;
            _rear = NULL;
            _size = 0;

            if(capacity == 0) return;

            Node* newNode = new Node();
            head = newNode;
            newNode = NULL;

            Node* tmp = head;
            for(int i=2; i<=capacity; i++) {
                newNode = new Node();
                tmp -> link = newNode;
                tmp = newNode;
                newNode = NULL;
            }
        }

        ~Queue() {
            while(_front != NULL) {
                _front = _front -> link;
                delete(head);
                head = _front;
            }
            _rear = NULL;
        }

        bool isEmpty() {
            if(_front == NULL && _rear == NULL)
                return true;
            else 
                return false;
        }

        void enqueue(int data) {
            if(isEmpty()) {
                head -> data = data;
                _front = head;
                _rear = head;
                _size++;
            }
            else if(_rear -> link == NULL)
                cout << "Queue is full!!!" << endl;
            else {
                _rear = _rear -> link;
                _rear -> data = data;
                _size++;
            }
        }

        void dequeue() {
            if(isEmpty())
                cout << "Queue is empty!!!" << endl;
            else if(_front == _rear) {
                _front = NULL;
                _rear = NULL;
                _size--;
            }
            else {
                _front = _front -> link;
                _size--;
            }
        }

        int front() {
            if(!isEmpty()) return _front -> data;
            else {
                cout << "...Queue is empty...";
                return 0;
            }
        }

        int rear() {
            if(!isEmpty()) return _rear -> data;
            else {
                cout << "...Queue is empty...";
                return 0;
            }
        }

        int size() {
            return _size;
        }

        void printQueue() {
            if(isEmpty()) {
                cout << "Queue is empty!!!" << endl;
                return;
            }

            Node* tmp = _front;
            cout << "The queue is: ";
            while(tmp != _rear -> link) {
                cout << tmp -> data << " ";
                tmp = tmp -> link;
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