#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i=0; i<numRows; i++){
            // 第i行有i+1个数,初始化为 1
            ans[i].resize(i+1, 1);
            // 更新[1,i+1]的数(首尾为1不用更新)
            for(int j=1; j<i; j++){
                // 每个数等于左上角和正上方的数的和
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        return ans;
    }
};