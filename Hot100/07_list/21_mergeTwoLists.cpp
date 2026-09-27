struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 尾插法
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 创建新链表的哨兵节点
        ListNode newList;
        // 新链表的指针,指向新链表尾部
        ListNode* cur = &newList;
        while(list1 && list2){
            // 谁小指谁
            if(list1->val < list2->val){
                cur->next = list1;
                list1 = list1->next;
            }else{
                // 相等时指谁都行,合并为指2
                cur->next = list2;
                list2 = list2->next;
            }
            // 新链表后移
            cur = cur->next;
        }
        // 把没遍历的部分加上
        cur->next = list1 ? list1 : list2;
        return newList.next;
    }
};


// 递归
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 一个为空,直接返回另一个
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        // 谁小移谁
        if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
};