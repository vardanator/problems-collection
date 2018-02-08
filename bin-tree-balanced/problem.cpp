/*
Implement a function to check if a binary tree is balanced.
For the purposes of this question, a balanced tree is de ned to be a tree such that the heights of the
two subtrees of any node never differ by more than one.
*/

#include <cmath>
#include <iostream>
#include <algorithm>

struct Node
{
    int item;
    Node* left;
    Node* right;
    Node() : left(nullptr), right(nullptr) {}
    Node(int i) : item(i), left(nullptr), right(nullptr) {}
};

int getHeight(Node* node)
{
    if (node == nullptr) return 0;
    return 1 + std::max(getHeight(node->left), getHeight(node->right));
}

bool isBalanced(Node* root)
{
    if (root == nullptr) return true;
    int left_height = getHeight(root->left);
    int right_height = getHeight(root->right);
    return !(std::abs(left_height - right_height) > 1);
}

int main()
{
    Node* root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(3);
    Node* cur = root->right;
    for (int ix = 0; ix < 2; ++ix) { // making inbalanced
        cur->right = new Node(ix);
        cur = cur->right;
    }

    std::cout << "is balanced: " << isBalanced(root) << std::endl;
}
