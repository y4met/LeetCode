#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        // 无序哈希表记录已有数组值的下标
        unordered_map<int, int> idx;
        int n = nums.size();
        // 数组值依次在哈希表中找 和为目标值 的对象
        for(int j = 0; ; j++){
            auto it = idx.find(target - nums[j]);
            // 找到就返回对应下标的数对
            if(it != idx.end()) return {it->second, j};
            // 没找到即记录当前值下标
            idx[nums[j]] = j;
        }
    }
};