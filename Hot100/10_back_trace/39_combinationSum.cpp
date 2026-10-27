#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> path;
        vector<vector<int>> ans;
        
        auto dfs = [&](this auto&& dfs, int i, int left) -> void {
            // 距离目标值剩余值,若为0,说明当前路径是一个答案
            if(left == 0){
                ans.emplace_back(path);
                return;
            }
            // 遍历完数组,或者剩余值<0,说明没找到
            if(i == n || left<0) return;

            // 不选当前数字,直接进入下一个数
            dfs(i+1, left);

            // 选当前数字,加入当前路径
            path.push_back(candidates[i]);
            // 再进下一个数字,剩余值要减去当前数
            dfs(i, left-candidates[i]);
            // 恢复路径,防止下一轮路径中有多余数字
            path.pop_back();
        };
        dfs(0, target);
        return ans;
    }
};