#include <string>
#include <cstring>
using namespace std;

// 26叉树,一个节点对应一个字母,一条链对应一个单词
class Trie {
private:
    // 标记单词末尾
    bool isEnd;
    // 每个节点都可以接26个子节点,对应26字母
    Trie* next[26];
public:
    Trie() {
        // 初始无末尾,子节点都空
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    
    void insert(string word) {
        Trie* node = this;
        // 遍历单词
        for(char c: word){
            // 如果当前节点的子节点不包含当前字母,则创建一个新子节点
            if(node->next[c-'a'] == NULL){
                node->next[c-'a'] = new Trie();
            }
            node = node->next[c-'a'];
        }
        // 单词末尾标记
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(char c: word){
            // 如果子节点不包含当前字母,说明不包含该单词
            node = node->next[c-'a'];
            if(node == NULL) return false;
        }
        // 如果包含该单词的所有字母,要判断目前是否到达单词末尾
        // 是则说明对应上了,否则说明该单词只是这条链的一部分
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(char c: prefix) {
            node = node->next[c-'a'];
            if(node == NULL) return false;
        }
        // 不用判断是否是结尾,只要包含该单词所有字母
        return true;
    }
};