static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return vector<int> {-1, -1};
        
        int l = 0 , r = nums.size() - 1;
        int mid = 0;
        while(l < r)
        {
            mid = l + (r-l+1)/2;
            if(nums[mid] <= target)
                l = mid;
            else
                r = mid - 1;
        }
        
        int ans_r = l;
        if(nums[ans_r] != target)
            return vector<int> {-1, -1};
        
        l = 0 , r = nums.size() - 1;
        while(l < r)
        {
            mid = l + (r-l)/2;//0011
            if(nums[mid] >= target)
                r = mid;
            else l = mid + 1;
        }

        return vector<int> {l, ans_r};
    }
};