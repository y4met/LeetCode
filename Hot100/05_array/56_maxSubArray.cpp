#include <vector>
#include <climits>
using namespace std;

// 前缀和
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        // 记录先前最小前缀和
        int min_pre_sum = 0;
        // 记录当前前缀和
        int sum = 0;
        for(int x: nums){
            sum += x;
            // 寻找 当前前缀和-最小前缀和 的最大值
            ans = max(ans, sum - min_pre_sum);
            min_pre_sum = min(sum, min_pre_sum);
        }
        return ans;
    }
};