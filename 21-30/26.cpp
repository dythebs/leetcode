static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size()) return 0;
        int ans = 1, last = nums[0];
        for(int i = 1 ; i < nums.size() ; i++)
        {
            if(nums[i] == last)
                continue;
            last = nums[i];
            nums[ans++] = nums[i];
        }
        return ans;
    }
};