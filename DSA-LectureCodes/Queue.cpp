#include <iostream>
using namespace std;

struct Queue {
    struct Node {
        int data;
        Node *next;
    };
    Node *front = NULL;
    Node *rear = NULL;

    void enqueue (int data) {
        Node *temp = new Node();
        temp->data = data;
        temp->next = NULL;
        if (front == NULL) {
            front = temp;
            rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }

    int dequeue () {
        if(!front) return -1;
        else if(front == rear) {
            int x = front->data;
            front = NULL;
            rear = NULL;
            return x;
        }
        else {
            Node *temp = front;
            front = front->next;
            int x = temp->data;
            delete temp;
            return x;
        }
    }

    void display () {
        Node *temp = front;
        while(temp != NULL) {
            cout << temp->data << " ";            
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.dequeue() << endl;
    q.enqueue(4);
    q.enqueue(5);
    q.display();
}