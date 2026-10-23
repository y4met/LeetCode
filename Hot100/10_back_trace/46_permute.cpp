#include <vector>
using namespace std;

// 递归:轮流让不同元素固定在第一个
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        auto dfs = [&](this auto&& dfs, int x) -> void {
            // 当前要固定元素是数组最后一个元素时,说明本轮排列完成
            if(x == nums.size()-1) {
                ans.push_back(nums);
                return;
            }
            // 遍历数组,依次固定每个元素
            for(int i=x; i<nums.size(); i++){
                // 将本轮要固定的元素放在未固定的第一位
                swap(nums[i], nums[x]);
                // 递归固定下一位
                dfs(x+1);
                // 恢复位置,方便下一次排列
                swap(nums[i], nums[x]);
            }
        };

        dfs(0);
        return ans;
    }
};