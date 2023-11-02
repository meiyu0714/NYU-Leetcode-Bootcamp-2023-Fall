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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() != 0){
            int count = q.size();
            vector<int> cur_level;
            while(count != 0){
                TreeNode* temp = q.front();
                q.pop();
                count --;
                cur_level.push_back(temp->val);
                if(temp->left != nullptr) q.push(temp->left);
                if(temp->right != nullptr) q.push(temp->right);
            }
            ans.push_back(cur_level);
        }
        return ans;
    }
};