#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 记录最远能到达位置
        int mx = 0;
        int n = nums.size();
        // 从头遍历到尾,也可以当 mx >= n-1时提前结束
        for(int i=0; i<n-1; i++){
            // 如果最远到达位置小于当前位置,说明跳不到当前位置,更跳不到末尾
            if(i>mx) return false;
            // 能到达当前位置则更新最远位置
            mx = max(i+nums[i], mx);
        }
        return true;
    }
};