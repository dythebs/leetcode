static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        bool firstZero = false;
        for(int j = 0 ; j < col ; j++)
            if(matrix[0][j] == 0)
            {
                firstZero = true;
                break;
            }
        for(int i = 1 ; i < row ; i++)
        {
            bool flag = false;
            for(int j = 0 ; j < col ; j++)
            {
                if(matrix[i][j] == 0)
                {
                    flag = true;
                    matrix[0][j] = 0;
                }
            }
            if(flag)
            {
                for(int j = 0 ; j < col ; j++)
                    matrix[i][j] = 0;
            }
        }
        for(int j = 0 ; j < col ; j++)
            if(matrix[0][j] == 0)
                for(int i = 0 ; i < row ; i++)
                    matrix[i][j] = 0;
        if(firstZero)
            for(int j = 0 ; j < col ; j++)
                matrix[0][j] = 0;
    }
};