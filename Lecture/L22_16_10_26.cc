#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int key;
    Node* parent = nullptr; // allows us to walk up the tree w/o recursion
    Node* left = nullptr;
    Node* right = nullptr;
};

class BST
{
private:
    Node* root;

    Node* insertHelper(Node* currNode, int data);
    Node* searchKeyHelper(Node* currNode, int key);
    Node* deleteNodeHelper(Node* currNode, int value);
    void destroySubTree(Node* currNode);
    Node* getMinValueNode(Node* currNode);
    Node* getMaxValueNode(Node* currNode);
    Node* createNode(int data);

public:
    BST();
    BST(int data);
    ~BST();

    void insert(int data);
    bool searchKey(int key);
    void deleteKey(int key);
    void printTree();

};

BST::BST()
{
}

BST::BST(int data)
{
}

BST::~BST()
{
}

Node* BST::insertHelper(Node* currNode, int data)
{
    // Case 1: empty spot || empty tree
    if (currNode == nullptr)
    {
        return createNode(data);
    } 
    else if (data >= currNode->key) // Case 2: data >= key === go right
    {
        currNode->right = insertHelper(currNode->right, data);
        currNode->right->parent = currNode;
    } 
    else // Case 3: data < key === go left
    { 
        currNode->left = insertHelper(currNode->left, data);
        currNode->left->parent = currNode;
    }
    
    return currNode;
}

void BST::insert(int data)
{
    root = insertHelper(root, data);
}

Node* BST::searchKeyHelper(Node* currNode, int key)
{
    if ( (currNode == nullptr) || (currNode->key == key) ) // have to do the nullptr check first to ensure that you dont accidentally try and de-ref nullptr to check node->key. Called a short circuit
    {
        return currNode;
    }
    if (key < currNode->key)
    {
        return searchKeyHelper(currNode->left, key);
    }
    else
    {
        return searchKeyHelper(currNode->right, key);
    }
}

bool BST::searchKey(int key)
{
    return searchKeyHelper(root, key) != nullptr; // bool tells us whether the key was found or not
}

Node* BST::getMinValueNode(Node* currNode)
{
    if (currNode == nullptr)
    {
        return nullptr;
    }
    while (currNode->left != nullptr)
    {
        currNode = currNode->left;
    }
    return currNode;
}

Node* BST::getMaxValueNode(Node* currNode)
{
    if (currNode == nullptr)
    {
        return nullptr;
    }
    while (currNode->right != nullptr)
    {
        currNode = currNode->right;
    }
    return currNode;
}