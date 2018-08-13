static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0 , j = height.size() - 1;
        int ans = -1;
        while(i < j)
        {
            ans = max(ans, min(height[i], height[j])*(j-i));
            height[i] > height[j] ? j-- : i++;
        }
        return ans;
    }
};