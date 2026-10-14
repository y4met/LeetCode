struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 头插法,从后向前遍历(右->左->根)
class Solution {
    // 创建头节点始终指向已经处理好的部分的第一个节点,即当前处理节点的下一个节点
    TreeNode* head = nullptr;
public:
    void flatten(TreeNode* root) {
        if(root == nullptr) return;

        // 先右
        flatten(root->right);
        // 再左
        flatten(root->left);
        // 最后根,左子节点置空
        root->left = nullptr;
        // 右指针指向头节点,即自己成为头节点
        root->right = head;
        // 头节点移动,方便下一节点插入
        head = root;
    }
};

// 分治:根的左右子树分别展开,再统一相接
class Solution{
    TreeNode* dfs(TreeNode* root) {
        if(root == nullptr) return nullptr;

        // 左右分别展开
        TreeNode* left_tail = dfs(root->left);
        TreeNode* right_tail = dfs(root->right);
        // 左子树展开后的尾节点
        if(left_tail){
            // 左子树尾节点的右子节点应为根的右子节点
            left_tail->right = root->right;
            // 根右子节点更新为左子节点
            root->right = root->left;
            // 左边置空
            root->left = nullptr;
        }

        // 返回展开后的尾节点,便于上层把右子树接在左子树后面
        return right_tail ? right_tail : left_tail ? left_tail : root;
    }
public:
    void flatten(TreeNode* root) {
        dfs(root);
    }
};