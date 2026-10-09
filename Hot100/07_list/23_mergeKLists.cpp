#include <vector>
#include <queue>
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

// 最小堆
// 将所有可能是当前最小的节点入堆,再从堆中弹出最小节点
class Solution{
public:
    ListNode* mergeKLists(vector<ListNode*>& List){
        // 最小堆比较函数
        auto cmp = [](const ListNode* a, const ListNode* b){
            return a->val > b->val;
        };

        // 用优先队列实现最小堆
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;
        // 初始将所有非空链表的头节点入堆
        for(auto head: List){
            if(head){
                pq.push(head);
            }
        }

        ListNode dummy{};
        auto cur = &dummy;
        // 
        while(!pq.empty()){
            // 当前堆中最小节点(即堆顶节点)
            auto node = pq.top();
            // 弹出堆顶
            pq.pop();
            // 如果堆顶节点有下一个节点,就入堆
            if(node->next){
                pq.push(node->next);
            }
            // 最小节点接入结果链表
            cur->next = node;
            cur = cur->next;
        }
        return dummy.next;
    }
};