#include<iostream>
#include<stack>
using namespace std;

bool findredundantBrackets(string &s) {
    stack<char> st;
    bool isredundant;
    for(char i: s) {
        if(i == '(' || i == '+' || i == '-' || i == '*' || i == '/') {
            st.push(i);
        }
        else if(i == ')') {
            isredundant = true;
            while(st.top() != '(') {
                if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/') {
                    isredundant = false;
                }
                st.pop();
            }
            if(isredundant == true) return true;
            st.pop();
        }
    }
    return false;
}

int main() {
    cout << "Enter the epxression: ";
    string s;
    cin >> s;
    cout << "The given string contains redundant brackets: ";
    if(findredundantBrackets(s)){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}