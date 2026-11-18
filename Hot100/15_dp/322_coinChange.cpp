#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // 记忆数组
        vector memo(n, vector<int>(amount+1, -1));

        // 递归选与不选当前面值
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            // 出口,无面值时结算
            // 总金额归零说明兑换完成,否则兑换不完
            if(i < 0) return j == 0 ? 0 : INT_MAX/2;
            int& res = memo[i][j];
            if(res != -1) return res;
            // 若当前面值>总金额,则不能选
            if(coins[i] > j) return res = dfs(i-1, j);
            // 可以选时,取不选和选的情况中次数更少的
            return res = min(dfs(i-1, j), dfs(i, j-coins[i])+1);
        };

        // 从最后一个面值向前选
        int ans = dfs(n-1, amount);
        // 如果答案为无限大,说明兑换不完,返回-1
        return ans<INT_MAX/2 ? ans : -1;
    }
};