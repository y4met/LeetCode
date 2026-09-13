#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n-k+1);
        // 用双向队列记录窗口内元素
        deque<int> q;
        // 遍历数组
        for(int i=0; i<n; i++){
            // 当 即将进入窗口的元素 > 队列最后一个元素时,删除最后队列最后一个元素,确保最大的元素在队列开头位置
            while(!q.empty() && nums[q.back()] <= nums[i]){
                q.pop_back();
            }
            // 元素进入窗口
            q.push_back(i);

            // 检测窗口长度
            int left = i - k + 1;
            // 当队列长度 > 窗口长度时,删除队列开头元素
            if(q.front() < left){
                q.pop_front();
            }
            // 每个窗口最大元素为当前队列开头元素
            if(left >= 0) ans[left] = nums[q.front()];
        }
        return ans;
    }
};