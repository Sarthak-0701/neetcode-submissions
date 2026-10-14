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

    int solve(TreeNode* root , int& maxi){
        if(!root)   return 0;
        
        int leftAns = max(0 , solve(root -> left , maxi));
        int rightAns = max(0 ,solve(root -> right , maxi));

        int currSum = root -> val + leftAns + rightAns;
        maxi = max(maxi , currSum);
        
        return root -> val + max(leftAns , rightAns);
    }
  
    int maxPathSum(TreeNode* root) {
        if(!root)   return 0;
        
        int maxSum = INT_MIN;
        solve(root , maxSum);
        return maxSum == INT_MIN ? 0 : maxSum;
    }
};
