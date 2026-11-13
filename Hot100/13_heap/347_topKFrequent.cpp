#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 哈希表记录每个元素出现次数
        unordered_map<int, int> m;
        int max_cnt = 0;
        // 遍历记录,并更新最大出现次数
        for(int i: nums) {
            m[i]++;
            max_cnt = max(max_cnt, m[i]);
        }

        // 把相同出现次数的元素放进同一个桶中
        vector<vector<int>> buckets(max_cnt+1);
        for(auto& [x, c]: m){
            buckets[c].push_back(x);
        }

        vector<int> ans;
        // 倒着遍历桶,即返回前 k大的出现次数元素
        for(int i = max_cnt; ans.size()<k; i--) {
            // insert用法(插入位置(实际插在这位置之前),插入区间起点,终点(前闭后开))
            ans.insert(ans.end(), buckets[i].begin(), buckets[i].end());
        }
        return ans;
    }
};