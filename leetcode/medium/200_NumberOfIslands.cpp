#include <vector>
using namespace std;
class Solution {
public:

    int *dx;
    int *dy;
    vector<vector<int>> visited;

    Solution(){
        dx = new int[]{0, 1, 0, -1};
        dy = new int[]{-1, 0, 1, 0};
    }

    int numIslands(vector<vector<char>>& grid) {
        visited.resize(grid.size(), vector<int>(grid[0].size()));
        int ctr = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[i].size(); j++){
                if (!visited[i][j] && grid[i][j] == '1'){
                    dfs(i, j, grid);
                    ctr++;
                }
            }
        }
        return ctr;
    }
    bool check(int x, int y, vector<vector<char>>& grid){
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
    }

    void dfs(int x, int y, vector<vector<char>>& grid){
        if (visited[x][y] || grid[x][y] == '0') return;
        visited[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newy = y + dy[i];
            if (check(newX, newy, grid))
                dfs(newX, newy, grid);
        }
    }
};