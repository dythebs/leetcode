static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for(int j = 0 ; j < nums.size() ; j++)
        {
            if(nums[j] == val)
                continue;
            nums[i++] = nums[j];
        }
        return i;
    }
};