static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
    void myRotate(vector<vector<int>>& matrix, int deep)
    {
        if(deep >= matrix.size() / 2)
            return;
        
        int l = matrix.size() - 2*deep;
        int temp[l];
        for(int i = 0 ; i < l ; i++)
            temp[i] = matrix[deep][i+deep];
        
        for(int i = l-1 ; i >= 1 ; i--)
            matrix[deep][i+deep] = matrix[matrix.size()-i-deep-1][deep];
        for(int i = l-1 ; i >= 1 ; i--)
            matrix[matrix.size()-i-deep-1][deep] = matrix[matrix.size()-deep-1][matrix.size()-deep-i-1];
        for(int i = l-1 ; i >= 1 ; i--)
            matrix[matrix.size()-deep-1][matrix.size()-deep-i-1] = matrix[deep+i][matrix.size()-deep-1];
        for(int i = l-1 ; i >= 1 ; i--)
            matrix[deep+i][matrix.size()-deep-1] = temp[i];
        
        myRotate(matrix, deep+1);
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        myRotate(matrix, 0);
    }
};