/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:

Input: root = [2,1,3]
Output: true
Example 2:

Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4. 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int updateMin(int min){
    if (min != INT_MAX) {
        min++;
    }
    return min;
}
int updateMax(int max){
    if (max != INT_MIN) {
        max--;
    }
    return max;
}
bool isValidBSTHelper(struct TreeNode* root, int min, int max){
    if (root == NULL){
        return true;
    }
    if (root -> val > max || root -> val < min){
        return false;
    }
    if (root -> val == INT_MIN && root -> left){
        return false;
    }
    if (root -> val == INT_MAX && root -> right){
        return false;
    }
    return isValidBSTHelper(root -> right, updateMin(root -> val), max) && isValidBSTHelper(root -> left, min, updateMax(root -> val));
}
bool isValidBST(struct TreeNode* root) {
    return isValidBSTHelper(root, INT_MIN, INT_MAX);
}
