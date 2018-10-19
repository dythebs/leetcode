static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())
            return 0;
        int l = 0, r = height.size() - 1;
        int lmax = height[l], rmax = height[r];
        int lmaxi = l, rmaxi = r;
        int ans = 0;
        while(1)
        {
            if(height[l] <= height[r])
            {
                l++;
                if(height[l] >= lmax)
                {
                    for(int i = lmaxi + 1 ; i < l ; i++)
                        ans += lmax - height[i];
                    lmax = height[l];
                    lmaxi = l;
                }
            }
            else
            {
                r--;
                if(height[r] >= rmax)
                {
                    for(int i = rmaxi - 1 ; i > r ; i--)
                        ans += rmax - height[i];
                    rmax = height[r];
                    rmaxi = r;
                }
            }
            if(l >= r)
                break;
        }
        return ans;
    }
};