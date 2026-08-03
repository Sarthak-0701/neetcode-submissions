/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    bool isValid(TreeNode* root , int maxi , int mini){
        if(!root)   return true;
        
        bool leftAns = isValid(root -> left , root -> val , mini);
        bool rightAns = isValid(root -> right , maxi , root -> val);
        bool ans = (root -> val > mini) && (root -> val < maxi);

        return leftAns && rightAns && ans;

    }

    bool isValidBST(TreeNode* root) {
        if(!root)   return true;

        return isValid(root , INT_MAX , INT_MIN);

    }
};
