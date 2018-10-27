static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> Map;
        for(int i = 0 ; i < strs.size() ; i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(!Map.count(temp))
            {
                Map[temp] = ans.size();
                ans.push_back(vector<string> {});
            }
            ans[Map[temp]].push_back(strs[i]);
                
        }
        return ans;
    }
};