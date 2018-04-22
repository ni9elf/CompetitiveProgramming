class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0, columns, rows = grid.size();
        for (int i = 0; i < rows; ++i) {
            columns = grid[i].size();
            for (int j = 0; j < columns; ++j) {                
                if(grid[i][j] == 1) {
                    if(i-1 < 0)
                        perimeter += 1;
                    else if(grid[i-1][j] == 0)
                        perimeter += 1;
                    if(j-1 < 0)
                        perimeter += 1;
                    else if(grid[i][j-1] == 0)
                        perimeter += 1;
                    if(i+1 >= rows)
                        perimeter += 1;
                    else if(grid[i+1][j] == 0)
                        perimeter += 1;
                    if(j+1 >= columns)
                        perimeter += 1;
                    else if(grid[i][j+1] == 0)
                        perimeter += 1;
                }
            }
        }
        return perimeter;
    }
};
