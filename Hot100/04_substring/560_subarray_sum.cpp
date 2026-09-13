#include <vector>
#include <unordered_map>
using namespace std;

// 连续子串和为k 等价于 子串起点和末尾位置前缀和差值为k,即s[j]-s[i] = k
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        // 计算nums前缀和,并且s[0] = 0
        vector<int> s(n+1);
        for(int i=0; i<n; i++){
            s[i+1] = s[i] + nums[i];
        }

        // 将问题转化为 枚举s[j],寻找先前是否有s[i],s[i] = s[j]-k,所以找s[j]-k即可 
        unordered_map<int, int> m;
        int ans = 0;
        for(int sj: s){
            ans += m.contains(sj - k) ? m[sj - k] : 0;
            m[sj]++;
        }
        return ans;
    }
};