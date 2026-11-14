#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int start = 0, end = 0;
        int n = s.length();
        // 记录s中每个字母最后出现位置
        vector<int> last(26);
        for(int i=0; i<n; i++){
            last[s[i]-'a'] = i;
        }

        vector<int> ans;
        for(int i=0; i<n; i++){
            // 更新当前子串的末尾(先前末尾和当前字母的最后出现位置取大)
            end = max(end, last[s[i]-'a']);
            // 如果到达当前子串末尾,则将子串长度加入答案,同时更新下一个子串起点
            if(i == end){
                ans.push_back(end-start+1);
                start = end+1;
            }
        }
        return ans;
    }
};