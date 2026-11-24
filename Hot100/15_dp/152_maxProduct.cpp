#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        // 分别表示到当前元素的最大和最小乘积
        int f_max = 1, f_min = 1;
        for(int x: nums) {
            // 当前元素<0时,交换最大和最小,保证相乘后仍是最大和最小
            if(x<0) swap(f_max, f_min);
            // 比较 将当前元素加入前面子数组后的乘积 和 当前元素自成子数组 的乘积值,取最大和最小
            f_max = max(f_max*x, x);
            f_min = min(f_min*x, x);
            // 更新答案,取大
            ans = max(f_max, ans);
        }
        return ans;
    }
};