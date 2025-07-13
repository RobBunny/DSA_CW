#include <iostream>
using namespace std;

struct doubleLL {
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };
    Node* head = NULL;
    Node* tail = NULL;

    void insert_first (int data) {
        Node* temp = new Node();
        temp->data = data;
        temp->prev = NULL;
        temp->next = NULL;
        if(!head) {
            head = temp;
            tail = temp;
        } else {
            head->prev = temp;
            temp->next = head;
            head = temp;
        }
    }

    void insert_last (int data) {
        Node* temp = new Node();
        temp->data = data;
        temp->prev = NULL;
        temp->next = NULL;
        if(!head) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    int delete_first () {
        if(!head) return -1;
        else if(head == tail) {
            int x = head->data;
            head = NULL;
            tail = NULL;
            return x;
        }
        else {
            Node* temp = head;
            head = head->next;
            int x = temp->data;
            delete temp;
            return x;
        }
    }

    int delete_last () {
        if(!head) return -1;
        else if(head == tail) {
            int x = head->data;
            head = NULL;
            tail = NULL;
            return x;
        }
        else {
            Node* temp = tail;
            tail = tail->prev;
            int x = temp->data;
            delete temp;
            return x;
        }
    }

    void traverse () {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    doubleLL dll;
}