#include <unordered_map>
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
    int pathSum(TreeNode* root, int targetSum) {
        // 记录根节点到当前节点的前缀节点值之和
        unordered_map<long long, int> cnt{{0, 1}};
        int ans = 0;

        auto dfs = [&](this auto&& dfs, TreeNode* node, long long s){
            if(node == nullptr) return;
            s += node->val;
            // 如果 s-targetSum 存在,说明此时存在从某一节点到当前节点的和==targetSum
            ans += cnt[s - targetSum];

            cnt[s]++;
            dfs(node->left, s);
            dfs(node->right, s);
            // 回溯,使cnt记录的是当前路径上的值,不会跨左右子树
            cnt[s]--;
        };
        dfs(root, 0);
        return ans;
    }
};