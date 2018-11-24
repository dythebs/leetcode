static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;
        heights.push_back(0);
        stack<int> s;
        int ans = 0;
        int l = -1, r = -1;
        for(int i = 0 ; i < heights.size() ; i++)
        {
            if(s.empty() || heights[s.top()] <= heights[i])
            {
                s.push(i);
                continue;
            }
            while(!s.empty() && heights[s.top()] > heights[i])
            {
                r = s.top();
                s.pop();
                l = s.empty() ? -1 : s.top();
                ans = max(ans, heights[r]*(i-l-1));
            }
            s.push(i);
        }
        return ans;
    }
};