#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode* dfs(vector<int>& nums, int left, int right){
        if(left == right) return nullptr;
        // 将数组分为两半,分别建树(递归)
        int m = left + (right - left) / 2;
        return new TreeNode(nums[m], dfs(nums, left, m), dfs(nums, m+1, right));
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size());
    }
};