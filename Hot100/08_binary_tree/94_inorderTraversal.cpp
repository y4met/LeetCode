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

// 递归
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        // lambda 递归
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> void{
            // 递归出口
            if(node == nullptr) return;
            // 递归左子树
            dfs(node->left);
            // 根
            ans.push_back(node->val);
            // 递归右子树
            dfs(node->right);
        };
        
        //递归开始
        dfs(root);
        return ans;
    }
};

// Morris
class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> ans;

        while(root){
            // 从当前节点的左子树开始,一路向右,直到叶子节点,即可找到当前节点的前驱
            if(root->left){
                TreeNode* pre = root->left;
                // 找前驱
                while(pre->right && pre->right != root){
                    pre = pre->right;
                }
                // 如果第一次找到叶子节点,则建立前驱线索,并将当前节点移至左子树
                if(pre->right == nullptr){
                    pre->right = root;
                    root = root->left;
                    continue;
                }
                // 删除前驱线索,恢复树
                pre->right = nullptr;
            }
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
    }
};