static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0 , r = nums.size()-1;
        for(int m = l ; m <= r ; m++)
        {
            if(nums[m] == 0)
                swap(nums[m], nums[l++]);
            else if(nums[m] == 2)
                swap(nums[m--], nums[r--]);
        }
    }
};