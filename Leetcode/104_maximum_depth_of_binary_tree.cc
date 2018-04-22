/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if ( root == NULL )
            return 0;
        else if ( root->left == NULL and root->right == NULL )
            return 1;
        else if ( root->left == NULL )
            return 1 + maxDepth(root->right);
        else if ( root->right == NULL )
            return 1 + maxDepth(root->left);
        else
            return (max(1 + maxDepth(root->left), 1 + maxDepth(root->right)));
    }
};
