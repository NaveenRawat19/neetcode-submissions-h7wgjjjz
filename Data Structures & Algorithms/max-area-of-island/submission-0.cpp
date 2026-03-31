class Solution {
public:
    void findArea(vector<vector<int>>& grid, vector<vector<int>>& vis, int& row, int& col, int& area){
        vis[row][col] = 1;
        area++;
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int nx = row + delrow[i];
            int ny = col + delcol[i];
            if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && !vis[nx][ny] && grid[nx][ny]==1){
                findArea(grid, vis, nx, ny, area);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        int maxArea = 0, area=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    findArea(grid, vis, i, j, area);
                }
                maxArea = max(maxArea, area);
                area = 0;
            }
        }

        return maxArea;
    }
};
