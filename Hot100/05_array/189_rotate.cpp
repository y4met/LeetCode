#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // 减小时间消耗关键: 轮转 k 次 == 轮转 k%n 次
        k %= nums.size();
        // 先整体逆序
        reverse(nums.begin(), nums.end());
        // 再把 前k个 和 其余的 分别逆序
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin()+k, nums.end());
    }
};
