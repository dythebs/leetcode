static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;
        int col = 0;
        int colLen = matrix[0].size();
        if(colLen == 0)
            return false;
        for(col = 0 ; col < matrix.size() ; col++)
            if(matrix[col][colLen-1] >= target)
                break;
        if(col == matrix.size())
            return false;
        int l = 0 , r = colLen-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(matrix[col][mid] > target)
                r = mid-1;
            else if(matrix[col][mid] < target)
                l = mid+1;
            else return true;
        }
        return false;
    }
};