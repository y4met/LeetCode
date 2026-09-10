#include <vector>
#include <algorithm>
using namespace std;

// 双指针法
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 记录最左侧0的位置
        int start0 = 0;
        // 遍历数组元素
        for(int& x: nums){
            // 当前元素不为0时,与最左侧0交换位置
            if(x){
                swap(x, nums[start0]);
                start0++;
            }
        }
    }
};

// 入栈法
// 将nums看作栈,遍历到非0元素即入栈,所有非0遍历完后,末尾补0至原大小
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 记录栈大小
        int stackSize = 0;
        for(int x: nums){
            if(x){
                // 元素不为0时入栈
                nums[stackSize++] = x;
            }
        }
        // 全部入栈后末尾补0
        fill(nums.begin() + stackSize, nums.end(), 0);
    }
};