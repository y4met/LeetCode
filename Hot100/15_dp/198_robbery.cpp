#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // 标记每个数是否计算过
        vector<int> idx(n, -1);

        auto dfs = [&](this auto&& dfs, int i) -> int {
            if(i < 0) return 0;
            // 计算过就直接返回,避免重复计算
            if(idx[i] != -1) return idx[i];
            // 每个位置有两种情况(取大):
            // 1.选了前一个数,则此位置不选
            // 2.没选前一个位置,则此位置为前2个位置+当前位置
            return idx[i] = max(dfs(i-1), dfs(i-2)+nums[i]);
        };
        // 从最后一个数向前
        return dfs(n-1);
    }
};


class Solution {
public:
    int rob(vector<int>& nums){
        int n = nums.size();
        // 用一个数组记录每个位置最大值
        vector<int> f(n+2);
        for(int i=0; i<n; i++){
            // 从前向后走
            f[i+2] = max(f[i+1], f[i]+nums[i]);
        }
        return f[n+1];
    }
};

// 滚动数组方式
class Solution {
public:
    int rob(vector<int>& nums){
        int f0 = 0, f1 = 0;
        for(int x: nums){
            // 新位置的最大值
            int new_f = max(f1, f0+x);
            // 向前滚动
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }
};
