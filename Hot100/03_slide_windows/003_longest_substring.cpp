#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 左指针作为窗口起点
        int ans = 0, left = 0;
        // 哈希表记录字符是否出现
        unordered_map<char, int> m;
        for(int i=0; i<s.length(); i++){
            // 记录字符
            m[s[i]]++;
            // 若有重复,则移动窗口
            while(m[s[i]] > 1){
                // 去除最左侧字符,左指针向右移动,缩小窗口
                m[s[left]]--;
                left++;
            }
            // 更新答案,先前最大值与当前窗口大小取大
            ans = max(ans, i-left+1);
        }
        return ans;
    }
};