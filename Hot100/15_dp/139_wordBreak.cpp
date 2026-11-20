#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // ranges::max(遍历范围, 比较器(默认less), 投影)
        // 即找到wordDict中最长的字符串
        int maxLen = ranges::max(wordDict, {}, &string::size).size();
        // 将wordDict放到哈希集合中,方便后续查找
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        int n = s.size();
        // 记忆化
        vector<int> memo(n+1, -1);

        auto dfs = [&](this auto&& dfs, int i) -> bool {
            // 出口,递归到第一个字符时,说明能包含,返回true
            if(i == 0) return true;

            int& res = memo[i];
            if(res != -1) return res;

            // 每次从后往前遍历,终点为maxLen(超出maxLen的一定不在字典中)
            for(int j = i-1; j >= max(i-maxLen, 0); j--){
                if(words.contains(s.substr(j, i-j)) && dfs(j)) return res = true;
            }
            return res = false;
        };
        // 从后向前递归
        return dfs(n);
    }
};