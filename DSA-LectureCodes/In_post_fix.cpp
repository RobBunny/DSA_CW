#include <iostream>
using namespace std;

struct Stack {
    struct Node {
        char data;
        Node* next;
    };
    Node *top = NULL;

    void push(char data) {
        Node* temp = new Node();
        temp->data = data;
        temp->next = NULL;
        if (top == NULL) {
            top = temp;
        } else {
            temp->next = top;
            top = temp;
        }
    }

    char pop() {
        if(!top) return '\0';
        else {
            Node* temp = top;
            char x = top->data;
            top = top->next;
            delete temp;
            return x;
        }
    }

    char peek() {
        if(!top) return '\0';
        else return top->data;
    }

    void print() {
        Node* temp = top;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int precedence(char ch) {
        if (ch == '+' || ch == '-') return 1;
        else if (ch == '*' || ch == '/') return 2;
        else if (ch == '^') return 3;
        else return 0;
    }
};

string postfix(Stack s, string input) {
    string ans = "";
    for(int i=0; i<input.length(); i++) {
        if(isalnum(input[i])) ans += input[i];
        else if(input[i] == '(') s.push(input[i]);
        else if(input[i] == ')') {
            while(s.peek() != '(' && s.peek() != '\0') {
                ans += s.pop();
            }
            s.pop();
        }
        else {
            while(s.precedence(input[i]) <= s.precedence(s.peek())) {
                ans += s.pop();
            }
            s.push(input[i]);
        }
    }
    while(s.peek() != '\0') {
        ans += s.pop();
    }
    return ans;
}

int main() {
    Stack s;
    string input;
    cin >> input;
    string ans = postfix(s, input);
    cout << ans << endl;
    return 0;
}
