#include <iostream>
#include <algorithm> // For std::max
using namespace std;

// Structure for AVL Tree node
struct Node {
    int data;
    Node *left;
    Node *right;
    int height;
};

class AVLTree {
private:
    Node* root;

    // Function to get the height of the tree
    int height(Node *N) {
        if (N == NULL)
            return 0;
        return N->height;
    }

    // Create a new node
    Node* newNode(int data) {
        Node* node = new Node();
        node->data = data;
        node->left = node->right = NULL;
        node->height = 1; // new node is initially added at leaf
        return node;
    }

    // Right rotate subtree rooted with y
    Node* rightRotate(Node *y) {
        Node *x = y->left;
        Node *T2 = x->right;
        // Perform rotation
        x->right = y;
        y->left = T2;
        // Update heights
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        // Return new root
        return x;
    }

    // Left rotate subtree rooted with x
    Node* leftRotate(Node *x) {
        Node *y = x->right;
        Node *T2 = y->left;
        // Perform rotation
        y->left = x;
        x->right = T2;
        // Update heights
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        // Return new root
        return y;
    }

    // Get Balance factor of node N
    int getBalance(Node *N) {
        if (N == NULL)
            return 0;
        return height(N->left) - height(N->right);
    }

    // Insert a node into AVL Tree
    Node* insert(Node* node, int data) {
        // Perform normal BST insertion
        if (node == NULL)
            return newNode(data);
        if (data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        else // Equal keys are not allowed
            return node;
            
        // Update height of this ancestor node
        node->height = 1 + max(height(node->left), height(node->right));
        
        // Get balance factor
        int balance = getBalance(node);

        // If unbalanced, there are 4 cases
        // Left Left Case
        if (balance > 1 && data < node->left->data)
            return rightRotate(node);
        // Right Right Case
        if (balance < -1 && data > node->right->data)
            return leftRotate(node);
        // Left Right Case
        if (balance > 1 && data > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        // Right Left Case
        if (balance < -1 && data < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        // Return unchanged node pointer
        return node;
    }

    // Find node with minimum value
    Node *minValueNode(Node* node) {
        Node* current = node;
        while (current->left != NULL)
            current = current->left;
        return current;
    }

    // Delete a node from AVL Tree
    Node* deleteNode(Node* root, int data) {
        // Perform standard BST deletion
        if (root == NULL) return root;
        if (data < root->data)
            root->left = deleteNode(root->left, data);
        else if (data > root->data)
            root->right = deleteNode(root->right, data);
        else {
            // Node found
            if ((root->left == NULL) || (root->right == NULL)) {
                Node *temp = root->left ? root->left : root->right;
                if (temp == NULL) {
                    temp = root;
                    root = NULL;
                } else
                    *root = *temp;
                delete temp;
            } else {
                Node* temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }

        // If tree had only one node
        if (root == NULL) return root;

        // Update height
        root->height = 1 + max(height(root->left), height(root->right));
        
        // Check balance factor
        int balance = getBalance(root);

        // Left Left Case
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);
        // Left Right Case
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        // Right Right Case
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);
        // Right Left Case
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }

    // Print preorder traversal
    void preOrder(Node *root) {
        if (root != NULL) {
            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

public:
    AVLTree() { root = NULL; }

    void insert(int data) {
        root = insert(root, data);
    }
    
    void deleteNode(int data) {
        root = deleteNode(root, data);
    }
    
    void displayPreOrder() {
        cout << "Preorder traversal: ";
        preOrder(root);
        cout << "\n";
    }
};

int main() {
    AVLTree tree;
    int choice, val;
    while (1) {
        cout << "\n\n--- AVL Tree Menu ---\n";
        cout << "1. Insert\n2. Delete\n3. Display (Preorder)\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                tree.insert(val);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                tree.deleteNode(val);
                break;
            case 3:
                tree.displayPreOrder();
                break;
            case 4:
                return 0; // Exit main
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}
