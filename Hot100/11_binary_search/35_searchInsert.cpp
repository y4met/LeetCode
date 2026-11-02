#include <vector>
using namespace std;

// 开区间写法(left, right)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 左右指针索引
        int left = -1, right = nums.size();
        while(left+1 < right) {
            // 每次判断当前区间内中点与目标大小
            int mid = left + (right - left)/2;
            // 若中点大,则目标在区间前半部分,移动右指针到中点
            (nums[mid] >= target ? right : left) = mid;
        }
        return right;
    }
};