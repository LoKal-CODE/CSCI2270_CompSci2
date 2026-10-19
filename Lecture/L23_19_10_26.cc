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
    Node* getMinValueNode(Node* currNode);
    Node* getMaxValueNode(Node* currNode);
    Node* createNode(int data);
    void destroySubTree(Node* currNode);

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

/*
 *  INSERT
*/

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

/*
 * SEARCH
*/

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

/*
 * MIN AND MAX VALUE NODES
*/

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

/*
 *  DELETE
*/

void BST::deleteKey(int key)
{
    root = deleteNodeHelper(root, key);
}

Node* BST::deleteNodeHelper(Node* currNode, int key)
{
    if (currNode == nullptr)
    {
        return nullptr;
    }
    else if (key < currNode->key)
    {
        currNode->left = deleteNodeHelper(currNode->left, key);
    }
    else if (key > currNode->key)
    {
        currNode->right = deleteNodeHelper(currNode->right, key);
    }
    else
    { // we have found the node that we want to delete, now we have to determine the surroundings of the node we want to delete...

        // A. No children
        if (currNode->left == nullptr && currNode->right == nullptr)
        {
            delete currNode;
            return nullptr;
        }
        
        // B. only right child
        else if (currNode->left == nullptr)
        {
            Node* pRight = currNode->right; // save the right child before deleting the node
            delete currNode; // delete the desired node
            return pRight; // replace the spot the desired node lived at in the tree with the right child and its children
        }
                

        // C. only left child
        else if (currNode->right == nullptr)
        {
            Node* pLeft = currNode->left; // save the left child before deleting the node
            delete currNode; // delete the desired node
            return pLeft; // replace the spot the desired node lived at in the tree with the left child and its children
        }
         

        // D. two children
        // Which child will take the place of the node we delete to keep the BST rule for every node?


    }
    
    return currNode;
    
}