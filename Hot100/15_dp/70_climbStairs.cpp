#include <vector>
using namespace std;

// 简单递归,超时
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

class Solution {
public:
    int climbStairs(int n) {
        // 滚动数组
        // 初始化r=1,即f(0) = 1
        int p=0, q=0, r=1;
        // 滚动 n 次
        for(int i=0; i<n; i++){
            // p滚动到q 即f(i-1)
            p = q;
            // q 滚动到r 即f(i)
            q = r;
            // r 更新为f(i+1) = f(i-1) + f(i)
            r = p+q;
        }
        return r;
    }
};