#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n);

        auto dfs = [&](this auto&& dfs, int i) -> int {
            // 记忆化
            int& res = memo[i];
            if(res > 0) return res;
            // 从开头到自己(dfs(i))的最长递增子序列
            for(int j = 0; j<i; j++){
                // 若当前元素<结尾元素,说明可以加入子序列
                // 更新答案为 先前最长 和 当前元素的最长 的较大者
                if(nums[j] < nums[i]) res = max(res, dfs(j));
            }
            // 加上自己
            res++;
            return res;
            
        };
        int ans = 0;
        // 遍历每个元素,记录以其结尾的最长递增子序列
        for(int i=0; i<n; i++){
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};