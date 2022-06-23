#include<iostream>
using namespace std;

class Node {
    private:
        Node* prev;
        int data;
        Node* next;
    public:
        Node(int data) {
            this -> prev = NULL;
            this -> data = data;
            this -> next = NULL;
        }
        friend void createLinkedList(Node* &head, int nodes);
        friend void print(Node* tmp);
        friend void delLargest(Node* &head);
};

void createLinkedList(Node* &head, int nodes) {
    if(nodes == 0) return;
    cout << "Enter the data: ";
    int data; cin >> data;
    Node* newNode = new Node(data);
    head = newNode;
    Node* tmp = newNode;
    newNode = NULL;
    delete(newNode);

    for(int i=2; i<=nodes; i++) {
        cout << "Enter the data: ";
        cin >> data;
        Node* newNode = new Node(data);
        tmp -> next = newNode;
        newNode -> prev = tmp;
        tmp = tmp -> next;
    }

//    cout << "Doubly Linked List is created with " << nodes << " nodes..." << endl;
}

void print(Node* tmp) {
    if(tmp == NULL) {
        cout << "Linked list is empty..." << endl;
        return;
    }
    cout << "\nThe linked list is:-" << endl;
    
    while(tmp != NULL) {
        cout << tmp -> data << " ";
        tmp = tmp -> next;
    }
    cout << endl;
}

void delLargest(Node* &head) {
	if(head == NULL) {
	    cout << "\nList is empty..." << endl;
	    return;
    }
    Node* curr = head;
    Node* largest = curr;
    while(curr != NULL) {
        if(curr -> data > largest -> data)
            largest = curr;
        curr = curr -> next;
    }
    if(largest == head) head = head -> next;
    else largest -> prev -> next = largest -> next;
    delete(largest);
    cout << "\nAfter removing the largest node from Linked List...";
}


int main() {
    cout << "Enter the number of nodes: ";
    int nodes; cin >> nodes;
    Node* head = NULL;
    createLinkedList(head, nodes);
    print(head);
    if(nodes == 0)
        return 0;

    delLargest(head);
    print(head);
    return 0;
}