static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        string ans = "";
        while(1)
        {
            char c = '\0';
            for(int i = 0 ; i < strs.size() ; i++)
            {
                if(ans.size() + 1 <= strs[i].size())
                {
                    if(c == '\0')
                        c = strs[i][ans.size()];
                    else if(strs[i][ans.size()] != c)
                        return ans;
                }
                else
                    return ans;
            }
            ans += c;
        }
    }
};