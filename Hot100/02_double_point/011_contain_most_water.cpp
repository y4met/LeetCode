#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        // 双指针,分别从数组两端向中间移动
        int left = 0,right = height.size()-1;
        while(left < right){
            // 计算每次移动后的容量(较小高度*距离)
            ans = max(ans, min(height[left],height[right])*(right-left));
            // 谁小谁动(短板效应)
            // 可写成三元形式 height[left] < height[right] ? left++ : right--;
            if(height[left] < height[right]) left++;
            else right--;
        }
        return ans;
    }
};