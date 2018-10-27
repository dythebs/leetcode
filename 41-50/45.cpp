static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int cur = nums[0], next = nums[0], step = 1;
        for(int i = 1 ; i < nums.size() ; i++)
        {
            if(cur < i)
                cur = next, step++;
            if(i + nums[i] > next)
                next = i + nums[i];
            if(cur >= nums.size()-1)
                return step;
        }
        return 0;
    }
};