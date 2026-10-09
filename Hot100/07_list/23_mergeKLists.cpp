#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    // 合并两有序链表
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode newList;
        ListNode* cur = &newList;
        while(list1 && list2){
            if(list1->val < list2->val){
                cur->next = list1;
                list1 = list1->next;
            }else{
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2;
        return newList.next;
    }
    
    // 分治+递归
    ListNode* mergeKLists(vector<ListNode*>& list, int i, int j){
        // 当前数组长度
        int m = j - i;
        // 递归出口
        if(m == 0) return nullptr;
        if(m == 1) return list[i];

        // 分治左半边
        auto left = mergeKLists(list, i, i+m/2);
        // 分治右半边
        auto right = mergeKLists(list, i+m/2, j);
        // 再将左右合并
        return mergeTwoLists(left, right);
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists(lists, 0, lists.size());
    }
};