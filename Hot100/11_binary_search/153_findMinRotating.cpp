#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = -1, right = nums.size()-1;
        while(left+1 < right){
            int mid = left + (right - left)/2;
            // 中间值和最后一个数比大小,
            // 若中间值小,说明最小值在前半段
            (nums[mid] < nums.back() ? right : left) = mid;
        }
        return nums[right];
    }
};