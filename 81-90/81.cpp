static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        int l = 0, r = nums.size()-2;
        while(l < r && nums[r] == nums[nums.size()-1])
            r--;
            
        while(l<r)
        {
            int mid = l + (r-l+1)/2; //1100
            if(nums[mid] >= nums[nums.size()-1])
                l = mid;
            else r = mid-1;
        }
        int key = l;

        l = 0, r = key;
        while(l<r)
        {
            int mid = l + (r-l+1)/2; //1100
            if(nums[mid] <= target)
                l = mid;
            else r = mid-1;
        }
        if(l >= 0 && l < nums.size() && nums[l] == target)
            return true;
        
        l = key+1, r = nums.size()-1;
        while(l<r)
        {
            int mid = l + (r-l+1)/2; //1100
            if(nums[mid]  <=  target)
                l = mid;
            else r = mid-1;
        }
        if(l >= 0 && l < nums.size() && nums[l] == target)
            return true;
        
        return false;
    }
};