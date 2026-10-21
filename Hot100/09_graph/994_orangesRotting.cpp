#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // fresh记录所有新鲜橘子数量
        int fresh = 0, minutes = 0;
        // 记录所有腐烂橘子位置
        queue<pair<int, int>> q;
        // 遍历图,找到所有新鲜和腐烂橘子
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    fresh++;
                }else if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        // 没新鲜的直接返回
        if(fresh == 0) return 0;

        // 方向数组:分别为 右左下上
        int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while(!q.empty() && fresh>0) {
            // 这一轮腐烂橘子数量
            int sz = q.size();
            while(sz--) {
                auto [x, y] = q.front();
                q.pop();
                // 找腐烂橘子的上下左右四边
                for(auto d: dirs){
                    int nx = x + d[0], ny = y + d[1];
                    // 越界则停
                    if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
                    // 为空或烂橘子也停
                    if(grid[nx][ny] != 1) continue;
                    // 新鲜变腐烂
                    grid[nx][ny] = 2;
                    // 新鲜个数-1
                    fresh--;
                    // 把新变腐烂的加入腐烂橘子队列
                    q.push({nx, ny});
                }
            }
            // 一轮结束后加时间
            minutes++;
        }
        // 结束后如果还有新鲜橘子,说明它没办法被感染,返回-1
        // 没有新鲜橘子说明都被感染,返回时间
        return fresh==0 ? minutes : -1;
    }
};