#include <stack>
#include <climits>
using namespace std;

class MinStack {
    // 每个位置保存当前值和到目前位置的最小值(前缀最小值)
    stack<pair<int,int>> st;
public:
    // 初始化为任意值+最大值
    MinStack() {
        st.emplace(0, INT_MAX);
    }
    // 入栈时更新前缀最小
    void push(int value) {
        st.emplace(value, min(getMin(), value));
    }
    
    void pop() {
        st.pop();
    }
    // 返回栈顶pair第一个值(即原始值)
    int top() {
        return st.top().first;
    }
    // 返回栈顶的前缀最小
    int getMin() {
        return st.top().second;
    }
};
