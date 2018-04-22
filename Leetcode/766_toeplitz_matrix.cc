class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols;
        if (rows > 0)
            cols = matrix[0].size();
        int index, val;
        for (int j = 0; j < cols; ++j) {
            index = j;
            val = matrix[0][j];
            for (int i = 1; i < rows; ++i) {
                index += 1;
                if (index == cols)
                    break;
                if (matrix[i][index] != val)
                    return false;                       
            }                
        }
        for (int i = 1; i < rows; ++i) {
            val = matrix[i][0];
            index = i;
            for (int j = 1; j < cols; ++j) {
                index += 1;
                if (index == rows)
                    break;
                if (matrix[index][j] != val)
                    return false;                
            }
        }
    return true;
    }
};
