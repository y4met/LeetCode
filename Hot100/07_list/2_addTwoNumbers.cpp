#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 递归+原地修改
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
        // 递归出口:若两链表皆空,则看有无进位,有则创建进位的新节点返回,无则返回空指针
        if(l1 == nullptr && l2 == nullptr){
            return carry ? new ListNode(carry) : nullptr;
        }
        // 保证l1非空,简化代码
        if(l1 == nullptr && l2){
            swap(l1, l2);
        }
        // 计算当前节点的值 = l1 + 进位 + l2(若有)
        int sum = l1->val + carry + (l2 ? l2->val : 0);
        // 保留个位数
        l1->val = sum % 10;
        // 递归求解下一节点
        l1->next = addTwoNumbers(l1->next, (l2 ? l2->next : nullptr), sum/10);
        return l1;
    }
};