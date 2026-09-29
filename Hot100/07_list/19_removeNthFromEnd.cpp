struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy{0, head};
        // 双指针间隔 n 位,当右指针到达末尾时,左指针的下一位即在倒数 n 位
        ListNode* right = &dummy;
        ListNode* left = &dummy;
        // 先移动右指针 n 位
        while(n--){
            right = right->next;
        }
        // 再一起移动
        while(right->next){
            left = left->next;
            right = right->next;
        }
        // 标记下一位方便删除
        ListNode* nxt = left->next;
        left->next = left->next->next;
        delete nxt;
        return dummy.next;
    }
};