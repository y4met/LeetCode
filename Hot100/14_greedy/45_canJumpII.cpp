#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt = 0;
        // cur记录当前最远能到哪,nxt记录下一次最远能到哪
        int curEnd = 0, nxtEnd = 0;
        int n = nums.size();
        // 只用遍历到 n-2 处, n-1处是终点,不用再跳
        for(int i=0; i<n-1; i++){
            // 更新下一次最远
            nxtEnd = max(nxtEnd, i+nums[i]);
            // 如果已经到达当前最远位置,说明必须要跳,跳到下一次最远位置
            if(i == curEnd){
                curEnd = nxtEnd;
                cnt++;
            }
        }
        return cnt;
    }
};