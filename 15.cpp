static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3)
            return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size() - 2 ; i++)
        {
            int j = i + 1 , k = nums.size() - 1;//枚举第一个数，two points找两数之和
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            if(nums[i] > 0)
                break;
            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0)
                    j++;
                else if(sum > 0)
                    k--;
                else
                {
                    ans.push_back(vector<int> 
                                  {nums[i], nums[j], nums[k]});
                    while(j + 1 < nums.size() && nums[j+1]==nums[j])
                        j++;
                    while(k - 1 > 0 && nums[k-1]==nums[k])
                        k--;
                    j++;k--;
                }
            }
        }
        return ans;
    }
};