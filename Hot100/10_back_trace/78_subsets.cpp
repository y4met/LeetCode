#include <vector>
using namespace std;

// 枚举数组每个元素,选择是否加入本轮答案
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        // 记录本轮答案
        vector<int> path;
        vector<vector<int>> ans;

        auto dfs = [&](this auto&& dfs, int i) -> void {
            // 遍历到头时,本轮答案确定
            if(i == n){
                ans.emplace_back(path);
                return;
            }

            // 不选当前元素,直接进入下一个元素
            dfs(i+1);

            // 选当前元素,加入答案后,再进入下一个
            path.push_back(nums[i]);
            dfs(i+1);
            // 恢复现场:弹出当前元素,否则下一轮时当前元素会留在答案里
            path.pop_back();
        };

        dfs(0);
        return ans;
    }
};