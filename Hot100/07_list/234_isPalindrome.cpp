struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    // 翻转链表
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

public:
    bool isPalindrome(ListNode* head) {
        // 空链表和两元素链表直接返回true
        if(!head || !head->next) return true;

        // 快慢指针找中点
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // 只翻转后半部分链表
        ListNode* re = reverseList(slow->next);
        slow->next = nullptr;

        // 比较前半部分和翻转后的后半部分,都相同则是回文,否则不是
        ListNode* p = re;
        ListNode* q = head;
        while(p && q){
            if(p->val != q->val) return false;
            p = p->next;
            q = q->next;
        }
        return true;
    }
};