#include <string>
#include <vector>
using namespace std;

class Solution {
    static constexpr string letter[10] = {" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        if(n == 0) return {};
        vector<string> ans;
        // 记录每轮答案,长度一定为 n
        string path(n, 0);

        auto dfs = [&](this auto&& dfs, int i) -> void {
            // 达到长度时,记录答案
            if(i == n){
                ans.emplace_back(path);
                return;
            }

            // 遍历当前数字对应字母
            for(char c: letter[digits[i] - '0']){
                path[i] = c;
                // 下一个数字
                dfs(i+1);
            }
        };

        dfs(0);
        return ans;
    }
};