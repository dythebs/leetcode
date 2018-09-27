static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
    vector<string> ans;
    vector<char> temp;
    string letterMap[10]={
        " ",
        "*","abc","def",
        "ghi","jkl","mno",
        "pqrs","tuv","wxyz"
    };
    void dfs(int depth, string& str)
    {
        if(depth == str.length())
        {
            ans.push_back(string(temp.begin(), temp.end()));
            return;
        }
        for(auto c : letterMap[str[depth]-'0'])
        {
            temp.push_back(c);
            dfs(depth+1, str);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        ans.clear();temp.clear();
        if(digits.size() == 0)
            return ans;
        dfs(0, digits);
        return ans;
    }
};