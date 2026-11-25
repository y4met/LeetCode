#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 计算数组总和,分成两等和数组==两数组和都为原数组和一半
        int s = reduce(nums.begin(), nums.end());
        // 若原数组和不为偶数,则一定无法分
        if(s % 2) return false;

        int n = nums.size();
        // 记忆化,二维数组
        vector memo(n, vector<int>(s/2+1, -1));

        auto dfs = [&](this auto&& dfs, int i, int j) -> bool {
            // 出口,若剩余和==0,则能分,否则不能
            if(i < 0) return j == 0;
            int& res = memo[i][j];
            if(res != -1) return res;

            // 若剩余和已经小于当前数,则不能选当前数,直接下一个数
            if(j < nums[i]) return res = dfs(i-1, j);
            // 选或不选当前数,能有一个能分即可
            return res = dfs(i-1, j) || dfs(i-1, j-nums[i]);
        };
        return dfs(n-1, s/2);
    }
};