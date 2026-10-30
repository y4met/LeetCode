#include <vector>
#include <string>
using namespace std;

// 枚举每个位置是左括号还是右括号
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path(n*2, 0);

        auto dfs = [&](this auto&& dfs, int left, int right) -> void {
            if(right == n){
                ans.emplace_back(path);
                return;
            }
            // 左括号总数是n,没达到时可以选左括号
            if(left < n) {
                path[left+right] = '(';
                // 枚举下一个位置
                dfs(left+1, right);
            }
            // 左右必须相等,只有左边多时才能选右边
            if(left > right) {
                path[left+right] = ')';
                dfs(left, right+1);
            }
        };
        dfs(0, 0);
        return ans;
    }
};