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
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode* , int>> q;
        int count = 0;
        q.push({root , 0});
        while(!q.empty()){
            TreeNode* frontNode = q.front().first;
            int dist = q.front().second;
            q.pop();
            if(dist < frontNode -> val) count++;

            if(frontNode -> left){
                q.push({frontNode -> left , dist+1});
            }
            if(frontNode -> right){
                q.push({frontNode -> right , dist+1});
            }
        }
        return count;
    }
};
