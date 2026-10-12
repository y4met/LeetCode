#include <climits>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // 添加两参数,表示到当前节点的最小值和最大值
    bool isValidBST(TreeNode* root, long long left = LLONG_MIN, long long right = LLONG_MAX) {
        if(root == nullptr) return true;

        // 当前节点值
        long long x = root->val;
        // 左子节点一定小于当前值,右子节点一定大于当前值,左右子树也是
        return left < x && right > x &&
            isValidBST(root->left, left, x) &&
            isValidBST(root->right, x, right);
    }
};