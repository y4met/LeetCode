struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 哨兵
        ListNode dummy(0, head);
        // 交换两节点的前一个节点
        ListNode* node0 = &dummy;
        // 交换两节点的左节点
        ListNode* node1 = head;

        while(node1 && node1->next){
            // 交换两节点的右节点
            ListNode* node2 = node1->next;
            // 交换两节点的下一节点
            ListNode* node3 = node2->next;

            // 先将上一节点指向右节点
            node0->next = node2;
            // 再将右节点指向左节点
            node2->next = node1;
            // 最后将左节点指向下一节点
            node1->next = node3;

            // 下次交换的上一节点是这次交换的左节点
            node0 = node1;
            // 下次交换的左节点是这次交换的下一节点
            node1 = node3;
        }
        return dummy.next;
    }
};

// 递归
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        // 当前交换两节点的左节点
        ListNode* node1 = head;
        // 当前交换两节点的右节点
        ListNode* node2 = head->next;
        // 交换两节点的下一节点
        ListNode* node3 = node2->next;

        // 左节点指向后面一次交换的左节点(即链表头)
        node1->next = swapPairs(node3);
        // 右节点指向左节点
        node2->next = node1;

        // 返回链表头
        return node2;
    }
};