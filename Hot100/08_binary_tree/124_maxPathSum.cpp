#include <climits>
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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;

        auto dfs = [&](this auto&& dfs, TreeNode* node) ->int {
            if(node == nullptr) return 0;
            // 递归求左右子树和
            int sumLeft = dfs(node->left);
            int sumRight = dfs(node->right);
            // 更新答案,左右子树和+当前节点值
            ans = max(ans, sumLeft + sumRight + node->val);
            // 返回 从当前节点出发,能得到的最大单边路径和
            // 左右子树只取一边是因为父节点只能接一条路径
            // 如果此值 <0 说明此路不值得走
            return max(max(sumLeft,sumRight)+node->val, 0);
        };

        dfs(root);
        return ans;
    }
};