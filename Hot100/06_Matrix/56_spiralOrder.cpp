#include <vector>
#include <climits>
using namespace std;

class Solution {
    // 创建方向数组,分别代表向右下左上,即在当前方向时下一步坐标如何变化(向右时行号不变,列+1)
    static constexpr int DIRS[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans(m*n);

        // di标记方向,用于访问DIRS
        int i=0, j=0, di=0;
        // 遍历矩阵
        for(int k=0; k<m*n; k++){
            ans[k] = matrix[i][j];
            // 遍历完的元素置为无限,防止重复输出
            matrix[i][j] = INT_MAX;
            // 先算出下一步位置,并判断是否要转向
            int x = i + DIRS[di][0];
            int y = j + DIRS[di][1];
            // 当行或列越界,或者已经访问过时,转向
            if(x<0 || x>=m || y<0 || y>=n || matrix[x][y] == INT_MAX){
                // di==4时可以回到0
                di = (di+1) % 4;
            }
            i += DIRS[di][0];
            j += DIRS[di][1];
        }
        return ans;
    }
};