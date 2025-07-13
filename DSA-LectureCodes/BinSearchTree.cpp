#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

Node *insert(Node *root, int key) {
    if(root == nullptr) return new Node(key);
    if(key > root->val) root->right = insert(root->right, key);
    else root->left = insert(root->left, key);
    return root;
}

void inorder(Node *root) {
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->val << endl;
    inorder(root->right);
}

void decinorder(Node *root) {
    if(root == nullptr) return;
    decinorder(root->right);
    cout << root->val << endl;
    decinorder(root->left);
}

bool find(Node *cur, int key) {
    if(cur == nullptr) return false;

    if(cur->val == key) return true;
    else if(cur-> val > key) return find(cur->left, key);
    else return find(cur->right, key);
}

Node *findMin(Node *root) {
    while(root->left != nullptr) root = root->left;
    return root;
}

Node *findMax(Node *root) {
    while(root->right != nullptr) root = root->right;
    return root;
}

void inorderWithVector(Node *root, vector<int> &v) {
    if(root == nullptr) return;
    inorderWithVector(root->left, v);
    v.push_back(root->val);
    inorderWithVector(root->right, v);
}

int median(Node* root) {
    vector<int> v;
    inorderWithVector(root, v);
    return v[v.size()/2];
}

void inverseBST(Node *root) {
    if (root == nullptr) return;

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    inverseBST(root->left);
    inverseBST(root->right);
}

Node *deleteNode(Node *root, int key) {
    if(root == nullptr) return root;

    if(root->val > key) root->left = deleteNode(root->left, key);

    else if(root->val < key) root->right = deleteNode(root->right, key);

    else {
        if(root->left == nullptr) {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr) {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *temp = findMax(root->left);
        root->val = temp->val;
        root->left = deleteNode(root->left, temp->val);
    }
}

int main() {
    Node *root = nullptr;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);
    //inorder(root);
    //cout << find(root, 7) << endl;
    //deleteNode(root, 3);
    //cout << find(root, 3) << endl;
    inorder(root);
    cout << endl;
    decinorder(root);
    cout << endl;
    cout << median(root) << endl;
    cout << endl;
    inverseBST(root);
    inorder(root);
    return 0;
}