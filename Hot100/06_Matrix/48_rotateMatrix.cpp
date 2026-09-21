#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        // 先按照主对角线翻转
        for(int i=0; i<m; i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 再把每一行翻转(一定要用引用,否则原矩阵不会变)
        for(auto& row: matrix){
            ranges::reverse(row);
        }
    }
};

/* 
一般地,把一个点绕 O旋转任意 θ 角度,可以通过两个翻转操作实现.
要求这两条翻转的对称轴,交点为 O 且夹角为 θ/2
​
对于本题,每个元素需要绕矩阵中心顺时针旋转 90∘
这可以通过关于主对角线翻转,关于垂直中轴翻转实现.
这两条对称轴的交点为矩阵中心，且夹角为 45∘
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        // 按照主对角线遍历,可以优化一次循环
        for(int i=0; i<m; i++){
            for(int j=i+1; j<m; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
            ranges::reverse(matrix[i]);
        }
    }
};