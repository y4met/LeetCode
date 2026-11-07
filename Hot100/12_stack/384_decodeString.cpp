#include <string>
#include <stack>
using namespace std;

// 递归法
class Solution {
public:
    string decodeString(string s) {
        // s为空直接返回
        if(s.empty()) return s;
        // 第一个为字母说明该字母不用复制,直接返回+递归后面的字符
        if(isalpha(s[0])) return s[0] + decodeString(s.substr(1));

        // 第一位不是字母时,向后找第一个[,即找要复制的部分
        int i = s.find('[');
        // 用作[]匹配
        int balance = 1;
        for(int j=i+1; ; j++){
            // 找到 [,balance+1
            if(s[j] == '[') balance++;
            // 找到 ],balance-1,如果此时==0,说明[]匹配完全,复制部分已找到
            else if(s[j] == ']') {
                balance--;
                if(balance == 0) {
                    // 复制次数
                    int k = stoi(s.substr(0,i));
                    // 待复制部分
                    string t = decodeString(s.substr(i+1, j-i-1));
                    string res;
                    // 复制
                    while(k--) res += t;
                    // 返回复制后+递归后面字符
                    return res + decodeString(s.substr(j+1));
                }
            }
        }
    }
};

// 用栈模拟递归
class Solution {
public:
    string decodeString(string s) {
        // 用栈记录字符串和复制次数
        // 字符串是先前已经处理好的字符串, 复制次数是即将要复制的部分的复制次数
        stack<pair<string, int>> st;
        string res;
        // 复制次数
        int k = 0;

        for(char c: s){
            // 如果是字母就加入当前字符串
            if(isalpha(c)) res += c;
            // 是数字就更新复制次数
            else if(isdigit(c)) k = k*10 + (c-'0');
            // 是 [就准备复制
            else if(c == '['){
                // 先将之前的字符串状态保存
                st.emplace(move(res), k);
                k=0;
            }else { // 其余情况即为 ]
                // 当前res记录的为要复制的部分,把它暂存
                auto t = move(res);
                // 更新res为先前保存字符串
                res = move(st.top().first);
                // 取出复制次数
                k = st.top().second;
                // 取完弹出
                st.pop();
                // 复制
                for(; k>0; k--){
                    res += t;
                }
            }
        }
        return res;
    }
};