#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node *insert(Node *root, int key) {
    if(root == nullptr) return new Node(key);
    
    if(key >= root->data) root->right = insert(root->right, key);
    else root->left = insert(root->left, key);
    return root;
}

void inorder(Node *root) {
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void combineTree(Node *root1, Node *root2) {
    if(root1 == nullptr) return;
    if(root2 == nullptr) return;
    combineTree(root1, root2->left);
    root1 = insert(root1, root2->data);
    combineTree(root1, root2->right);
}

int main() {
    Node *root1 = nullptr;
    Node *root2 = nullptr;
    int n1, n2;
    cin >> n1 >> n2;
    for(int i = 0; i < n1; i++) {
        int temp;
        cin >> temp;
        root1 = insert(root1, temp);
    }
    for(int i = 0; i < n2; i++) {
        int temp;
        cin >> temp;
        root2 = insert(root2, temp);
    }
    inorder(root1);
    cout << endl;
    inorder(root2);
    cout << endl;
    combineTree(root1, root2);
    inorder(root1);
}