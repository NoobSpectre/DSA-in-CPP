#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *parent, *leftchild, *rightchild;

    Node(int); 
};

Node::Node(int data) {
    this -> data = data;
    parent = leftchild = rightchild = NULL;
}

void insert(Node* &, int);
void inOrder(Node* &);
void search(Node* &,int);

int main() {
    Node* root = NULL;

    insert(root, 5);
    insert(root, 2);
    insert(root, 4);
    insert(root, 1);
    insert(root, 6);
    insert(root, 8);
    insert(root, 10);

    cout << "The inorder traversal of the tree is : ";
    inOrder(root);
    cout << '\n';

    cout << "Enter a value: ";
    int val; cin >> val;

    search(root, val);

    return 0;
}

void insert(Node* &root, int val) {
    if(root == NULL)
        root = new Node(val);
    else if(root -> data > val) {
        if(root -> leftchild == NULL) {
            Node* newNode = new Node(val);
            root -> leftchild = newNode;
            newNode->parent = root;
        }
        else
            insert(root -> leftchild, val);
    }
    else if(root->data < val){
        if(root -> rightchild == NULL) {
            Node* newNode = new Node(val);
            root -> rightchild = newNode;
            newNode->parent = root;
        }
        else
            insert(root -> rightchild, val);
    }
}

void inOrder(Node* &root) {
    if(root == NULL) return;
    inOrder(root -> leftchild);
    cout << root -> data << " ";
    inOrder(root -> rightchild);
}

void search(Node* &root, int val) {
    if(!root) {
        cout << "The given value is not found..." << endl;
        return;
    }
    if(root->data == val) {
        if(root->parent == NULL) {
            cout << "It is the root of the whole tree...\nThe tree is: ";
            inOrder(root);
        }
        else if(root->leftchild == NULL && root->rightchild == NULL) {
            cout << "It is a leaf node of the whole tree...\nThe node is: " << root->data << endl;
        }
        else {
            cout << "It is an internal node of the whole tree...\n";
            if(root->leftchild != NULL) {
                cout << "Its leftchld is: " << root->leftchild->data << endl;
            }
            else if(!(root->leftchild)) {
                cout << "Its leftchild is: NULL" << endl;
            }
            if(root->rightchild != NULL) {
                cout << "Its rightchld is: " << root->rightchild->data << endl;
            }
            else if(!(root->rightchild)) {
                cout << "Its rightchild is: NULL" << endl;
            }
        }
    }
    else if(root->data > val) {
        search(root->leftchild, val);
    }
    else if(root->data < val) {
        search(root->rightchild, val);
    }
}