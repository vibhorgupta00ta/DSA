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
    int depth=1;
    int solve(TreeNode* curr,int d){
        if(curr==NULL) return 0;
        depth=1+max(solve(curr->left,depth+1),solve(curr->right,depth+1));
        return depth;
    }
    int maxDepth(TreeNode* root) {
        TreeNode* curr=root;
        return solve(curr,1);
    }
};