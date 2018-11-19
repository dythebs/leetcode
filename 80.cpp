static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int l = 1, num = 1, last = nums[0];
        for(int i = 1 ; i < nums.size() ; i++)
        {
            if(nums[i] == last)
            {
                if(num == 2)
                    continue;
                else
                {
                    nums[l++] = nums[i];
                    num++;
                }
            }
            else
            {
                nums[l++] = nums[i];
                last = nums[i];
                num = 1;
            }
        }
        return l;
    }
};