struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    bool isSame(TreeNode* p, TreeNode* q){
        // 如果左右子树有一边为空,则判断另一边是否为空,是则对称,否则不对称
        if(p == nullptr || q == nullptr) return p == q;
        // 判断是否对称条件:
        // 1.左右子节点值
        // 2.左子节点的左子树与右子节点的右子树
        // 3.左子节点的右子树与右子节点的左子树
        return p->val == q->val && isSame(p->left, q->right) && isSame(p->right, q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isSame(root->left, root->right);
    }
};