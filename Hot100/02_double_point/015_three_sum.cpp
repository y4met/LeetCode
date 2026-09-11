#include <vector>
#include <algorithm>
#include <ranges>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        // 先排序
        ranges::sort(nums);
        // 从小到大遍历,当前元素下一位和数组末尾的两个指针从两边向中间移动(转为双指针问题)
        for(int k = 0; k<nums.size()-2; k++){
            // 双指针
            int i = k+1, j=nums.size()-1;
            // 当前元素>0时,无满足和为0的对象
            if(nums[k]>0) break;
            // 去重, k &&去除第一个元素,防止越界
            if(k && nums[k] == nums[k-1]) continue;
            // 连续3个元素和>0时,后续 不会再有满足条件的组合,直接结束
            if (nums[k] + nums[k + 1] + nums[k + 2] > 0) break;
            // 当前元素和最大的两个元素和<0时，本轮不再有满足条件的组合,跳过本轮
            if (nums[k] + nums[j-1] + nums[j] < 0) continue;
            
            while(i<j){
                int s = nums[k]+nums[i]+nums[j];
                if(s < 0){
                    i++;
                }else if(s > 0){
                    j--;
                }else{
                    ans.push_back({nums[k],nums[i],nums[j]});
                    for(i++; i<j && nums[i]==nums[i-1]; i++); // 去重
                    for(j--; i<j && nums[j]==nums[j+1]; j--); // 去重
                }
            }
        }
        return ans;
    }
};