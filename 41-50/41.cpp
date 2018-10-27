static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //n = nums.size() 缺失的正数一定在[1, n]范围内
        for(int i = 0 ; i < nums.size() ; i++)
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i]-1] != nums[i])
                //原来在i的数字要放到正确的位置上
                //交换结束后i上也应是正确的数字
                swap(nums[nums[i]-1], nums[i]);
        
        for(int i = 0 ; i < nums.size() ; i++)
            if(nums[i] != i + 1)
                return i + 1;
        
        return nums.size() + 1;
    }
};