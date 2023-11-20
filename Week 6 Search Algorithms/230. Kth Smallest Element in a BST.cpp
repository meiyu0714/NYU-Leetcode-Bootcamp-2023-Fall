class Solution {
public:
    //先做tree pre-order traversal lc144感受一下
    vector<int> nums;
    void record(TreeNode* root){
        if(root == nullptr) return;
        record(root->left);
        nums.push_back(root->val);
        record(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        record(root);
        return nums[k-1];
    }
};