#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <ranges>
using namespace std;

class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        // 创建哈希表存 排序后相同的字符串
        unordered_map<string, vector<string>> m;
        // 字符串依次排序,存入哈希表
        for(string& s:strs){
            string sorted_s = s;
            ranges::sort(sorted_s);
            // 排序后相同的存在表中同一组
            m[sorted_s].push_back(s);
        }
        // 结果数组
        vector<vector<string>>  ans;
        // 分配空间
        ans.reserve(m.size());
        // 遍历哈希表中的值,即为答案
        for(auto& [_, value] : m){
            ans.push_back(value);
        }
        return ans;
    } 
};