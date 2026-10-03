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

    void createMapping(const vector<int>& in ,
     unordered_map<int,int>& nodeToIdx){
        for(int i = 0 ; i < in.size() ; i++)    nodeToIdx[in[i]] = i;
        
    }

    TreeNode* buildBST(const vector<int>& pre , unordered_map<int,int>& nodeToIdx , int& idx , int s , int e){
        if(idx >= pre.size() || s > e){
            return nullptr;
        }
        int val = pre[idx++];
        TreeNode* root = new TreeNode(val);

        int i = nodeToIdx[val];

        root -> left = buildBST(pre, nodeToIdx, idx, s , i-1);
        root -> right = buildBST(pre, nodeToIdx, idx, i+1 , e);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderidx = 0;
        unordered_map<int,int> nodeToIdx;
        createMapping(inorder , nodeToIdx);
        int s = 0;
        int e = preorder.size()-1;
        return buildBST(preorder , nodeToIdx , preorderidx , s , e);
    }
};
