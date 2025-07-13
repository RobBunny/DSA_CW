#include <iostream>
using namespace std;

struct llist {
    struct Node{
        int data;
        Node* next;
    };

    Node* head = NULL;
    Node* tail = NULL;
    Node* mid = NULL;
    int count = 0;

    void traverse() {
        Node *temp = head;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl; 
    }

    void insert_first(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = NULL;
        if(!head) {
            head = temp;
            tail = temp;
            mid = temp;
        } else {
            temp->next = head;
            head = temp;
            if(count%2 == 0) mid = mid->next;
        }
        count++;
    }

    void insert_last(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = NULL;
        if(!head) {
            head = temp;
            tail = temp;
            mid = temp;
        } else {
            tail->next = temp;
            tail = temp;
            if(count%2 == 1) mid = mid->next;
        }
        count++;
    }

    void deleteAtMiddle() {
        if (!mid) return;  // Empty list case

        if (head == tail) {  // Single node case
            delete mid;
            head = tail = mid = NULL;
            count = 0;
            return;
        }

        Node* prev = head;
        if (mid == head) {  // If mid is the first node
            head = head->next;
            delete mid;
            mid = head;
        } else {
            // Find the previous node of mid
            while (prev->next != mid) {
                prev = prev->next;
            }
            prev->next = mid->next;
            delete mid;
            
            // Update tail if mid was the last node
            if (prev->next == NULL) {
                tail = prev;
            }
            
            if (count % 2 == 0) { // Update mid
                mid = prev;    
            } else {
                mid = prev->next;
            }
        }

        count--;
    }

    void insert_At(int x, int idx) {
        Node* temp = new Node();
        temp->data = x;
        Node* pos = head;
        int i = 0;
        while(i < idx-1) {
            pos = pos->next;
            i++;
        }
        temp->next = pos->next;
        pos->next = temp;
    }

    void insert_After(int x, int val) {
        Node* temp = new Node();
        temp->data = x;
        Node* pos = head;
        while(pos->data != val && pos != NULL) {
            pos = pos->next;
        }
        if(pos == NULL) return;
        if(pos == tail) tail = temp;
        temp->next = pos->next;
        pos->next = temp;
    }

    int delete_first() {
        if(!head) return -1;
        else if(head == tail) {
            int x = head->data;
            head = NULL;
            tail = NULL;
            return x;
        }
        else {
            Node* temp = head;
            int x = temp->data;
            head = head->next;
            delete temp;
            return x;
        }
    }

    int delete_last() {
        if(!head) return -1;
        else if(head == tail) {
            int x = head->data;
            head = NULL;
            tail = NULL;
            return x;
        }
        else {
            Node* temp1 = head;
            while(temp1->next != tail) temp1 = temp1->next;
            temp1->next = NULL;
            int x = tail->data;
            delete tail;
            tail = temp1;
            return x;
        }
    }

    int delete_At(int idx) {
        if(!head) return -1;
        else if(idx == 0) return delete_first();
        else {
            Node* temp1 = head;
            Node* temp2 = head->next;
            int i = 0;
            while(i < idx-1 && temp2 != NULL) {
                temp1 = temp1->next;
                temp2 = temp2->next;
                i++;
            }
            if(temp2 == NULL) return -1;
            else if(temp2 == tail) tail = temp1;
            temp1->next = temp2->next;
            int x = temp2->data;
            delete temp2;
            return x;
        }
    }

    int delete_key(int key) {
        if(!head) return -1;
        else if(head->data == key) {
            return delete_first();
        }
        else {
            Node* temp1 = head;
            Node* temp2 = head->next;
            while(temp2->data != key && temp2 != NULL) {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            if(temp2 == NULL) return -1;
            else if(temp2 == tail) tail = temp1;
            temp1->next = temp2->next;
            int x = temp2->data;
            delete temp2;
            return x;
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
    
    l1.traverse();
}