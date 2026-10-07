#include <iostream>
#include <string>

using namespace std;

// BST use: faster to find something/better optimization. O(log n) for a BST search
// we are currently not worried about ensuring that the BST is balanced. We only get O(log n) if the tree is balanced.
// Height is defined as the number of edges from the root to the leaf node
// public calls private
// Three traversal conventions: Pre-order (root->left->right), In-order (left->root->right), and Post-order (left->right->root)

// The BST node
struct Node
{
    int key;
    Node* leftChild = nullptr;
    Node* rightChild = nullptr;
};

void printInOrder(Node* currNode)
{
    if (currNode == nullptr)
    {
        return;
    }
    printInOrder(currNode->leftChild);
    cout << currNode->key;
    printInOrder(currNode->rightChild);
}

int main()
{

    return 0;
}