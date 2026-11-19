#include <vector>
#include <algorithm>
using namespace std;

// 两数组并在一起排序,再找中位数
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto merged = nums1;
        merged.insert(merged.end(), nums2.begin(), nums2.end());
        ranges::sort(merged);

        int n = merged.size();
        int k = (n-1) / 2;
        return n % 2 ? merged[k] : (merged[k] + merged[k+1])/2.0;
    }
};


// https://leetcode.cn/problems/median-of-two-sorted-arrays/solutions/2950686/tu-jie-xun-xu-jian-jin-cong-shuang-zhi-z-p2gd
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) swap(nums1, nums2);

        int m = nums1.size(), n = nums2.size();
        nums1.insert(nums1.begin(), INT_MIN);
        nums2.insert(nums2.begin(), INT_MIN);
        nums1.insert(nums1.end(), INT_MAX);
        nums2.insert(nums2.end(), INT_MAX);

        int i = 0, j = (m+n+1)/2;
        while(nums1[i+1] <= nums2[j]){
            i++;
            j--;
        }

        int max1 = max(nums1[i], nums2[j]);
        int min2 = min(nums1[i+1], nums2[j+1]);
        return (m+n)%2 ? max1 : (max1+min2)/2.0;
    }
};