struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 哨兵节点
        ListNode dummy(0, head);
        // 上一组调整后的尾节点
        ListNode* lastTail = &dummy;

        while(true){
            ListNode* cur = lastTail;
            // 检查剩余节点数是否够k个
            for(int i=0; i<k; i++){
                cur = cur->next;
                // 不够就结束
                if(cur == nullptr){
                    return dummy.next;
                }
            }

            // 翻转本组
            ListNode* pre = nullptr;
            // cur为本组第一个,即 上组翻转后 的尾节点 的下一节点
            cur = lastTail->next;
            for(int i=0; i<k; i++){
                ListNode* nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }

            // 调整链表,使本组接回原链表,并调整指针,方便开启下一组翻转
            ListNode* tail = lastTail->next; // 本组翻转前的第一个节点,即翻转后的尾节点
            tail->next = cur; // 接上下组的第一个节点
            lastTail->next = pre; // 上组的尾节点指向本组新的头节点
            lastTail = tail; // 更新lastTail为本组新尾节点
        }
    }
};