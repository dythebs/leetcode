static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr = nums[0], next = nums[0];
        for(int i = 1 ; i < nums.size() ; i++)
        {
            if(i > curr)
                curr = next;
            if(curr < i)
                return false;
            if(i+nums[i] > next)
                next = i+nums[i];
        }
        return true;
    }
};