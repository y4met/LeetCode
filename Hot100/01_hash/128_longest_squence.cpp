#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution{
public:
    int longestConsecutive(vector<int>& nums){
        // nums转为集合,去除重复元素,提高遍历效率
        unordered_set<int> st(nums.begin(),nums.end());
        int ans = 0;
        // 遍历集合
        for(int x: st){
            // 检查是否包含x-1,若是则说明x-1才是序列开头,跳过本次
            if(st.contains(x-1)) continue;

            // 依次向后检查是否包含
            int y = x + 1;
            while(st.contains(y)) y++;
            // 结束时, y-1 指向序列最后一个元素
            ans = max(ans, y-x);
            // 优化:ans >= nums长度一半时可提前结束
            if(ans * 2 >= st.size()) return ans;
        }
        return ans;
    }
};