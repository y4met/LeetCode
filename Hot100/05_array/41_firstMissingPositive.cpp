#include <vector>
using namespace std;

// 将每个数放在对应大小的位置,第一个数与位置不匹配的地方,位置下标即为第一个缺失的数
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // 如果当前数不在正确位置上,并且没有重复元素
            while (1 <= nums[i] && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                // 那么就交换 nums[i] 和 nums[j]，其中 j 是 i 的正确位置
                int j = nums[i] - 1; // 减一是因为数组下标从 0 开始
                swap(nums[i], nums[j]);
            }
        }

        // 找第一个下标与数字不匹配的位置
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        // 所有位置均正确,则返回最后一个数+1
        return n + 1;
    }
};