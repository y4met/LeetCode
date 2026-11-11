#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

// 库函数
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        ranges::nth_element(nums, nums.end()-k);
        return nums[nums.size()-k];
    }
};

// 快速选择
class Solution {
    // 取一pivot, >pivot 的排后面, <pivot的排前面
    int partition(vector<int>& nums, int left, int right) {
        // 随机取pivot
        int i = left + rand()%(right - left + 1);
        int pivot = nums[i];
        // 先把pivot放最前面
        swap(nums[i], nums[left]);

        // 双指针遍历
        i = left + 1;
        int j = right;

        while(right) {
            // 左边小就直接向右移动
            while(i<=j && nums[i]<pivot) i++;
            // 右边大就直接向左移动
            while(i<=j && nums[j]>pivot) j--;
            if(i>=j) break;

            // 左边大,且右边小就交换左右
            swap(nums[i], nums[j]);
            // 交换完继续移动
            i++;
            j--;
        }
        // 把pivot归位
        swap(nums[left], nums[j]);
        // pivot下标
        return j;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        int n = nums.size();
        // 第k大的元素下标为 n-k
        int tar_idx = n - k;
        int left = 0, right = n - 1;
        while(true) {
            int i = partition(nums, left, right);
            // 如果pivot刚好是目标,即结束
            if(i == tar_idx) return nums[i];
            // pivot>目标则将区间缩到pivot的前面
            if(i > tar_idx) right = i - 1;
            // pivot<目标则区间缩到pivot后面
            else left = i + 1;
        }
    }
};