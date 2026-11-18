#include <cstring>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

// 全局记忆,避免各测试数据间重复计算
int memo[101][10001];
// 初始化记忆数组
auto init = [] {
    // -1表示没有被计算过
    memset(memo, -1, sizeof(memo));
    return 0;
}();

int dfs(int i, int j) {
    // 出口
    if(i == 0) {
        // (0,0)时说明计算完成,没有更多解; j!=0说明累加值<j,无解
        return j == 0 ? 0 : INT_MAX;
    }

    // 先将答案与记忆数组对应位置绑定
    int& res = memo[i][j];
    // 若此时不为-1,说明已经计算过,直接返回,不重复计算
    if(res != -1) return res;
    // 若此时 j 已经 < i*i, 一定不能选 i,否则将超额
    if(j < i*i) res = dfs(i-1, j);
    // 将答案更新为不选 i 和选 i的总数更小的一方
    else res = min(dfs(i-1, j), dfs(i, j-i*i)+1); // 选择 i时,下一次递归仍从i开始(因为可以重复选择)
    return res;
}

class Solution {
public:
    int numSquares(int n) {
        // 入口,从sqrt(n)开始向前选,若 >sqrt(n)则选择后一定 >n
        return dfs(sqrt(n), n);
    }
};