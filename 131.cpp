class Solution {
public:
    vector<string> temp;
    vector<vector<string>> ans;
    bool valid(string s) {
        int n = s.size()/2;// ab n=1
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] != s[s.size()-1-i])
                return false;
        }
        return true;
    }
    void dfs(string &s, int index) {
        if(index == s.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i = index ; i < s.size() ; i++)
        {
            string tmp = s.substr(index, i-index+1);
            if(valid(tmp))
            {
                temp.push_back(tmp);
                dfs(s, i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return ans;
    }
};