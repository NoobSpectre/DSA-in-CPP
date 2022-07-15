#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
};

void createLinkedList(Node* &head, int nodes) {
    cout << "Enter the data: ";
    int data; cin >> data;
    Node* newNode = new Node(data);
    head = newNode;
    Node* tmp = head;
    newNode = NULL;
    delete(newNode);

    for(int i=2; i<=nodes; i++) {
        cout << "Enter the data: ";
        cin >> data;
        Node* newNode = new Node(data);
        tmp -> next = newNode;
        tmp = newNode;
    }

    cout << "Singly Linked List is created..." << endl;
}

void insertAtBeg(Node* &head, int data) {
    Node* newNode = new Node(data);
    head->next = newNode;
}

void insertAtENd(Node* &head, int data) {
    if(head == NULL) {
        insertAtBeg(head, data);
    }
    Node* curr = head;
    Node* newNode = new Node(data);
    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
}

void print(Node* &head) {
    if(head == NULL) {
        cout << "Linked list is empty..." << endl;
        return;
    }
    cout << "\nThe linked list is:-" << endl;
    
    Node* tmp = head;
    while(tmp != NULL) {
        cout << tmp -> data << " ";
        tmp = tmp -> next;
    }
    cout << endl;
}

// void displayNodefromEnd(Node* &head, int M, int N) {
//     if(head == NULL) cout << "Linked List has no nodes..." << endl;
//     else if(N > M) cout << "Linked List has less than " << N << " nodes..." << endl;
//     else {
//         int hold = N;
//         Node* curr = head;
//         while(N != 0) {
//             curr = curr -> next;
//             N--;
//         }
//         Node* prev = head;
//         while(curr != NULL) {
//             curr = curr -> next;
//             prev = prev -> next;
//         }
//         cout << "\nThe " << hold << "th node from end of linked list is: " << prev -> data << endl;
//     }
// }

int main() {
    cout << "Enter the number of nodes to create: ";
    int M; cin >> M;
    Node* head = NULL;
    createLinkedList(head, M);
    print(head);

    insertAtENd(head, 10);
    print(head);

    // cout << "\nEnter the value of n: ";
    // int N; cin >> N;
    // displayNodefromEnd(head, M, N);
    // print(head);
    return 0;
}