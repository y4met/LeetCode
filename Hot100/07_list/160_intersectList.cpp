#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p = headA;
        ListNode* q = headB;
        // 两个节点分别向后走,走到空节点时从对方链表的头部再次走
        // 二者相等时说明在相交点,或者都在空节点(即无相交点)
        while(p != q){
            p = p ? p->next : headB;
            q = q ? q->next : headA;
        }
        return p;
    }
};