#include <vector>
#include <span>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 递归:在前序中找到根节点,对应中序里根节点的左边为左子树,右边为右子树
class Solution {
    // span是引用了一段内存,
    TreeNode* build(span<int> preorder, span<int> inorder){
        if(preorder.empty()) return nullptr;
        int left_size = ranges::find(inorder, preorder[0]) - inorder.begin();
        // subspan(开始, 长度)切出子视图
        TreeNode* left = build(preorder.subspan(1, left_size), inorder.subspan(0, left_size));
        // subspan(开始)默认到末尾
        TreeNode* right = build(preorder.subspan(1+left_size), inorder.subspan(1+left_size));
        return new TreeNode(preorder[0], left, right);
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder);
    }
};