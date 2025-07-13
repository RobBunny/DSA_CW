#include <iostream>
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

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(69);
    cout << s.peek() << endl;
    cout << s.pop() << endl;
    s.print();
    return 0;
}