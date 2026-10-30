#include <vector>
#include <string>
using namespace std;

class Solution {
    // 判断是否回文
    bool isPalindrome(const string s, int left, int right){
        while(left < right){
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> path;

        // 枚举每两个字符中间位置是否切开
        auto dfs = [&](this auto&& dfs, int i) -> void {
            if(i == n){
                ans.emplace_back(path);
                return;
            }

            for(int j = i; j<n; j++){
                // 如果从 i 到当前位置是回文,即切开
                if(isPalindrome(s, i, j)){
                    path.push_back(s.substr(i, j-i+1));
                    // 进入下一个位置
                    dfs(j+1);
                    // 恢复现场,防止 path 中有多余
                    path.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }
};