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

    pair<int, int> diameter(TreeNode* root){
        if(!root)   return {0 , 0};

        pair<int,int> leftAns = diameter(root -> left);
        pair<int,int> rightAns = diameter(root -> right);

        pair<int , int> ans;
        ans.first = max(leftAns.first , rightAns.first) + 1;
        
        int op1 = leftAns.second;
        int op2 = rightAns.second;
        int op3 = leftAns.first + rightAns.first ;
        ans.second = max(op1 , max(op2 , op3));

        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)   return 0;

        pair<int,int> ans = diameter(root);

        return ans.second;    
    }
};
