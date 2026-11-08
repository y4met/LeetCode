#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        // 记录当前温度下标
        stack<int> st;

        for(int i=0; i<n; i++){
            int t = temperatures[i];
            // 当前温度不断与栈顶温度比较,一旦大于栈顶温度,就弹出
            while(!st.empty() && t>temperatures[st.top()]) {
                int j = st.top();
                st.pop();
                // 更新栈顶温度等待时间(即当前温度下标-栈顶温度下标)
                ans[j] = i - j;
            }
            // 栈空或者当前温度小于栈顶温度,直接入栈
            st.push(i);
        }
        return ans;
    }
};