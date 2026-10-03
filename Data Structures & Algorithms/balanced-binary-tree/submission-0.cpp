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

    pair<int , bool> isbalance(TreeNode* root){
        if(!root)   return {0 , true};
        if(!root -> left && !root -> right) return {1 , true};

        pair<int,bool> leftAns = isbalance(root -> left);
        pair<int,bool> rightAns = isbalance(root -> right);

        bool check1 = leftAns.second;
        bool check2 = rightAns.second;
        bool check3 = abs(leftAns.first - rightAns.first) <= 1;

        pair<int , bool> ans;
        ans.second = check1 && check2 && check3;
        ans.first = max(leftAns.first , rightAns.first) + 1;

        return ans;
    }

    bool isBalanced(TreeNode* root) {
        return isbalance(root).second;
    }
};
