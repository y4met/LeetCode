struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 归并排序
class Solution {
    // 快慢指针找到中间节点
    ListNode* middleNode(ListNode* head){
        // pre指向中间节点的前一节点,用于断开链表
        ListNode* pre = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        return slow;
    }

    // 合并两有序链表
    ListNode* mergeTwoList(ListNode* list1, ListNode* list2){
        ListNode dummy;
        ListNode* tail = &dummy;
        while(list1 && list2){
            if(list1->val < list2->val){
                tail->next = list1;
                list1 = list1->next;
            }else{
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }

public:
    ListNode* sortList(ListNode* head) {
        // 递归出口
        if(head == nullptr || head->next == nullptr) return head;

        // 找中间节点,拆成两链表
        ListNode* h2 = middleNode(head);

        // 分别排序
        head = sortList(head);
        h2 = sortList(h2);

        // 再合并
        return mergeTwoList(head, h2);
    }
};