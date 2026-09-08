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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL) return res;
        queue<TreeNode*>q;
        q.push(root);
        bool f=true;
        while(!q.empty()){
            int n=q.size();
            vector<int>ans;
            for(int i=0;i<n;i++){
                TreeNode* head = q.front();
                q.pop();
                ans.push_back(head->val);
                if(head->left!=NULL) q.push(head->left);
                if(head->right!=NULL) q.push(head->right);
            }
            if(f){
                res.push_back(ans);
                f=false;
            }
            else {
                reverse(ans.begin(),ans.end());
                res.push_back(ans);
                f=true;
            }
        }
        return res;
    }
};