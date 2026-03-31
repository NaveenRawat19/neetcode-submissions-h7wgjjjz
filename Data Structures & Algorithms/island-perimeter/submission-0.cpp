class Solution {
public:
    int findEdges(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col)
    {
        if(row < 0 || col <0 || row >= grid.size() || col>= grid[0].size() || grid[row][col] == 0)
            return 1;
        if(vis[row][col]){
            return 0;
        }

        vis[row][col] = 1;
        return findEdges(grid, vis, row, col+1) + findEdges(grid, vis, row+1, col) + findEdges(grid, vis, row, col-1) + findEdges(grid, vis, row-1, col);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == 1){
                    return findEdges(grid, vis, i, j);
                }
            }
        }

        return 0;
    }
};