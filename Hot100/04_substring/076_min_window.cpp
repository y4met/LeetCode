#include <string>
using namespace std;

class Solution {
    // 通过两个循环判断当前子串是否包含t
    bool isCover(int scnt[], int tcnt[]){
        // 包含时,scnt中字符对应数字 > tcnt中
        for(int i = 'A'; i <= 'Z'; i++){
            if(scnt[i] < tcnt[i]){
                return false;
            }
        }
        for(int i = 'a'; i <= 'z'; i++){
            if(scnt[i] < tcnt[i]){
                return false;
            }
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        // 用两个数组记录子串和t中字母出现次数
        int t_cnt[128]{};
        int s_cnt[128]{};

        // 统计t中字母出现次数
        for(char c: t){
            t_cnt[c]++;
        }

        int ans_left = -1, ans_right = s.length();
        int left = 0;
        // 滑动窗口统计子串
        for(int r = 0; r < s.length(); r++){
            // 窗右进入
            s_cnt[s[r]]++;
            // 判断是否包含
            while(isCover(s_cnt, t_cnt)){
                // 如果包含,并且此时窗口长度小于先前记录的长度,则更新
                if(r-left < ans_right-ans_left){
                    ans_left = left;
                    ans_right = r;
                }
                // 窗左移出
                s_cnt[s[left]]--;
                left++;
            }
        }

        return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
    }
};

// 优化覆盖判定
class Solution {
public:
    string minWindow(string s, string t) {
        // 两个统计数组合并为一个,diff[i] = t_cnt[i] - s_cnt[i]
        int diff[128]{};
        // 记录t中字母种类
        int kind = 0;
        for(char c: t) {
            // 字母第一次出现则记录种类
            if(diff[c] == 0) kind++;
            diff[c]++;
        }

        int ans_left = -1, ans_right = s.length();
        int left = 0;
        // 记录窗口内满足 包含t中字母 的字母种类
        int subKind = 0;
        for(int r = 0; r < s.length(); r++){
            // 窗右进入,
            diff[s[r]]--;
            // 如果diff[i]==0, 说明此时该字母达到包含t的要求,种类+1
            if(diff[s[r]] == 0){
                subKind++;
            }

            // 如果窗口内种类==t中种类,则判断当前窗口和先前子串的长度
            while(subKind == kind){
                if(r-left < ans_right-ans_left){
                    ans_left = left;
                    ans_right = r;
                }

                //窗左移出,若在移出前diff[i]==0,说明移出后该字母不再满足要求,subKind-1
                if(diff[s[left]] == 0){
                    subKind--;
                }
                diff[s[left]]++;
                left++;
            }
        }
        return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
    }
};