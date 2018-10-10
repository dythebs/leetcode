static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        if(r < 0)
            return -1;
        while(l<r)
        {
            int mid = l + (r-l+1)/2;//1100
            if(nums[mid] > nums[nums.size()-1])
                l = mid;
            else r = mid - 1;
        }
        int d = l;
        l = 0, r = nums.size()-1;
        if(target <= nums[d] && target >= nums[0])
            r = d;
        else l = d + 1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};