#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

struct Node* formTree (Node* root) {
    int data;
    cin >> data;
    root = new Node(data);

    if(data == -1) return NULL;

    root->left = formTree(root->left);
    root->right = formTree(root->right);

    return root;
}

void printTree(Node* root) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* trav = q.front();
        cout << trav->data << " ";
        q.pop();
        if(trav->left) q.push(trav->left);
        if(trav->right) q.push(trav->right);
    }
    cout << endl;
}

void levelOrderTraversal(Node *root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        Node* trav = q.front();
        q.pop();
        if(trav == NULL) {
            cout << endl;
            if(!q.empty()) q.push(NULL);
        } else {
            cout << trav->data << " ";
            if(trav->left) q.push(trav->left);
            if(trav->right) q.push(trav->right);
        }
    }
}

void reverselevelOrderTraversal(Node *root) {
    queue<Node*> q;
    stack<Node*> s;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        Node* trav = q.front();
        q.pop();
        if(trav == NULL) {
            if(!q.empty()) {
                q.push(NULL);
                s.push(NULL);
            }
        } else {
            s.push(trav);
            if(trav->left) q.push(trav->left);
            if(trav->right) q.push(trav->right);
        }
    }
    while(!s.empty()) {
        Node *temp = s.top();
        s.pop();
        if(temp == NULL) cout << endl;
        else cout << temp->data << " ";
    }
}

void inorder(Node *root) {
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root) {
    if (root == nullptr) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {
    if (root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

/*void LevelOrderTraversal(Node *root) {
    if(root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}*/

int main() {
    Node* root = NULL;
    root = formTree(root);
    printTree(root);
    levelOrderTraversal(root);
    reverselevelOrderTraversal(root);
    cout << endl;
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    return 0;
}