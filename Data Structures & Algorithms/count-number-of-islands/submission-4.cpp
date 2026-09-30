
class Solution {
public:
    void chcker(vector<vector<char>>& grid, vector<int> cur_cord, int numIslands) {
        queue<pair<int, int>> q;
        q.push({cur_cord[0], cur_cord[1]});
        
        while(!q.empty()) {
            int size_y = grid[0].size();
            int size_x = grid.size();

            pair<int, int> current = q.front();
            q.pop();
            int x = current.first;
            int y = current.second;
            grid[x][y] = '0';
            if (y + 1 < size_y && grid[x][y + 1] == '1') {
                q.push({x, y+1});
                grid[x][y + 1] = '0';

            }
            if (y - 1 >= 0 && grid[x][y - 1] == '1') {
                q.push({x, y-1});
                grid[x][y - 1] = '0';

            }

            if (x + 1 < size_x && grid[x + 1][y] == '1') {
                q.push({x + 1, y});
                grid[x + 1][y] = '0';

            }
            if (x - 1 >= 0 && grid[x - 1][y] == '1') {
                q.push({x - 1, y});
                grid[x -1][y] = '0';

            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                vector<int> cur_cord = {i, j}; 
                if (grid[i][j] == '1') {
                    chcker(grid, cur_cord, numIslands);
                    numIslands++;
                }
                else {
                    continue;
                }
            }
        }
        return numIslands;
    }
};
