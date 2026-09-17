#include <vector>
using namespace std;

// 暴力枚举,超时
class Solution {
    int multiple(vector<int>& arr, int idx){
        int result = 1;
        for(int i = 0; i < arr.size(); i++){
            if(i != idx) result *= arr[i];
        }
        return result;
    }

public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(multiple(nums, i));
        }
        return ans;
    }
};

// 前后缀处理
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // pre[i]表示从num[0]到num[i-1]的乘积
        vector<int> pre(n, 1);
        for(int i = 1; i < n; i++){
            pre[i] = pre[i-1] * nums[i-1];
        }
        // suf[i]表示从num[i+1]到num[n-1]的乘积
        vector<int> suf(n, 1);
        for(int i = n-2; i >= 0; i--){
            suf[i] = suf[i+1] * nums[i+1];
        }

        // 每个位置对应答案为pre[i] * suf[i],即前缀积*后缀积
        vector<int> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(pre[i]*suf[i]);
        }

        return ans;
    }
};

// 前后缀优化
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // 先计算suf
        vector<int> suf(n, 1);
        for(int i = n-2; i >= 0; i--){
            suf[i] = suf[i+1] * nums[i+1];
        }
        // 计算pre时,直接*suf
        int pre = 1;
        for(int i = 0; i < n; i++){
            suf[i] *= pre;
            pre *= nums[i];
        }

        return suf;
    }
};