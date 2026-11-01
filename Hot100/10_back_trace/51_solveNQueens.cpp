#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        // 棋盘,初始化全为.
        vector board(n, string(n, '.'));
        // col记录当前列是否有 Q,diag1记录主对角线方向是否有Q ,diag2记录副对角线方向
        vector<bool> col(n), diag1(n*2-1), diag2(n*2-1);
        // dfs按行遍历
        auto dfs = [&](this auto&& dfs, int r) {
            // 每行都放下Q, 说明可行
            if(r == n) {
                ans.push_back(board);
                return;
            }
            // 遍历列,在(r,c)处放 Q
            for(int c=0; c<n; c++){
                // 副对角线索引
                int rc = r-c+n-1;
                // 主对角线方向是r+c相等,副对角线方向是r-c相等
                if(!col[c] && !diag1[r+c] && !diag2[rc]) {
                    // 当前位置放 Q
                    board[r][c] = 'Q';
                    // 标记列和对角线已有 Q
                    col[c] = diag1[r+c] = diag2[rc] = true;
                    // 下一行
                    dfs(r+1);
                    // 恢复现场
                    col[c] = diag1[r+c] = diag2[rc] = false;
                    board[r][c] = '.';
                }
            }
        };
        dfs(0);
        return ans;
    }
};