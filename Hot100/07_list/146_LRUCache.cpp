#include <unordered_map>
using namespace std;

// 双向链表数据结构
struct Node {
    int key;
    int value;
    Node* pre;
    Node* next;

    Node(int k=0, int v=0): key(k), value(v) {}
};

class LRUCache {
private:
    int capacity;
    Node* dummy;
    // 哈希表记录节点的key,方便通过key找节点
    unordered_map<int, Node*> keyToNode;

    // 删除节点,用于超额时删除节点和调整节点位置
    void remove(Node* x){
        x->pre->next = x->next;
        x->next->pre = x->pre;
    }

    // 在链表开头插入节点
    void push_front(Node* x){
        x->pre = dummy;
        x->next = dummy->next;
        x->pre->next = x;
        x->next->pre = x;
    }

    // 查找节点
    Node* getNode(int key){
        auto it = keyToNode.find(key);
        if(it == keyToNode.end()){
            return nullptr;
        }
        // 找到的节点
        Node* node = it->second;
        // 先删除
        remove(node);
        // 再插到开头
        push_front(node);
        return node;
    }

public:
    LRUCache(int capacity): capacity(capacity), dummy(new Node()) {
        dummy->pre = dummy;
        dummy->next = dummy;
    }
    
    int get(int key) {
        Node* node = getNode(key);
        return node ? node->value : -1;
    }
    
    void put(int key, int value) {
        Node* node = getNode(key);
        if(node){
            node->value = value;
            return;
        }
        keyToNode[key] = node = new Node(key, value);
        push_front(node);
        // 超载时删除末尾节点
        if(keyToNode.size() > capacity){
            Node* tail = dummy->pre;
            keyToNode.erase(tail->key);
            remove(tail);
            delete(tail);
        }
    }
};
