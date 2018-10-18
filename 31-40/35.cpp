static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0 , r = nums.size() - 1;
        int mid = 0;
        while(l < r)
        {
            mid = l + (r-l+1)/2;//1100
            if(nums[mid] <= target)
                l = mid;
            else r = mid - 1;
        }
        if(nums[l] == target)
            return l;
        else return nums[l] > target ? l : l + 1;
    }
};