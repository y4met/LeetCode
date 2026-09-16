#include <vector>
#include <algorithm>
using namespace std;

// 排序法
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 先将数组按照区间起点大小升序排序
        ranges::sort(intervals);
        vector<vector<int>> ans;

        // 遍历区间
        for(auto& p: intervals){
            // 如果答案数组中已有区间,并且末尾区间的终点 >= 当前区间的起点,则合并
            if(!ans.empty() && p[0] <= ans.back()[1]){
                // 将答案末尾区间的终点更新为二者较大值
                ans.back()[1] = max(ans.back()[1], p[1]);
            }else{
                // 答案数组为空,则将当前区间加入
                ans.emplace_back(p);
            }
        }
        return ans;
    }
};