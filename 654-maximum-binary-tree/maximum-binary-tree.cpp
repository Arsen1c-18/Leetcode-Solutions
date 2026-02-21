// 654. Maximum Binary Tree
class Solution {
public:
    TreeNode* build(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;
        int maxIdx = l;
        for (int i = l; i <= r; i++)
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        TreeNode* root = new TreeNode(nums[maxIdx]);
        root->left = build(nums, l, maxIdx - 1);
        root->right = build(nums, maxIdx + 1, r);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
};