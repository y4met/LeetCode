#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// 定长处理
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        // 记录p中字符出现情况
        unordered_map<char, int> p_cnt;
        for(char c: p){
            p_cnt[c]++;
        }
        // 定长滑动窗口记录s字符,与p对比
        unordered_map<char, int> s_cnt;
        for(int right=0; right<s.length(); right++){
            // 窗右进入窗口
            s_cnt[s[right]]++;
            // 窗口左指针,保持与p等长
            int left = right - p.length() + 1;
            if(left < 0) continue; // 窗口大小<p长度时,跳过本轮

            // 字符出现情况一致则记录窗口左指针位置(起点)
            if(s_cnt == p_cnt){
                ans.push_back(left);
            }
            // 窗左移出窗口
            s_cnt[s[left]]--;
            // 字符出现次数为0时要删除该字符键,否则后续无法相等
            if(s_cnt[s[left]] == 0) s_cnt.erase(s[left]);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        // 使用定长数组代替哈希表记录字符,避免次数归0时未删除的问题
        vector<int> p_cnt(26,0);
        vector<int> s_cnt(26,0);

        for(char c: p){
            p_cnt[c-'a']++;
        }
        
        for(int right=0; right<s.length(); right++){
            s_cnt[s[right] - 'a']++;
            int left = right - p.length() + 1;
            if(left < 0) continue;

            if(s_cnt == p_cnt){
                ans.push_back(left);
            }
            s_cnt[s[left] - 'a']--;
        }
        return ans;
    }
};

// 不定长窗口处理
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> p_cnt(26,0);

        for(char c: p){
            p_cnt[c - 'a']++;
        }

        int left = 0;
        for(int r=0; r<s.length(); r++){
            // 窗右进入窗口
            p_cnt[s[r] - 'a']--;
            // 当p中字符出现次数<0时,说明有不属于p的字符出现,或者s中字符出现次数多余p中
            while(p_cnt[s[r] - 'a'] < 0){
                // 窗左移出
                p_cnt[s[left] - 'a']++;
                // 窗口左指针右移
                left++;
            }
            // 当窗口大小 == p长度时,匹配成功
            if(r - left + 1 == p.length()) ans.push_back(left);
        }
        return ans;
    }
};