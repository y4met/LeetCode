#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // 必须是偶数才能匹配完全
        if(s.length()%2 != 0) return false;
        stack<char> st;
        for(char c: s){
            // 当前字符为左括号时,入栈对应右括号(方便比较)
            if(c == '(') st.push(')');
            else if(c == '{') st.push('}');
            else if(c == '[') st.push(']');
            // 为右括号时,如果栈空或者栈顶不与自己相同,说明匹配不上
            else {
                if(st.empty() || st.top() != c) return false;
                // 匹配上时,弹出栈顶
                st.pop();
            }
        }
        // 结束时如果栈空说明匹配完全,否则不行
        return st.empty();
    }
};