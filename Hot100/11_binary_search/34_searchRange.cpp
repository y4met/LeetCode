#include <vector>
using namespace std;

class Solution {
    // 二分查找
    int lower_bound(vector<int>& nums, int target) {
        int left = -1, right = nums.size();
        while(left+1 < right) {
            int mid = left + (right - left)/2;
            (nums[mid] >= target ? right : left) = mid;
        }
        return right;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // 先找目标值第一次出现的位置
        int start = lower_bound(nums, target);
        if(start == nums.size() || target != nums[start]) return {-1, -1};
        // 再找比目标值大 1的值的位置, 此处-1即为目标值最后出现位置
        int end = lower_bound(nums, target+1) - 1;
        return {start, end};
    }
};