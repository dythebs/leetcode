static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX, a = 0 , b = 1 , c = 2;
        for(int i = 0 ; i < nums.size() - 2 ; i ++)
        {
            int j = i+1 , k = nums.size() - 1;
            while(j < k)
            {
                int res = nums[i] + nums[j] + nums[k];
                int ans_tmp = abs(res - target);
                if(ans_tmp < ans)
                {
                    ans = ans_tmp;
                    a = i, b = j, c = k;
                }
                if(res > target)
                    k--;
                else
                    j++;
            }
        }
        return nums[a] + nums[b] + nums[c];
    }
};