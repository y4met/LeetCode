#include <cstddef>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }

    Node(int _val, Node* nxt, Node* r) {
        val = _val;
        next = nxt;
        random = r;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 先复制每个节点,接在对应节点后面,形成原节点->复制节点->原节点的交错链表
        for(Node* cur = head; cur; cur=cur->next->next){
            cur->next = new Node(cur->val, cur->next, nullptr);
        }

        // 再遍历交错链表处理random
        for(Node* cur = head; cur; cur=cur->next->next){
            // 如果random存在,则将当前节点的下一节点(即当前节点的复制节点)的random 指向 random对应节点的下一节点(即random对应节点的复制节点)
            if(cur->random){
                cur->next->random = cur->random->next;
            }
        }

        // 将交错节点拆开
        Node dummy(0);
        // 新链表的尾部
        Node* tail = &dummy;
        for(Node* cur = head; cur; cur=cur->next,tail=tail->next){
            // 复制出来的新节点,即当前节点的下一节点
            Node* copy = cur->next;
            // 新节点接到新链表尾部
            tail->next = copy;
            // 当前节点的下一节点应指向新节点的下一节点,即跳过复制出来的节点
            cur->next = copy->next;
        }
        return dummy.next;
    }
};