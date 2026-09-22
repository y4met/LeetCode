struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 空链表直接返回
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        // 递归尾插:先到链表尾部,作为新链表头节点
        auto rev_head = reverseList(head->next);
        // 新链表的尾部是原链表尾部的上一个节点(即倒序)
        ListNode* tail = head->next;
        tail->next = head;
        head->next = nullptr;
        return rev_head;
    }
};

// 头插法:从原链表前往后变方向
class Solution{
public:
    ListNode* reverseList(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur){
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};