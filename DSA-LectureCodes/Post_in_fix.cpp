#include <iostream>
#include <cmath>
using namespace std;

struct Stack {
    struct Node {
        int data;
        Node* next;
    };
    Node *top = NULL;

    void push(int data) {
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

    int pop() {
        if(!top) return -1;
        else {
            Node* temp = top;
            int x = top->data;
            top = top->next;
            delete temp;
            return x;
        }
    }

    int peek() {
        if(!top) return -1;
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
};

int PostCalc(string exp, Stack s) {
    for(int i = 0; i < exp.length(); i++) {
        if(exp[i] >= '0' && exp[i] <= '9') {
            s.push(exp[i] - '0');
        }
        else {
            int a = s.pop();
            int b = s.pop();
            switch(exp[i]) {
                case '+':
                    s.push(a + b);
                    break;
                case '-':
                    s.push(b - a);
                    break;
                case '*':
                    s.push(a * b);
                    break;
                case '/':
                    s.push(b / a);
                    break;
                case '^':
                    s.push(pow(b, a));
                    break;
                default:
                    break;
            }
        }
    }
    return s.pop();
}

int main() {
    Stack s;
    string exp;
    cin >> exp;
    int ans = PostCalc(exp, s);
    cout << ans << endl;
}