#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// dfs
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        // 引入深度变量,用于判断此层是否首次到达
        auto dfs = [&](this auto&& dfs, TreeNode* node, int depth) -> void {
            if(node == nullptr) return;
            // 首次到达则记录
            if(depth == ans.size()) ans.push_back(node->val);
            // 先右子树再左子树
            dfs(node->right, depth+1);
            dfs(node->left, depth+1);
        };
        dfs(root, 0);
        return ans;
    }
};

// bfs,层序遍历,记录每层最后一个节点
class Solution {
public:
    vector<int> rightSideView(TreeNode* root){
        if(root == nullptr) return {};

        vector<int> ans;
        // 记录当前层节点
        vector<TreeNode*> cur = {root};

        while(cur.size()){
            // 将当前层最右边节点值加入答案数组
            ans.push_back(cur.back()->val);
            // 记录下一层节点
            vector<TreeNode*> nxt;
            // 遍历当前层节点,将每个节点的左右子节点加入下一层节点数组
            for(auto node: cur){
                if(node->left) nxt.push_back(node->left);
                if(node->right) nxt.push_back(node->right);
            }
            // 当前层移动到下一层
            cur = move(nxt);
        }
        return ans;
    }
};