#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, minprice = prices[0];
        // 依次遍历,每次计算当前元素-先前最小元素值
        for(int x: prices){
            // 取最大差值
            ans = max(ans, x-minprice);
            // 更新先前最小值
            minprice = min(minprice, x);
        }
        return ans;
    }
};