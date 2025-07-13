#include <iostream>
using namespace std;

struct llist {
    struct Node {
        int data;
        Node* next;
    };

    Node* head = NULL;
    Node* tail = NULL;
    Node* mid = NULL;  
    int count = 0;     

    void traverse() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insert_first(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = head;

        if (!head) {  
            head = tail = mid = temp;
        } else {
            head = temp;
            if (count % 2 == 0) {  // Move mid forward when even-sized list
                mid = mid->next;
            }
        }

        count++;

        if (count == 1) {
            mid = head;
        }
    }

    void insert_last(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = NULL;

        if (!head) {
            head = tail = mid = temp;
        } else {
            tail->next = temp;
            tail = temp;
            if (count % 2 == 1) {  // Move mid forward when odd-sized list
                mid = mid->next;
            }
        }

        count++;

        if (count == 1) {
            mid = head;
        }
    }

    void deleteAtMiddle() {
        if (!mid) return;  // Empty list case

        if (head == tail) {  // Single node case
            delete mid;
            head = tail = mid = NULL;
            count = 0;
            return;
        }

        Node* prev = NULL;
        Node* temp = head;

        // Find previous node of mid
        while (temp != mid) {
            prev = temp;
            temp = temp->next;
        }

        if (!prev) {  // If mid is the first node
            head = mid->next;
        } else {
            prev->next = mid->next;
        }

        if (mid == tail) {
            tail = prev;  // Update tail if needed
        }

        delete mid;
        count--;

        // Correctly update mid
        if (count == 0) {
            mid = NULL;
        } else {
            Node* temp = head;
            for (int i = 0; i < count / 2; i++) {  // Recalculate mid
                temp = temp->next;
            }
            mid = temp;
        }
    }
};

int main() {
    llist l1;
    l1.insert_first(1);
    l1.insert_first(2);
    l1.insert_first(3);
    l1.insert_first(4);
    l1.insert_first(5);
    l1.insert_last(6);
    l1.insert_last(7);
    l1.insert_last(8);
    l1.insert_last(9);
    l1.insert_last(10);

    cout << "Original List: ";
    l1.traverse();

    l1.deleteAtMiddle();  
    cout << "After deleting middle: ";
    l1.traverse();
}
