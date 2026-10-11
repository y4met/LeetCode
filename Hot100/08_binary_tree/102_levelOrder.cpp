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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> ans;

        // 用队列保存当前层的节点
        queue<TreeNode*> q;
        // 初始层:根节点
        q.push(root);
        while(!q.empty()){
            // 保存当前层节点的值
            vector<int> vals;
            // 遍历当前层
            for(int n = q.size(); n--;){
                auto node = q.front();
                q.pop();
                vals.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            // 将当前层作为一个数组加入答案
            ans.push_back(move(vals));
        }
        return ans;
    }
};