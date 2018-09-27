static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size() < 4)
            return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size() - 3 ; i++)
        {
            for(int j = i + 1 ; j < nums.size() - 2; j++)
            {
                int k = j + 1 , l = nums.size() - 1;
                while(k < l)
                {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum < target)
                        k++;
                    else if(sum > target)
                        l--;
                    else
                    {
                        ans.push_back(vector<int> {nums[i], nums[j],
                                                  nums[k], nums[l]});
                        while(k + 1 < nums.size() && nums[k] == nums[k+1])
                            k++;
                        while(l - 1 > 0 && nums[l] == nums[l-1])
                            l--;
                        k++;l--;
                    }
                }
                while(j + 1 < nums.size() && nums[j] == nums[j+1])
                    j++;
            }
            while(i + 1 < nums.size() && nums[i] == nums[i+1])
                i++;
        }
        return ans;
    }
};