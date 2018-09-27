static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
    unordered_map<char,int> nums;
public:
    Solution() {
        nums['I'] = 1;
        nums['V'] = 5;
        nums['X'] = 10;
        nums['L'] = 50;
        nums['C'] = 100;
        nums['D'] = 500;
        nums['M'] = 1000;
    }
    int romanToInt(string s) {
        int ans = 0;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(i == s.size()-1 || nums[s[i]] >= nums[s[i+1]])
                ans += nums[s[i]];
            else
                ans -= nums[s[i]];
        }
        return ans;
    }
};