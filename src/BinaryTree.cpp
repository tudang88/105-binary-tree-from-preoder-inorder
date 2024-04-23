#include <iostream>
#include "BinaryTree.h"
using namespace std;

/**
 * preorder traverser
*/
void Solution::DFSPreOrder(TreeNode *currentNode)
{
    if (currentNode == nullptr) return;
    cout << currentNode->val <<" ";
    if (currentNode->left != nullptr) {
        DFSPreOrder(currentNode->left);
    }
    if (currentNode->right != nullptr) {
        DFSPreOrder(currentNode->right);
    }
}

// /**
//  * traverser all level
//  * Depth First Search Solution
// */
TreeNode *Solution::createNode(vector<int>& preorder, vector<int>& inorder, 
unordered_map<int, int> &inorderMap, int& rootIdx, int leftInorderIndex, int lastInorderIndex)
{
    // base case
    if ( leftInorderIndex > lastInorderIndex || rootIdx + 1> preorder.size())
        return nullptr;
    int rootVal = preorder.at(rootIdx++);

    int pivot = inorderMap.at(rootVal);

    TreeNode* root = new TreeNode(rootVal);
    root->left = createNode(preorder, inorder, inorderMap, rootIdx, leftInorderIndex, pivot -1);
    root->right = createNode(preorder, inorder, inorderMap, rootIdx, pivot + 1, lastInorderIndex);
 
    return root;
}

/**
 * main method
*/
TreeNode *Solution::buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if (preorder.size() == 0 || preorder.size() != inorder.size()) return nullptr;
    unordered_map<int, int> inoderMap;
    // store value-index in a map
    int rootIdx = 0;
    int size = inorder.size();
    for (int i = 0 ; i < size; i++) {
        inoderMap[inorder.at(i)] = i;
    }
    return createNode(preorder, inorder, inoderMap, rootIdx, 0, size -1);
}
