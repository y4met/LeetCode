#include <algorithm>
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
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;

        auto dfs = [&](this auto&& dfs, TreeNode* node) -> int {
            if(node == nullptr) return 0;
            // 求左右子树最长链
            int left = dfs(node->left);
            int right = dfs(node->right);
            // 取 先前直径与左右子树最长链和 较大者
            ans = max(ans, left+right);
            // 返回左右子树中较长的链,+1是加上根节点
            return max(left, right)+1;
        };
        dfs(root);
        return ans;
    }
};