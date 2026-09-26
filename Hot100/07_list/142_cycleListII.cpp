#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            // 快慢指针,当二者相遇时,slow再走从头指针到入环点的距离,即到达入环点
            if(slow == fast){
                while(slow != head){
                    // slow会在环内绕圈,当head和slow相遇时说明走够距离了
                    slow = slow->next;
                    head = head->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};