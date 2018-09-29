static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size() - 1 ; i > 0 ; i--)
        {
            if(nums[i] > nums[i-1])
            {
                for(int j = i ; j < nums.size() ; j++)
                {
                    if(nums[j] <= nums[i-1])
                    {
                        swap(nums[i-1], nums[j-1]);
                        reverse(nums.begin()+i, nums.end());
                        return;
                    }
                    if(j == nums.size()-1)
                    {
                        swap(nums[i-1], nums[j]);
                        reverse(nums.begin()+i, nums.end());
                        return;
                    }
                }
            }
        }
        reverse(nums.begin(), nums.end());
    }
};