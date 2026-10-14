struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 用 ans 记录答案
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> void{
            if(node == nullptr || k == 0) return;
            
            // 中序遍历,从小到大遍历树,每次遍历时 --k,当 k==0 时,当前节点即为第 k 小
            dfs(node->left);
            if(--k == 0) ans = node->val;
            dfs(node->right);
        };
        dfs(root);
        return ans;
    }
};

// 不用 ans 记录答案,找到直接返回
class Solution{
public:
    int kthSmallest(TreeNode* root, int& k){
        // 空节点说明没找到,返回-1(树中不含负数)
        if(root == nullptr) return -1;

        // 先在左子树中找
        int left = kthSmallest(root->left, k);
        // 不等于-1说明找到,直接返回
        if(left != -1) return left;

        // 再判断当前节点
        if(--k == 0) return root->val;

        // 最后在右子树中找,找到就直接返回值,没找到就返回-1
        return kthSmallest(root->right, k);
    }
};