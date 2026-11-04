#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 数组最后一个数,用于比较,判断对应值在数组哪个部分
        int last = nums.back();
        int left = -1, right = nums.size()-1;
        while(left + 1 < right) {
            int mid = left + (right - left)/2;
            int m = nums[mid];
            // 如果目标值大于最后值,并且中间值小于等于最后值,
            // 说明目标值位于第一段,中间值在第二段,即目标值在中间值前面(收缩右指针)
            if(target>last && m<=last) right = mid;
            // 如果目标值小于等于最后值,并且中间值大于最后值,
            // 说明目标值位于第二段,中间值在第一段,即目标值在中间值后面(收缩左指针)
            else if(target<=last && m>last) left = mid;
            // 如果目标值小于等于中间值
            // 说明二者在同一段,并且目标值在中间值前面(收缩右指针)
            else if(m>=target) right = mid;
            // 剩余情况
            else left = mid;
        }
        return nums[right] == target ? right : -1;
    }
};