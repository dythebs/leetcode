class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	unordered_map<int,int> rec;
    	for(int i = 0 ; i < nums.size() ; i++)
    	{
    		if(rec.count(target - nums[i]))
			{
                return vector<int> {rec[target - nums[i]],i};
			}
            rec[nums[i]] = i;
		}
    }
};